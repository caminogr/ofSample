#include "ofApp.h"

void ofApp::setup() {
  // ofSetWindowShape(600, 400);
  ofSetFrameRate(30);
  ofSetBackgroundColor(249);

  ofTrueTypeFontSettings font_settings("Apple Color Emoji.ttc", 30);
  font_settings.addRanges(ofAlphabet::Emoji);
  font.load(font_settings);

  receiver.setup(PORT);

  float app_time = ofGetElapsedTimef();
  float animation_time = fmodf(app_time, 2) / 2.;

  box2d.init();
  box2d.setGravity(0, 5);
  box2d.createGround();
  box2d.createBounds();
  box2d.registerGrabbing();
  box2d.setFPS(60);
}

void ofApp::update() {
  //現在順番待ちのOSCメッセージがあるか確認
  while (receiver.hasWaitingMessages()) {
    //次のメッセージを取得
    ofxOscMessage m;
    receiver.getNextMessage(m);

    string msg_string;

    if (m.getAddress() == "/input/text") {
      msg_string = m.getAddress();
      postedText = m.getArgAsString(0);
      cout << "postedText: " << postedText << endl;
    }

    // dumpOSC(m);
  }

  float radius = 15;
  auto circle = make_shared<ofxBox2dCircle>();
  circle->setPhysics(1.0, 0.63, 0.1);
  circle->setup(this->box2d.getWorld(),
                ofRandom(ofGetWidth() * 0.5 - 50, ofGetWidth() * 0.5 + 50), 15,
                radius);
  this->circles.push_back(circle);

  word = "💩";
  box2d.update();
}

void ofApp::draw() {
  ofSetColor(0);

  ofTranslate(this->circles[0]->getPosition().x,
              this->circles[0]->getPosition().y);
  ofSetColor(21, 122, 184);

  font.drawString(word, 170, 300);
}

// OSCメッセージをコンソールに出力する関数
void ofApp::dumpOSC(ofxOscMessage m) {
  // cout << "m: " << m << endl;
  string msg_string;
  msg_string = m.getAddress();
  for (int i = 0; i < m.getNumArgs(); i++) {
    msg_string += " ";
    if (m.getArgType(i) == OFXOSC_TYPE_INT32) {
      msg_string += ofToString(m.getArgAsInt32(i));
      // cout << "msg_string int: " << i << endl;
    } else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
      msg_string += ofToString(m.getArgAsFloat(i));
      cout << "msg_string float: " << i << endl;
    } else if (m.getArgType(i) == OFXOSC_TYPE_STRING) {
      msg_string += m.getArgAsString(i);
      cout << "msg_string string: " << i << endl;
    }
  }
  cout << msg_string << endl;
}

void ofApp::drawPolyline(ofPolyline polyline) {
  // ofSetColor(255, 0, 255);
  ofFill();
  ofSetColor(215, 19, 69);
  polyline.draw();

  vector<glm::vec3> &vertices = polyline.getVertices();
  for (int i = 0; i < vertices.size(); i++) {
    ofPoint point = vertices.at(i);
    ofSetColor(215, 19, 69);
    ofDrawCircle(point.x, point.y, 10);
  }
}

void ofApp::keyPressed(int key) {}

void ofApp::mouseMoved(int x, int y) {}

void ofApp::mouseDragged(int x, int y, int button) {}

void ofApp::mousePressed(int x, int y, int button) {}

void ofApp::mouseReleased(int x, int y, int button) {}

void ofApp::windowResized(int w, int h) {}
