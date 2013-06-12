#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	camWidth = 640;
    camHeight = 480;
    
	vidGrabber.initGrabber(camWidth,camHeight);
    frameCtr = 0;
    firstPass = true;
    
    ofSetFrameRate(60);
    
    for (int i = 0; i < NUM_FRAMES; i++) {
        frames[i].allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    }

    probability = 0.05f; // of chronological glitching
}

//--------------------------------------------------------------
void testApp::update(){

	vidGrabber.update();
    
    if (vidGrabber.isFrameNew())
    {
    
        ofImage img;
        img.setFromPixels(vidGrabber.getPixels(), camWidth, camHeight, OF_IMAGE_COLOR);
        
        if (firstPass) // on first pass store everything in order
        {
            frames[frameCtr] = frames[frameCtr+1] = img; // clunky but useful to start seeing things immediately
            if (frameCtr == NUM_FRAMES - 2)
                firstPass = false;
        }
        
        else // once we have a full set start glitching
        {
            if (ofRandom(1.0f) < probability) {
                frames[(int)ofRandom(NUM_FRAMES)] = img;
            }
            
            else {
                frames[frameCtr] = img;
            }
        }
        
        frameCtr = frameCtr < NUM_FRAMES-1 ? frameCtr + 1 : 0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
 
    frames[frameCtr].draw(0,0);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
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