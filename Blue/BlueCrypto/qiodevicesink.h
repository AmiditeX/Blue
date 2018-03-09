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

#ifndef QIODEVICESINK_H
#define QIODEVICESINK_H

#include <filters.h>
#include <QIODevice>
#include <QByteArray>
#include <QBuffer>

class QIODeviceSink : public CryptoPP::Sink, public CryptoPP::NotCopyable
{
public:
#if CRYPTOPP_VERSION >= 600
    using byte = CryptoPP::byte;
#endif

    class Err : public CryptoPP::Exception
    {
    public:
        Err(const QString &s);
    };

    QIODeviceSink();
    QIODeviceSink(QIODevice *device);

    QIODevice *device() const;

    void IsolatedInitialize(const CryptoPP::NameValuePairs &parameters) override;
    size_t Put2(const byte *inString, size_t length, int messageEnd, bool blocking) override;
    bool IsolatedFlush(bool hardFlush, bool blocking) override;

protected:
    static const char * const DeviceParameter;

private:
    QIODevice *_device;
};

class QByteArraySink : public QIODeviceSink
{
public:
    QByteArraySink();
    QByteArraySink(QByteArray &sink);

    const QByteArray &buffer() const;

private:
    QBuffer _buffer;
};

#endif // QIODEVICESINK_H
