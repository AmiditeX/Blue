<<<<<<< HEAD
// ripemd.h - originally written and placed in the public domain by Wei Dai

/// \file
/// \brief Classes for RIPEMD message digest
=======
// ripemd.h - written and placed in the public domain by Wei Dai

//! \file
//! \brief Classes for RIPEMD message digest
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_RIPEMD_H
#define CRYPTOPP_RIPEMD_H

#include "iterhash.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief RIPEMD-160 message digest
/// \details Digest size is 160-bits.
/// \sa <a href="http://www.weidai.com/scan-mirror/md.html#RIPEMD-160">RIPEMD-160</a>
/// \since Crypto++ 2.1
=======
//! <a href="http://www.weidai.com/scan-mirror/md.html#RIPEMD-160">RIPEMD-160</a>
/*! Digest Length = 160 bits */
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class RIPEMD160 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 20, RIPEMD160>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "RIPEMD-160";}
};

/// \brief RIPEMD-320 message digest
/// \details Digest size is 320-bits.
/// \sa <a href="http://www.weidai.com/scan-mirror/md.html#RIPEMD-320">RIPEMD-320</a>
/// \since Crypto++ 2.1
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "RIPEMD-160";}
};

/*! Digest Length = 320 bits, Security is similar to RIPEMD-160 */
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class RIPEMD320 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 40, RIPEMD320>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "RIPEMD-320";}
};

/// \brief RIPEMD-128 message digest
/// \details Digest size is 128-bits.
/// \warning RIPEMD-128 is considered insecure, and should not be used unless you absolutely need it for compatibility.
/// \sa <a href="http://www.weidai.com/scan-mirror/md.html#RIPEMD-128">RIPEMD-128</a>
/// \since Crypto++ 2.1
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "RIPEMD-320";}
};

/*! \warning RIPEMD-128 is considered insecure, and should not be used
	unless you absolutely need it for compatibility. */
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class RIPEMD128 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 16, RIPEMD128>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "RIPEMD-128";}
};

/// \brief RIPEMD-256 message digest
/// \details Digest size is 256-bits.
/// \warning RIPEMD-256 is considered insecure, and should not be used unless you absolutely need it for compatibility.
/// \sa <a href="http://www.weidai.com/scan-mirror/md.html#RIPEMD-256">RIPEMD-256</a>
/// \since Crypto++ 2.1
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "RIPEMD-128";}
};

/*! \warning RIPEMD-256 is considered insecure, and should not be used
	unless you absolutely need it for compatibility. */
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
class RIPEMD256 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 32, RIPEMD256>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
<<<<<<< HEAD
	CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "RIPEMD-256";}
=======
	CRYPTOPP_CONSTEXPR static const char *StaticAlgorithmName() {return "RIPEMD-256";}
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
};

NAMESPACE_END

#endif
