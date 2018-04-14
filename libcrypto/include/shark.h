<<<<<<< HEAD
// shark.h - originally written and placed in the public domain by Wei Dai

/// \file shark.h
/// \brief Classes for the SHARK block cipher
/// \since Crypto++ 2.1
=======
// shark.h - written and placed in the public domain by Wei Dai

//! \file shark.h
//! \brief Classes for the SHARK block cipher
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_SHARK_H
#define CRYPTOPP_SHARK_H

#include "config.h"
#include "seckey.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief SHARK block cipher information
/// \since Crypto++ 2.1
struct SHARK_Info : public FixedBlockSize<8>, public FixedKeyLength<16>, public VariableRounds<6, 2>
{
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "SHARK-E";}
};

/// \brief SHARK block cipher
/// <a href="http://www.cryptopp.com/wiki/SHARK-E">SHARK-E</a>
/// \since Crypto++ 2.1
class SHARK : public SHARK_Info, public BlockCipherDocumentation
{
	/// \brief SHARK block cipher default operation
	/// \since Crypto++ 2.1
=======
//! \class SHARK_Info
//! \brief SHARK block cipher information
struct SHARK_Info : public FixedBlockSize<8>, public FixedKeyLength<16>, public VariableRounds<6, 2>
{
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "SHARK-E";}
};

//! \class SHARK
//! \brief SHARK block cipher
/// <a href="http://www.weidai.com/scan-mirror/cs.html#SHARK-E">SHARK-E</a>
class SHARK : public SHARK_Info, public BlockCipherDocumentation
{
	//! \class Base
	//! \brief SHARK block cipher default operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Base : public BlockCipherImpl<SHARK_Info>
	{
	public:
		void UncheckedSetKey(const byte *key, unsigned int length, const NameValuePairs &param);

	protected:
		unsigned int m_rounds;
		SecBlock<word64> m_roundKeys;
	};

<<<<<<< HEAD
	/// \brief SHARK block cipher encryption operation
	/// \since Crypto++ 2.1
=======
	//! \class Enc
	//! \brief SHARK block cipher encryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;

		// used by Base to do key setup
		void InitForKeySetup();

	private:
		static const byte sbox[256];
		static const word64 cbox[8][256];
	};

<<<<<<< HEAD
	/// \brief SHARK block cipher decryption operation
	/// \since Crypto++ 2.1
=======
	//! \class Dec
	//! \brief SHARK block cipher decryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;

	private:
		static const byte sbox[256];
		static const word64 cbox[8][256];
	};

public:
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
	typedef BlockCipherFinal<DECRYPTION, Dec> Decryption;
};

typedef SHARK::Encryption SHARKEncryption;
typedef SHARK::Decryption SHARKDecryption;

NAMESPACE_END

#endif
