#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

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
    ofTrueTypeFont font;
    //OSCメッセージを受信するインスタンス
    ofxOscReceiver    receiver;
    //マウス座標
    int remoteMouseX, remoteMouseY;
    //マウスボタンの状態 ("up", "down")
    string mouseButtonState;
    //string oscString;
    string postedText;
};
