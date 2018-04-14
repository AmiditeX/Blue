<<<<<<< HEAD
// rc2.h - originally written and placed in the public domain by Wei Dai

/// \file rc2.h
/// \brief Classes for the RC2 block cipher
/// \since Crypto++ 3.0
=======
// rc2.h - written and placed in the public domain by Wei Dai

//! \file rc2.h
//! \brief Classes for the RC2 block cipher
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_RC2_H
#define CRYPTOPP_RC2_H

#include "seckey.h"
#include "secblock.h"
#include "algparam.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief RC2 block cipher information
/// \since Crypto++ 3.0
=======
//! \class RC2_Info
//! \brief RC2 block cipher information
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
struct RC2_Info : public FixedBlockSize<8>, public VariableKeyLength<16, 1, 128>
{
	CRYPTOPP_CONSTANT(DEFAULT_EFFECTIVE_KEYLENGTH = 1024)
	CRYPTOPP_CONSTANT(MAX_EFFECTIVE_KEYLENGTH = 1024)
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "RC2";}
};

/// \brief RC2 block cipher
/// \sa <a href="http://www.cryptopp.com/wiki/RC2">RC2</a> on the Crypto Lounge.
/// \since Crypto++ 3.0
class RC2 : public RC2_Info, public BlockCipherDocumentation
{
	/// \brief Class specific methods used to operate the cipher.
	/// \details Implementations and overrides in \p Base apply to both \p ENCRYPTION and \p DECRYPTION directions
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "RC2";}
};

//! \class RC2
//! \brief RC2 block cipher
//! \sa <a href="http://www.weidai.com/scan-mirror/cs.html#RC2">RC2</a> on the Crypto Lounge.
class RC2 : public RC2_Info, public BlockCipherDocumentation
{
	//! \class Base
	//! \brief Class specific methods used to operate the cipher.
	//! \details Implementations and overrides in \p Base apply to both \p ENCRYPTION and \p DECRYPTION directions
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Base : public BlockCipherImpl<RC2_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params);
		unsigned int OptimalDataAlignment() const {return GetAlignmentOf<word16>();}

	protected:
		FixedSizeSecBlock<word16, 64> K;  // expanded key table
	};

<<<<<<< HEAD
	/// \brief Class specific methods used to operate the cipher in the forward direction.
	/// \details Implementations and overrides in \p Enc apply to \p ENCRYPTION.
=======
	//! \class Enc
	//! \brief Class specific methods used to operate the cipher in the forward direction.
	//! \details Implementations and overrides in \p Enc apply to \p ENCRYPTION.
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

<<<<<<< HEAD
	/// \brief Class specific methods used to operate the cipher in the reverse direction.
	/// \details Implementations and overrides in \p Dec apply to \p DECRYPTION.
=======
	//! \class Dec
	//! \brief Class specific methods used to operate the cipher in the reverse direction.
	//! \details Implementations and overrides in \p Dec apply to \p DECRYPTION.
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

public:

<<<<<<< HEAD
	/// \brief Class specific methods used to operate the cipher in the forward direction.
	/// \details Implementations and overrides in \p Encryption apply to \p ENCRYPTION.
=======
	//! \class Encryption
	//! \brief Class specific methods used to operate the cipher in the forward direction.
	//! \details Implementations and overrides in \p Encryption apply to \p ENCRYPTION.
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class Encryption : public BlockCipherFinal<ENCRYPTION, Enc>
	{
	public:
		Encryption() {}
		Encryption(const byte *key, size_t keyLen=DEFAULT_KEYLENGTH)
			{SetKey(key, keyLen);}
		Encryption(const byte *key, size_t keyLen, int effectiveKeyLen)
			{SetKey(key, keyLen, MakeParameters("EffectiveKeyLength", effectiveKeyLen));}
	};

<<<<<<< HEAD
	/// \brief Class specific methods used to operate the cipher in the reverse direction.
	/// \details Implementations and overrides in \p Decryption apply to \p DECRYPTION.
=======
	//! \class Decryption
	//! \brief Class specific methods used to operate the cipher in the reverse direction.
	//! \details Implementations and overrides in \p Decryption apply to \p DECRYPTION.
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class Decryption : public BlockCipherFinal<DECRYPTION, Dec>
	{
	public:
		Decryption() {}
		Decryption(const byte *key, size_t keyLen=DEFAULT_KEYLENGTH)
			{SetKey(key, keyLen);}
		Decryption(const byte *key, size_t keyLen, int effectiveKeyLen)
			{SetKey(key, keyLen, MakeParameters("EffectiveKeyLength", effectiveKeyLen));}
	};
};

typedef RC2::Encryption RC2Encryption;
typedef RC2::Decryption RC2Decryption;

NAMESPACE_END

#endif

