
typedef int CanvasImageSource;

//====================================================================================================
// canvas state functions
void Java_com_pender_canvas_save() {

}

void Java_com_pender_canvas_restore() {

}
//====================================================================================================
// Transformations functions
void Java_com_pender_canvas_Transform_scale(JNIEnv * env,
				  jobject obj,
				  double x,
				  double y) {

}

void Java_com_pender_canvas_Transform_rotate(JNIEnv * env,
				   jobject obj,
				   double angle) {

}

void Java_com_pender_canvas_Transform_translate(JNIEnv * env,
				      jobject obj,
				      double x,
				      double y) {


}

void Java_com_pender_canvas_Transform_transform(JNIEnv * env,
				      jobject obj,
				      double a,
				      double b,
				      double c,
				      double d,
				      double e,
				      double f) {


}

void Java_com_pender_canvas_Transform_setTransform(JNIEnv * env,
				         jobject obj,
					 double a,
					 double b,
					 double c,
					 double d,
					 double e,
					 double f) {


}

void Java_com_pender_canvas_Transform_resetTransform(JNIEnv * env,
					   jobject obj) { 

}
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
void Java_com_pender_canvas_drawImage(JNIEnv * env,
                                      jobject obj,
                                      CanvasImageSource image,
                                      double dx,
                                      double dy) {
                                            

}

void Java_come_pender_canvas_drawImage(JNIEnv * env,
                                       jobject obj,
                                       CanvasImageSource image,
                                       double dx,
                                       double dy,
                                       double dw,
                                       double dh) {


}

void Java_come_pender_canvas_drawImage(JNIEnv * env,
                                       jobject obj,
                                       CanvasImageSource image,
                                       double sx,
                                       double sy,
                                       double sw,
                                       double sh,
                                       double dx,
                                       double dy,
                                       double dw,
                                       double dh) {


}
//====================================================================================================
// Hit Regions
//====================================================================================================
// Pixel Manipulation
//====================================================================================================
