#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "TAG"

// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmakeproject_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cmakeproject_TestJni_setResponse(JNIEnv *env, jobject thiz) {
    jclass jCardResponseClass;
    jobject jCardObject;
    jfieldID jCommandFieldId;
    jfieldID jCommandLenFieldId;
    jmethodID setCommandLen;
    const char *value;
    jCardResponseClass = env->FindClass("com/example/cmakeproject/bean/CardResponse");
    jCardObject = env->AllocObject(jCardResponseClass);
//    setCommandLen = env->GetMethodID(jCardResponseClass, "setCommandLen", "(I)V");
//    jCommandFieldId = env->GetFieldID(jCardResponseClass, "command", "[B");
    jCommandLenFieldId = env->GetStaticFieldID(jCardResponseClass, "commandLen", "I");
    env->SetStaticIntField(jCardResponseClass, jCommandLenFieldId, 10);
//    env->GetStaticIntField(jCardResponseClass,jCommandLenFieldId);
    LOGD("commandLen: %d", env->GetStaticIntField(jCardResponseClass, jCommandLenFieldId))
    return 1;
}