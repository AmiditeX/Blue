<<<<<<< HEAD
// pkcspad.h - originally written and placed in the public domain by Wei Dai

/// \file pkcspad.h
/// \brief Classes for PKCS padding schemes
/// \details PKCS #1 v1.5, v2.0 and P1363a allow MD2, MD5, SHA1, SHA224, SHA256, SHA384,
///   SHA512, Tiger and RipeMd-160 to be instantiated.
=======
// pkcspad.h - written and placed in the public domain by Wei Dai

//! \file pkcspad.h
//! \brief Classes for PKCS padding schemes
//! \details PKCS#1 v1.5, v2.0 and P1363a allow MD2, MD5, SHA1, SHA224, SHA256, SHA384, SHA512, Tiger and RipeMd-160 to be instantiated.
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_PKCSPAD_H
#define CRYPTOPP_PKCSPAD_H

#include "cryptlib.h"
#include "pubkey.h"
<<<<<<< HEAD
#include "hashfwd.h"
=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifdef CRYPTOPP_IS_DLL
#include "sha.h"
#endif

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief PKCS #1 v1.5 Encryption Padding Scheme
/// \sa <a href="http://www.weidai.com/scan-mirror/ca.html#cem_PKCS1-1.5">EME-PKCS1-v1_5</a>
class PKCS_EncryptionPaddingScheme : public PK_EncryptionMessageEncodingMethod
{
public:
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "EME-PKCS1-v1_5";}
=======
//! \class PKCS_EncryptionPaddingScheme
//! \brief PKCS#1 v1.5 Encryption Padding Scheme
//! \sa <a href="http://www.weidai.com/scan-mirror/ca.html#cem_PKCS1-1.5">EME-PKCS1-v1_5</a>
class PKCS_EncryptionPaddingScheme : public PK_EncryptionMessageEncodingMethod
{
public:
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "EME-PKCS1-v1_5";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

	size_t MaxUnpaddedLength(size_t paddedLength) const;
	void Pad(RandomNumberGenerator &rng, const byte *raw, size_t inputLength, byte *padded, size_t paddedLength, const NameValuePairs &parameters) const;
	DecodingResult Unpad(const byte *padded, size_t paddedLength, byte *raw, const NameValuePairs &parameters) const;
};

<<<<<<< HEAD
/// \brief PKCS #1 decoration data structure
=======
//! \class PKCS_DigestDecoration
//! \brief PKCS#1 decoration data structure
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
template <class H> class PKCS_DigestDecoration
{
public:
	static const byte decoration[];
	static const unsigned int length;
};

// PKCS_DigestDecoration can be instantiated with the following
<<<<<<< HEAD
// classes as specified in PKCS #1 v2.0 and P1363a
// SHA1, SHA224, SHA256, SHA384, SHA512, Tiger, RIPEMD160, MD2, MD5

#if defined(CRYPTOPP_IS_DLL)
=======
// classes as specified in PKCS#1 v2.0 and P1363a
class SHA1;
class SHA224;
class SHA256;
class SHA384;
class SHA512;
class Tiger;
class RIPEMD160;
namespace Weak1 {
class MD2;
class MD5;
}
// end of list

#ifdef CRYPTOPP_IS_DLL
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA1>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA224>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA256>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA384>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA512>;
<<<<<<< HEAD
// http://github.com/weidai11/cryptopp/issues/517
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_256>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_384>;
CRYPTOPP_DLL_TEMPLATE_CLASS PKCS_DigestDecoration<SHA3_512>;
#endif

// https://github.com/weidai11/cryptopp/issues/300 and
// https://github.com/weidai11/cryptopp/issues/533
#if defined(__clang__)
template<> const byte PKCS_DigestDecoration<SHA1>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA1>::length;
template<> const byte PKCS_DigestDecoration<SHA224>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA224>::length;
template<> const byte PKCS_DigestDecoration<SHA256>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA256>::length;
template<> const byte PKCS_DigestDecoration<SHA384>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA384>::length;
template<> const byte PKCS_DigestDecoration<SHA512>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA512>::length;

// http://github.com/weidai11/cryptopp/issues/517
template<> const byte PKCS_DigestDecoration<SHA3_256>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_256>::length;
template<> const byte PKCS_DigestDecoration<SHA3_384>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_384>::length;
template<> const byte PKCS_DigestDecoration<SHA3_512>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<SHA3_512>::length;

template<> const byte PKCS_DigestDecoration<Weak1::MD2>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<Weak1::MD2>::length;
template<> const byte PKCS_DigestDecoration<Weak1::MD5>::decoration[];
template<> const unsigned int PKCS_DigestDecoration<Weak1::MD5>::length;
#endif

/// \brief PKCS #1 v1.5 Signature Encoding Scheme
/// \sa <a href="http://www.weidai.com/scan-mirror/sig.html#sem_PKCS1-1.5">EMSA-PKCS1-v1_5</a>
class CRYPTOPP_DLL PKCS1v15_SignatureMessageEncodingMethod : public PK_DeterministicSignatureMessageEncodingMethod
{
public:
	CRYPTOPP_STATIC_CONSTEXPR const char* CRYPTOPP_API StaticAlgorithmName() {return "EMSA-PKCS1-v1_5";}
=======
#endif

//! \class PKCS1v15_SignatureMessageEncodingMethod
//! \brief PKCS#1 v1.5 Signature Encoding Scheme
//! \sa <a href="http://www.weidai.com/scan-mirror/sig.html#sem_PKCS1-1.5">EMSA-PKCS1-v1_5</a>
class CRYPTOPP_DLL PKCS1v15_SignatureMessageEncodingMethod : public PK_DeterministicSignatureMessageEncodingMethod
{
public:
	CRYPTOPP_CONSTEXPR static const char * CRYPTOPP_API StaticAlgorithmName() {return "EMSA-PKCS1-v1_5";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

	size_t MinRepresentativeBitLength(size_t hashIdentifierSize, size_t digestSize) const
		{return 8 * (digestSize + hashIdentifierSize + 10);}

	void ComputeMessageRepresentative(RandomNumberGenerator &rng,
		const byte *recoverableMessage, size_t recoverableMessageLength,
		HashTransformation &hash, HashIdentifier hashIdentifier, bool messageEmpty,
		byte *representative, size_t representativeBitLength) const;

	struct HashIdentifierLookup
	{
		template <class H> struct HashIdentifierLookup2
		{
			static HashIdentifier Lookup()
			{
				return HashIdentifier(PKCS_DigestDecoration<H>::decoration, PKCS_DigestDecoration<H>::length);
			}
		};
	};
};

<<<<<<< HEAD
/// \brief PKCS #1 version 1.5, for use with RSAES and RSASS
/// \dontinclude pkcspad.h

=======
//! PKCS #1 version 1.5, for use with RSAES and RSASS
/*! Only the following hash functions are supported by this signature standard:
	\dontinclude pkcspad.h
	\skip can be instantiated
	\until end of list
*/
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
struct PKCS1v15 : public SignatureStandard, public EncryptionStandard
{
	typedef PKCS_EncryptionPaddingScheme EncryptionMessageEncodingMethod;
	typedef PKCS1v15_SignatureMessageEncodingMethod SignatureMessageEncodingMethod;
};

NAMESPACE_END

#endif
