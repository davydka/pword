#pragma once

#include "ofxTeensyOcto.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// LED - Teensy stuff
		ofxTeensyOcto teensy;
		int stripWidth;
		int stripHeight;
		int rowHeight;
		int stripsPerPort;
		int numPorts;
		int brightness;

		// FBO stuff
		//-----------------------------
		ofFbo fbo;
		ofFbo fboHolder;

		// Graphic functions
		//-----------------------------
		int rectWidth;

		// Font
		// ----------------------------
		ofTrueTypeFont tFont;

};
