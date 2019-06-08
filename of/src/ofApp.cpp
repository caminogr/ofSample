#include "ofApp.h"

void ofApp::setup(){
    ofSetWindowShape(600, 400);
    ofSetFrameRate(30);
    ofSetBackgroundColor(249);

    font.load("NotoSansCJKjp-Regular.ttf", 72);

    // font = new ofTrueTypeFont();
    // ofTrueTypeFontSettings settings("NotoSansCJKjp-Regular.ttf", 30);
    // settings.antialiased = true;
    // settings.addRanges(ofAlphabet::Japanese);
    // this->font.load(settings);

    //指定したポートで接続
    receiver.setup( PORT );
    
    //値を初期化
//    mouseX = 0;
//    mouseY = 0;
//    mouseButtonState = "";
//
    // ofBackground(239);
}

void ofApp::update(){
    //現在順番待ちのOSCメッセージがあるか確認
    while( receiver.hasWaitingMessages() )
    {
        //次のメッセージを取得
        ofxOscMessage m;
        receiver.getNextMessage( m );
        
        string msg_string;
        
        if ( m.getAddress() == "/input/text") {
            msg_string = m.getAddress();
            postedText = m.getArgAsString( 0 );
            cout << "postedText: " << postedText << endl;
        }
    
        dumpOSC(m);
    }
}

//OSCメッセージをコンソールに出力する関数
void ofApp::dumpOSC(ofxOscMessage m) {
    cout << "m: " << m << endl;
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32) {
            msg_string += ofToString( m.getArgAsInt32(i));
            cout << "msg_string int: " << i << endl;
        }
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
        {
            msg_string += ofToString( m.getArgAsFloat(i));
            cout << "msg_string float: " << i << endl;
        }
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
        {
            msg_string += m.getArgAsString(i);
            cout << "msg_string string: " << i << endl;
        }
    }
    cout << msg_string << endl;
}

void ofApp::draw(){
    ofSetColor(40, 30, 60);
    font.drawString(postedText, 100, 200);
}

void ofApp::keyPressed (int key){}

void ofApp::mouseMoved(int x, int y ){}

void ofApp::mouseDragged(int x, int y, int button){}

void ofApp::mousePressed(int x, int y, int button){}

void ofApp::mouseReleased(int x, int y, int button){}

void ofApp::windowResized(int w, int h){}
