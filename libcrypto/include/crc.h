<<<<<<< HEAD
// crc.h - originally written and placed in the public domain by Wei Dai

/// \file crc.h
/// \brief Classes for CRC-32 and CRC-32C checksum algorithm
=======
// crc.h - written and placed in the public domain by Wei Dai

//! \file
//! \headerfile crc.h
//! \brief Classes for CRC-32 and CRC-32C checksum algorithm
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_CRC32_H
#define CRYPTOPP_CRC32_H

#include "cryptlib.h"

NAMESPACE_BEGIN(CryptoPP)

const word32 CRC32_NEGL = 0xffffffffL;

<<<<<<< HEAD
#ifdef CRYPTOPP_LITTLE_ENDIAN
=======
#ifdef IS_LITTLE_ENDIAN
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#define CRC32_INDEX(c) (c & 0xff)
#define CRC32_SHIFTED(c) (c >> 8)
#else
#define CRC32_INDEX(c) (c >> 24)
#define CRC32_SHIFTED(c) (c << 8)
#endif

<<<<<<< HEAD
/// \brief CRC-32 Checksum Calculation
/// \details Uses CRC polynomial 0xEDB88320
=======
//! \brief CRC-32 Checksum Calculation
//! \details Uses CRC polynomial 0xEDB88320
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class CRC32 : public HashTransformation
{
public:
	CRYPTOPP_CONSTANT(DIGESTSIZE = 4)
	CRC32();
	void Update(const byte *input, size_t length);
	void TruncatedFinal(byte *hash, size_t size);
	unsigned int DigestSize() const {return DIGESTSIZE;}
<<<<<<< HEAD
    CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "CRC32";}
=======
    CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "CRC32";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
    std::string AlgorithmName() const {return StaticAlgorithmName();}

	void UpdateByte(byte b) {m_crc = m_tab[CRC32_INDEX(m_crc) ^ b] ^ CRC32_SHIFTED(m_crc);}
	byte GetCrcByte(size_t i) const {return ((byte *)&(m_crc))[i];}

protected:
	void Reset() {m_crc = CRC32_NEGL;}

private:
	static const word32 m_tab[256];
	word32 m_crc;
};

<<<<<<< HEAD
/// \brief CRC-32C Checksum Calculation
/// \details Uses CRC polynomial 0x82F63B78
/// \since Crypto++ 5.6.4
=======
//! \brief CRC-32C Checksum Calculation
//! \details Uses CRC polynomial 0x82F63B78
//! \since Crypto++ 5.6.4
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class CRC32C : public HashTransformation
{
public:
	CRYPTOPP_CONSTANT(DIGESTSIZE = 4)
	CRC32C();
	void Update(const byte *input, size_t length);
	void TruncatedFinal(byte *hash, size_t size);
	unsigned int DigestSize() const {return DIGESTSIZE;}
<<<<<<< HEAD
    CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "CRC32C";}
=======
    CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "CRC32C";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
    std::string AlgorithmName() const {return StaticAlgorithmName();}

	void UpdateByte(byte b) {m_crc = m_tab[CRC32_INDEX(m_crc) ^ b] ^ CRC32_SHIFTED(m_crc);}
	byte GetCrcByte(size_t i) const {return ((byte *)&(m_crc))[i];}

protected:
	void Reset() {m_crc = CRC32_NEGL;}

private:
	static const word32 m_tab[256];
	word32 m_crc;
};

NAMESPACE_END

#endif
