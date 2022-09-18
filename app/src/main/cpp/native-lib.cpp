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
    jCommandLenFieldId = env->GetStaticFieldID(jCardResponseClass, "commandLen", "I");
    env->SetStaticIntField(jCardResponseClass, jCommandLenFieldId, 10);
    LOGD("commandLen: %d", env->GetStaticIntField(jCardResponseClass, jCommandLenFieldId))
    return 1;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cmakeproject_TestJni_setPerson(JNIEnv *env, jobject thiz) {
    jclass jCardResponse;
    jclass jPerson;
    jobject jCardResObj;
    jobject jPersonObj;
    jmethodID setPerson;
    jmethodID setUsername;
    jmethodID setPassword;
    jPerson = env->FindClass("com/example/cmakeproject/bean/Person");
    jPersonObj = env->AllocObject(jPerson);
    setUsername = env->GetMethodID(jPerson,"setUsername", "(Ljava/lang/String;)V");
    setPassword = env->GetMethodID(jPerson,"setPassword", "(I)V");
    std::string value = "张三";
    jstring username = env->NewStringUTF(value.c_str());
    env->CallVoidMethod(jPersonObj,setUsername,username);
    env->CallVoidMethod(jPersonObj,setPassword,123456);
    jCardResponse = env->FindClass("com/example/cmakeproject/bean/CardResponse");
    jCardResObj = env->AllocObject(jCardResponse);
    setPerson = env->GetMethodID(jCardResponse,"setPerson", "(Lcom/example/cmakeproject/bean/Person;)V");
    env->CallVoidMethod(jCardResObj, setPerson, jPersonObj);
}