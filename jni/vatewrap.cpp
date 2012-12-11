#include <jni.h>
#include <string.h>
#include <android/log.h>

#include <v8.h>


jstring Java_com_vatedroid_Vatedroid_test(JNIEnv*env,jobject obj) {


   v8::Persistent< v8::Context > context = v8::Context::New();
//    __android_log_print(ANDROID_LOG_DEBUG, "FROM THE NDK!", "ALLLL CAPPPPS!");
   return env->NewStringUTF( "Hello from JNI !");

}

extern "C" void Java_com_vatedroid_Vatedroid_init(JNIEnv*env, jobject obj) {
    v8::Persistent< v8::Context > context;
    context = v8::Context::New();

}
