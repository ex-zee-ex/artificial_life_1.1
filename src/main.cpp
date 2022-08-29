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
#include "ofMain.h"
#include "ofApp.h"

#include "GuiApp.h"
#include "ofAppGLFWWindow.h"


int main(){
    
    //--------------oldsinglewindowsetup
    /*
	ofSetupOpenGL(1280,720, OF_WINDOW);
    //ofSetupOpenGL(1920,800, OF_WINDOW);
	ofRunApp(new ofApp());
     */
    
    
    //---------------------------------
    //dualwindowsetup
    ofGLFWWindowSettings settings;
    
  
    //settings.setSize(512,512);
    settings.setSize(1280,720);
	//settings.setSize(1920, 1080);
	//settings.setSize(720, 480);
    
    //settings.setSize(796,633);
    //settings.setSize(1024,1024);

    
    //settings.setSize(640, 480);
    settings.setPosition(ofVec2f(550,80));
    settings.resizable = true;
    //settings.decorated = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.setSize(550, 960);
    settings.setPosition(ofVec2f(0,80));
    settings.resizable = true;
    // settings.doubleBuffering=false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->gui = guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();


    
    
    
    
}
