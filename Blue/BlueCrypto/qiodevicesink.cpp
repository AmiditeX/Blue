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

#include "qiodevicesink.h"
using namespace CryptoPP;

#ifdef max
#undef max
#endif

const char * const QIODeviceSink::DeviceParameter = "QIODevice";

QIODeviceSink::QIODeviceSink() :
	_device(nullptr)
{}

QIODeviceSink::QIODeviceSink(QIODevice *device) :
	_device(nullptr)
{
	IsolatedInitialize(MakeParameters(DeviceParameter, device));
}

QIODevice *QIODeviceSink::device() const
{
	return _device;
}

void QIODeviceSink::IsolatedInitialize(const NameValuePairs &parameters)
{
	_device = nullptr;
	parameters.GetValue(DeviceParameter, _device);
	if(!_device || !_device->isWritable())
		throw Err(QStringLiteral("QIODeviceSink: passed QIODevice is either null or not opened for writing"));
}

bool QIODeviceSink::IsolatedFlush(bool hardFlush, bool blocking)
{
	Q_UNUSED(hardFlush)
	Q_UNUSED(blocking)

	if(!_device)
		throw Err(QStringLiteral("QIODeviceSink: passed QIODevice is null"));

	if(_device->bytesToWrite() > 0) {
		if(!_device->waitForBytesWritten(-1))
			throw Err(QStringLiteral("QIODeviceSink: Failed to flush with error: %1").arg(_device->errorString()));
	}
	return false;
}

size_t QIODeviceSink::Put2(const byte *inString, size_t length, int messageEnd, bool blocking)
{
	Q_UNUSED(blocking)

	if (!_device)
		throw Err(QStringLiteral("QIODeviceSink: passed QIODevice is null"));

	while (length > 0)
	{
		qint64 size;
		if (!SafeConvert(length, size))
			size = std::numeric_limits<qint64>::max();
		auto written = _device->write(reinterpret_cast<const char *>(inString), size);
		if(written == -1)
			throw Err(QStringLiteral("QIODeviceSink: Failed to write with error: %1").arg(_device->errorString()));
		inString += written;
		length -= static_cast<size_t>(written);
	}

	if(messageEnd)
		IsolatedFlush(false, blocking);
	return 0;
}



QByteArraySink::QByteArraySink() :
	QIODeviceSink()
{}

QByteArraySink::QByteArraySink(QByteArray &sink) :
	QIODeviceSink(),
	_buffer(&sink)
{
	_buffer.open(QIODevice::WriteOnly);
	IsolatedInitialize(MakeParameters(DeviceParameter, static_cast<QIODevice*>(&_buffer)));
}

const QByteArray &QByteArraySink::buffer() const
{
	return _buffer.data();
}



QIODeviceSink::Err::Err(const QString &s) :
	Exception(IO_ERROR, s.toStdString())
{}
