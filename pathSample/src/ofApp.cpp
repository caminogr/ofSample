#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
////    draw square
        path.moveTo(20,20);
        path.lineTo(40,20);
        path.lineTo(40,40);
        path.lineTo(20,40);
        path.close();
        path.setStrokeColor(ofColor::blue);
        path.setFillColor(ofColor::red);
        path.setFilled(true);
        path.setStrokeWidth(2);
//      path.getOutline();
//      const ofPolyline line = path.getOutline()[0];
//      tessellation = path.getTessellation();
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    path.draw();
//    tessellation.drawWireframe();
//    ofMultMatrix(m);
//    path.draw();
    float app_time = ofGetElapsedTimef();
    float animation_time = fmodf(app_time, 2) / 2.;
    const vector<ofPolyline>& polys = path.getOutline();
    for (int k = 0; k < polys.size(); k++)
    {
        ofPolyline poly = polys[k];
        
        poly = poly.getResampledByCount(100);
        
        int target_size = poly.size() * animation_time;
        poly.resize(target_size);
        poly.draw();
    }

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
