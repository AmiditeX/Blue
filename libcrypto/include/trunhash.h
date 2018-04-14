#ifndef CRYPTOPP_TRUNHASH_H
#define CRYPTOPP_TRUNHASH_H

#include "cryptlib.h"

NAMESPACE_BEGIN(CryptoPP)

class NullHash : public HashTransformation
{
public:
	void Update(const byte *input, size_t length)
		{CRYPTOPP_UNUSED(input);CRYPTOPP_UNUSED(length);}
	unsigned int DigestSize() const
		{return 0;}
	void TruncatedFinal(byte *digest, size_t digestSize)
		{CRYPTOPP_UNUSED(digest);CRYPTOPP_UNUSED(digestSize);}
	bool TruncatedVerify(const byte *digest, size_t digestLength)
		{CRYPTOPP_UNUSED(digest);CRYPTOPP_UNUSED(digestLength);return true;}
};

<<<<<<< HEAD
/// construct new HashModule with smaller DigestSize() from existing one
=======
//! construct new HashModule with smaller DigestSize() from existing one
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
template <class T>
class TruncatedHashTemplate : public HashTransformation
{
public:
	TruncatedHashTemplate(T hm, unsigned int digestSize)
		: m_hm(hm), m_digestSize(digestSize) {}
	TruncatedHashTemplate(const byte *key, size_t keyLength, unsigned int digestSize)
		: m_hm(key, keyLength), m_digestSize(digestSize) {}
	TruncatedHashTemplate(size_t digestSize)
		: m_digestSize(digestSize) {}

	void Restart()
		{m_hm.Restart();}
	void Update(const byte *input, size_t length)
		{m_hm.Update(input, length);}
	unsigned int DigestSize() const {return m_digestSize;}
	void TruncatedFinal(byte *digest, size_t digestSize)
		{m_hm.TruncatedFinal(digest, digestSize);}
	bool TruncatedVerify(const byte *digest, size_t digestLength)
		{return m_hm.TruncatedVerify(digest, digestLength);}

private:
	T m_hm;
	unsigned int m_digestSize;
};

typedef TruncatedHashTemplate<HashTransformation &> TruncatedHashModule;

NAMESPACE_END

#endif
