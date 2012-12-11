/* Copyright 2012 Adobe Systems Incorporated
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#include <v8.h>
#include <string>
#include <android/log.h>


class VateWrap {
public:
    VateWrap() {
        v8::HandleScope scope;

        v8::Local< v8::ObjectTemplate > global = v8::ObjectTemplate::New();

        mPrimaryContext = v8::Context::New(NULL, global);
    }

    ~VateWrap() {
        mPrimaryContext.Dispose();
    }

    const char* test() {

	v8::HandleScope current_scope;

	v8::Context::Scope context_scope(mPrimaryContext);

	v8::Local< v8::String > name = v8::String::New("il",2);

	v8::Local< v8::String > source = v8::String::New("function plus(x,y) { return x+y; }");

        if ( v8::Context::InContext() ) {
            __android_log_write(ANDROID_LOG_DEBUG, "HEY", "Joe");
 
        } else {

            __android_log_write(ANDROID_LOG_DEBUG, "YO", "JUST WANTED YOU TO KNOW");
}

        v8::Handle< v8::Script > script = v8::Script::Compile(source, name);
	 script->Run();
        v8::Local< v8::String > source1 = v8::String::New("plus(5,5)");

        v8::Handle< v8::Script > script1 = v8::Script::Compile(source1, name);

	v8::Local<v8::Value> val = script1->Run();



          if( val->IsInt32() ){ 
         v8::String::Utf8Value p(val->ToString());	
         __android_log_write(ANDROID_LOG_DEBUG, "HEY", *p);
}

        

    }

 
// Extracts a C string from a V8 Utf8Value.
    const char* ToCString(const v8::String::Utf8Value& value) {
        return *value ? *value : "<string conversion failed>";
    }


 
    const char * executeString( v8::Handle< v8::String > source, v8::Handle< v8::Value > name ) {
        v8::HandleScope scope;
        v8::TryCatch tc;
        v8::Handle< v8::Script > script = v8::Script::Compile(source, name);

        if( script.IsEmpty()) {
            // well, shit. Better fail silently!
            return 0;
        }       

        v8::Handle< v8::Value > result = script->Run();

        // sanity check result, use tc
 

        v8::String::Utf8Value str(result);
   //     const char * cstr = *result;
return "";
  //      return cstr;       
    }
 
    private:

        v8::Persistent< v8::Context > mPrimaryContext;    

};
