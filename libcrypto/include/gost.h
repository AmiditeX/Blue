<<<<<<< HEAD
// gost.h - originally written and placed in the public domain by Wei Dai

/// \file gost.h
/// \brief Classes for the GIST block cipher
=======
// gost.h - written and placed in the public domain by Wei Dai

//! \file gost.h
//! \brief Classes for the GIST block cipher
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_GOST_H
#define CRYPTOPP_GOST_H

#include "seckey.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief GOST block cipher information
/// \since Crypto++ 2.1
struct GOST_Info : public FixedBlockSize<8>, public FixedKeyLength<32>
{
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "GOST";}
};

/// \brief GOST block cipher
/// \sa <a href="http://www.cryptopp.com/wiki/GOST">GOST</a>
/// \since Crypto++ 2.1
class GOST : public GOST_Info, public BlockCipherDocumentation
{
	/// \brief GOST block cipher default operation
=======
//! \class GOST_Info
//! \brief GOST block cipher information
struct GOST_Info : public FixedBlockSize<8>, public FixedKeyLength<32>
{
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "GOST";}
};

//! \class GOST
//! \brief GOST block cipher
//! \sa <a href="http://www.weidai.com/scan-mirror/cs.html#GOST">GOST</a>
class GOST : public GOST_Info, public BlockCipherDocumentation
{
	//! \class Base
	//! \brief GOST block cipher default operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Base : public BlockCipherImpl<GOST_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params);

	protected:
		static void PrecalculateSTable();

		static const byte sBox[8][16];
		static volatile bool sTableCalculated;
		static word32 sTable[4][256];

		FixedSizeSecBlock<word32, 8> m_key;
	};

<<<<<<< HEAD
	/// \brief GOST block cipher encryption operation
=======
	//! \class Enc
	//! \brief GOST block cipher encryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

<<<<<<< HEAD
	/// \brief GOST block cipher decryption operation
=======
	//! \class Dec
	//! \brief GOST block cipher decryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	};

public:
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
	typedef BlockCipherFinal<DECRYPTION, Dec> Decryption;
};

typedef GOST::Encryption GOSTEncryption;
typedef GOST::Decryption GOSTDecryption;

NAMESPACE_END

#endif
