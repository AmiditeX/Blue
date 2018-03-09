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

#ifndef QIODEVICESOURCE_H
#define QIODEVICESOURCE_H

#include <filters.h>
#include <QIODevice>
#include <QByteArray>
#include <QBuffer>

class QIODeviceStore : public CryptoPP::Store, private CryptoPP::FilterPutSpaceHelper, public CryptoPP::NotCopyable
{
public:
#if CRYPTOPP_VERSION >= 600
    using byte = CryptoPP::byte;
#endif

    static const char * const DeviceParameter;

    class Err : public CryptoPP::Exception
    {
    public:
        Err(const QString &s);
    };

    QIODeviceStore();
    QIODeviceStore(QIODevice *device);

    CryptoPP::lword MaxRetrievable() const override;
    size_t TransferTo2(CryptoPP::BufferedTransformation &target, CryptoPP::lword &transferBytes, const std::string &channel, bool blocking) override;
    size_t CopyRangeTo2(CryptoPP::BufferedTransformation &target, CryptoPP::lword &begin, CryptoPP::lword end, const std::string &channel, bool blocking) const override;
    CryptoPP::lword Skip(CryptoPP::lword skipMax=ULONG_MAX) override;

    QIODevice *device() const;

protected:
    void StoreInitialize(const CryptoPP::NameValuePairs &parameters) override;

private:
    QIODevice *_device;
    byte *_space;
    qint64 _len;
    bool _waiting;
};

class QIODeviceSource : public CryptoPP::SourceTemplate<QIODeviceStore>
{
public:
    QIODeviceSource(CryptoPP::BufferedTransformation *attachment = nullptr);
    QIODeviceSource(QIODevice *device, bool pumpAll, CryptoPP::BufferedTransformation *attachment = nullptr);

    QIODevice *device() const;
};

class QByteArraySource : public QIODeviceSource
{
public:
    QByteArraySource(CryptoPP::BufferedTransformation *attachment = nullptr);
    QByteArraySource(const QByteArray &source, bool pumpAll, CryptoPP::BufferedTransformation *attachment = nullptr);

    const QByteArray &buffer() const;

private:
    QBuffer _buffer;
};

#endif // QIODEVICESOURCE_H
