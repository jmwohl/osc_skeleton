#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    oscReceiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
	while(oscReceiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
        // handle heartbeat
        if(m.getAddress() == "/heartbeat"){
			handleHeartbeat(m);
		}
        
		// check for mouse moved message
//		if(m.getAddress() == "/mouse/position"){
//			// both the arguments are int32's
//			mouseX = m.getArgAsInt32(0);
//			mouseY = m.getArgAsInt32(1);
//		}
//        
//		// check for mouse button message
//		else if(m.getAddress() == "/mouse/button"){
//			// the single argument is a string
//			mouseButtonState = m.getArgAsString(0);
//		}
//        
//        
//		else{
//			// unrecognized message: display on the bottom of the screen
//			string msg_string;
//			msg_string = m.getAddress();
//			msg_string += ": ";
//			for(int i = 0; i < m.getNumArgs(); i++){
//				// get the argument type
//				msg_string += m.getArgTypeName(i);
//				msg_string += ":";
//				// display the argument - make sure we get the right type
//				if(m.getArgType(i) == OFXOSC_TYPE_INT32){
//					msg_string += ofToString(m.getArgAsInt32(i));
//				}
//				else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
//					msg_string += ofToString(m.getArgAsFloat(i));
//				}
//				else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
//					msg_string += m.getArgAsString(i);
//				}
//				else{
//					msg_string += "unknown";
//				}
//			}
//			// add to the list of strings to display
//			msg_strings[current_msg_string] = msg_string;
//			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
//			current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
//			// clear the next line
//			msg_strings[current_msg_string] = "";
//		}
        
	}
}

void ofApp::callHome() {
    ofxOscMessage m;
	m.setAddress("/call/home");
	m.addStringArg(MY_IP);
	sender.sendMessage(m);
}

void ofApp::handleHeartbeat(ofxOscMessage &m) {
    int numArgs = m.getNumArgs();
    for(int i=0; i<numArgs; i++) {
        string ip = m.getArgAsString(i);
        clients.insert(ip);
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
