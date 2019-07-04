#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofTrueTypeFontSettings font_settings("Apple Color Emoji.ttc", 30);
    font_settings.antialiased = true;
    font_settings.addRanges(ofAlphabet::Emoji);
    this->font.load(font_settings);

    
	this->box2d.init();
	this->box2d.setGravity(0, 5);
	this->box2d.createBounds();
	this->box2d.setFPS(60);
	this->box2d.registerGrabbing();

  gui.setup();
  gui.add(deg.setup("deg", 140, -300, 300));
  gui.add(rotateX.setup("rotateX", 30, -100, 100));
  gui.add(rotateY.setup("rotateY", 30, -100, 100));
  gui.add(rotateZ.setup("rotateZ", 30, -100, 100));
  gui.add(density.setup("density", 1, 0, 100));
  gui.add(bounce.setup("bounce", 1, 0, 100));
  gui.add(friction.setup("friction", 1, 0, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetFrameNum() % 10 == 0) {
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setPhysics(1.0, 0.63, 0.1);
//        circle->setPhysics(density, bounce, friction);
//        circle->setup(this->box2d.getWorld(), ofRandom(ofGetWidth() * 0.5 - 50, ofGetWidth() * 0.5 + 50), 15, radius);
        circle->setup(box2d.getWorld(), 300, 300, 10);
        circles.push_back(circle);


		// float radius = 15;
		// auto circle = make_shared<ofxBox2dCircle>();
		// circle->setPhysics(1.0, 0.63, 0.1);
		// circle->setup(this->box2d.getWorld(), ofRandom(ofGetWidth() * 0.5 - 50, ofGetWidth() * 0.5 + 50), 15, radius);
		// this->circles.push_back(circle);
    // for (int i = 0; i < this->circles.size(); i++) {
        vector<string> emojis = { "💩" };
        this->words.push_back(emojis[(int)ofRandom(emojis.size())]);
    }
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float radius = 15;

    ofPushMatrix();
        ofTranslate(circles[0]->getPosition().x, circles[0]->getPosition().y);

//        ofRotateDeg(deg, rotateX, rotateY, rotateZ);
//        ofRotateDeg(20, 0,0,30);
        // 当たり判定を考慮してくれる？
         ofRotateDeg(circles[0]->getRotation());
        font.drawString(this->words[0], -15, 15);
    ofPopMatrix();
    
//    circles[0]->draw();
    
    
  gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
