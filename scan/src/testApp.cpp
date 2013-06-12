#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	camWidth = 640;
    camHeight = 480;
    
    vidGrabber.initGrabber(camWidth,camHeight);
    toDraw.allocate(camWidth,camHeight, OF_IMAGE_COLOR);

    ofSetBackgroundAuto(false);
    vCursor = camHeight-1;
    hCursor = 0;
    lr = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
		
        unsigned char * source   = vidGrabber.getPixels();
        unsigned char * existing = toDraw.getPixels();
        
        if (lr) // horizontal scan
        {
            
            for (int i = hCursor; i < camHeight * camWidth*3; i+= camWidth*3) {
                existing[i] = source[i];
            }
            
            hCursor = hCursor < camWidth*3 ? hCursor+1 : 0;
        }
        
        else // vertical scan
        {
            
            int beginRow = camWidth*vCursor*3;
            
            for (int i = beginRow; i < beginRow + camWidth*3; i++) {
                existing[i] = source[i];
            }
            
            vCursor = vCursor > 0 ? vCursor-1 : camHeight-1;
        }
        
        toDraw.setFromPixels(existing, camWidth, camHeight, OF_IMAGE_COLOR);
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    toDraw.draw(0,0);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    lr = !lr;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    hCursor = 0;
    vCursor = camHeight-1;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}