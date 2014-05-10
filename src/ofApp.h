#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

// You can get your IP address by running the following at the command line (look for addr:[your IP])
// ifconfig | grep inet | grep 127.0.0.1 --invert-match
#define MY_IP_ADDRESS "10.88.0.134"

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
    
    ofxOscReceiver oscReceiver;
    ofxOscSender oscSender;

};
