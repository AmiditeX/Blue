<<<<<<< HEAD
// skipjack.h - originally written and placed in the public domain by Wei Dai

/// \file skipjack.h
/// \brief Classes for the SKIPJACK block cipher
=======
// skipjack.h - written and placed in the public domain by Wei Dai

//! \file skipjack.h
//! \brief Classes for the SKIPJACK block cipher
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_SKIPJACK_H
#define CRYPTOPP_SKIPJACK_H

#include "seckey.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief SKIPJACK block cipher information
=======
//! \class SKIPJACK_Info
//! \brief SKIPJACK block cipher information
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
struct SKIPJACK_Info : public FixedBlockSize<8>, public FixedKeyLength<10>
{
	CRYPTOPP_DLL static const char * CRYPTOPP_API StaticAlgorithmName() {return "SKIPJACK";}
};

<<<<<<< HEAD
/// \brief SKIPJACK block cipher
/// \sa <a href="http://www.cryptopp.com/wiki/SKIPJACK">SKIPJACK</a>
class SKIPJACK : public SKIPJACK_Info, public BlockCipherDocumentation
{
	/// \brief SKIPJACK block cipher default operation
=======
//! \class SKIPJACK
//! \brief SKIPJACK block cipher
//! \sa <a href="http://www.weidai.com/scan-mirror/cs.html#SKIPJACK">SKIPJACK</a>
class SKIPJACK : public SKIPJACK_Info, public BlockCipherDocumentation
{
	//! \class Base
	//! \brief SKIPJACK block cipher default operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_DLL CRYPTOPP_NO_VTABLE Base : public BlockCipherImpl<SKIPJACK_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params);
		unsigned int OptimalDataAlignment() const {return GetAlignmentOf<word16>();}

	protected:
		static const byte fTable[256];

		FixedSizeSecBlock<byte, 10*256> tab;
	};

<<<<<<< HEAD
	/// \brief SKIPJACK block cipher encryption operation
=======
	//! \class Enc
	//! \brief SKIPJACK block cipher encryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_DLL CRYPTOPP_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	private:
		static const byte Se[256];
		static const word32 Te[4][256];
	};

<<<<<<< HEAD
	/// \brief SKIPJACK block cipher decryption operation
=======
	//! \class Dec
	//! \brief SKIPJACK block cipher decryption operation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	class CRYPTOPP_DLL CRYPTOPP_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
	private:
		static const byte Sd[256];
		static const word32 Td[4][256];
	};

public:
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
	typedef BlockCipherFinal<DECRYPTION, Dec> Decryption;
};

typedef SKIPJACK::Encryption SKIPJACKEncryption;
typedef SKIPJACK::Decryption SKIPJACKDecryption;

NAMESPACE_END

#endif
