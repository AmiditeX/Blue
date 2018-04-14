<<<<<<< HEAD
// oaep.h - originally written and placed in the public domain by Wei Dai

/// \file oaep.h
/// \brief Classes for optimal asymmetric encryption padding
/// \since Crypto++ 2.1

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#ifndef CRYPTOPP_OAEP_H
#define CRYPTOPP_OAEP_H

#include "cryptlib.h"
#include "pubkey.h"
#include "sha.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief OAEP padding base class
/// \since Crypto++ 2.1
=======
//! _
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class CRYPTOPP_DLL OAEP_Base : public PK_EncryptionMessageEncodingMethod
{
public:
	bool ParameterSupported(const char *name) const {return strcmp(name, Name::EncodingParameters()) == 0;}
	size_t MaxUnpaddedLength(size_t paddedLength) const;
	void Pad(RandomNumberGenerator &rng, const byte *raw, size_t inputLength, byte *padded, size_t paddedLength, const NameValuePairs &parameters) const;
	DecodingResult Unpad(const byte *padded, size_t paddedLength, byte *raw, const NameValuePairs &parameters) const;

protected:
	virtual unsigned int DigestSize() const =0;
	virtual HashTransformation * NewHash() const =0;
	virtual MaskGeneratingFunction * NewMGF() const =0;
};

<<<<<<< HEAD
/// \brief OAEP padding
/// \tparam H HashTransformation derived class
/// \tparam MGF MaskGeneratingFunction derived class
/// \sa <a href="http://www.weidai.com/scan-mirror/ca.html#cem_OAEP-MGF1">EME-OAEP</a>, for use with classes derived from TF_ES
/// \since Crypto++ 2.1
=======
//! <a href="http://www.weidai.com/scan-mirror/ca.html#cem_OAEP-MGF1">EME-OAEP</a>, for use with classes derived from TF_ES
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
template <class H, class MGF=P1363_MGF1>
class OAEP : public OAEP_Base, public EncryptionStandard
{
public:
	static std::string CRYPTOPP_API StaticAlgorithmName() {return std::string("OAEP-") + MGF::StaticAlgorithmName() + "(" + H::StaticAlgorithmName() + ")";}
	typedef OAEP<H, MGF> EncryptionMessageEncodingMethod;

protected:
	unsigned int DigestSize() const {return H::DIGESTSIZE;}
	HashTransformation * NewHash() const {return new H;}
	MaskGeneratingFunction * NewMGF() const {return new MGF;}
};

<<<<<<< HEAD
CRYPTOPP_DLL_TEMPLATE_CLASS OAEP<SHA1>;
=======
CRYPTOPP_DLL_TEMPLATE_CLASS OAEP<SHA>;
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

NAMESPACE_END

#endif
