#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

// Replace with hub ID
#define HUB_IP "127.0.0.1"

// CALL_HOME_INTERVAL
#define CALL_HOME_INTERVAL 5000

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void callHome();
    void handlePulse(ofxOscMessage *m);
    void sendMessage(ofxOscMessage &m);
    

    ofxOscReceiver oscReceiver;
    ofxOscSender oscSender;
    
    map<string, ofxOscSender> clients;
    int lastCallHomeTime;
		
};
