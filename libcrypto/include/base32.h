// base32.h - written and placed in the public domain by Frank Palazzolo, based on hex.cpp by Wei Dai
<<<<<<< HEAD
//              extended hex alphabet added by JW in November, 2017.

/// \file base32.h
/// \brief Classes for Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
=======

//! \file
//! \brief Classes for Base32Encoder and Base32Decoder
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_BASE32_H
#define CRYPTOPP_BASE32_H

#include "cryptlib.h"
#include "basecode.h"

NAMESPACE_BEGIN(CryptoPP)

<<<<<<< HEAD
/// \brief Base32 encodes data using DUDE encoding
/// \details Converts data to base32 using DUDE encoding. The default code is based on <A HREF="http://www.ietf.org/proceedings/51/I-D/draft-ietf-idn-dude-02.txt">Differential Unicode Domain Encoding (DUDE) (draft-ietf-idn-dude-02.txt)</A>.
/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
class Base32Encoder : public SimpleProxyFilter
{
public:
	/// \brief Construct a Base32Encoder
	/// \param attachment a BufferedTrasformation to attach to this object
	/// \param uppercase a flag indicating uppercase output
	/// \param groupSize the size of the grouping
	/// \param separator the separator to use between groups
	/// \param terminator the terminator appeand after processing
	/// \details Base32Encoder() constructs a default encoder. The constructor lacks fields for padding and
	///   line breaks. You must use IsolatedInitialize() to change the default padding character or suppress it.
	/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
	Base32Encoder(BufferedTransformation *attachment = NULLPTR, bool uppercase = true, int groupSize = 0, const std::string &separator = ":", const std::string &terminator = "")
=======
//! \class Base32Encoder
//! \brief Base32 encodes data
//! \details Converts data to base32. The default code is based on <A HREF="http://www.ietf.org/proceedings/51/I-D/draft-ietf-idn-dude-02.txt">Differential Unicode Domain Encoding (DUDE) (draft-ietf-idn-dude-02.txt)</A>.
class Base32Encoder : public SimpleProxyFilter
{
public:
	//! \brief Construct a Base32Encoder
	//! \param attachment a BufferedTrasformation to attach to this object
	//! \param uppercase a flag indicating uppercase output
	//! \param groupSize the size of the grouping
	//! \param separator the separator to use between groups
	//! \param terminator the terminator appeand after processing
	//! \details Base32Encoder() constructs a default encoder. The constructor lacks fields for padding and
	//!   line breaks. You must use IsolatedInitialize() to change the default padding character or suppress it.
	//! \sa IsolatedInitialize() for an example of modifying a Base32Encoder after construction.
	Base32Encoder(BufferedTransformation *attachment = NULL, bool uppercase = true, int groupSize = 0, const std::string &separator = ":", const std::string &terminator = "")
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
		: SimpleProxyFilter(new BaseN_Encoder(new Grouper), attachment)
	{
		IsolatedInitialize(MakeParameters(Name::Uppercase(), uppercase)(Name::GroupSize(), groupSize)(Name::Separator(), ConstByteArrayParameter(separator))(Name::Terminator(), ConstByteArrayParameter(terminator)));
	}

<<<<<<< HEAD
	/// \brief Initialize or reinitialize this object, without signal propagation
	/// \param parameters a set of NameValuePairs used to initialize this object
	/// \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	///   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	///   transformations. If initialization should be propagated, then use the Initialize() function.
	/// \details The following code modifies the padding and line break parameters for an encoder:
	///   <pre>
	///     Base32Encoder encoder;
	///     AlgorithmParameters params = MakeParameters(Pad(), false)(InsertLineBreaks(), false);
	///     encoder.IsolatedInitialize(params);</pre>
	/// \details You can change the encoding to <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base
	///   32 Encoding with Extended Hex Alphabet</A> by performing the following:
	///   <pre>
	///     Base32Encoder encoder;
	///     const byte ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	///     AlgorithmParameters params = MakeParameters(Name::EncodingLookupArray(),(const byte *)ALPHABET);
	///     encoder.IsolatedInitialize(params);</pre>
	/// \details If you change the encoding alphabet, then you will need to change the decoding alphabet \a and
	///   the decoder's lookup table.
	/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
	void IsolatedInitialize(const NameValuePairs &parameters);
};

/// \brief Base32 decodes data using DUDE encoding
/// \details Converts data from base32 using DUDE encoding. The default code is based on <A HREF="http://www.ietf.org/proceedings/51/I-D/draft-ietf-idn-dude-02.txt">Differential Unicode Domain Encoding (DUDE) (draft-ietf-idn-dude-02.txt)</A>.
/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
class Base32Decoder : public BaseN_Decoder
{
public:
	/// \brief Construct a Base32Decoder
	/// \param attachment a BufferedTrasformation to attach to this object
	/// \sa IsolatedInitialize() for an example of modifying a Base32Decoder after construction.
	Base32Decoder(BufferedTransformation *attachment = NULLPTR)
		: BaseN_Decoder(GetDefaultDecodingLookupArray(), 5, attachment) {}

	/// \brief Initialize or reinitialize this object, without signal propagation
	/// \param parameters a set of NameValuePairs used to initialize this object
	/// \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	///   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	///   transformations. If initialization should be propagated, then use the Initialize() function.
	/// \details You can change the encoding to <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base
	///   32 Encoding with Extended Hex Alphabet</A> by performing the following:
	///   <pre>
	///     int lookup[256];
	///     const byte ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	///     Base32Decoder::InitializeDecodingLookupArray(lookup, ALPHABET, 32, true /*insensitive*/);
	///
	///     Base32Decoder decoder;
	///     AlgorithmParameters params = MakeParameters(Name::DecodingLookupArray(),(const int *)lookup);
	///     decoder.IsolatedInitialize(params);</pre>
	/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
	void IsolatedInitialize(const NameValuePairs &parameters);

private:
	/// \brief Provides the default decoding lookup table
	/// \return default decoding lookup table
	static const int * CRYPTOPP_API GetDefaultDecodingLookupArray();
};

/// \brief Base32 encodes data using extended hex
/// \details Converts data to base32 using extended hex alphabet. The alphabet is different than Base32Encoder.
/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder, <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base 32 Encoding with Extended Hex Alphabet</A>.
/// \since Crypto++ 6.0
class Base32HexEncoder : public SimpleProxyFilter
{
public:
	/// \brief Construct a Base32HexEncoder
	/// \param attachment a BufferedTrasformation to attach to this object
	/// \param uppercase a flag indicating uppercase output
	/// \param groupSize the size of the grouping
	/// \param separator the separator to use between groups
	/// \param terminator the terminator appeand after processing
	/// \details Base32HexEncoder() constructs a default encoder. The constructor lacks fields for padding and
	///   line breaks. You must use IsolatedInitialize() to change the default padding character or suppress it.
	/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
	Base32HexEncoder(BufferedTransformation *attachment = NULLPTR, bool uppercase = true, int groupSize = 0, const std::string &separator = ":", const std::string &terminator = "")
		: SimpleProxyFilter(new BaseN_Encoder(new Grouper), attachment)
	{
		IsolatedInitialize(MakeParameters(Name::Uppercase(), uppercase)(Name::GroupSize(), groupSize)(Name::Separator(), ConstByteArrayParameter(separator))(Name::Terminator(), ConstByteArrayParameter(terminator)));
	}

	/// \brief Initialize or reinitialize this object, without signal propagation
	/// \param parameters a set of NameValuePairs used to initialize this object
	/// \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	///   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	///   transformations. If initialization should be propagated, then use the Initialize() function.
	/// \details The following code modifies the padding and line break parameters for an encoder:
	///   <pre>
	///     Base32HexEncoder encoder;
	///     AlgorithmParameters params = MakeParameters(Pad(), false)(InsertLineBreaks(), false);
	///     encoder.IsolatedInitialize(params);</pre>
	void IsolatedInitialize(const NameValuePairs &parameters);
};

/// \brief Base32 decodes data using extended hex
/// \details Converts data from base32 using extended hex alphabet. The alphabet is different than Base32Decoder.
/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder, <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base 32 Encoding with Extended Hex Alphabet</A>.
/// \since Crypto++ 6.0
class Base32HexDecoder : public BaseN_Decoder
{
public:
	/// \brief Construct a Base32HexDecoder
	/// \param attachment a BufferedTrasformation to attach to this object
	/// \sa Base32Encoder, Base32Decoder, Base32HexEncoder and Base32HexDecoder
	Base32HexDecoder(BufferedTransformation *attachment = NULLPTR)
		: BaseN_Decoder(GetDefaultDecodingLookupArray(), 5, attachment) {}

	/// \brief Initialize or reinitialize this object, without signal propagation
	/// \param parameters a set of NameValuePairs used to initialize this object
	/// \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	///   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	///   transformations. If initialization should be propagated, then use the Initialize() function.
	void IsolatedInitialize(const NameValuePairs &parameters);

private:
	/// \brief Provides the default decoding lookup table
	/// \return default decoding lookup table
=======
	//! \brief Initialize or reinitialize this object, without signal propagation
	//! \param parameters a set of NameValuePairs used to initialize this object
	//! \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	//!   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	//!   transformations. If initialization should be propagated, then use the Initialize() function.
	//! \details The following code modifies the padding and line break parameters for an encoder:
	//!   <pre>
	//!     Base32Encoder encoder;
	//!     AlgorithmParameters params = MakeParameters(Pad(), false)(InsertLineBreaks(), false);
	//!     encoder.IsolatedInitialize(params);</pre>
	//! \details You can change the encoding to <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base
	//!   32 Encoding with Extended Hex Alphabet</A> by performing the following:
	//!   <pre>
	//!     Base32Encoder encoder;
	//!     const byte ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	//!     AlgorithmParameters params = MakeParameters(Name::EncodingLookupArray(),(const byte *)ALPHABET);
	//!     encoder.IsolatedInitialize(params);</pre>
	//! \details If you change the encoding alphabet, then you will need to change the decoding alphabet \a and
	//!   the decoder's lookup table.
	//! \sa Base32Decoder::IsolatedInitialize() for an example of changing a Base32Decoder's lookup table.
	void IsolatedInitialize(const NameValuePairs &parameters);
};

//! \class Base32Decoder
//! \brief Base32 decodes data
//! \details Decode base32 data. The default code is based on <A HREF="http://www.ietf.org/proceedings/51/I-D/draft-ietf-idn-dude-02.txt">Differential Unicode Domain Encoding (DUDE) (draft-ietf-idn-dude-02.txt)</A>.
class Base32Decoder : public BaseN_Decoder
{
public:
	//! \brief Construct a Base32Decoder
	//! \param attachment a BufferedTrasformation to attach to this object
	//! \sa IsolatedInitialize() for an example of modifying a Base32Decoder after construction.
	Base32Decoder(BufferedTransformation *attachment = NULL)
		: BaseN_Decoder(GetDefaultDecodingLookupArray(), 5, attachment) {}

	//! \brief Initialize or reinitialize this object, without signal propagation
	//! \param parameters a set of NameValuePairs used to initialize this object
	//! \details IsolatedInitialize() is used to initialize or reinitialize an object using a variable
	//!   number of arbitrarily typed arguments. IsolatedInitialize() does not call Initialize() on attached
	//!   transformations. If initialization should be propagated, then use the Initialize() function.
	//! \details You can change the encoding to <A HREF="http://tools.ietf.org/html/rfc4648#page-10">RFC 4648, Base
	//!   32 Encoding with Extended Hex Alphabet</A> by performing the following:
	//!   <pre>
	//!     int lookup[256];
	//!     const byte ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	//!     Base32Decoder::InitializeDecodingLookupArray(lookup, ALPHABET, 32, true /*insensitive*/);
	//!
	//!     Base32Decoder decoder;
	//!     AlgorithmParameters params = MakeParameters(Name::DecodingLookupArray(),(const int *)lookup);
	//!     decoder.IsolatedInitialize(params);</pre>
	//! \sa Base32Encoder::IsolatedInitialize() for an example of changing a Base32Encoder's alphabet.
	void IsolatedInitialize(const NameValuePairs &parameters);

private:
	//! \brief Provides the default decoding lookup table
	//! \return default decoding lookup table
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	static const int * CRYPTOPP_API GetDefaultDecodingLookupArray();
};

NAMESPACE_END

#endif
