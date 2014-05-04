#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    oscReceiver.setup(PORT);
    
    // initialize to HUB_IP for heartbeat?
    oscSender.setup(HUB_IP, PORT);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    int time = ofGetElapsedTimeMillis();
    
    if (time - lastCallHomeTime > CALL_HOME_INTERVAL) {
        lastCallHomeTime = time;
        sendHeartbeat();
    }
    
    
    // check for waiting messages
	while(oscReceiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
        // handle heartbeat
        if(m.getAddress() == "/pulse"){
			handleHeartbeat(&m);
		}
	}
}

void ofApp::callHome() {
    cout << "calling home" << endl;
    
    ofxOscMessage m;
	m.setAddress("/call/home");
//	m.addStringArg(MY_IP);
	sender.sendMessage(m);
}

void ofApp::handleHeartbeat(ofxOscMessage *m) {
    int numArgs = m->getNumArgs();
    for(int i=0; i<numArgs; i++) {
        string ip = m->getArgAsString(i);
        clients.insert(ip);
        
        cout << "Heatbeat: " + ip << endl;
    }
}

void ofApp::handleAnyRoute() {
    
}

//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
