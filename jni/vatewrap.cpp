#include <jni.h>
#include <v8.h>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <map>
#include "vatewrap.h"
#include "parmenides.h"

#include "pendercanvasjs/pendercanvasjs.h"



v8::Handle<v8::Value> messageInABottle(const v8::Arguments & args);

v8::Persistent<v8::Context> PrimaryContext;

jstring Java_com_pender_PenderRenderer_test(JNIEnv*env,jobject obj) {

   v8::Persistent< v8::Context > context = v8::Context::New();
   return env->NewStringUTF( "Hello from JNI !");

}

extern "C" jstring Java_com_pender_PenderRenderer_bottleThrower(JNIEnv * env, jobject obj, jstring name, jstring message) {
    v8::HandleScope scope;
    v8::TryCatch tc;
    v8::Context::Scope context_scope(PrimaryContext);
    jstring retval;

    jboolean nameIsCopy;
    Handle< String > nme = String::New(env->GetStringChars(name,&nameIsCopy));
    Handle< String > cmd = String::New("function main() { var nothing = \"foobar\"; return nothing; } \n main();");

    v8::Handle< v8::Script > script = v8::Script::Compile(cmd, nme);

    __android_log_write(ANDROID_LOG_DEBUG, "VATEDROID Bottle Thrower", "Bottling Message");

    if (script.IsEmpty()) {
        return env->NewStringUTF("Error: Bottle is empty!");
    }

    __android_log_write(ANDROID_LOG_DEBUG, "VATEDROID Bottle Thrower", "Throwing Bottle");
    v8::Local< v8::Value > result = script->Run();

    if (result.IsEmpty()) {
        __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "RESULT IS EMPTY");
        v8::String::Utf8Value error(tc.Exception());
        __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", std::string(*error).c_str());
    }
    v8::String::Utf8Value retstr(result);
    retval = env->NewStringUTF(*retstr);
    return retval;
}

extern "C" void Java_com_pender_PenderRenderer_initvate(JNIEnv * env, jobject obj) {
  
    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "INITIALIZING VATEWRAP");

    using namespace v8;

    // create the scope and context

    // governs local handles
    HandleScope localscope;
    // object template used to create the global object of our context
    Local< ObjectTemplate > global = ObjectTemplate::New();
    // inject into global context
    global->Set(String::New("messageInABottle"), FunctionTemplate::New(messageInABottle));
    // declaration and instantiation of the primary context
    PrimaryContext = v8::Context::New(NULL, global);

}


v8::Handle<v8::Value> messageInABottle(const v8::Arguments & args) {
    return v8::String::New("demicanadian battle-felon");
}

/*
v8::Handle<v8::Value> ParmenidesHelperGetNothing(v8::Local<v8::String> property, const v8::AccessorInfo & info) {
	using namespace v8;
    return String::New("lunatic bastard");
}

void ParmenidesHelperSetNothing(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo & info) {

}

v8::Handle<v8::Value> ParmenidesConstructorHelper(const v8::Arguments & args) {
	__android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "PARMENIDES CONSTRUCTOR HELPER");
	using namespace v8;
	// throw if called without `new'
	if (!args.IsConstructCall()) {
		return ThrowException(String::New("Cannot call constructor as function, use with new"));
	}

	HandleScope scope;

	return v8::String::New("demicanadian battle-felon");

}


std::string executeString( v8::Handle< v8::String > source, v8::Handle< v8::Value > name ) {
	__android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "EXECUTING STRING");

    v8::HandleScope scope;
    v8::TryCatch tc;
    v8::Context::Scope context_scope(PrimaryContext);

    v8::Handle< v8::Script > script = v8::Script::Compile(source, name);

    if (script.IsEmpty()) {
        return std::string("Error: Script is empty!");
    }

    v8::Local< v8::Value > result = script->Run();

    if (result.IsEmpty()) {
    	__android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "RESULT IS EMPTY");
    	v8::String::Utf8Value error(tc.Exception());
    	__android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", std::string(*error).c_str());
    }
    v8::String::Utf8Value retstr(result);
    return std::string(*retstr);
}
*/

/*
 *
 */
void initCanvasTemplate() {

}

/*

v8::Handle<v8::Value> NewParmenides (const v8::Arguments& args) {
	using namespace v8;
	HandleScope scope;
	Local<External> data = Local<External>::Cast(args.Data());
}

static inline v8::Handle<v8::Value> New( const v8::Arguments& args ) {
		v8::HandleScope scope;
		v8::Local<v8::External> edata = v8::Local<v8::External>::Cast(args.Data());
		ExposedClass* that = static_cast<ExposedClass*>(edata->Value());
		return that->createNew(args);
	}
*/
