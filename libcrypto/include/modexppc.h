#ifndef CRYPTOPP_MODEXPPC_H
#define CRYPTOPP_MODEXPPC_H

#include "cryptlib.h"
#include "modarith.h"
#include "integer.h"
#include "algebra.h"
#include "eprecomp.h"
#include "smartptr.h"
#include "pubkey.h"

<<<<<<< HEAD
#if CRYPTOPP_MSC_VERSION
# pragma warning(push)
# pragma warning(disable: 4231 4275)
#endif

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
NAMESPACE_BEGIN(CryptoPP)

CRYPTOPP_DLL_TEMPLATE_CLASS DL_FixedBasePrecomputationImpl<Integer>;

class ModExpPrecomputation : public DL_GroupPrecomputation<Integer>
{
public:
<<<<<<< HEAD
	virtual ~ModExpPrecomputation() {}

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
	// DL_GroupPrecomputation
	bool NeedConversions() const {return true;}
	Element ConvertIn(const Element &v) const {return m_mr->ConvertIn(v);}
	virtual Element ConvertOut(const Element &v) const {return m_mr->ConvertOut(v);}
	const AbstractGroup<Element> & GetGroup() const {return m_mr->MultiplicativeGroup();}
	Element BERDecodeElement(BufferedTransformation &bt) const {return Integer(bt);}
	void DEREncodeElement(BufferedTransformation &bt, const Element &v) const {v.DEREncode(bt);}

	// non-inherited
	void SetModulus(const Integer &v) {m_mr.reset(new MontgomeryRepresentation(v));}
	const Integer & GetModulus() const {return m_mr->GetModulus();}

private:
	value_ptr<MontgomeryRepresentation> m_mr;
};

NAMESPACE_END

<<<<<<< HEAD
#if CRYPTOPP_MSC_VERSION
# pragma warning(pop)
#endif

=======
>>>>>>> ed2c7340b8810ff6b77e11e1c946a083c3bfae56
#endif
