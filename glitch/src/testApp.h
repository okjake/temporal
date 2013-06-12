#pragma once

#include "ofMain.h"

#define NUM_FRAMES 600

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVideoGrabber vidGrabber;
        ofImage frames[NUM_FRAMES];
     
        int camWidth, camHeight, frameCtr;
        bool firstPass;
    
        float probability;
};
