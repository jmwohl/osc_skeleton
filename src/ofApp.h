#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "oscClient.h"

#define PORT 8000

// Replace with my own IP
#define MY_IP "127.0.0.1"

// Replace with hub ID
#define HUB_IP "10.88.0.128"

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
    void handleAnyRoute();
    

    ofxOscReceiver oscReceiver;
    ofxOscSender oscSender;
    
    set<string> clientIps;
    map<string, oscClient> clients;
    int lastCallHomeTime;
		
};
