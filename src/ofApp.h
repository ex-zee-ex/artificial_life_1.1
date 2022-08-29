/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "GuiApp.h"
#include "ofxNDIReceiver.h"
#include "ofxNDIRecvStream.h"

class ofApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
    void NDI_setup();
    
    void NDI_update();
	
    void midibiz();
    
    float lfo(float amp, float rate,int shape);
    
    void lfo_update();
    
    //guibiz
    
    shared_ptr<GuiApp> gui;
    
    //----------------------------midibiz
    
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	ofxMidiIn midiIn;
	std::vector<ofxMidiMessage> midiMessages;
	std::size_t maxMessages = 10; //< max number of messages to keep track of
    
    
    
    ofVideoGrabber cam1;
    ofVideoGrabber cam2;
    
   
    ofShader shader_osc0;
    ofShader shader_osc1;
    
    ofShader shader_osc0_blur;
    ofShader shader_osc0_sharpen;
    
    ofShader shader_osc1_blur;
    ofShader shader_osc1_sharpen;
    
    //thes buffers we store the oscs
    ofFbo fb_osc0;
    ofFbo fb_osc1;
    ofFbo fbo_osc0_blur;
    ofFbo fbo_osc1_blur;
    
    //these are for pingpong
    ofFbo fb_osc0_pp;
    ofFbo fb_osc1_pp;
    
    //ndi biz
    ofxNDIReceiver ndi_receiver_;
    ofxNDIRecvVideoFrameSync ndi_video_;
    ofPixels ndi_pixels;
    
    ofFbo ndi_fbo;
    
  
    
    
    
};
