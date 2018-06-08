#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<ofPoint> points;
	points.push_back(ofPoint(0, 0));
	points.push_back(ofPoint(ofGetWidth(), ofGetHeight()));
	points.push_back(ofPoint(0, ofGetHeight()));
	points.push_back(ofPoint(ofGetWidth(), 0));

	int deg_span = 1;
	int color_start = 0;
	int color_end = 120;

	ofSetColor(239);

	for (int i = 0; i < points.size(); i++) {

		ofPushMatrix();
		ofTranslate(points[i]);

		for (int radius = 150; radius <= 380; radius += 15) {

			int start_deg = i * 90;
			for (int deg = start_deg; deg < start_deg + 360; deg += deg_span) {

				int value = (ofGetFrameNum() * 2 + deg + radius) % 360;
				if (value > color_start && value < color_end) {
					
					ofPoint start = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
					ofPoint end = ofPoint(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD));

					ofDrawLine(start, end);
				}
			}
		}

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}