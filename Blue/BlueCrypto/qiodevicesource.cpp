// Code from CryptoQQ https://github.com/Skycoder42/CryptoQQ
// Interface between CryptoPP library and Qt to use QByteArrays
// as Sink and Source during the encryption process.
//
// BSD 3-Clause License
// Copyright (c) 2018, Felix Barz
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//  contributors may be used to endorse or promote products derived from
//  this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "qiodevicesource.h"
using namespace CryptoPP;

const char * const QIODeviceStore::DeviceParameter = "QIODevice";

QIODeviceStore::QIODeviceStore() :
	_device(nullptr),
	_space(nullptr),
	_len(0),
	_waiting(0)
{}

QIODeviceStore::QIODeviceStore(QIODevice *device) :
	_device(nullptr),
	_space(nullptr),
	_len(0),
	_waiting(0)
{
	StoreInitialize(MakeParameters(DeviceParameter, device));
}

lword QIODeviceStore::MaxRetrievable() const
{
	if (!_device)
		return 0;
	return _device->bytesAvailable();
}

size_t QIODeviceStore::TransferTo2(BufferedTransformation &target, lword &transferBytes, const std::string &channel, bool blocking)
{
	if (!_device) {
		transferBytes = 0;
		return 0;
	}

	auto size = transferBytes;
	transferBytes = 0;

	while (size > 0 && !_device->atEnd()) {
		if(!_waiting) {
			size_t spaceSize = 1024;
			_space = HelpCreatePutSpace(target, channel, 1, UnsignedMin(size_t(SIZE_MAX), size), spaceSize);
			_len = static_cast<size_t>(_device->read(reinterpret_cast<char*>(_space), static_cast<qint64>(STDMIN(size, static_cast<lword>(spaceSize)))));
			if(_len == -1)
				throw Err(QStringLiteral("QIODeviceStore: Failed to read with error: %1").arg(_device->errorString()));
		}

		auto blockedBytes = target.ChannelPutModifiable2(channel, _space, _len, 0, blocking);
		_waiting = blockedBytes > 0;
		if (_waiting)
			return blockedBytes;
		size -= static_cast<size_t>(_len);
		transferBytes += static_cast<size_t>(_len);
	}

	return 0;
}

size_t QIODeviceStore::CopyRangeTo2(BufferedTransformation &target, lword &begin, lword end, const std::string &channel, bool blocking) const
{
	if (!_device)
		return 0;

	QByteArray data;
	if(_device->isSequential()) {
		data = _device->peek(static_cast<qint64>(end));
		if (data.isEmpty())
			return 0;
		data = data.mid(static_cast<int>(begin));
	} else {
		const auto cPos = _device->pos();
		const auto nPos = cPos + static_cast<qint64>(begin);
		if(nPos >= _device->size())
			return 0;
		_device->seek(nPos);
		data = _device->read(static_cast<qint64>(end - begin));
		_device->seek(cPos);
	}
	size_t blockedBytes = target.ChannelPut(channel, reinterpret_cast<byte*>(data.data()), static_cast<size_t>(data.size()), blocking);
	begin += static_cast<size_t>(data.size()) - blockedBytes;
	return blockedBytes;
}

lword QIODeviceStore::Skip(lword skipMax)
{
	if (!_device)
		return 0;

	auto pos = _device->pos();
	qint64 offset;
	if (!SafeConvert(skipMax, offset))
		throw InvalidArgument("QIODeviceStore: maximum seek offset exceeded");
	_device->seek(pos + offset);
	return static_cast<lword>(_device->pos() - pos);
}

QIODevice *QIODeviceStore::device() const
{
	return _device;
}

void QIODeviceStore::StoreInitialize(const CryptoPP::NameValuePairs &parameters)
{
	_device = nullptr;
	parameters.GetValue(DeviceParameter, _device);
	if(!_device || !_device->isReadable())
		throw Err(QStringLiteral("QIODeviceStore: passed QIODevice is either null or not opened for reading"));
}



QIODeviceSource::QIODeviceSource(BufferedTransformation *attachment) :
	SourceTemplate<QIODeviceStore>(attachment)
{}

QIODeviceSource::QIODeviceSource(QIODevice *device, bool pumpAll, BufferedTransformation *attachment) :
	SourceTemplate<QIODeviceStore>(attachment)
{
	SourceInitialize(pumpAll, MakeParameters(QIODeviceStore::DeviceParameter, device));
}

QIODevice *QIODeviceSource::device() const
{
	return m_store.device();
}



QByteArraySource::QByteArraySource(BufferedTransformation *attachment) :
	QIODeviceSource(attachment),
	_buffer()
{}

QByteArraySource::QByteArraySource(const QByteArray &source, bool pumpAll, BufferedTransformation *attachment) :
	QIODeviceSource(attachment),
	_buffer()
{
	_buffer.setData(source);
	_buffer.open(QIODevice::ReadOnly);
	SourceInitialize(pumpAll, MakeParameters(QIODeviceStore::DeviceParameter, static_cast<QIODevice*>(&_buffer)));
}

const QByteArray &QByteArraySource::buffer() const
{
	return _buffer.data();
}



QIODeviceStore::Err::Err(const QString &s) :
	 Exception(IO_ERROR, s.toStdString())
{}
