#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

// Replace with my own IP
#define MY_IP 127.0.0.1

// Replace with hub ID
#define HUB_IP 10.0.88.129

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
    void handleHeartbeat(ofxOscMessage *m);
    
    void handleAnyRoute();
    

    ofxOscReceiver oscReceiver;
    ofxOscSender oscSender;
    set<string> clients;
		
};
