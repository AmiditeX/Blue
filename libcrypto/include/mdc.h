<<<<<<< HEAD
// mdc.h - originally written and placed in the public domain by Wei Dai

/// \file mdc.h
/// \brief Classes for the MDC message digest
=======
// mdc.h - written and placed in the public domain by Wei Dai
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_MDC_H
#define CRYPTOPP_MDC_H

<<<<<<< HEAD
=======
//! \file mdc.h
//! \brief Classes for the MDC message digest

>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#include "seckey.h"
#include "secblock.h"
#include "misc.h"

<<<<<<< HEAD
// GCC cast warning
#define HashWordPtr(x) ((HashWordType*)(void*)(x))
#define ConstHashWordPtr(x) ((const HashWordType*)(const void*)(x))

NAMESPACE_BEGIN(CryptoPP)

/// \tparam B BlockCipher derived class
/// \brief MDC_Info cipher information
template <class B>
struct MDC_Info : public FixedBlockSize<B::DIGESTSIZE>, public FixedKeyLength<B::BLOCKSIZE>
{
	static std::string StaticAlgorithmName() {return std::string("MDC/")+B::StaticAlgorithmName();}
};

/// \brief MDC cipher
/// \tparam H HashTransformation derived class
/// \details MDC() is a construction by Peter Gutmann to turn an iterated hash function into a PRF
/// \sa <a href="http://www.cryptopp.com/wiki/MDC">MDC</a>
template <class H>
class MDC : public MDC_Info<H>
{
	/// \brief MDC cipher encryption operation
	class CRYPTOPP_NO_VTABLE Enc : public BlockCipherImpl<MDC_Info<H> >
	{
		typedef typename H::HashWordType HashWordType;
=======
NAMESPACE_BEGIN(CryptoPP)

//! \class MDC_Info
//! \brief MDC_Info cipher information
template <class T>
struct MDC_Info : public FixedBlockSize<T::DIGESTSIZE>, public FixedKeyLength<T::BLOCKSIZE>
{
	static std::string StaticAlgorithmName() {return std::string("MDC/")+T::StaticAlgorithmName();}
};


//! \class MDC
//! \brief MDC cipher
//! \details MDC() is a construction by Peter Gutmann to turn an iterated hash function into a PRF
//! \sa <a href="http://www.weidai.com/scan-mirror/cs.html#MDC">MDC</a>
template <class T>
class MDC : public MDC_Info<T>
{
	//! \class Enc
	//! \brief MDC cipher encryption operation
	class CRYPTOPP_NO_VTABLE Enc : public BlockCipherImpl<MDC_Info<T> >
	{
		typedef typename T::HashWordType HashWordType;
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

	public:
		void UncheckedSetKey(const byte *userKey, unsigned int length, const NameValuePairs &params)
		{
<<<<<<< HEAD
			CRYPTOPP_UNUSED(params);
			this->AssertValidKeyLength(length);
			ConditionalByteReverse(BIG_ENDIAN_ORDER, Key(), ConstHashWordPtr(userKey), this->KEYLENGTH);
=======
			this->AssertValidKeyLength(length);
			memcpy_s(m_key, m_key.size(), userKey, this->KEYLENGTH);
			T::CorrectEndianess(Key(), Key(), this->KEYLENGTH);
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
		}

		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const
		{
<<<<<<< HEAD
			ConditionalByteReverse(BIG_ENDIAN_ORDER, Buffer(), ConstHashWordPtr(inBlock), this->BLOCKSIZE);
			H::Transform(Buffer(), Key());

			if (xorBlock)
			{
				ConditionalByteReverse(BIG_ENDIAN_ORDER, Buffer(), Buffer(), this->BLOCKSIZE);
				xorbuf(outBlock, xorBlock, m_buffer, this->BLOCKSIZE);
			}
			else
			{
				ConditionalByteReverse(BIG_ENDIAN_ORDER, HashWordPtr(outBlock), Buffer(), this->BLOCKSIZE);
			}
=======
			T::CorrectEndianess(Buffer(), (HashWordType *)inBlock, this->BLOCKSIZE);
			T::Transform(Buffer(), Key());
			if (xorBlock)
			{
				T::CorrectEndianess(Buffer(), Buffer(), this->BLOCKSIZE);
				xorbuf(outBlock, xorBlock, m_buffer, this->BLOCKSIZE);
			}
			else
				T::CorrectEndianess((HashWordType *)outBlock, Buffer(), this->BLOCKSIZE);
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
		}

		bool IsPermutation() const {return false;}

		unsigned int OptimalDataAlignment() const {return sizeof(HashWordType);}

	private:
<<<<<<< HEAD
		HashWordType *Key() {return HashWordPtr(m_key.data());}
		const HashWordType *Key() const {return ConstHashWordPtr(m_key.data());}
		HashWordType *Buffer() const {return HashWordPtr(m_buffer.data());}

		// VC60 workaround: bug triggered if using FixedSizeAllocatorWithCleanup
		FixedSizeSecBlock<byte, MDC_Info<H>::KEYLENGTH, AllocatorWithCleanup<byte> > m_key;
		mutable FixedSizeSecBlock<byte, MDC_Info<H>::BLOCKSIZE, AllocatorWithCleanup<byte> > m_buffer;
	};

public:
	// use BlockCipher interface
=======
		HashWordType *Key() {return (HashWordType *)m_key.data();}
		const HashWordType *Key() const {return (const HashWordType *)m_key.data();}
		HashWordType *Buffer() const {return (HashWordType *)m_buffer.data();}

		// VC60 workaround: bug triggered if using FixedSizeAllocatorWithCleanup
		FixedSizeSecBlock<byte, MDC_Info<T>::KEYLENGTH, AllocatorWithCleanup<byte> > m_key;
		mutable FixedSizeSecBlock<byte, MDC_Info<T>::BLOCKSIZE, AllocatorWithCleanup<byte> > m_buffer;
	};

public:
	//! use BlockCipher interface
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
};

NAMESPACE_END

#endif
