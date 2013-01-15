
#include <list>
#include <assert.h>
#include <android/log.h>
#include <stdio.h>
#include "pendercanvasjs.h"
v8::Handle<v8::Value> ParmenidesConstructorHelper(const v8::Arguments & args);
/*
 * dynamically defines the canvas api
 */
PenderCanvasJS::PenderCanvasJS() {
    HandleScope localscope;
    Handle<FunctionTemplate> _object = FunctionTemplate::New(ParmenidesConstructorHelper);
    _CanvasFunctionTemplate = Persistent<FunctionTemplate>::New(_object);
//    _CanvasFunctionTemplate = Persistent<FunctionTemplate>::New(FunctionTemplate::New(ParmenidesConstructorHelper)); 
	// read out canvasapi.def
	list<string> apidef;
	int i = 0;
	//====================================================================================================
	// Transformation Functions
	_FunctionMap.insert (pair<string,int>("scale",i++));
	_FunctionMap.insert (pair<string,int>("rotate",i++));
	_FunctionMap.insert (pair<string,int>("translate",i++));
	_FunctionMap.insert (pair<string,int>("transform",i++));
    _FunctionMap.insert (pair<string,int>("settransform",i++));
    _FunctionMap.insert (pair<string,int>("gettransform",i++));
	//====================================================================================================
	// Compositing
	//====================================================================================================
	// Image Smoothing
	//====================================================================================================
	// Colors and Styles
	//====================================================================================================
	// Shadows
	//====================================================================================================
	// Rects API
	//====================================================================================================
	// Path API
	//====================================================================================================
	// Text API
	//====================================================================================================
	// Image Draw API
    _FunctionMap.insert (pair<string,int>("drawImage",i++));
	//====================================================================================================
	// Hit Regions
	//====================================================================================================
	// Pixel Manipulation
	//====================================================================================================

}

void PenderCanvasJS::injectInto(Handle<Context> ctx) {
    HandleScope localscope;
    //Context::Scope execCtx(ctx);
    //Handle<Object> global = ctx->Global();
    char * str = new char[256];
    sprintf (str,"%d",_CanvasFunctionTemplate);
    __android_log_write(ANDROID_LOG_DEBUG,"PENDERCANVASJS INJECTINTO", str);
    //asserit(ctx);
    delete [] str;
    Handle<ObjectTemplate> protoTemplate = _CanvasFunctionTemplate->PrototypeTemplate();


    //assert(_CanvasFunctionTemplate);
//    _CanvasFunctionTemplate->GetFunction();
    //global->Set(String::New("Canvas"), _CanvasFunctionTemplate->GetFunction());
    __android_log_write(ANDROID_LOG_DEBUG,"FUCK YEAH!, WE HAVE INJECTED!", "HAVE WE?");
}

void PenderCanvasJS::initCanvasFunctionTemplate() {
/*
    HandleScope localscope;

    Handle<ObjectTemplate> protoTemplate = _CanvasFunctionTemplate->PrototypeTemplate();

    for (map<string,int>::iterator it = _FunctionMap.begin(); it != _FunctionMap.end(); it++) {
        protoTemplate->Set(it->first.c_str(), FunctionTemplate::New(CanvasRenderHandler, Number::New(it->second)) );
    } 
*/  
}

Handle<Value> PenderCanvasJS::CanvasRenderHandler(const Arguments & args) {
    return String::New("canvas render handler message");
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
