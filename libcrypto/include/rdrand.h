// rdrand.h - written and placed in public domain by Jeffrey Walton and Uri Blumenthal.
<<<<<<< HEAD

/// \file rdrand.h
/// \brief Classes for RDRAND and RDSEED
/// \since Crypto++ 5.6.3
=======
//            Copyright assigned to Crypto++ project.

//! \file rdrand.h
//! \brief Classes for RDRAND and RDSEED
//! \since Crypto++ 5.6.3
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_RDRAND_H
#define CRYPTOPP_RDRAND_H

#include "cryptlib.h"

<<<<<<< HEAD
// This class file provides both RDRAND and RDSEED. They were added at
//   Crypto++ 5.6.3. At compile time, it uses CRYPTOPP_BOOL_{X86|X32|X64}
//   to select an implementation or "throw NotImplemented". At runtime the
//   constructor will throw RDRAND_Err or RDSEED_Err if a generator is
//   is not available.
// The original classes accepted a retry count. Retries were superflous for
//   RDRAND, and RDSEED encountered a failure about 1 in 256 bytes depending
//   on the processor. Retries were removed at Crypto++ 6.0 because
//   GenerateBlock unconditionally retries and always fulfills the request.

// Throughput varies wildly depending on processor and manufacturer. A Core i5 or
//   Core i7 RDRAND can generate at over 200 MiB/s. Its below the theroetical
//    maximum, but it takes about 5 instructions to generate, retry and store a
//   result. A low-end Celeron may perform RDRAND at about 7 MiB/s. RDSEED
//   performs at about 1/4 to 1/2 the rate of RDRAND. AMD RDRAND performed poorly
//   during testing with Athlon X4 845. The Bulldozer v4 only performed at 1 MiB/s.

// Microsoft added RDRAND in August 2012, VS2012; RDSEED in October 2013, VS2013.
// GCC added RDRAND in December 2010, GCC 4.6. LLVM added RDRAND in July 2012,
// Clang 3.2. Intel added RDRAND in September 2011, ICC 12.1.

NAMESPACE_BEGIN(CryptoPP)

/// \brief Exception thrown when a RDRAND generator encounters
///    a generator related error.
/// \since Crypto++ 5.6.3
class RDRAND_Err : public Exception
{
public:
    RDRAND_Err(const std::string &operation)
        : Exception(OTHER_ERROR, "RDRAND: " + operation + " operation failed") {}
};

/// \brief Hardware generated random numbers using RDRAND instruction
/// \sa MaurerRandomnessTest() for random bit generators
/// \since Crypto++ 5.6.3
class RDRAND : public RandomNumberGenerator
{
public:
    CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() { return "RDRAND"; }

    virtual ~RDRAND() {}

    /// \brief Construct a RDRAND generator
    /// \details According to DJ of Intel, the Intel RDRAND circuit does not underflow.
    ///   If it did hypothetically underflow, then it would return 0 for the random value.
    ///   AMD's RDRAND implementation appears to provide the same behavior.
     /// \throws RDRAND_Err if the random number generator is not available
    RDRAND();

    /// \brief Generate random array of bytes
    /// \param output the byte buffer
    /// \param size the length of the buffer, in bytes
    virtual void GenerateBlock(byte *output, size_t size);

    /// \brief Generate and discard n bytes
    /// \param n the number of bytes to generate and discard
    /// \details the RDSEED generator discards words, not bytes. If n is
    ///   not a multiple of a machine word, then it is rounded up to
    ///   that size.
    virtual void DiscardBytes(size_t n);

    /// \brief Update RNG state with additional unpredictable values
    /// \param input unused
    /// \param length unused
    /// \details The operation is a nop for this generator.
    virtual void IncorporateEntropy(const byte *input, size_t length)
    {
        // Override to avoid the base class' throw.
        CRYPTOPP_UNUSED(input); CRYPTOPP_UNUSED(length);
    }
};

/// \brief Exception thrown when a RDSEED generator encounters
///    a generator related error.
/// \since Crypto++ 5.6.3
class RDSEED_Err : public Exception
{
public:
    RDSEED_Err(const std::string &operation)
        : Exception(OTHER_ERROR, "RDSEED: " + operation + " operation failed") {}
};

/// \brief Hardware generated random numbers using RDSEED instruction
/// \sa MaurerRandomnessTest() for random bit generators
/// \since Crypto++ 5.6.3
class RDSEED : public RandomNumberGenerator
{
public:
    CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() { return "RDSEED"; }

    virtual ~RDSEED() {}

    /// \brief Construct a RDSEED generator
    /// \details Empirical testing under a 6th generaton i7 (6200U) shows RDSEED fails
    ///   to fulfill requests at about once every for every 256 bytes requested.
    ///   The generator runs about 4 times slower than RDRAND.
     /// \throws RDSEED_Err if the random number generator is not available
    RDSEED();

    /// \brief Generate random array of bytes
    /// \param output the byte buffer
    /// \param size the length of the buffer, in bytes
    virtual void GenerateBlock(byte *output, size_t size);

    /// \brief Generate and discard n bytes
    /// \param n the number of bytes to generate and discard
    /// \details the RDSEED generator discards words, not bytes. If n is
    ///   not a multiple of a machine word, then it is rounded up to
    ///   that size.
    virtual void DiscardBytes(size_t n);

    /// \brief Update RNG state with additional unpredictable values
    /// \param input unused
    /// \param length unused
    /// \details The operation is a nop for this generator.
    virtual void IncorporateEntropy(const byte *input, size_t length)
    {
        // Override to avoid the base class' throw.
        CRYPTOPP_UNUSED(input); CRYPTOPP_UNUSED(length);
    }
=======
// This file (and friends) provides both RDRAND and RDSEED, but its somewhat
//   experimental. They were added at Crypto++ 5.6.3. At compile time, it
//   indirectly uses CRYPTOPP_BOOL_{X86|X32|X64} (via CRYPTOPP_CPUID_AVAILABLE)
//   to select an implementation or "throw NotImplemented". At runtime, the
//   class uses the result of CPUID to determine if RDRAND or RDSEED are
//   available. If not available, a lazy throw strategy is used. I.e., the
//   throw is deferred until GenerateBlock() is called.

// Microsoft added RDRAND in August 2012, VS2012. GCC added RDRAND in December 2010, GCC 4.6.
// Clang added RDRAND in July 2012, Clang 3.2. Intel added RDRAND in September 2011, ICC 12.1.

NAMESPACE_BEGIN(CryptoPP)

//! \brief Exception thrown when a RDRAND generator encounters
//!    a generator related error.
//! \since Crypto++ 5.6.3
class RDRAND_Err : public Exception
{
public:
	RDRAND_Err(const std::string &operation)
		: Exception(OTHER_ERROR, "RDRAND: " + operation + " operation failed") {}
};

//! \brief Hardware generated random numbers using RDRAND instruction
//! \sa MaurerRandomnessTest() for random bit generators
//! \since Crypto++ 5.6.3
class RDRAND : public RandomNumberGenerator
{
public:
	std::string AlgorithmName() const {return "RDRAND";}

	//! \brief Construct a RDRAND generator
	//! \param retries the number of retries for failed calls to the hardware
	//! \details RDRAND() constructs a generator with a maximum number of retires
	//!   for failed generation attempts.
	//! \details According to DJ of Intel, the Intel RDRAND circuit does not underflow.
	//!   If it did hypothetically underflow, then it would return 0 for the random value.
	//!   Its not clear what AMD's behavior will be, and what the returned value will be if
	//!   underflow occurs.
	//!   Also see <A HREF="https://lists.randombit.net/pipermail/cryptography/2016-June/007702.html">RDRAND
	//!   not really random with Oracle Studio 12.3 + patches</A>
	RDRAND(unsigned int retries = 4) : m_retries(retries) {}

	virtual ~RDRAND() {}

	//! \brief Retrieve the number of retries used by the generator
	//! \returns the number of times GenerateBlock() will attempt to recover from a failed generation
	unsigned int GetRetries() const
	{
		return m_retries;
	}

	//! \brief Set the number of retries used by the generator
	//! \param retries number of times GenerateBlock() will attempt to recover from a failed generation
	void SetRetries(unsigned int retries)
	{
		m_retries = retries;
	}

	//! \brief Generate random array of bytes
	//! \param output the byte buffer
	//! \param size the length of the buffer, in bytes
#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64)
	virtual void GenerateBlock(byte *output, size_t size);
#else
	virtual void GenerateBlock(byte *output, size_t size) {
		CRYPTOPP_UNUSED(output), CRYPTOPP_UNUSED(size);
		throw NotImplemented("RDRAND: rdrand is not available on this platform");
	}
#endif

	//! \brief Generate and discard n bytes
	//! \param n the number of bytes to generate and discard
	//! \details the RDSEED generator discards words, not bytes. If n is
	//!   not a multiple of a machine word, then it is rounded up to
	//!   that size.
#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64)
	virtual void DiscardBytes(size_t n);
#else
	virtual void DiscardBytes(size_t n) {
		CRYPTOPP_UNUSED(n);
		throw NotImplemented("RDRAND: rdrand is not available on this platform");
	}
#endif

	//! \brief Update RNG state with additional unpredictable values
	//! \param input unused
	//! \param length unused
	//! \details The operation is a nop for this generator.
	virtual void IncorporateEntropy(const byte *input, size_t length)
	{
		// Override to avoid the base class' throw.
		CRYPTOPP_UNUSED(input); CRYPTOPP_UNUSED(length);
		// CRYPTOPP_ASSERT(0); // warn in debug builds
	}

private:
	unsigned int m_retries;
};

//! \brief Exception thrown when a RDSEED generator encounters
//!    a generator related error.
//! \since Crypto++ 5.6.3
class RDSEED_Err : public Exception
{
public:
	RDSEED_Err(const std::string &operation)
		: Exception(OTHER_ERROR, "RDSEED: " + operation + " operation failed") {}
};

//! \brief Hardware generated random numbers using RDSEED instruction
//! \sa MaurerRandomnessTest() for random bit generators
//! \since Crypto++ 5.6.3
class RDSEED : public RandomNumberGenerator
{
public:
	std::string AlgorithmName() const {return "RDSEED";}

	//! \brief Construct a RDSEED generator
	//! \param retries the number of retries for failed calls to the hardware
	//! \details RDSEED() constructs a generator with a maximum number of retires
	//!   for failed generation attempts.
	//! \details Empirical testing under a 6th generaton i7 (6200U) shows RDSEED fails
	//!   to fulfill requests at about 6 to 8 times the rate of RDRAND. The default
	//!   retries reflects the difference.
	RDSEED(unsigned int retries = 64) : m_retries(retries) {}

	virtual ~RDSEED() {}

	//! \brief Retrieve the number of retries used by the generator
	//! \returns the number of times GenerateBlock() will attempt to recover from a failed generation
	unsigned int GetRetries() const
	{
		return m_retries;
	}

	//! \brief Set the number of retries used by the generator
	//! \param retries number of times GenerateBlock() will attempt to recover from a failed generation
	void SetRetries(unsigned int retries)
	{
		m_retries = retries;
	}

	//! \brief Generate random array of bytes
	//! \param output the byte buffer
	//! \param size the length of the buffer, in bytes
#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64)
	virtual void GenerateBlock(byte *output, size_t size);
#else
	virtual void GenerateBlock(byte *output, size_t size) {
		CRYPTOPP_UNUSED(output), CRYPTOPP_UNUSED(size);
		throw NotImplemented("RDSEED: rdseed is not available on this platform");
	}
#endif

	//! \brief Generate and discard n bytes
	//! \param n the number of bytes to generate and discard
	//! \details the RDSEED generator discards words, not bytes. If n is
	//!   not a multiple of a machine word, then it is rounded up to
	//!   that size.
#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64)
	virtual void DiscardBytes(size_t n);
#else
	virtual void DiscardBytes(size_t n) {
		CRYPTOPP_UNUSED(n);
		throw NotImplemented("RDSEED: rdseed is not available on this platform");
	}
#endif

	//! \brief Update RNG state with additional unpredictable values
	//! \param input unused
	//! \param length unused
	//! \details The operation is a nop for this generator.
	virtual void IncorporateEntropy(const byte *input, size_t length)
	{
		// Override to avoid the base class' throw.
		CRYPTOPP_UNUSED(input); CRYPTOPP_UNUSED(length);
		// CRYPTOPP_ASSERT(0); // warn in debug builds
	}

private:
	unsigned int m_retries;
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
};

NAMESPACE_END

#endif // CRYPTOPP_RDRAND_H
