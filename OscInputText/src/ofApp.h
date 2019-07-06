#pragma once 
#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxBox2d.h"

//ポート番号を設定
#define PORT 8000

//——————————————————–
class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed (int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dumpOSC(ofxOscMessage m); //OSCメッセージを出力

private:
    //OSCメッセージを受信するインスタンス
    ofxOscReceiver    receiver;
    ofxBox2d box2d;
    vector<shared_ptr<ofxBox2dCircle>> circles;
    vector<ofPath> paths;
    ofTrueTypeFont font;
    string postedText;
    string word;

    void drawPolyline(ofPolyline polyline);
};
