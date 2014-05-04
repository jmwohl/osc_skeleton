//
//  oscClient.h
//  osc_skeleton_hub
//
//  Created by jonathan wohl on 5/4/14.
//
//

#ifndef __osc_skeleton_hub__oscClient__
#define __osc_skeleton_hub__oscClient__

#include <iostream>
#include "ofxOsc.h"

#endif /* defined(__osc_skeleton_hub__oscClient__) */

struct oscClient
{
    string ipAddress;
    ofxOscSender sender;
};