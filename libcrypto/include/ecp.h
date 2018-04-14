<<<<<<< HEAD
// ecp.h - originally written and placed in the public domain by Wei Dai

/// \file ecp.h
/// \brief Classes for Elliptic Curves over prime fields
=======
// ecp.h - written and placed in the public domain by Wei Dai

//! \file ecp.h
//! \brief Classes for Elliptic Curves over prime fields
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56

#ifndef CRYPTOPP_ECP_H
#define CRYPTOPP_ECP_H

#include "cryptlib.h"
#include "integer.h"
#include "algebra.h"
#include "modarith.h"
<<<<<<< HEAD
#include "ecpoint.h"
=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#include "eprecomp.h"
#include "smartptr.h"
#include "pubkey.h"

<<<<<<< HEAD
#if CRYPTOPP_MSC_VERSION
# pragma warning(push)
# pragma warning(disable: 4231 4275)
#endif

NAMESPACE_BEGIN(CryptoPP)

/// \brief Elliptic Curve over GF(p), where p is prime
class CRYPTOPP_DLL ECP : public AbstractGroup<ECPPoint>, public EncodedPoint<ECPPoint>
=======
NAMESPACE_BEGIN(CryptoPP)

//! Elliptical Curve Point
struct CRYPTOPP_DLL ECPPoint
{
	ECPPoint() : identity(true) {}
	ECPPoint(const Integer &x, const Integer &y)
		: identity(false), x(x), y(y) {}

	bool operator==(const ECPPoint &t) const
		{return (identity && t.identity) || (!identity && !t.identity && x==t.x && y==t.y);}
	bool operator< (const ECPPoint &t) const
		{return identity ? !t.identity : (!t.identity && (x<t.x || (x==t.x && y<t.y)));}

#ifndef CRYPTOPP_MAINTAIN_BACKWARDS_COMPATIBILITY_562
	virtual ~ECPPoint() {}
#endif

	bool identity;
	Integer x, y;
};

CRYPTOPP_DLL_TEMPLATE_CLASS AbstractGroup<ECPPoint>;

//! Elliptic Curve over GF(p), where p is prime
class CRYPTOPP_DLL ECP : public AbstractGroup<ECPPoint>
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
{
public:
	typedef ModularArithmetic Field;
	typedef Integer FieldElement;
	typedef ECPPoint Point;

<<<<<<< HEAD
	virtual ~ECP() {}

	/// \brief Construct an ECP
	ECP() {}

	/// \brief Copy construct an ECP
	/// \param ecp the other ECP object
	/// \param convertToMontgomeryRepresentation flag indicating if the curve should be converted to a MontgomeryRepresentation
	/// \sa ModularArithmetic, MontgomeryRepresentation
	ECP(const ECP &ecp, bool convertToMontgomeryRepresentation = false);

	/// \brief Construct an ECP
	/// \param modulus the prime modulus
	/// \param a Field::Element
	/// \param b Field::Element
	ECP(const Integer &modulus, const FieldElement &a, const FieldElement &b)
		: m_fieldPtr(new Field(modulus)), m_a(a.IsNegative() ? modulus+a : a), m_b(b) {}

	/// \brief Construct an ECP from BER encoded parameters
	/// \param bt BufferedTransformation derived object
	/// \details This constructor will decode and extract the the fields fieldID and curve of the sequence ECParameters
	ECP(BufferedTransformation &bt);

	/// \brief Encode the fields fieldID and curve of the sequence ECParameters
	/// \param bt BufferedTransformation derived object
=======
	ECP() {}
	ECP(const ECP &ecp, bool convertToMontgomeryRepresentation = false);
	ECP(const Integer &modulus, const FieldElement &a, const FieldElement &b)
		: m_fieldPtr(new Field(modulus)), m_a(a.IsNegative() ? modulus+a : a), m_b(b) {}
	// construct from BER encoded parameters
	// this constructor will decode and extract the the fields fieldID and curve of the sequence ECParameters
	ECP(BufferedTransformation &bt);

	// encode the fields fieldID and curve of the sequence ECParameters
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	void DEREncode(BufferedTransformation &bt) const;

	bool Equal(const Point &P, const Point &Q) const;
	const Point& Identity() const;
	const Point& Inverse(const Point &P) const;
	bool InversionIsFast() const {return true;}
	const Point& Add(const Point &P, const Point &Q) const;
	const Point& Double(const Point &P) const;
	Point ScalarMultiply(const Point &P, const Integer &k) const;
	Point CascadeScalarMultiply(const Point &P, const Integer &k1, const Point &Q, const Integer &k2) const;
	void SimultaneousMultiply(Point *results, const Point &base, const Integer *exponents, unsigned int exponentsCount) const;

	Point Multiply(const Integer &k, const Point &P) const
		{return ScalarMultiply(P, k);}
	Point CascadeMultiply(const Integer &k1, const Point &P, const Integer &k2, const Point &Q) const
		{return CascadeScalarMultiply(P, k1, Q, k2);}

	bool ValidateParameters(RandomNumberGenerator &rng, unsigned int level=3) const;
	bool VerifyPoint(const Point &P) const;

	unsigned int EncodedPointSize(bool compressed = false) const
		{return 1 + (compressed?1:2)*GetField().MaxElementByteLength();}
	// returns false if point is compressed and not valid (doesn't check if uncompressed)
	bool DecodePoint(Point &P, BufferedTransformation &bt, size_t len) const;
	bool DecodePoint(Point &P, const byte *encodedPoint, size_t len) const;
	void EncodePoint(byte *encodedPoint, const Point &P, bool compressed) const;
	void EncodePoint(BufferedTransformation &bt, const Point &P, bool compressed) const;

	Point BERDecodePoint(BufferedTransformation &bt) const;
	void DEREncodePoint(BufferedTransformation &bt, const Point &P, bool compressed) const;

	Integer FieldSize() const {return GetField().GetModulus();}
	const Field & GetField() const {return *m_fieldPtr;}
	const FieldElement & GetA() const {return m_a;}
	const FieldElement & GetB() const {return m_b;}

	bool operator==(const ECP &rhs) const
		{return GetField() == rhs.GetField() && m_a == rhs.m_a && m_b == rhs.m_b;}

<<<<<<< HEAD
=======
#ifndef CRYPTOPP_MAINTAIN_BACKWARDS_COMPATIBILITY_562
	virtual ~ECP() {}
#endif

>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
private:
	clonable_ptr<Field> m_fieldPtr;
	FieldElement m_a, m_b;
	mutable Point m_R;
};

CRYPTOPP_DLL_TEMPLATE_CLASS DL_FixedBasePrecomputationImpl<ECP::Point>;
CRYPTOPP_DLL_TEMPLATE_CLASS DL_GroupPrecomputation<ECP::Point>;

<<<<<<< HEAD
/// \brief Elliptic Curve precomputation
/// \tparam EC elliptic curve field
template <class EC> class EcPrecomputation;

/// \brief ECP precomputation specialization
/// \details Implementation of <tt>DL_GroupPrecomputation<ECP::Point></tt> with input and output
///   conversions for Montgomery modular multiplication.
/// \sa DL_GroupPrecomputation, ModularArithmetic, MontgomeryRepresentation
=======
template <class T> class EcPrecomputation;

//! ECP precomputation
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
template<> class EcPrecomputation<ECP> : public DL_GroupPrecomputation<ECP::Point>
{
public:
	typedef ECP EllipticCurve;

<<<<<<< HEAD
	virtual ~EcPrecomputation() {}

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	// DL_GroupPrecomputation
	bool NeedConversions() const {return true;}
	Element ConvertIn(const Element &P) const
		{return P.identity ? P : ECP::Point(m_ec->GetField().ConvertIn(P.x), m_ec->GetField().ConvertIn(P.y));};
	Element ConvertOut(const Element &P) const
		{return P.identity ? P : ECP::Point(m_ec->GetField().ConvertOut(P.x), m_ec->GetField().ConvertOut(P.y));}
	const AbstractGroup<Element> & GetGroup() const {return *m_ec;}
	Element BERDecodeElement(BufferedTransformation &bt) const {return m_ec->BERDecodePoint(bt);}
	void DEREncodeElement(BufferedTransformation &bt, const Element &v) const {m_ec->DEREncodePoint(bt, v, false);}

<<<<<<< HEAD
	/// \brief Set the elliptic curve
	/// \param ec ECP derived class
	/// \details SetCurve() is not inherited
=======
	// non-inherited
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	void SetCurve(const ECP &ec)
	{
		m_ec.reset(new ECP(ec, true));
		m_ecOriginal = ec;
	}
<<<<<<< HEAD

	/// \brief Get the elliptic curve
	/// \returns ECP curve
	/// \details GetCurve() is not inherited
	const ECP & GetCurve() const {return *m_ecOriginal;}

=======
	const ECP & GetCurve() const {return *m_ecOriginal;}

#ifndef CRYPTOPP_MAINTAIN_BACKWARDS_COMPATIBILITY_562
	virtual ~EcPrecomputation() {}
#endif

>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
private:
	value_ptr<ECP> m_ec, m_ecOriginal;
};

NAMESPACE_END

<<<<<<< HEAD
#if CRYPTOPP_MSC_VERSION
# pragma warning(pop)
#endif

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#endif
