#ifndef CRYPTOPP_MODEXPPC_H
#define CRYPTOPP_MODEXPPC_H

#include "cryptopp/cryptlib.h"
#include "cryptopp/modarith.h"
#include "cryptopp/integer.h"
#include "cryptopp/algebra.h"
#include "cryptopp/eprecomp.h"
#include "cryptopp/smartptr.h"
#include "cryptopp/pubkey.h"

#if CRYPTOPP_MSC_VERSION
# pragma warning(push)
# pragma warning(disable: 4231 4275)
#endif

NAMESPACE_BEGIN(CryptoPP)

CRYPTOPP_DLL_TEMPLATE_CLASS DL_FixedBasePrecomputationImpl<Integer>;

class ModExpPrecomputation : public DL_GroupPrecomputation<Integer>
{
public:
	virtual ~ModExpPrecomputation() {}

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

#if CRYPTOPP_MSC_VERSION
# pragma warning(pop)
#endif

#endif
