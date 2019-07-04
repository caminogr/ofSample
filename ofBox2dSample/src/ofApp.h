#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxBox2d box2d;
    ofxFloatSlider deg;
    ofxFloatSlider rotateX;
    ofxFloatSlider rotateY;
    ofxFloatSlider rotateZ;
    ofxFloatSlider density;
    ofxFloatSlider bounce;
    ofxFloatSlider friction;
    ofxPanel gui;

    ofTrueTypeFont font;
    
    vector<shared_ptr<ofxBox2dCircle>> circles;
    shared_ptr<ofxBox2dCircle> circle;
    vector<ofColor> circles_color;
    vector<string> words;
    ofxBox2dEdge eage_1, eage_2;
};
