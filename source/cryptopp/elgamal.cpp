// elgamal.cpp - originally written and placed in the public domain by Wei Dai

#include "cryptopp/pch.h"
#include "cryptopp/elgamal.h"
#include "cryptopp/asn.h"
#include "cryptopp/nbtheory.h"

// Squash MS LNK4221 and libtool warnings
extern const char ELGAMAL_FNAME[] = __FILE__;

NAMESPACE_BEGIN(CryptoPP)

#if defined(CRYPTOPP_DEBUG) && !defined(CRYPTOPP_DOXYGEN_PROCESSING)
void ElGamal_TestInstantiations()
{
	ElGamalEncryptor test1(1, 1, 1);
	ElGamalDecryptor test2(NullRNG(), 123);
	ElGamalEncryptor test3(test2);
}
#endif

NAMESPACE_END
