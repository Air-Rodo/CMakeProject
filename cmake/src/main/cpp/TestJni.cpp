/**
 * Desc: 
 * @author Coco
 * Created on 2022/9/19 21:25
 * Email: 
 */
#include <jni.h>
#include <string>
#include "android/log.h"
#define TAG "TAG"

// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

struct PublicAttr {
    jclass user;
    jobject userObj;
} pubAttr;

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_cmake_api_TestApi_test(JNIEnv *env, jobject thiz) {
    jmethodID jSetUsernameMethodId;
    jmethodID jSetPasswordMethodId;
    jmethodID jGetUsernameMethodId;
    jmethodID jGetPasswordMethodId;
    jstring jUserName;
    jstring jPassword;
    pubAttr.user = env->FindClass("com/example/cmake/bean/User");
    pubAttr.userObj = env->AllocObject(pubAttr.user);
    jSetUsernameMethodId = env->GetMethodID(pubAttr.user,"setUsername", "(Ljava/lang/String;)V");
    jSetPasswordMethodId = env->GetMethodID(pubAttr.user,"setPassword","(Ljava/lang/String;)V");
    const char* userName = "李乐祺";
    const char* password = "123456";
    env->CallVoidMethod(pubAttr.userObj,jSetUsernameMethodId,env->NewStringUTF(userName));
    env->CallVoidMethod(pubAttr.userObj,jSetPasswordMethodId,env->NewStringUTF(password));
    jGetUsernameMethodId = env->GetMethodID(pubAttr.user,"getUsername", "()Ljava/lang/String;");
    jGetPasswordMethodId = env->GetMethodID(pubAttr.user,"getPassword","()Ljava/lang/String;");
    jUserName = (jstring)env->CallObjectMethod(pubAttr.userObj,jGetUsernameMethodId);
    jPassword = (jstring)env->CallObjectMethod(pubAttr.userObj,jGetPasswordMethodId);
    LOGD("username:%s",env->GetStringUTFChars(jUserName,NULL))
    LOGD("password:%s",env->GetStringUTFChars(jPassword,NULL))
    return pubAttr.userObj;
}