#include "ofApp.h"
int offset = 0;
int rot = 0;
int flip = 0;
int length = 1;

//--------------------------------------------------------------
void ofApp::setup(){
	 offset = ofToInt(ofGetEnv("OFLED_OFFSET"));
	 rot = ofToInt(ofGetEnv("OFLED_ROT"));
	 flip = ofToInt(ofGetEnv("OFLED_FLIP"));
	 length = ofToInt(ofGetEnv("OFLED_LENGTH"));
	 cout << offset << endl;;
	 cout << rot << endl;;
	 cout << flip << endl;;
	 cout << length << endl;;

	 // cout << ofGetEnv("OFLED_OFFSET") << endl;;
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
	teensy.serialConfigure("ttyACM0", 0, 0, 100, 100, flip);
	teensy.setBrightness(brightness);

	// allocate our pixels, fbo, and texture
	 fbo.allocate(stripWidth, stripHeight*stripsPerPort*numPorts, GL_RGB);
	 fboHolder.allocate(stripWidth, rowHeight, GL_RGB);

	 tFont.load("fonts/AverageMono.ttf", 14, false);

}

//--------------------------------------------------------------
void ofApp::update(){

	teensy.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.begin();
	ofClear(0,0,0);                             // refreshes fbo, removes artifacts

	ofBuffer buffer = ofBufferFromFile("display.log");
	if(buffer.size()) {
		auto end = buffer.getReverseLines().begin();
		string line = *end;

		float r = tFont.stringWidth(line);
		float s = ofToFloat(ofGetTimestampString("%S")) * 1000;
		float i = ofToFloat(ofGetTimestampString("%i"));
		float time = s + i;
		float max = 10000;
		float xPos = ofMap(ofWrap(time, 0, max), 0, max, 0, -r-(16*length));

		ofPushMatrix();
		ofTranslate(8, 8);
		ofRotateZ(rot);
		ofTranslate(-8, -8);
		ofSetColor(0, 255, 0);
		tFont.drawString(line, xPos+16+(16*offset), 13);
		ofPopMatrix();
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
