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

using namespace v8;

typedef int CanvasImageSource;

class PenderCanvas2DContext {
  public:
    /**
     *
     *
     */    
    PenderCanvas2DContext();

    
    /**
     *
     */
    void initialize() {
        Local< ObjectTemplate > syringe = ObjectTemplate::New();
      //  syringe->SetCallAsFunctionHandler()
    }


    /**
     *
     */
    Local< External > externalClassPointer() {
        HandleScope scope;
        return scope.Close(External::New(reinterpret_cast<void *>(this)));
    }
 
    /**
     *
     *
     */
    void drawImage (CanvasImageSource image, 
                   double dx, 
                   double dy);

    /**
     *
     *
     */
    void drawImage (CanvasImageSource image, 
                    double dx, 
                    double dy, 
                    double dw, 
                    double dh);
    

        //void drawImage(CanvasImageSource image, unrestricted double sx, unrestricted double sy, unrestricted double sw, unrestricted double sh, unrestricted double dx, unrestricted double dy, unrestricted double dw, unrestricted double dh);


};
