#include <jni.h>
#include <v8.h>
#include <android/log.h>
#include <stdlib.h>

#include "vatewrap.h"
#include "parmenides.h"


v8::Handle<v8::Value> ParmenidesHelperGetNothing(v8::Local<v8::String> property, const v8::AccessorInfo & info);
void ParmenidesHelperSetNothing(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo & info);
v8::Handle<v8::Value> ParmenidesConstructorHelper(const v8::Arguments & args);
std::string executeString( v8::Handle< v8::String > source, v8::Handle< v8::Value > name );

v8::Persistent<v8::Context> PrimaryContext;

v8::Handle<v8::FunctionTemplate> ParmenidesTemplate;


VateWrap * mPersistentVate;


std::string ObjectToString(v8::Local<v8::Value> value) {
  v8::String::Utf8Value utf8_value(value);
  return std::string(*utf8_value);
}


jstring Java_com_pender_PenderRenderer_test(JNIEnv*env,jobject obj) {


   v8::Persistent< v8::Context > context = v8::Context::New();
//    __android_log_print(ANDROID_LOG_DEBUG, "FROM THE NDK!", "ALLLL CAPPPPS!");
   return env->NewStringUTF( "Hello from JNI !");

}

extern "C" void Java_com_pender_cordovaplugin_PenderCordova_initvate(JNIEnv*env, jobject obj) {
  
    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "INITIALIZING VATEWRAP");

    using namespace v8;


    // create the scope and context

    // governs local handles
    HandleScope localscope;
    // object template used to create the global object of our context
    Local< ObjectTemplate > global = ObjectTemplate::New();

    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "Create Parmenides Function Template");

    // create a function template to wrap an object

    //embed an instance of the cpp class parmenides
    Parmenides nothing;
    // create an empty function template
    //Handle<FunctionTemplate> parmenidesTemplate = FunctionTemplate::New(ParmenidesConstructorHelper);
    ParmenidesTemplate = FunctionTemplate::New(ParmenidesConstructorHelper);


    // the instance template is an ObjectTemplate used to create objects when the function is used as a constructor

    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "get the instance template");
    Handle<ObjectTemplate> nothingInstanceTemplate = ParmenidesTemplate->InstanceTemplate();
    // a single internal field will hold a reference to the corresponding c++ object
    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK", "got the instance template");
    nothingInstanceTemplate->SetInternalFieldCount(1);

    // add object properties
    nothingInstanceTemplate->SetAccessor(String::New("nothing"), ParmenidesHelperGetNothing, ParmenidesHelperSetNothing);
    //nothingInstanceTemplate->SetAccessor(String::New("something"), &Parmenides::getNothing, &Parmenides::setNothing);
    ParmenidesTemplate->SetCallHandler(ParmenidesConstructorHelper);

    // inject into global context
    char * cstr = new char[250];
    sprintf (cstr,"%d",ParmenidesTemplate);
    global->Set(String::New("Parmenides"), ParmenidesTemplate);

    // declaration and instantiation of the primary context
    PrimaryContext = v8::Context::New(NULL, global);

    // Test Parmenides
    Handle< String > name = String::New("The Edge of Sanity");
    Handle< String > cmd = String::New("function main() { var nothing = new Parmenides(); return nothing.nothing; } \n main();");

    std::string result = executeString(cmd, name);

    __android_log_write(ANDROID_LOG_DEBUG, "Pender NDK: Executing Parmenides", result.c_str());

    delete [] cstr;
}

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
