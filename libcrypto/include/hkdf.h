<<<<<<< HEAD
// hkdf.h - written and placed in public domain by Jeffrey Walton.

/// \file hkdf.h
/// \brief Classes for HKDF from RFC 5869
/// \since Crypto++ 5.6.3

#ifndef CRYPTOPP_HKDF_H
#define CRYPTOPP_HKDF_H

#include "cryptlib.h"
=======
// hkdf.h - written and placed in public domain by Jeffrey Walton. Copyright assigned to Crypto++ project.

//! \file hkdf.h
//! \brief Classes for HKDF from RFC 5869
//! \since Crypto++ 5.6.3

#ifndef CRYPTOPP_HASH_KEY_DERIVATION_FUNCTION_H
#define CRYPTOPP_HASH_KEY_DERIVATION_FUNCTION_H

#include "cryptlib.h"
#include "hrtimer.h"
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#include "secblock.h"
#include "hmac.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief Extract-and-Expand Key Derivation Function (HKDF)
/// \tparam T HashTransformation class
/// \sa <A HREF="http://eprint.iacr.org/2010/264">Cryptographic Extraction and Key
///   Derivation: The HKDF Scheme</A> and
///   <A HREF="http://tools.ietf.org/html/rfc5869">HMAC-based Extract-and-Expand Key
///   Derivation Function (HKDF)</A>
/// \since Crypto++ 5.6.3
template <class T>
class HKDF : public KeyDerivationFunction
{
public:
	virtual ~HKDF() {}

	static std::string StaticAlgorithmName () {
		const std::string name(std::string("HKDF(") +
			std::string(T::StaticAlgorithmName()) + std::string(")"));
		return name;
	}

	// KeyDerivationFunction interface
	std::string AlgorithmName() const {
		return StaticAlgorithmName();
	}

	// KeyDerivationFunction interface
	size_t MaxDerivedLength() const {
		return static_cast<size_t>(T::DIGESTSIZE) * 255;
	}

	// KeyDerivationFunction interface
	size_t GetValidDerivedLength(size_t keylength) const;

	// KeyDerivationFunction interface
	size_t DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen,
	    const NameValuePairs& params) const;

	/// \brief Derive a key from a seed
	/// \param derived the derived output buffer
	/// \param derivedLen the size of the derived buffer, in bytes
	/// \param secret the seed input buffer
	/// \param secretLen the size of the secret buffer, in bytes
	/// \param salt the salt input buffer
	/// \param saltLen the size of the salt buffer, in bytes
	/// \param info the additional input buffer
	/// \param infoLen the size of the info buffer, in bytes
	/// \returns the number of iterations performed
	/// \throws InvalidDerivedLength if <tt>derivedLen</tt> is invalid for the scheme
	/// \details DeriveKey() provides a standard interface to derive a key from
	///   a seed and other parameters. Each class that derives from KeyDerivationFunction
	///   provides an overload that accepts most parameters used by the derivation function.
	/// \details <tt>salt</tt> and <tt>info</tt> can be <tt>nullptr</tt> with 0 length.
	///   HKDF is unusual in that a non-NULL salt with length 0 is different than a
	///   NULL <tt>salt</tt>. A NULL <tt>salt</tt> causes HKDF to use a string of 0's
	///   of length <tt>T::DIGESTSIZE</tt> for the <tt>salt</tt>.
	/// \details HKDF always returns 1 because it only performs 1 iteration. Other
	///   derivation functions, like PBKDF's, will return more interesting values.
	size_t DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen,
	    const byte *salt, size_t saltLen, const byte* info, size_t infoLen) const;

protected:
	// KeyDerivationFunction interface
	const Algorithm & GetAlgorithm() const {
		return *this;
	}

	// If salt is absent (NULL), then use the NULL vector. Missing is different than
	// EMPTY (Non-NULL, 0 length). The length of s_NullVector used depends on the Hash
	// function. SHA-256 will use 32 bytes of s_NullVector.
	typedef byte NullVectorType[T::DIGESTSIZE];
=======
//! abstract base class for key derivation function
class KeyDerivationFunction
{
public:
	//! maximum number of bytes which can be produced under a secuirty context
	virtual size_t MaxDerivedKeyLength() const =0;
	virtual bool Usesinfo() const =0;
	//! derive a key from secret
	virtual unsigned int DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen, const byte *salt, size_t saltLen, const byte* info=NULL, size_t infoLen=0) const =0;

	virtual ~KeyDerivationFunction() {}
};

//! \brief Extract-and-Expand Key Derivation Function (HKDF)
//! \tparam T HashTransformation class
//! \sa <A HREF="http://eprint.iacr.org/2010/264">Cryptographic Extraction and Key Derivation: The HKDF Scheme</A>
//!   and <A HREF="http://tools.ietf.org/html/rfc5869">HMAC-based Extract-and-Expand Key Derivation Function (HKDF)</A>
//! \since Crypto++ 5.6.3
template <class T>
class HKDF : public KeyDerivationFunction
{
public:
	CRYPTOPP_CONSTANT(DIGESTSIZE = T::DIGESTSIZE)
	CRYPTOPP_CONSTANT(SALTSIZE = T::DIGESTSIZE)
	static const char* StaticAlgorithmName () {
		static const std::string name(std::string("HKDF(") + std::string(T::StaticAlgorithmName()) + std::string(")"));
		return name.c_str();
	}
	size_t MaxDerivedKeyLength() const {return static_cast<size_t>(T::DIGESTSIZE) * 255;}
	bool Usesinfo() const {return true;}
	unsigned int DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen, const byte *salt, size_t saltLen, const byte* info, size_t infoLen) const;

protected:
	// If salt is missing (NULL), then use the NULL vector. Missing is different than EMPTY (0 length). The length
	// of s_NullVector used depends on the Hash function. SHA-256 will use 32 bytes of s_NullVector.
	typedef byte NullVectorType[SALTSIZE];
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	static const NullVectorType& GetNullVector() {
		static const NullVectorType s_NullVector = {0};
		return s_NullVector;
	}
};

template <class T>
<<<<<<< HEAD
size_t HKDF<T>::GetValidDerivedLength(size_t keylength) const
{
	if (keylength > MaxDerivedLength())
		return MaxDerivedLength();
	return keylength;
}

template <class T>
size_t HKDF<T>::DeriveKey(byte *derived, size_t derivedLen,
    const byte *secret, size_t secretLen, const NameValuePairs& params) const
{
	CRYPTOPP_ASSERT(secret && secretLen);
	CRYPTOPP_ASSERT(derived && derivedLen);
	CRYPTOPP_ASSERT(derivedLen <= MaxDerivedLength());

	ConstByteArrayParameter p;
	SecByteBlock salt, info;

	if (params.GetValue("Salt", p))
		salt.Assign(p.begin(), p.size());
	else
		salt.Assign(GetNullVector(), T::DIGESTSIZE);

	if (params.GetValue("Info", p))
		info.Assign(p.begin(), p.size());
	else
		info.Assign(GetNullVector(), 0);

	return DeriveKey(derived, derivedLen, secret, secretLen, salt.begin(), salt.size(), info.begin(), info.size());
}

template <class T>
size_t HKDF<T>::DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen,
    const byte *salt, size_t saltLen, const byte* info, size_t infoLen) const
{
	CRYPTOPP_ASSERT(secret && secretLen);
	CRYPTOPP_ASSERT(derived && derivedLen);
	CRYPTOPP_ASSERT(derivedLen <= MaxDerivedLength());

	ThrowIfInvalidDerivedLength(derivedLen);

	// HKDF business logic. NULL is different than empty.
	if (salt == NULLPTR)
	{
		salt = GetNullVector();
		saltLen = T::DIGESTSIZE;
	}

	// key is PRK from the RFC, salt is IKM from the RFC
	HMAC<T> hmac;
	SecByteBlock key(T::DIGESTSIZE), buffer(T::DIGESTSIZE);

	// Extract
	hmac.SetKey(salt, saltLen);
	hmac.CalculateDigest(key, secret, secretLen);

	// Key
	hmac.SetKey(key.begin(), key.size());
	byte block = 0;

	// Expand
	while (derivedLen > 0)
	{
		if (block++) {hmac.Update(buffer, buffer.size());}
		if (infoLen) {hmac.Update(info, infoLen);}
		hmac.CalculateDigest(buffer, &block, 1);

#if CRYPTOPP_MSC_VERSION
		const size_t digestSize = static_cast<size_t>(T::DIGESTSIZE);
		const size_t segmentLen = STDMIN(derivedLen, digestSize);
		memcpy_s(derived, segmentLen, buffer, segmentLen);
#else
		const size_t digestSize = static_cast<size_t>(T::DIGESTSIZE);
		const size_t segmentLen = STDMIN(derivedLen, digestSize);
=======
unsigned int HKDF<T>::DeriveKey(byte *derived, size_t derivedLen, const byte *secret, size_t secretLen, const byte *salt, size_t saltLen, const byte* info, size_t infoLen) const
{
	static const size_t DIGEST_SIZE = static_cast<size_t>(T::DIGESTSIZE);
	const unsigned int req = static_cast<unsigned int>(derivedLen);

	CRYPTOPP_ASSERT(secret && secretLen);
	CRYPTOPP_ASSERT(derived && derivedLen);
	CRYPTOPP_ASSERT(derivedLen <= MaxDerivedKeyLength());

	if (derivedLen > MaxDerivedKeyLength())
		throw InvalidArgument("HKDF: derivedLen must be less than or equal to MaxDerivedKeyLength");

	HMAC<T> hmac;
	FixedSizeSecBlock<byte, DIGEST_SIZE> prk, buffer;

	// Extract
	const byte* key = (salt ? salt : GetNullVector());
	const size_t klen = (salt ? saltLen : DIGEST_SIZE);

	hmac.SetKey(key, klen);
	hmac.CalculateDigest(prk, secret, secretLen);

	// Expand
	hmac.SetKey(prk.data(), prk.size());
	byte block = 0;

	while (derivedLen > 0)
	{
		if (block++) {hmac.Update(buffer, buffer.size());}
		if (info && infoLen) {hmac.Update(info, infoLen);}
		hmac.CalculateDigest(buffer, &block, 1);

#if CRYPTOPP_MSC_VERSION
		const size_t segmentLen = STDMIN(derivedLen, DIGEST_SIZE);
		memcpy_s(derived, segmentLen, buffer, segmentLen);
#else
		const size_t segmentLen = STDMIN(derivedLen, DIGEST_SIZE);
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
		std::memcpy(derived, buffer, segmentLen);
#endif

		derived += segmentLen;
		derivedLen -= segmentLen;
	}

<<<<<<< HEAD
	return 1;
=======
	return req;
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
}

NAMESPACE_END

<<<<<<< HEAD
#endif // CRYPTOPP_HKDF_H
=======
#endif // CRYPTOPP_HASH_KEY_DERIVATION_FUNCTION_H
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
