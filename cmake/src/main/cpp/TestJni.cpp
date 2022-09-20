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
extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_cmake_api_TestApi_test(JNIEnv *env, jobject thiz) {
    jclass jUser;
    jobject jUserObj;
    jmethodID jSetUsernameMethodId;
    jmethodID jSetPasswordMethodId;
    jmethodID jGetUsernameMethodId;
    jmethodID jGetPasswordMethodId;
    jstring jUserName;
    jstring jPassword;
    jUser = env->FindClass("com/example/cmake/bean/User");
    jUserObj = env->AllocObject(jUser);
    jSetUsernameMethodId = env->GetMethodID(jUser,"setUsername", "(Ljava/lang/String;)V");
    jSetPasswordMethodId = env->GetMethodID(jUser,"setPassword","(Ljava/lang/String;)V");
    const char* userName = "李乐祺";
    const char* password = "123456";
    env->CallVoidMethod(jUserObj,jSetUsernameMethodId,env->NewStringUTF(userName));
    env->CallVoidMethod(jUserObj,jSetPasswordMethodId,env->NewStringUTF(password));
    jGetUsernameMethodId = env->GetMethodID(jUser,"getUsername", "()Ljava/lang/String;");
    jGetPasswordMethodId = env->GetMethodID(jUser,"getPassword","()Ljava/lang/String;");
    jUserName = (jstring)env->CallObjectMethod(jUserObj,jGetUsernameMethodId);
    jPassword = (jstring)env->CallObjectMethod(jUserObj,jGetPasswordMethodId);
    LOGD("username:%s",jUserName)
    LOGD("password:%s",jPassword)
    return jUserObj;
}