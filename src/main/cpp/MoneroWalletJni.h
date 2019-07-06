#include <jni.h>

#ifndef _Included_MoneroWalletJni
#define _Included_MoneroWalletJni

jfieldID getHandleField(JNIEnv *env, jobject obj, const char *fieldName) {
  jclass c = env->GetObjectClass(obj);
  return env->GetFieldID(c, fieldName, "J"); // of type long
}

template<typename T>
T *getHandle(JNIEnv *env, jobject obj, const char *fieldName) {
  jlong handle = env->GetLongField(obj, getHandleField(env, obj, fieldName));
  return reinterpret_cast<T *>(handle);
}

#ifdef __cplusplus
extern "C" {
#endif

// ------------------------------ STATIC METHODS ------------------------------

JNIEXPORT jboolean JNICALL Java_monero_wallet_MoneroWalletJni_walletExistsJni(JNIEnv *, jclass, jstring);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_openWalletJni(JNIEnv *, jclass, jstring, jstring, jint);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_createWalletRandomJni(JNIEnv *, jclass, jstring, jstring, jint, jstring, jstring, jstring, jstring);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_createWalletFromMnemonicJni(JNIEnv *, jclass, jstring, jstring, jstring, jint, jlong);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_createWalletFromKeysJni(JNIEnv *, jclass, jstring, jstring, jstring, jstring, jstring, jint, jlong, jstring);

// ----------------------------- INSTANCE METHODS -----------------------------

JNIEXPORT jobjectArray JNICALL Java_monero_wallet_MoneroWalletJni_getDaemonConnectionJni(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_setDaemonConnectionJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getPathJni(JNIEnv *, jobject);

JNIEXPORT jint JNICALL Java_monero_wallet_MoneroWalletJni_getNetworkTypeJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getMnemonicJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getPublicViewKeyJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getPrivateViewKeyJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getPublicSpendKeyJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getPrivateSpendKeyJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getLanguageJni(JNIEnv *, jobject);

JNIEXPORT jobjectArray JNICALL Java_monero_wallet_MoneroWalletJni_getLanguagesJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getAddressJni(JNIEnv *, jobject, jint, jint);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getAddressIndexJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getIntegratedAddressJni(JNIEnv *, jobject, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_decodeIntegratedAddressJni(JNIEnv *, jobject, jstring);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_setListenerJni(JNIEnv *, jobject, jobject);

JNIEXPORT jobjectArray JNICALL Java_monero_wallet_MoneroWalletJni_syncJni(JNIEnv *, jobject, jlong);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_getHeightJni(JNIEnv *, jobject);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_getChainHeightJni(JNIEnv *, jobject);

JNIEXPORT jlong JNICALL Java_monero_wallet_MoneroWalletJni_getRestoreHeightJni(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_setRestoreHeightJni(JNIEnv *, jobject, jlong);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getBalanceWalletJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getBalanceAccountJni(JNIEnv *, jobject, jint);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getBalanceSubaddressJni(JNIEnv *, jobject, jint, jint);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getUnlockedBalanceWalletJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getUnlockedBalanceAccountJni(JNIEnv *, jobject, jint);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getUnlockedBalanceSubaddressJni(JNIEnv *, jobject, jint, jint);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getAccountsJni(JNIEnv *, jobject, jboolean, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getAccountJni(JNIEnv *, jobject, jint, jboolean);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_createAccountJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getSubaddressesJni(JNIEnv *, jobject, jint, jintArray);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_createSubaddressJni(JNIEnv *, jobject, jint, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getTxsJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getTransfersJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getOutputsJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getKeyImagesJni(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_importKeyImagesJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_sendSplitJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_sweepOutputJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_sweepDustJni(JNIEnv *, jobject, jboolean);

JNIEXPORT jobjectArray JNICALL Java_monero_wallet_MoneroWalletJni_relayTxsJni(JNIEnv *, jobject, jobjectArray);

JNIEXPORT jobjectArray JNICALL Java_monero_wallet_MoneroWalletJni_getTxNotesJni(JNIEnv *, jobject, jobjectArray);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_setTxNotesJni(JNIEnv *, jobject, jobjectArray, jobjectArray);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_signJni(JNIEnv *, jobject, jstring);

JNIEXPORT jboolean JNICALL Java_monero_wallet_MoneroWalletJni_verifyJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getTxKeyJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_checkTxKeyJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getTxProofJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_checkTxProofJni(JNIEnv *, jobject, jstring, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getSpendProofJni(JNIEnv *, jobject, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_monero_wallet_MoneroWalletJni_checkSpendProofJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getReserveProofWalletJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getReserveProofAccountJni(JNIEnv *, jobject, jint, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_checkReserveProofJni(JNIEnv *, jobject, jstring, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_createPaymentUriJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_parsePaymentUriJni(JNIEnv *, jobject, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getOutputsHexJni(JNIEnv *, jobject);

JNIEXPORT jint JNICALL Java_monero_wallet_MoneroWalletJni_importOutputsHexJni(JNIEnv *, jobject, jstring);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_setAttributeJni(JNIEnv *, jobject, jstring, jstring);

JNIEXPORT jstring JNICALL Java_monero_wallet_MoneroWalletJni_getAttributeJni(JNIEnv *, jobject, jstring);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_startMiningJni(JNIEnv *, jobject, jlong, jboolean, jboolean);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_stopMiningJni(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_saveJni(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_moveToJni(JNIEnv *, jobject, jstring, jstring);

JNIEXPORT void JNICALL Java_monero_wallet_MoneroWalletJni_closeJni(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
