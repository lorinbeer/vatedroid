

#ifndef __PENDER_CANVAS_JS_H__
#define __PENDER_CANVAS_JS_H__

#include <v8.h>
#include <map>
#include <string>

using namespace std;
using namespace v8;

/**
 * object responsible for the javascript pender canvas api injected into a v8 context
 *   - creation of Canvas template
 *   - injection into v8 context
 */
class PenderCanvasJS {
public: 
    PenderCanvasJS();
    /**
     *
     */
    void initFunctionMap();
    /**
     *
     */
    void initCanvasFunctionTemplate();
    /**
     *
     */
    void injectInto(Handle<Context> ctx);
    /**
     *
     */
    static Handle<Value> CanvasRenderHandler(const Arguments &args);
//private: 
    map<string,int> _FunctionMap;
    Persistent<FunctionTemplate> _CanvasFunctionTemplate;
};

#endif // __PENDER_CANVAS_JS_H__
