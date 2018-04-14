<<<<<<< HEAD
// esign.h - originally written and placed in the public domain by Wei Dai

/// \file esign.h
/// \brief Classes providing ESIGN signature schemes as defined in IEEE P1363a
/// \since Crypto++ 5.0

#ifndef CRYPTOPP_ESIGN_H
#define CRYPTOPP_ESIGN_H

=======
#ifndef CRYPTOPP_ESIGN_H
#define CRYPTOPP_ESIGN_H

/** \file
	This file contains classes that implement the
	ESIGN signature schemes as defined in IEEE P1363a.
*/

>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#include "cryptlib.h"
#include "pubkey.h"
#include "integer.h"
#include "asn.h"
#include "misc.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief ESIGN trapdoor function using the public key
/// \since Crypto++ 5.0
=======
//! _
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class ESIGNFunction : public TrapdoorFunction, public ASN1CryptoMaterial<PublicKey>
{
	typedef ESIGNFunction ThisClass;

public:
<<<<<<< HEAD

	/// \brief Initialize a ESIGN public key with {n,e}
	/// \param n the modulus
	/// \param e the public exponent
=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	void Initialize(const Integer &n, const Integer &e)
		{m_n = n; m_e = e;}

	// PublicKey
	void BERDecode(BufferedTransformation &bt);
	void DEREncode(BufferedTransformation &bt) const;

	// CryptoMaterial
	bool Validate(RandomNumberGenerator &rng, unsigned int level) const;
	bool GetVoidValue(const char *name, const std::type_info &valueType, void *pValue) const;
	void AssignFrom(const NameValuePairs &source);

	// TrapdoorFunction
	Integer ApplyFunction(const Integer &x) const;
	Integer PreimageBound() const {return m_n;}
	Integer ImageBound() const {return Integer::Power2(GetK());}

	// non-derived
	const Integer & GetModulus() const {return m_n;}
	const Integer & GetPublicExponent() const {return m_e;}

	void SetModulus(const Integer &n) {m_n = n;}
	void SetPublicExponent(const Integer &e) {m_e = e;}

protected:
	// Covertiy finding on overflow. The library allows small values for research purposes.
	unsigned int GetK() const {return SaturatingSubtract(m_n.BitCount()/3, 1U);}

	Integer m_n, m_e;
};

<<<<<<< HEAD
/// \brief ESIGN trapdoor function using the private key
/// \since Crypto++ 5.0
=======
//! _
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class InvertibleESIGNFunction : public ESIGNFunction, public RandomizedTrapdoorFunctionInverse, public PrivateKey
{
	typedef InvertibleESIGNFunction ThisClass;

public:
<<<<<<< HEAD

	/// \brief Initialize a ESIGN private key with {n,e,p,q}
	/// \param n modulus
	/// \param e public exponent
	/// \param p first prime factor
	/// \param q second prime factor
	/// \details This Initialize() function overload initializes a private key from existing parameters.
	void Initialize(const Integer &n, const Integer &e, const Integer &p, const Integer &q)
		{m_n = n; m_e = e; m_p = p; m_q = q;}

	/// \brief Create a ESIGN private key
	/// \param rng a RandomNumberGenerator derived class
	/// \param modulusBits the size of the modulud, in bits
	/// \details This function overload of Initialize() creates a new private key because it
	///   takes a RandomNumberGenerator() as a parameter. If you have an existing keypair,
	///   then use one of the other Initialize() overloads.
	void Initialize(RandomNumberGenerator &rng, unsigned int modulusBits)
		{GenerateRandomWithKeySize(rng, modulusBits);}

	// Squash Visual Studio C4250 warning
	void Save(BufferedTransformation &bt) const
		{BEREncode(bt);}

	// Squash Visual Studio C4250 warning
	void Load(BufferedTransformation &bt)
		{BERDecode(bt);}

=======
	void Initialize(const Integer &n, const Integer &e, const Integer &p, const Integer &q)
		{m_n = n; m_e = e; m_p = p; m_q = q;}
	// generate a random private key
	void Initialize(RandomNumberGenerator &rng, unsigned int modulusBits)
		{GenerateRandomWithKeySize(rng, modulusBits);}

>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	void BERDecode(BufferedTransformation &bt);
	void DEREncode(BufferedTransformation &bt) const;

	Integer CalculateRandomizedInverse(RandomNumberGenerator &rng, const Integer &x) const;

	// GeneratibleCryptoMaterial
	bool Validate(RandomNumberGenerator &rng, unsigned int level) const;
	bool GetVoidValue(const char *name, const std::type_info &valueType, void *pValue) const;
	void AssignFrom(const NameValuePairs &source);
	/*! parameters: (ModulusSize) */
	void GenerateRandom(RandomNumberGenerator &rng, const NameValuePairs &alg);

	const Integer& GetPrime1() const {return m_p;}
	const Integer& GetPrime2() const {return m_q;}

	void SetPrime1(const Integer &p) {m_p = p;}
	void SetPrime2(const Integer &q) {m_q = q;}

protected:
	Integer m_p, m_q;
};

<<<<<<< HEAD
/// \brief EMSA5 padding method
/// \tparam T Mask Generation Function
/// \since Crypto++ 5.0
=======
//! _
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
template <class T>
class EMSA5Pad : public PK_DeterministicSignatureMessageEncodingMethod
{
public:
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "EMSA5";}
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "EMSA5";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

	void ComputeMessageRepresentative(RandomNumberGenerator &rng,
		const byte *recoverableMessage, size_t recoverableMessageLength,
		HashTransformation &hash, HashIdentifier hashIdentifier, bool messageEmpty,
		byte *representative, size_t representativeBitLength) const
	{
		CRYPTOPP_UNUSED(rng), CRYPTOPP_UNUSED(recoverableMessage), CRYPTOPP_UNUSED(recoverableMessageLength);
		CRYPTOPP_UNUSED(messageEmpty), CRYPTOPP_UNUSED(hashIdentifier);
		SecByteBlock digest(hash.DigestSize());
		hash.Final(digest);
		size_t representativeByteLength = BitsToBytes(representativeBitLength);
		T mgf;
		mgf.GenerateAndMask(hash, representative, representativeByteLength, digest, digest.size(), false);
		if (representativeBitLength % 8 != 0)
			representative[0] = (byte)Crop(representative[0], representativeBitLength % 8);
	}
};

<<<<<<< HEAD
/// \brief EMSA5 padding method, for use with ESIGN
/// \since Crypto++ 5.0
=======
//! EMSA5, for use with ESIGN
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
struct P1363_EMSA5 : public SignatureStandard
{
	typedef EMSA5Pad<P1363_MGF1> SignatureMessageEncodingMethod;
};

<<<<<<< HEAD
/// \brief ESIGN keys
/// \since Crypto++ 5.0
struct ESIGN_Keys
{
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "ESIGN";}
=======
struct ESIGN_Keys
{
	static std::string StaticAlgorithmName() {return "ESIGN";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	typedef ESIGNFunction PublicKey;
	typedef InvertibleESIGNFunction PrivateKey;
};

<<<<<<< HEAD
/// \brief ESIGN signature scheme, IEEE P1363a
/// \tparam H HashTransformation derived class
/// \tparam STANDARD Signature encoding method
/// \since Crypto++ 5.0
template <class H, class STANDARD = P1363_EMSA5>
struct ESIGN : public TF_SS<ESIGN_Keys, STANDARD, H>
=======
//! ESIGN, as defined in IEEE P1363a
template <class H, class STANDARD = P1363_EMSA5>
struct ESIGN : public TF_SS<STANDARD, H, ESIGN_Keys>
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
{
};

NAMESPACE_END

#endif
