#include "ofApp.h"
ofBitmapFont font;
// ofRectangle r;

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableAntiAliasing();
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	

	// SYSTEM SETTINGS
	//--------------------------------------
	stripWidth = 16;                            // pixel width of strip
	stripHeight = 128;                            // pixel height of strip
	rowHeight = 16;
	stripsPerPort = 1;                          // total number of strips per port
	numPorts = 1;                               // total number of teensy ports?
	brightness = 255;                             // LED brightness

	// setup our teensys
	teensy.setup(stripWidth, stripHeight, rowHeight, stripsPerPort, numPorts);

	/* Configure our teensy boards (portName, xOffset, yOffset, width%, height%, direction) */
	teensy.serialConfigure("ttyACM0", 0, 0, 100, 100, 0);
	teensy.setBrightness(brightness);

	// allocate our pixels, fbo, and texture
	 fbo.allocate(stripWidth, stripHeight*stripsPerPort*numPorts, GL_RGB);

	 // cout << ofGetEnv('OFLED_OFFSET') << endl;;
}

//--------------------------------------------------------------
void ofApp::update(){

	teensy.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.begin();
	ofClear(0,0,0);                             // refreshes fbo, removes artifacts
	ofSetColor(255, 0, 255);
	// ofDrawRectangle(ballpos,0,rectWidth,stripHeight*stripsPerPort*numPorts);
	// ofDrawRectangle(0,0,1,stripHeight*stripsPerPort*numPorts);
	ofBuffer buffer = ofBufferFromFile("display.log");
	if(buffer.size()) {
		auto end = buffer.getReverseLines().begin();
		string line = *end;

		ofRectangle r = font.getBoundingBox(line, 0, 0);
		float xPos = ofMap(sin(ofGetElapsedTimef()/4), -1, 1, 0, -r.getWidth()+16);

		ofDrawBitmapString(line, xPos, 16);
		// cout << line << endl;
		ofColor(255);
	}

	fbo.end();

	fbo.readToPixels(teensy.pixels1);           // send fbo pixels to teensy
	//fbo.draw(0, 0);
	teensy.draw(32,32);

	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage message){ 

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
