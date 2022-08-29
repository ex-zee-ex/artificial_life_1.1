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
#include "ofApp.h"

#include "iostream"



//lfo thetas
//osc0

//osc0_basic
float osc0_rate_theta=0;
float osc0_frequency_theta=0;
float osc0_amp_theta=0;
float osc0_width_theta=0;
float osc0_radial_theta=0;

//osc1->osc0_mods
float osc0_rm_theta=0;
float osc0_pm_theta=0;
float osc0_pwm_theta=0;
float osc0_modulation_rotate2_theta=0;

//osc0_m->osc0 mods
float osc0_m_rm_theta=0;
float osc0_m_pm_theta=0;
float osc0_pwm2_theta=0;
float osc0_modulation_rotate_theta=0;

//osc0 ext input mods
float osc0_ext_input_pm_theta=0;
float osc0_ext_input_rm_theta=0;
float osc0_ext_input_scale_theta=0;
float osc0_ext_input_x_displace_theta=0;
float osc0_ext_input_y_displace_theta=0;
float osc0_ext_input_rotate_theta=0;

//osc0 internal feedback
float osc0_feedback_pm_theta=0;
float osc0_feedback_rm_theta=0;
float osc0_feedback_scale_theta=0;
float osc0_feedback_x_displace_theta=0;
float osc0_feedback_y_displace_theta=0;
float osc0_feedback_rotate_theta=0;

//osc0 filters

float osc0_powmod_theta=1;
float osc0_blur_amount_theta=0;
float osc0_blur_radius_theta=1;
float osc0_sharpen_amount_theta=0;
float osc0_sharpen_radius_theta=1;
float osc0_temporal_filter_theta=0;

//osc0_m
float osc0_m_rate_theta=0;
float osc0_m_frequency_theta=0;
float osc0_m_amp_theta=0;
float osc0_m_radial_theta=0;
float osc0_m_modulation_rotate_theta=0;
float osc0_m_width_theta=0;
float osc0_m_pwm_theta=0;
float osc0_m_pwm2_theta=0;
float osc0_m_feedback_pm_theta=0;



//osc1

//osc1_basic
float osc1_rate_theta=0;
float osc1_frequency_theta=0;
float osc1_amp_theta=0;
float osc1_width_theta=0;
float osc1_radial_theta=0;

//osc1->osc1_mods
float osc1_rm_theta=0;
float osc1_pm_theta=0;
float osc1_pwm_theta=0;
float osc1_modulation_rotate2_theta=0;

//osc1_m->osc1 mods
float osc1_m_rm_theta=0;
float osc1_m_pm_theta=0;
float osc1_pwm2_theta=0;
float osc1_modulation_rotate_theta=0;

//osc1 ext input mods
float osc1_ext_input_pm_theta=0;
float osc1_ext_input_rm_theta=0;
float osc1_ext_input_scale_theta=0;
float osc1_ext_input_x_displace_theta=0;
float osc1_ext_input_y_displace_theta=0;
float osc1_ext_input_rotate_theta=0;

//osc1 internal feedback
float osc1_feedback_pm_theta=0;
float osc1_feedback_rm_theta=0;
float osc1_feedback_scale_theta=0;
float osc1_feedback_x_displace_theta=0;
float osc1_feedback_y_displace_theta=0;
float osc1_feedback_rotate_theta=0;

//osc1 filters
float osc1_powmod_theta=1;
float osc1_blur_amount_theta=0;
float osc1_blur_radius_theta=1;
float osc1_sharpen_amount_theta=0;
float osc1_sharpen_radius_theta=1;
float osc1_temporal_filter_theta=0;

//osc1_m
float osc1_m_rate_theta=0;
float osc1_m_frequency_theta=0;
float osc1_m_amp_theta=0;
float osc1_m_radial_theta=0;
float osc1_m_modulation_rotate_theta=0;
float osc1_m_width_theta=0;
float osc1_m_pwm_theta=0;
float osc1_m_pwm2_theta=0;
float osc1_m_feedback_pm_theta=0;








//keep these
float osc0_rate=0;
float osc0_m_rate=0;
float osc1_rate=0;
float osc1_m_rate=0;
float osc0_rotate=0;
float osc0_m_rotate=0;
float osc1_rotate=0;
float osc1_m_rotate=0;

int osc0_shape=0;
int osc1_shape=0;



int width=0;
int height=0;

//p_lock biz
//maximum total size of the plock array
const int p_lock_size=120;

bool p_lock_record_switch=0;

bool p_lock_erase=0;

//maximum number of p_locks available...maybe there can be one for every knob
//for whatever wacky reason the last member of this array of arrays has a glitch
//so i guess just make an extra array and forget about it for now
const int p_lock_number=44;

//so how we will organize the p_locks is in multidimensional arrays
//to access the data at timestep x for p_lock 2 (remember counting from 0) we use p_lock[2][x]
float p_lock[p_lock_number][p_lock_size];


//smoothing parameters(i think for all of these we can array both the arrays and the floats
//for now let us just try 1 smoothing parameter for everything.
float p_lock_smooth=.5;


//and then lets try an array of floats for storing the smoothed values
float p_lock_smoothed[p_lock_number];


//turn on and off writing to the array
bool p_lock_0_switch=1;

//global counter for all the locks
int p_lock_increment=0;


//just keep for when i need to test something quickly
float qq=0;

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    //this clamps the frame rate at 30fps
    //most usb cameras only work at 30 or 60
    //but it might be hard to get anything complex
    //to run at 60fps without framedropping or insconsistent
    //frame rates
    ofSetFrameRate(30);
    
    //this makes the background black
    ofBackground(0);
    
    //run this to hide the mouse cursor on the screen
    //ofHideCursor();
    
    NDI_setup();
    /*
    // print input ports to console
    midiIn.listInPorts();
    
    // open port by number (you may need to change this)
    midiIn.openPort(0);
    //midiIn.openPort("IAC Pure Data In");	// by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);
    */
    
    //shadersbiz
    shader_osc0.load("shadersGL2/shader_osc0");
    shader_osc1.load("shadersGL2/shader_osc1");
    shader_osc0_blur.load("shadersGL2/shader_osc0_blur");
    shader_osc0_sharpen.load("shadersGL2/shader_osc0_sharpen");
    shader_osc1_blur.load("shadersGL2/shader_osc1_blur");
    shader_osc1_sharpen.load("shadersGL2/shader_osc1_sharpen");
    
    
    width=ofGetWidth();
    height=ofGetHeight();
    
    fb_osc0.allocate(width,height);
    fb_osc0.begin();
    ofClear(0,0,0,255);
    fb_osc0.end();
    
    fb_osc1.allocate(width,height);
    fb_osc1.begin();
    ofClear(0,0,0,255);
    fb_osc1.end();
    
    fb_osc0_pp.allocate(width,height);
    fb_osc0_pp.begin();
    ofClear(0,0,0,255);
    fb_osc0_pp.end();
    
    fb_osc1_pp.allocate(width,height);
    fb_osc1.begin();
    ofClear(0,0,0,255);
    fb_osc1_pp.end();
    
    
    ndi_fbo.allocate(width,height);
    ndi_fbo.begin();
    ofClear(0,0,0,255);
    ndi_fbo.end();
    
    fbo_osc0_blur.allocate(width,height);
    fbo_osc0_blur.begin();
    ofClear(0,0,0,255);
    fbo_osc0_blur.end();
    
    fbo_osc1_blur.allocate(width,height);
    fbo_osc1_blur.begin();
    ofClear(0,0,0,255);
    fbo_osc1_blur.end();
    
    cam1.setVerbose(true);
    cam1.listDevices();
    cam1.setDeviceID(0);
    cam1.initGrabber(width,height);
    cam2.setDeviceID(1);
    cam2.initGrabber(width,height);
    
    
    
    
    //do some initializing
    for(int i=0;i<p_lock_size;i++){
        //p_lock[1][i]=.05;
        //p_lock[8][i]=1.0;
        
        //p_lock[17][i]=.05;
        //p_lock[24][i]=1.0;
        
        //p_lock[4][i]=.05;
        //p_lock[11][i]=1.0;
        
       // p_lock[20][i]=.05;
        //p_lock[27][i]=1.0;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
    //midibiz();
    

    cam1.update();
    cam2.update();
    NDI_update();
    
    lfo_update();
    
    //p-lock biz
    for(int i=0;i<p_lock_number;i++){
        p_lock_smoothed[i]=p_lock[i][p_lock_increment]*(1.0f-p_lock_smooth)+p_lock_smoothed[i]*p_lock_smooth;
        
        if(abs(p_lock_smoothed[i])<.001){p_lock_smoothed[i]=0;}
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetColor(255);
    //delete these after finishing up osc1 updates
    float cam_pm_scale=4.0;
    float osc1_cutoff=.5;
    float osc0_cutoff=.5;
    
    //keep and organize these
    //osc0 and osc1 can have the same scales on everything
    float osc0_pm_scale=.1;
    float osc0_rm_scale=5;
    float osc1_pm_scale=.1;
    float osc1_rm_scale=5;
    
    
    float osc_rm_scale=5;
    float osc_pm_scale=.01;
    float osc_frequency_scale=.15;
    float osc_rate_scale=.15;
    float angle_scale=3.14;
    float modulation_rotate_scale=10.0;
    float spiral_scale=ofGetWidth()*.0025f;
    float osc_rate_mod_scale=.15;
    float osc_rotate_scale=.01;
    float pwm_scale=2;
    float ext_input_pm_scale=10.0;
    float ext_input_rm_scale=10.0;
    float ext_input_scale_scale=2.0;
    float ext_input_x_displace_scale=100;
    float ext_input_y_displace_scale=100;
    float ext_input_rotate_scale=6.18;
    
    float feedback_pm_scale=10.0;
    float feedback_rm_scale=10.0;
    float feedback_scale_scale=.5;
    float feedback_x_displace_scale=20;
    float feedback_y_displace_scale=20;
    float feedback_rotate_scale=TWO_PI;
    
    float texmod_spiral_scale=ofGetWidth()*.05f;
    float texmod_rotate_scale=TWO_PI;
    float texmod_amp_scale=4.0;
    float texmod_width_scale=2.0;
    
    //osc0
    
    fb_osc0.begin();
    
    
    
    
    
    
    
    
    
    //oscillator rate adders
    osc0_rate+=osc_rate_scale*(p_lock_smoothed[0]+gui->gui_osc0_rate+lfo(gui->gui_osc0_rate_amp,osc0_rate_theta,0))+sin(osc1_rate)*(p_lock_smoothed[7]+gui->gui_osc0_rate_mod)*osc_rate_mod_scale;
    osc0_m_rate+=osc_rate_scale*(p_lock_smoothed[16]+gui->gui_osc0_m_rate+lfo(gui->gui_osc0_m_rate_amp,osc0_m_rate_theta,0))+sin(osc1_m_rate)*(p_lock_smoothed[23]+gui->gui_osc0_rate_mod)*osc_rate_mod_scale;
    
    //oscillator rotate adders
    osc0_rotate+=osc_rotate_scale*(p_lock_smoothed[33]+gui->gui_osc0_rotate);
    osc0_m_rotate+=osc_rotate_scale*(p_lock_smoothed[39]+gui->gui_osc0_m_rotate);
    
    shader_osc0.begin();
    
    
    
    
    //pass the textures
    //texture from osc1
    fb_osc1_pp.draw(0,0);
    //feedback texture
    shader_osc0.setUniformTexture("last_frame",fb_osc0_pp.getTexture(),2);
    
    //osc0_ext_input
    if(gui->gui_ext_input_switch==0){
        shader_osc0.setUniformTexture("ext_input",cam1.getTexture(),3);
        shader_osc0.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->gui_ext_input_switch==1){
        shader_osc0.setUniformTexture("ext_input",cam2.getTexture(),3);
        shader_osc0.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->gui_ext_input_switch==2){
        shader_osc0.setUniformTexture("ext_input",ndi_fbo.getTexture(),3);
        shader_osc0.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    //osc0_tex mod
    if(gui->osc0_texmod_select==0){
        shader_osc0.setUniformTexture("texmod",cam1.getTexture(),4);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc0_texmod_select==1){
        shader_osc0.setUniformTexture("texmod_input",cam2.getTexture(),4);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc0_texmod_select==2){
        shader_osc0.setUniformTexture("texmod_input",ndi_fbo.getTexture(),4);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc0_texmod_select==3){
        shader_osc0.setUniformTexture("texmod_input",fb_osc0_pp.getTexture(),4);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc0_pp.getWidth(),fb_osc0_pp.getHeight()));
    }
    
    //some globalish variables
    shader_osc0.setUniform1f("width",ofGetWidth());
    shader_osc0.setUniform1f("height",ofGetHeight());
    shader_osc0.setUniform1i("osc0_shape",gui->gui_osc0_shape);
    shader_osc0.setUniform1i("osc0_m_shape",gui->gui_osc0_m_shape);
    shader_osc0.setUniform1f("osc0_texmod_scale",gui->osc0_texmod_scale);
    
    
    
    //osc0 basic
    shader_osc0.setUniform1f("osc0_rate",osc0_rate);
    shader_osc0.setUniform1f("osc0_frequency",
                             (p_lock_smoothed[1]
                              +gui->gui_osc0_frequency
                              +lfo(gui->gui_osc0_frequency_amp,osc0_frequency_theta,0)
                              )*osc_frequency_scale);
    shader_osc0.setUniform1f("osc0_amp",p_lock_smoothed[8]
                             +gui->gui_osc0_amp
                             +lfo(gui->gui_osc0_amp_amp,osc0_amp_theta,0));
    shader_osc0.setUniform1f("osc0_width",gui->gui_osc0_width+lfo(gui->gui_osc0_width_amp,osc0_width_theta,0));
    shader_osc0.setUniform1f("osc0_angle",(p_lock_smoothed[9]+gui->gui_osc0_angle)*angle_scale);
    shader_osc0.setUniform1f("osc0_spiral",(p_lock_smoothed[32]
                                            +gui->gui_osc0_spiral+
                                            lfo(gui->gui_osc0_radial_amp,osc0_radial_theta,0)
                                            )*spiral_scale);
    shader_osc0.setUniform1f("osc0_rotate",fmod(osc0_rotate,2.0f*PI));
    
    //osc0 basic texmods
    shader_osc0.setUniform1f("texmod_osc0_frequency",gui->texmod_gui_osc0_frequency*osc_frequency_scale);
    shader_osc0.setUniform1f("texmod_osc0_amp",gui->texmod_gui_osc0_amp*texmod_amp_scale);
    shader_osc0.setUniform1f("texmod_osc0_width",gui->texmod_gui_osc0_width*texmod_width_scale);
    shader_osc0.setUniform1f("texmod_osc0_angle",gui->texmod_gui_osc0_angle*texmod_rotate_scale);
    shader_osc0.setUniform1f("texmod_osc0_spiral",gui->texmod_gui_osc0_spiral*texmod_spiral_scale);
    
    //osc1->osc0 mods
    shader_osc0.setUniform1f("osc0_rm",(p_lock_smoothed[2]
                                        +gui->gui_osc0_rm
                                        +lfo(gui->gui_osc0_rm_amp,osc0_rm_theta,0)
                                        )*osc0_rm_scale);
    shader_osc0.setUniform1f("osc0_pm",(p_lock_smoothed[10]
                                        +gui->gui_osc0_pm
                                        +lfo(gui->gui_osc0_pm_amp,osc0_pm_theta,0)
                                        )*osc0_pm_scale);
    shader_osc0.setUniform1f("osc0_pm_cutoff",gui->gui_osc0_pm_cutoff);
    shader_osc0.setUniform1f("osc0_pwm",(gui->gui_osc0_pwm
                                         +lfo(gui->gui_osc0_pwm_amp,osc0_pwm_theta,0)
                                         )*pwm_scale);
    shader_osc0.setUniform1f("osc0_modulation_rotate2",
                             (gui->gui_osc0_modulation_rotate2
                             +lfo(gui->gui_osc0_modulation_rotate2_amp,osc0_modulation_rotate2_theta,0)
                             )*modulation_rotate_scale);
    
    //osc1->osc0 texmods
    shader_osc0.setUniform1f("texmod_osc0_rm",gui->texmod_gui_osc0_rm*osc_rm_scale);
    shader_osc0.setUniform1f("texmod_osc0_pm",gui->texmod_gui_osc0_pm*osc_pm_scale);
    shader_osc0.setUniform1f("texmod_osc0_pm_cutoff",gui->texmod_gui_osc0_pm_cutoff);
    shader_osc0.setUniform1f("texmod_osc0_pwm",gui->texmod_gui_osc0_pwm*pwm_scale);
    shader_osc0.setUniform1f("texmod_osc0_modulation_rotate2",
                             gui->texmod_gui_osc0_modulation_rotate2*modulation_rotate_scale);

    
    //osc0_m->osc0 mods
    //make those coefficients global
    shader_osc0.setUniform1f("osc0_m_rm",10*(p_lock_smoothed[18]
                                             +gui->gui_osc0_m_rm
                                             +lfo(gui->gui_osc0_m_rm_amp,osc0_m_rm_theta,0)));
    shader_osc0.setUniform1f("osc0_m_pm",.1f*(p_lock_smoothed[26]
                                              +gui->gui_osc0_m_pm
                                              +lfo(gui->gui_osc0_m_pm_amp,osc0_m_pm_theta,0)));
    shader_osc0.setUniform1f("osc0_pwm2",(gui->gui_osc0_pwm2
                                          +lfo(gui->gui_osc0_pwm2_amp,osc0_pwm2_theta,0)
                                          )*pwm_scale);
    shader_osc0.setUniform1f("osc0_modulation_rotate",
                             (p_lock_smoothed[34]
                             +gui->gui_osc0_modulation_rotate
                             +lfo(gui->gui_osc0_modulation_rotate_amp,osc0_modulation_rotate_theta,0)
                             )*modulation_rotate_scale);
    
    //osc0_m->osc0 texmods
    shader_osc0.setUniform1f("texmod_osc0_m_rm",gui->texmod_gui_osc0_m_rm*osc_rm_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_pm",gui->texmod_gui_osc0_m_pm*osc_pm_scale);
    shader_osc0.setUniform1f("texmod_osc0_pwm2",gui->texmod_gui_osc0_pwm2*pwm_scale);
    shader_osc0.setUniform1f("texmod_osc0_modulation_rotate",
                             gui->texmod_gui_osc0_modulation_rotate*modulation_rotate_scale);
    
    //osc0 ext input
    shader_osc0.setUniform1f("osc0_ext_input_pm",
                             (gui->gui_osc0_ext_input_pm
                             +lfo(gui->gui_osc0_ext_input_pm_amp, osc0_ext_input_pm_theta,0)
                             )*ext_input_pm_scale);
    shader_osc0.setUniform1f("osc0_ext_input_rm",
                             (gui->gui_osc0_ext_input_rm
                             +lfo(gui->gui_osc0_ext_input_rm_amp, osc0_ext_input_rm_theta,0)
                             )*ext_input_rm_scale);
    shader_osc0.setUniform1f("osc0_ext_input_scale",
                             (gui->gui_osc0_ext_input_scale
                             +lfo(gui->gui_osc0_ext_input_scale_amp, osc0_ext_input_scale_theta,0)
                             )*ext_input_scale_scale);
    shader_osc0.setUniform1f("osc0_ext_input_x_displace",
                             (gui->gui_osc0_ext_input_x_displace
                             +lfo(gui->gui_osc0_ext_input_x_displace_amp
                                  , osc0_ext_input_x_displace_theta,0)
                             )*ext_input_x_displace_scale);
    shader_osc0.setUniform1f("osc0_ext_input_y_displace",
                             (gui->gui_osc0_ext_input_y_displace
                             +lfo(gui->gui_osc0_ext_input_y_displace_amp
                                  , osc0_ext_input_y_displace_theta,0)
                             )*ext_input_y_displace_scale);
    shader_osc0.setUniform1f("osc0_ext_input_rotate",
                             (gui->gui_osc0_ext_input_rotate
                             +lfo(gui->gui_osc0_ext_input_rotate_amp, osc0_ext_input_rotate_theta,0)
                              )*ext_input_rotate_scale);
    
    shader_osc0.setUniform1i("osc0_ext_input_x_mirror",gui->gui_osc0_ext_input_x_mirror);
    shader_osc0.setUniform1i("osc0_ext_input_y_mirror",gui->gui_osc0_ext_input_y_mirror);
    
    //texmod osc0 ext input
    shader_osc0.setUniform1f("texmod_osc0_ext_input_pm",gui->texmod_gui_osc0_ext_input_pm*ext_input_pm_scale);
    shader_osc0.setUniform1f("texmod_osc0_ext_input_rm",gui->texmod_gui_osc0_ext_input_rm*ext_input_rm_scale);
    shader_osc0.setUniform1f("texmod_osc0_ext_input_scale",gui->texmod_gui_osc0_ext_input_scale*ext_input_scale_scale);
    shader_osc0.setUniform1f("texmod_osc0_ext_input_x_displace",
                             gui->texmod_gui_osc0_ext_input_x_displace*ext_input_x_displace_scale);
    shader_osc0.setUniform1f("texmod_osc0_ext_input_y_displace",
                             gui->texmod_gui_osc0_ext_input_y_displace*ext_input_y_displace_scale);
    shader_osc0.setUniform1f("texmod_osc0_ext_input_rotate",gui->texmod_gui_osc0_ext_input_rotate*ext_input_rotate_scale);
    
    
    //osc0 feedback
    shader_osc0.setUniform1f("osc0_feedback_pm",
                             (p_lock_smoothed[6]
                              +gui->gui_osc0_feedback_pm
                              +lfo(gui->gui_osc0_feedback_pm_amp, osc0_feedback_pm_theta,0)
                              )*feedback_pm_scale);
    shader_osc0.setUniform1f("osc0_feedback_rm",
                             (gui->gui_osc0_feedback_rm
                             +lfo(gui->gui_osc0_feedback_rm_amp, osc0_feedback_rm_theta,0)
                              )*feedback_rm_scale);
    shader_osc0.setUniform1f("osc0_feedback_scale",
                             (gui->gui_osc0_feedback_scale
                             +lfo(gui->gui_osc0_feedback_scale_amp, osc0_feedback_scale_theta,0)
                              )*feedback_scale_scale);
    shader_osc0.setUniform1f("osc0_feedback_x_displace",
                             (gui->gui_osc0_feedback_x_displace
                             +lfo(gui->gui_osc0_feedback_x_displace_amp
                                  , osc0_feedback_x_displace_theta,0)
                              )*feedback_x_displace_scale);
    shader_osc0.setUniform1f("osc0_feedback_y_displace",
                             (gui->gui_osc0_feedback_y_displace
                             +lfo(gui->gui_osc0_feedback_y_displace_amp
                                  , osc0_feedback_y_displace_theta,0)
                              )*feedback_y_displace_scale);
    shader_osc0.setUniform1f("osc0_feedback_rotate",
                             (gui->gui_osc0_feedback_rotate
                              +lfo(gui->gui_osc0_feedback_rotate_amp, osc0_feedback_rotate_theta,0)
                              )*feedback_rotate_scale);
    
    shader_osc0.setUniform2f("feedback_dimensions"
                             ,ofVec2f(fb_osc0_pp.getWidth()
                                      ,fb_osc0_pp.getHeight()));
    shader_osc0.setUniform1i("osc0_feedback_x_mirror",gui->gui_osc0_feedback_x_mirror);
    shader_osc0.setUniform1i("osc0_feedback_y_mirror",gui->gui_osc0_feedback_y_mirror);
    
    
    //texmod osc0 feedback
    shader_osc0.setUniform1f("texmod_osc0_feedback_pm",gui->texmod_gui_osc0_feedback_pm*feedback_pm_scale);
    shader_osc0.setUniform1f("texmod_osc0_feedback_rm",gui->texmod_gui_osc0_feedback_rm*feedback_rm_scale);
    shader_osc0.setUniform1f("texmod_osc0_feedback_scale",gui->texmod_gui_osc0_feedback_scale*feedback_scale_scale);
    shader_osc0.setUniform1f("texmod_osc0_feedback_x_displace",
                             gui->texmod_gui_osc0_feedback_x_displace*feedback_x_displace_scale);
    shader_osc0.setUniform1f("texmod_osc0_feedback_y_displace",
                             gui->texmod_gui_osc0_feedback_y_displace*feedback_y_displace_scale);
    shader_osc0.setUniform1f("texmod_osc0_feedback_rotate",gui->texmod_gui_osc0_feedback_rotate*feedback_rotate_scale);
    
    
    //osc0 filters
	shader_osc0.setUniform1f("osc0BitCrushMix",gui->osc0BitCrushMix);
	shader_osc0.setUniform1f("osc0BitCrush", gui->osc0BitCrush);
	shader_osc0.setUniform1f("osc0BitCrushDenom", 1.0f/(gui->osc0BitCrush));

    shader_osc0.setUniform1f("osc0_powmod",
                             gui->gui_osc0_powmod
                             +lfo(gui->gui_osc0_powmod_amp,osc0_powmod_theta,0));
    shader_osc0.setUniform1f("osc0_temporal_filter"
                             ,gui->gui_osc0_temporal_filter
                             +lfo(gui->gui_osc0_temporal_filter_amp,osc0_temporal_filter_theta,0));
    shader_osc0.setUniform1i("osc0_overflow_switch",gui->gui_osc0_overflow_switch);
    
    
    //texmod osc0 color and filters
    shader_osc0.setUniform1f("texmod_osc0_powmod",gui->texmod_gui_osc0_powmod);
    shader_osc0.setUniform1f("texmod_osc0_temporal_filter",gui->texmod_gui_osc0_temporal_filter);
    
    //osc0_m
    shader_osc0.setUniform1f("osc0_m_rate",osc0_m_rate);
    shader_osc0.setUniform1f("osc0_m_amp",
                             p_lock_smoothed[24]
                             +gui->gui_osc0_m_amp
                             +lfo(gui->gui_osc0_m_amp_amp,osc0_m_amp_theta,0));
    shader_osc0.setUniform1f("osc0_m_frequency",
                             (p_lock_smoothed[17]
                              +gui->gui_osc0_m_frequency
                              +lfo(gui->gui_osc0_m_frequency_amp,osc0_m_frequency_theta,0)
                              )*osc_frequency_scale);
    shader_osc0.setUniform1f("osc0_m_width",
                             gui->gui_osc0_m_width
                             +lfo(gui->gui_osc0_m_width_amp,osc0_m_width_theta,0));
    shader_osc0.setUniform1f("osc0_m_angle",
                             (p_lock_smoothed[25]
                              +gui->gui_osc0_m_angle
                              )*angle_scale);
    shader_osc0.setUniform1f("osc0_m_rotate",fmod(osc0_m_rotate,2.0f*PI));
    shader_osc0.setUniform1f("osc0_m_spiral",
                             (p_lock_smoothed[38]
                              +gui->gui_osc0_m_spiral
                              +lfo(gui->gui_osc0_m_radial_amp,osc0_m_radial_theta,0)
                              )*spiral_scale);
    
    
    //texmod osc0_m
    shader_osc0.setUniform1f("texmod_osc0_m_amp",gui->texmod_gui_osc0_m_amp*texmod_amp_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_frequency",gui->texmod_gui_osc0_m_frequency*osc_frequency_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_width",gui->texmod_gui_osc0_m_width*texmod_width_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_angle",gui->texmod_gui_osc0_m_angle*texmod_rotate_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_spiral",gui->texmod_gui_osc0_m_spiral*texmod_spiral_scale);
    
    shader_osc0.setUniform1f("osc0_m_modulation_rotate",
                             (p_lock_smoothed[40]
                              +gui->gui_osc0_m_modulation_rotate
                              +lfo(gui->gui_osc0_m_modulation_rotate_amp,osc0_m_modulation_rotate_theta,0)
                              )*modulation_rotate_scale);
    shader_osc0.setUniform1f("osc0_m_pwm",
                             (gui->gui_osc0_m_pwm
                              +lfo(gui->gui_osc0_m_pwm_amp,osc0_m_pwm_theta,0)
                              )*pwm_scale);
    shader_osc0.setUniform1f("osc0_m_pwm2",
                             (gui->gui_osc0_m_pwm2
                              +lfo(gui->gui_osc0_m_pwm2_amp,osc0_m_pwm2_theta,0)
                              )*pwm_scale);
    shader_osc0.setUniform1f("osc0_m_feedback_pm",
                             (p_lock_smoothed[22]
                              +gui->gui_osc0_m_feedback_pm
                              +lfo(gui->gui_osc0_m_feedback_pm_amp,osc0_m_feedback_pm_theta,0)
                              )*feedback_pm_scale);

    //texmod osc0_m mods
    shader_osc0.setUniform1f("texmod_osc0_m_modulation_rotate",
                             gui->texmod_gui_osc0_m_modulation_rotate*modulation_rotate_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_pwm",gui->texmod_gui_osc0_m_pwm*pwm_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_pwm2",gui->texmod_gui_osc0_m_pwm2*pwm_scale);
    shader_osc0.setUniform1f("texmod_osc0_m_feedback_pm",
                             gui->texmod_gui_osc0_m_feedback_pm*feedback_pm_scale);
    
	//NEW
	shader_osc0.setUniform1f("osc0BrightBand1", gui->osc0BrightBand1);
	shader_osc0.setUniform1f("osc0SaturationBand1", gui->osc0SaturationBand1);
	shader_osc0.setUniform1f("osc0HueBand1", gui->osc0HueBand1);
	shader_osc0.setUniform1f("osc0BrightBand2", gui->osc0BrightBand2);
	shader_osc0.setUniform1f("osc0SaturationBand2", gui->osc0SaturationBand2);
	shader_osc0.setUniform1f("osc0HueBand2", gui->osc0HueBand2);
	shader_osc0.setUniform1f("osc0BrightBand3", gui->osc0BrightBand3);
	shader_osc0.setUniform1f("osc0SaturationBand3", gui->osc0SaturationBand3);
	shader_osc0.setUniform1f("osc0HueBand3", gui->osc0HueBand3);
	shader_osc0.setUniform1f("osc0BrightBand4", gui->osc0BrightBand4);
	shader_osc0.setUniform1f("osc0SaturationBand4", gui->osc0SaturationBand4);
	shader_osc0.setUniform1f("osc0HueBand4", gui->osc0HueBand4);
	shader_osc0.setUniform1f("osc0BrightBand5", gui->osc0BrightBand5);
	shader_osc0.setUniform1f("osc0SaturationBand5", gui->osc0SaturationBand5);
	shader_osc0.setUniform1f("osc0HueBand5", gui->osc0HueBand5);
	shader_osc0.setUniform1f("osc0BrightBand6", gui->osc0BrightBand6);
	shader_osc0.setUniform1f("osc0SaturationBand6", gui->osc0SaturationBand6);
	shader_osc0.setUniform1f("osc0HueBand6", gui->osc0HueBand6);
	shader_osc0.setUniform1f("osc0BrightBand7", gui->osc0BrightBand7);
	shader_osc0.setUniform1f("osc0SaturationBand7", gui->osc0SaturationBand7);
	shader_osc0.setUniform1f("osc0HueBand7", gui->osc0HueBand7);
	shader_osc0.setUniform1f("osc0BrightBand8", gui->osc0BrightBand8);
	shader_osc0.setUniform1f("osc0SaturationBand8", gui->osc0SaturationBand8);
	shader_osc0.setUniform1f("osc0HueBand8", gui->osc0HueBand8);

    shader_osc0.end();
    
    fb_osc0.end();
    
    
    
    
    
    
    
    
    //blur and sharpen
    fbo_osc0_blur.begin();
    shader_osc0_blur.begin();
    fb_osc0.draw(0,0);
    
    //blur_tex mod
    if(gui->osc0_texmod_select==0){
        shader_osc0_blur.setUniformTexture("texmod",cam1.getTexture(),5);
        shader_osc0_blur.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc0_texmod_select==1){
        shader_osc0_blur.setUniformTexture("texmod_input",cam2.getTexture(),5);
        shader_osc0_blur.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc0_texmod_select==2){
        shader_osc0_blur.setUniformTexture("texmod_input",ndi_fbo.getTexture(),5);
        shader_osc0_blur.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc0_texmod_select==3){
        shader_osc0_blur.setUniformTexture("texmod_input",fb_osc0_pp.getTexture(),5);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc0_pp.getWidth(),fb_osc0_pp.getHeight()));
    }
    
    shader_osc0_blur.setUniform1f("osc0_blur_amount"
                             ,gui->gui_osc0_blur_amount
                             +lfo(gui->gui_osc0_blur_amount_amp,osc0_blur_amount_theta,0));
    shader_osc0_blur.setUniform1f("osc0_blur_radius"
                             ,gui->gui_osc0_blur_radius
                             +lfo(gui->gui_osc0_blur_radius_amp,osc0_blur_radius_theta,0));
    
    shader_osc0_blur.setUniform1f("texmod_osc0_blur_amount",gui->texmod_gui_osc0_blur_amount);
    shader_osc0_blur.setUniform1f("texmod_osc0_blur_radius",gui->texmod_gui_osc0_blur_radius);
    
    shader_osc0_blur.setUniform1f("width",ofGetWidth());
    shader_osc0_blur.setUniform1f("height",ofGetHeight());
    
    shader_osc0_blur.end();
    fbo_osc0_blur.end();
    
    fb_osc0.begin();
    shader_osc0_sharpen.begin();
    fbo_osc0_blur.draw(0,0);
    
    //sharpen_tex mod
    if(gui->osc0_texmod_select==0){
        shader_osc0_sharpen.setUniformTexture("texmod",cam1.getTexture(),6);
        shader_osc0_sharpen.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc0_texmod_select==1){
        shader_osc0_sharpen.setUniformTexture("texmod_input",cam2.getTexture(),6);
        shader_osc0_sharpen.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc0_texmod_select==2){
        shader_osc0_sharpen.setUniformTexture("texmod_input",ndi_fbo.getTexture(),6);
        shader_osc0_sharpen.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc0_texmod_select==3){
        shader_osc0_sharpen.setUniformTexture("texmod_input",fb_osc0_pp.getTexture(),6);
        shader_osc0.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc0_pp.getWidth(),fb_osc0_pp.getHeight()));
    }
    
    shader_osc0_sharpen.setUniform1f("osc0_sharpen_amount"
                                ,gui->gui_osc0_sharpen_amount
                                +lfo(gui->gui_osc0_sharpen_amount_amp,osc0_sharpen_amount_theta,0));
    shader_osc0_sharpen.setUniform1f("osc0_sharpen_radius"
                                ,gui->gui_osc0_sharpen_radius
                                +lfo(gui->gui_osc0_sharpen_radius_amp,osc0_sharpen_radius_theta,0));
    
    shader_osc0_sharpen.setUniform1f("texmod_osc0_sharpen_amount",gui->texmod_gui_osc0_sharpen_amount);
    shader_osc0_sharpen.setUniform1f("texmod_osc0_sharpen_radius",gui->texmod_gui_osc0_sharpen_radius);
    
    shader_osc0_sharpen.setUniform1f("width",ofGetWidth());
    shader_osc0_sharpen.setUniform1f("height",ofGetHeight());
    
    shader_osc0_sharpen.end();
    fb_osc0.end();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //osc2
    
   
    
    
    
    
    
    
    
    
        //shader_osc1.setUniformTexture("cam1", fb_osc1_pp.getTexture(),4);
        //shader_osc1.setUniform2f("cam1_dimensions",ofVec2f(fb_osc1_pp.getWidth(),fb_osc1_pp.getHeight()));
    
    
    
   
    fb_osc1.begin();
    
    
    
    
    
    
    
    
    
    //oscillator rate adders
    osc1_rate+=osc_rate_scale*(p_lock_smoothed[0]+gui->gui_osc1_rate+lfo(gui->gui_osc1_rate_amp,osc1_rate_theta,0))+sin(osc0_rate)*(p_lock_smoothed[7]+gui->gui_osc1_rate_mod)*osc_rate_mod_scale;
    osc1_m_rate+=osc_rate_scale*(p_lock_smoothed[16]+gui->gui_osc1_m_rate+lfo(gui->gui_osc1_m_rate_amp,osc1_m_rate_theta,0))+sin(osc0_m_rate)*(p_lock_smoothed[23]+gui->gui_osc1_rate_mod)*osc_rate_mod_scale;
    
    //oscillator rotate adders
    osc1_rotate+=osc_rotate_scale*(p_lock_smoothed[33]+gui->gui_osc1_rotate);
    osc1_m_rotate+=osc_rotate_scale*(p_lock_smoothed[39]+gui->gui_osc1_m_rotate);
    
    shader_osc1.begin();
    
    
    
    
    //pass the textures
    //texture from osc1
    fb_osc0_pp.draw(0,0);
    //feedback texture
    shader_osc1.setUniformTexture("last_frame",fb_osc1_pp.getTexture(),7);
    
    //osc1_ext_input
    if(gui->gui_ext_input_switch==0){
        shader_osc1.setUniformTexture("ext_input",cam1.getTexture(),8);
        shader_osc1.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->gui_ext_input_switch==1){
        shader_osc1.setUniformTexture("ext_input",cam2.getTexture(),8);
        shader_osc1.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->gui_ext_input_switch==2){
        shader_osc1.setUniformTexture("ext_input",ndi_fbo.getTexture(),8);
        shader_osc1.setUniform2f("ext_input_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    //osc1_tex mod
    if(gui->osc1_texmod_select==0){
        shader_osc1.setUniformTexture("texmod",cam1.getTexture(),9);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc1_texmod_select==1){
        shader_osc1.setUniformTexture("texmod_input",cam2.getTexture(),9);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc1_texmod_select==2){
        shader_osc1.setUniformTexture("texmod_input",ndi_fbo.getTexture(),9);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc1_texmod_select==3){
        shader_osc1.setUniformTexture("texmod_input",fb_osc1_pp.getTexture(),9);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc1_pp.getWidth(),fb_osc1_pp.getHeight()));
    }
    
    //some globalish variables
    shader_osc1.setUniform1f("width",ofGetWidth());
    shader_osc1.setUniform1f("height",ofGetHeight());
    shader_osc1.setUniform1i("osc1_shape",gui->gui_osc1_shape);
    shader_osc1.setUniform1i("osc1_m_shape",gui->gui_osc1_m_shape);
    shader_osc1.setUniform1f("osc1_texmod_scale",gui->osc1_texmod_scale);
    
    
    
    //osc1 basic
    shader_osc1.setUniform1f("osc1_rate",osc1_rate);
    shader_osc1.setUniform1f("osc1_frequency",
                             (p_lock_smoothed[1]
                              +gui->gui_osc1_frequency
                              +lfo(gui->gui_osc1_frequency_amp,osc1_frequency_theta,0)
                              )*osc_frequency_scale);
    shader_osc1.setUniform1f("osc1_amp",p_lock_smoothed[8]
                             +gui->gui_osc1_amp
                             +lfo(gui->gui_osc1_amp_amp,osc1_amp_theta,0));
    shader_osc1.setUniform1f("osc1_width",gui->gui_osc1_width+lfo(gui->gui_osc1_width_amp,osc1_width_theta,0));
    shader_osc1.setUniform1f("osc1_angle",(p_lock_smoothed[9]+gui->gui_osc1_angle)*angle_scale);
    shader_osc1.setUniform1f("osc1_spiral",(p_lock_smoothed[32]
                                            +gui->gui_osc1_spiral+
                                            lfo(gui->gui_osc1_radial_amp,osc1_radial_theta,0)
                                            )*spiral_scale);
    shader_osc1.setUniform1f("osc1_rotate",fmod(osc1_rotate,2.0f*PI));
    
    //osc1 basic texmods
    shader_osc1.setUniform1f("texmod_osc1_frequency",gui->texmod_gui_osc1_frequency*osc_frequency_scale);
    shader_osc1.setUniform1f("texmod_osc1_amp",gui->texmod_gui_osc1_amp*texmod_amp_scale);
    shader_osc1.setUniform1f("texmod_osc1_width",gui->texmod_gui_osc1_width*texmod_width_scale);
    shader_osc1.setUniform1f("texmod_osc1_angle",gui->texmod_gui_osc1_angle*texmod_rotate_scale);
    shader_osc1.setUniform1f("texmod_osc1_spiral",gui->texmod_gui_osc1_spiral*texmod_spiral_scale);
    
    //osc1->osc1 mods
    shader_osc1.setUniform1f("osc1_rm",(p_lock_smoothed[2]
                                        +gui->gui_osc1_rm
                                        +lfo(gui->gui_osc1_rm_amp,osc1_rm_theta,0)
                                        )*osc1_rm_scale);
    shader_osc1.setUniform1f("osc1_pm",(p_lock_smoothed[10]
                                        +gui->gui_osc1_pm
                                        +lfo(gui->gui_osc1_pm_amp,osc1_pm_theta,0)
                                        )*osc1_pm_scale);
    shader_osc1.setUniform1f("osc1_pm_cutoff",gui->gui_osc1_pm_cutoff);
    shader_osc1.setUniform1f("osc1_pwm",(gui->gui_osc1_pwm
                                         +lfo(gui->gui_osc1_pwm_amp,osc1_pwm_theta,0)
                                         )*pwm_scale);
    shader_osc1.setUniform1f("osc1_modulation_rotate2",
                             (gui->gui_osc1_modulation_rotate2
                              +lfo(gui->gui_osc1_modulation_rotate2_amp,osc1_modulation_rotate2_theta,0)
                              )*modulation_rotate_scale);
    
    //osc1->osc1 texmods
    shader_osc1.setUniform1f("texmod_osc1_rm",gui->texmod_gui_osc1_rm*osc_rm_scale);
    shader_osc1.setUniform1f("texmod_osc1_pm",gui->texmod_gui_osc1_pm*osc_pm_scale);
    shader_osc1.setUniform1f("texmod_osc1_pm_cutoff",gui->texmod_gui_osc1_pm_cutoff);
    shader_osc1.setUniform1f("texmod_osc1_pwm",gui->texmod_gui_osc1_pwm*pwm_scale);
    shader_osc1.setUniform1f("texmod_osc1_modulation_rotate2",
                             gui->texmod_gui_osc1_modulation_rotate2*modulation_rotate_scale);
    
    
    //osc1_m->osc1 mods
    //make those coefficients global
    shader_osc1.setUniform1f("osc1_m_rm",10*(p_lock_smoothed[18]
                                             +gui->gui_osc1_m_rm
                                             +lfo(gui->gui_osc1_m_rm_amp,osc1_m_rm_theta,0)));
    shader_osc1.setUniform1f("osc1_m_pm",.1f*(p_lock_smoothed[26]
                                              +gui->gui_osc1_m_pm
                                              +lfo(gui->gui_osc1_m_pm_amp,osc1_m_pm_theta,0)));
    shader_osc1.setUniform1f("osc1_pwm2",(gui->gui_osc1_pwm2
                                          +lfo(gui->gui_osc1_pwm2_amp,osc1_pwm2_theta,0)
                                          )*pwm_scale);
    shader_osc1.setUniform1f("osc1_modulation_rotate",
                             (p_lock_smoothed[34]
                              +gui->gui_osc1_modulation_rotate
                              +lfo(gui->gui_osc1_modulation_rotate_amp,osc1_modulation_rotate_theta,0)
                              )*modulation_rotate_scale);
    
    //osc1_m->osc1 texmods
    shader_osc1.setUniform1f("texmod_osc1_m_rm",gui->texmod_gui_osc1_m_rm*osc_rm_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_pm",gui->texmod_gui_osc1_m_pm*osc_pm_scale);
    shader_osc1.setUniform1f("texmod_osc1_pwm2",gui->texmod_gui_osc1_pwm2*pwm_scale);
    shader_osc1.setUniform1f("texmod_osc1_modulation_rotate",
                             gui->texmod_gui_osc1_modulation_rotate*modulation_rotate_scale);
    
    //osc1 ext input
    shader_osc1.setUniform1f("osc1_ext_input_pm",
                             (gui->gui_osc1_ext_input_pm
                              +lfo(gui->gui_osc1_ext_input_pm_amp, osc1_ext_input_pm_theta,0)
                              )*ext_input_pm_scale);
    shader_osc1.setUniform1f("osc1_ext_input_rm",
                             (gui->gui_osc1_ext_input_rm
                              +lfo(gui->gui_osc1_ext_input_rm_amp, osc1_ext_input_rm_theta,0)
                              )*ext_input_rm_scale);
    shader_osc1.setUniform1f("osc1_ext_input_scale",
                             (gui->gui_osc1_ext_input_scale
                              +lfo(gui->gui_osc1_ext_input_scale_amp, osc1_ext_input_scale_theta,0)
                              )*ext_input_scale_scale);
    shader_osc1.setUniform1f("osc1_ext_input_x_displace",
                             (gui->gui_osc1_ext_input_x_displace
                              +lfo(gui->gui_osc1_ext_input_x_displace_amp
                                   , osc1_ext_input_x_displace_theta,0)
                              )*ext_input_x_displace_scale);
    shader_osc1.setUniform1f("osc1_ext_input_y_displace",
                             (gui->gui_osc1_ext_input_y_displace
                              +lfo(gui->gui_osc1_ext_input_y_displace_amp
                                   , osc1_ext_input_y_displace_theta,0)
                              )*ext_input_y_displace_scale);
    shader_osc1.setUniform1f("osc1_ext_input_rotate",
                             (gui->gui_osc1_ext_input_rotate
                              +lfo(gui->gui_osc1_ext_input_rotate_amp, osc1_ext_input_rotate_theta,0)
                              )*ext_input_rotate_scale);
    
    shader_osc1.setUniform1i("osc1_ext_input_x_mirror",gui->gui_osc1_ext_input_x_mirror);
    shader_osc1.setUniform1i("osc1_ext_input_y_mirror",gui->gui_osc1_ext_input_y_mirror);
    
    //texmod osc1 ext input
    shader_osc1.setUniform1f("texmod_osc1_ext_input_pm",gui->texmod_gui_osc1_ext_input_pm*ext_input_pm_scale);
    shader_osc1.setUniform1f("texmod_osc1_ext_input_rm",gui->texmod_gui_osc1_ext_input_rm*ext_input_rm_scale);
    shader_osc1.setUniform1f("texmod_osc1_ext_input_scale",gui->texmod_gui_osc1_ext_input_scale*ext_input_scale_scale);
    shader_osc1.setUniform1f("texmod_osc1_ext_input_x_displace",
                             gui->texmod_gui_osc1_ext_input_x_displace*ext_input_x_displace_scale);
    shader_osc1.setUniform1f("texmod_osc1_ext_input_y_displace",
                             gui->texmod_gui_osc1_ext_input_y_displace*ext_input_y_displace_scale);
    shader_osc1.setUniform1f("texmod_osc1_ext_input_rotate",gui->texmod_gui_osc1_ext_input_rotate*ext_input_rotate_scale);
    
    
    //osc1 feedback
    shader_osc1.setUniform1f("osc1_feedback_pm",
                             (p_lock_smoothed[6]
                              +gui->gui_osc1_feedback_pm
                              +lfo(gui->gui_osc1_feedback_pm_amp, osc1_feedback_pm_theta,0)
                              )*feedback_pm_scale);
    shader_osc1.setUniform1f("osc1_feedback_rm",
                             (gui->gui_osc1_feedback_rm
                              +lfo(gui->gui_osc1_feedback_rm_amp, osc1_feedback_rm_theta,0)
                              )*feedback_rm_scale);
    shader_osc1.setUniform1f("osc1_feedback_scale",
                             (gui->gui_osc1_feedback_scale
                              +lfo(gui->gui_osc1_feedback_scale_amp, osc1_feedback_scale_theta,0)
                              )*feedback_scale_scale);
    shader_osc1.setUniform1f("osc1_feedback_x_displace",
                             (gui->gui_osc1_feedback_x_displace
                              +lfo(gui->gui_osc1_feedback_x_displace_amp
                                   , osc1_feedback_x_displace_theta,0)
                              )*feedback_x_displace_scale);
    shader_osc1.setUniform1f("osc1_feedback_y_displace",
                             (gui->gui_osc1_feedback_y_displace
                              +lfo(gui->gui_osc1_feedback_y_displace_amp
                                   , osc1_feedback_y_displace_theta,0)
                              )*feedback_y_displace_scale);
    shader_osc1.setUniform1f("osc1_feedback_rotate",
                             (gui->gui_osc1_feedback_rotate
                              +lfo(gui->gui_osc1_feedback_rotate_amp, osc1_feedback_rotate_theta,0)
                              )*feedback_rotate_scale);
    
    shader_osc1.setUniform2f("feedback_dimensions"
                             ,ofVec2f(fb_osc1_pp.getWidth()
                                      ,fb_osc1_pp.getHeight()));
    shader_osc1.setUniform1i("osc1_feedback_x_mirror",gui->gui_osc1_feedback_x_mirror);
    shader_osc1.setUniform1i("osc1_feedback_y_mirror",gui->gui_osc1_feedback_y_mirror);
    
    
    //texmod osc1 feedback
    shader_osc1.setUniform1f("texmod_osc1_feedback_pm",gui->texmod_gui_osc1_feedback_pm*feedback_pm_scale);
    shader_osc1.setUniform1f("texmod_osc1_feedback_rm",gui->texmod_gui_osc1_feedback_rm*feedback_rm_scale);
    shader_osc1.setUniform1f("texmod_osc1_feedback_scale",gui->texmod_gui_osc1_feedback_scale*feedback_scale_scale);
    shader_osc1.setUniform1f("texmod_osc1_feedback_x_displace",
                             gui->texmod_gui_osc1_feedback_x_displace*feedback_x_displace_scale);
    shader_osc1.setUniform1f("texmod_osc1_feedback_y_displace",
                             gui->texmod_gui_osc1_feedback_y_displace*feedback_y_displace_scale);
    shader_osc1.setUniform1f("texmod_osc1_feedback_rotate",gui->texmod_gui_osc1_feedback_rotate*feedback_rotate_scale);
    
    
    //osc1 filters
	shader_osc1.setUniform1f("osc1BitCrushMix", gui->osc1BitCrushMix);
	shader_osc1.setUniform1f("osc1BitCrush", gui->osc1BitCrush);
	shader_osc1.setUniform1f("osc1BitCrushDenom", 1.0f / (gui->osc1BitCrush));
    shader_osc1.setUniform1f("osc1_powmod",
                             gui->gui_osc1_powmod
                             +lfo(gui->gui_osc1_powmod_amp,osc1_powmod_theta,0));
    shader_osc1.setUniform1f("osc1_temporal_filter"
                             ,gui->gui_osc1_temporal_filter
                             +lfo(gui->gui_osc1_temporal_filter_amp,osc1_temporal_filter_theta,0));
    shader_osc1.setUniform1i("osc1_overflow_switch",gui->gui_osc1_overflow_switch);
    
    
    //texmod osc1 color and filters
    shader_osc1.setUniform1f("texmod_osc1_powmod",gui->texmod_gui_osc1_powmod);
    shader_osc1.setUniform1f("texmod_osc1_temporal_filter",gui->texmod_gui_osc1_temporal_filter);
    
    //osc1_m
    shader_osc1.setUniform1f("osc1_m_rate",osc1_m_rate);
    shader_osc1.setUniform1f("osc1_m_amp",
                             p_lock_smoothed[24]
                             +gui->gui_osc1_m_amp
                             +lfo(gui->gui_osc1_m_amp_amp,osc1_m_amp_theta,0));
    shader_osc1.setUniform1f("osc1_m_frequency",
                             (p_lock_smoothed[17]
                              +gui->gui_osc1_m_frequency
                              +lfo(gui->gui_osc1_m_frequency_amp,osc1_m_frequency_theta,0)
                              )*osc_frequency_scale);
    shader_osc1.setUniform1f("osc1_m_width",
                             gui->gui_osc1_m_width
                             +lfo(gui->gui_osc1_m_width_amp,osc1_m_width_theta,0));
    shader_osc1.setUniform1f("osc1_m_angle",
                             (p_lock_smoothed[25]
                              +gui->gui_osc1_m_angle
                              )*angle_scale);
    shader_osc1.setUniform1f("osc1_m_rotate",fmod(osc1_m_rotate,2.0f*PI));
    shader_osc1.setUniform1f("osc1_m_spiral",
                             (p_lock_smoothed[38]
                              +gui->gui_osc1_m_spiral
                              +lfo(gui->gui_osc1_m_radial_amp,osc1_m_radial_theta,0)
                              )*spiral_scale);
    
    
    //texmod osc1_m
    shader_osc1.setUniform1f("texmod_osc1_m_amp",gui->texmod_gui_osc1_m_amp*texmod_amp_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_frequency",gui->texmod_gui_osc1_m_frequency*osc_frequency_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_width",gui->texmod_gui_osc1_m_width*texmod_width_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_angle",gui->texmod_gui_osc1_m_angle*texmod_rotate_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_spiral",gui->texmod_gui_osc1_m_spiral*texmod_spiral_scale);
    
    shader_osc1.setUniform1f("osc1_m_modulation_rotate",
                             (p_lock_smoothed[40]
                              +gui->gui_osc1_m_modulation_rotate
                              +lfo(gui->gui_osc1_m_modulation_rotate_amp,osc1_m_modulation_rotate_theta,0)
                              )*modulation_rotate_scale);
    shader_osc1.setUniform1f("osc1_m_pwm",
                             (gui->gui_osc1_m_pwm
                              +lfo(gui->gui_osc1_m_pwm_amp,osc1_m_pwm_theta,0)
                              )*pwm_scale);
    shader_osc1.setUniform1f("osc1_m_pwm2",
                             (gui->gui_osc1_m_pwm2
                              +lfo(gui->gui_osc1_m_pwm2_amp,osc1_m_pwm2_theta,0)
                              )*pwm_scale);
    shader_osc1.setUniform1f("osc1_m_feedback_pm",
                             (p_lock_smoothed[22]
                              +gui->gui_osc1_m_feedback_pm
                              +lfo(gui->gui_osc1_m_feedback_pm_amp,osc1_m_feedback_pm_theta,0)
                              )*feedback_pm_scale);
    
    //texmod osc1_m mods
    shader_osc1.setUniform1f("texmod_osc1_m_modulation_rotate",
                             gui->texmod_gui_osc1_m_modulation_rotate*modulation_rotate_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_pwm",gui->texmod_gui_osc1_m_pwm*pwm_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_pwm2",gui->texmod_gui_osc1_m_pwm2*pwm_scale);
    shader_osc1.setUniform1f("texmod_osc1_m_feedback_pm",
                             gui->texmod_gui_osc1_m_feedback_pm*feedback_pm_scale);
    

	//NEW
	shader_osc1.setUniform1f("osc1BrightBand1", gui->osc1BrightBand1);
	shader_osc1.setUniform1f("osc1SaturationBand1", gui->osc1SaturationBand1);
	shader_osc1.setUniform1f("osc1HueBand1", gui->osc1HueBand1);
	shader_osc1.setUniform1f("osc1BrightBand2", gui->osc1BrightBand2);
	shader_osc1.setUniform1f("osc1SaturationBand2", gui->osc1SaturationBand2);
	shader_osc1.setUniform1f("osc1HueBand2", gui->osc1HueBand2);
	shader_osc1.setUniform1f("osc1BrightBand3", gui->osc1BrightBand3);
	shader_osc1.setUniform1f("osc1SaturationBand3", gui->osc1SaturationBand3);
	shader_osc1.setUniform1f("osc1HueBand3", gui->osc1HueBand3);
	shader_osc1.setUniform1f("osc1BrightBand4", gui->osc1BrightBand4);
	shader_osc1.setUniform1f("osc1SaturationBand4", gui->osc1SaturationBand4);
	shader_osc1.setUniform1f("osc1HueBand4", gui->osc1HueBand4);
	shader_osc1.setUniform1f("osc1BrightBand5", gui->osc1BrightBand5);
	shader_osc1.setUniform1f("osc1SaturationBand5", gui->osc1SaturationBand5);
	shader_osc1.setUniform1f("osc1HueBand5", gui->osc1HueBand5);
	shader_osc1.setUniform1f("osc1BrightBand6", gui->osc1BrightBand6);
	shader_osc1.setUniform1f("osc1SaturationBand6", gui->osc1SaturationBand6);
	shader_osc1.setUniform1f("osc1HueBand6", gui->osc1HueBand6);
	shader_osc1.setUniform1f("osc1BrightBand7", gui->osc1BrightBand7);
	shader_osc1.setUniform1f("osc1SaturationBand7", gui->osc1SaturationBand7);
	shader_osc1.setUniform1f("osc1HueBand7", gui->osc1HueBand7);
	shader_osc1.setUniform1f("osc1BrightBand8", gui->osc1BrightBand8);
	shader_osc1.setUniform1f("osc1SaturationBand8", gui->osc1SaturationBand8);
	shader_osc1.setUniform1f("osc1HueBand8", gui->osc1HueBand8);


    shader_osc1.end();
    
    fb_osc1.end();
    
    
    //osc1 blur and sharpen
    fbo_osc1_blur.begin();
    shader_osc1_blur.begin();
    fb_osc1.draw(0,0);
    
    //blur_tex mod
    if(gui->osc1_texmod_select==0){
        shader_osc1_blur.setUniformTexture("texmod",cam1.getTexture(),10);
        shader_osc1_blur.setUniform2f("texmod_dimensions"
                                      ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc1_texmod_select==1){
        shader_osc1_blur.setUniformTexture("texmod_input",cam2.getTexture(),10);
        shader_osc1_blur.setUniform2f("texmod_dimensions"
                                      ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc1_texmod_select==2){
        shader_osc1_blur.setUniformTexture("texmod_input",ndi_fbo.getTexture(),10);
        shader_osc1_blur.setUniform2f("texmod_dimensions"
                                      ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc1_texmod_select==3){
        shader_osc1_blur.setUniformTexture("texmod_input",fb_osc1_pp.getTexture(),10);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc1_pp.getWidth(),fb_osc1_pp.getHeight()));
    }
    
    shader_osc1_blur.setUniform1f("osc1_blur_amount"
                                  ,gui->gui_osc1_blur_amount
                                  +lfo(gui->gui_osc1_blur_amount_amp,osc1_blur_amount_theta,0));
    shader_osc1_blur.setUniform1f("osc1_blur_radius"
                                  ,gui->gui_osc1_blur_radius
                                  +lfo(gui->gui_osc1_blur_radius_amp,osc1_blur_radius_theta,0));
    
    shader_osc1_blur.setUniform1f("texmod_osc1_blur_amount",gui->texmod_gui_osc1_blur_amount);
    shader_osc1_blur.setUniform1f("texmod_osc1_blur_radius",gui->texmod_gui_osc1_blur_radius);
    
    shader_osc1_blur.setUniform1f("width",ofGetWidth());
    shader_osc1_blur.setUniform1f("height",ofGetHeight());
    
    shader_osc1_blur.end();
    fbo_osc1_blur.end();
    
    fb_osc1.begin();
    shader_osc1_sharpen.begin();
    fbo_osc1_blur.draw(0,0);
    
    //sharpen_tex mod
    if(gui->osc1_texmod_select==0){
        shader_osc1_sharpen.setUniformTexture("texmod",cam1.getTexture(),11);
        shader_osc1_sharpen.setUniform2f("texmod_dimensions"
                                         ,ofVec2f(cam1.getWidth(),cam1.getHeight()));
    }
    
    if(gui->osc1_texmod_select==1){
        shader_osc1_sharpen.setUniformTexture("texmod_input",cam2.getTexture(),11);
        shader_osc1_sharpen.setUniform2f("texmod_dimensions"
                                         ,ofVec2f(cam2.getWidth(),cam2.getHeight()));
    }
    
    if(gui->osc1_texmod_select==2){
        shader_osc1_sharpen.setUniformTexture("texmod_input",ndi_fbo.getTexture(),11);
        shader_osc1_sharpen.setUniform2f("texmod_dimensions"
                                         ,ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
    }
    
    if(gui->osc1_texmod_select==3){
        shader_osc1_sharpen.setUniformTexture("texmod_input",fb_osc1_pp.getTexture(),11);
        shader_osc1.setUniform2f("texmod_dimensions"
                                 ,ofVec2f(fb_osc1_pp.getWidth(),fb_osc1_pp.getHeight()));
    }
    
    shader_osc1_sharpen.setUniform1f("osc1_sharpen_amount"
                                     ,gui->gui_osc1_sharpen_amount
                                     +lfo(gui->gui_osc1_sharpen_amount_amp,osc1_sharpen_amount_theta,0));
    shader_osc1_sharpen.setUniform1f("osc1_sharpen_radius"
                                     ,gui->gui_osc1_sharpen_radius
                                     +lfo(gui->gui_osc1_sharpen_radius_amp,osc1_sharpen_radius_theta,0));
    
    shader_osc1_sharpen.setUniform1f("texmod_osc1_sharpen_amount",gui->texmod_gui_osc1_sharpen_amount);
    shader_osc1_sharpen.setUniform1f("texmod_osc1_sharpen_radius",gui->texmod_gui_osc1_sharpen_radius);
    
    shader_osc1_sharpen.setUniform1f("width",ofGetWidth());
    shader_osc1_sharpen.setUniform1f("height",ofGetHeight());
    
    shader_osc1_sharpen.end();
    fb_osc1.end();
    
    
    
    //fb_osc1.draw(0,0);
    //shader_osc0_blur.begin();
    // shader_osc0_blur.setUniform1f("blurAmnt",10*c7);
    if(gui->osc_draw_switch==0){
        // fb_osc1.draw(0,0,ofGetWidth()/4,ofGetHeight()/4);
        fb_osc0.draw(0,0);
        
        //fbo_osc0_blur.draw(0,0);
        
    }
    
    if(gui->osc_draw_switch==1){
        // fb_osc1.draw(0,0,ofGetWidth()/4,ofGetHeight()/4);
        fb_osc1.draw(0,0);
        
    }
    
    
    //ndi_fbo.draw(0,0);
    
    // shader_osc0_blur.end();
    
    
    //cam1.draw(0,0,80,60);
    
    //don't actually need all of these buffers around, can instead
    //just feed the fb direct into each one and then clear the buffer in between each feedback draw
    
    
    fb_osc0_pp.begin();
    fb_osc0.draw(0,0);
    //fbo_osc0_blur.draw(0,0);
    fb_osc0_pp.end();
    
    fb_osc0.begin();
    ofClear(0,0,0,255);
    fb_osc0.end();
    
    fb_osc1_pp.begin();
    fb_osc1.draw(0,0);
    fb_osc1_pp.end();
    
    fb_osc1.begin();
    ofClear(0,0,0,255);
    fb_osc1.end();
    
    
    ofSetColor(255,255,0);
    string msg="fps="+ofToString(ofGetFrameRate(),2);//+" clear switch"+ofToString(clear_switch,5);//+" z="+ofToString(az,5);
    //ofDrawBitmapString(msg,10,10);
    
    
    
    
    if(p_lock_record_switch==1){
        p_lock_increment++;
        p_lock_increment=p_lock_increment%p_lock_size;
    }
    
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
	
    midiIn.closePort();
    midiIn.removeListener(this);
	
}


//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
    
    // add the latest message to the message queue
    midiMessages.push_back(msg);
    
    // remove any old messages if we have too many
    while(midiMessages.size() > maxMessages) {
        midiMessages.erase(midiMessages.begin());
    }
}

//_____----_-_-_-______---__---_--_----____--_-__-_-

void ofApp::NDI_setup(){
    auto findSource = [](const string &name_or_url) {
        auto sources = ofxNDI::listSources();
        if(name_or_url == "") {
            return make_pair(ofxNDI::Source(), false);
        }
        auto found = find_if(begin(sources), end(sources), [name_or_url](const ofxNDI::Source &s) {
            return ofIsStringInString(s.p_ndi_name, name_or_url) || ofIsStringInString(s.p_url_address, name_or_url);
        });
        if(found == end(sources)) {
            ofLogWarning("ofxNDI") << "no NDI source found by string:" << name_or_url;
            return make_pair(ofxNDI::Source(), false);
        }
        return make_pair(*found, true);
    };
    string name_or_url = "";    // Specify name or address of expected NDI source. In case of blank or not found, receiver will grab default(which is found first) source.
    auto result = findSource(name_or_url);
    if(result.second ? ndi_receiver_.setup(result.first) : ndi_receiver_.setup()) {
        ndi_video_.setup(ndi_receiver_);
    }
    
}
//-------------------------

void ofApp::NDI_update(){
    if(ndi_receiver_.isConnected()) {
        ndi_video_.update();
        if(ndi_video_.isFrameNew()) {
            ndi_video_.decodeTo(ndi_pixels);
        }
    }
    ndi_fbo.begin();
    if(ndi_pixels.isAllocated()) {
        //ofImage ndi_image;
        ofPushMatrix();
        ofTranslate(ndi_fbo.getWidth()/2,ndi_fbo.getHeight()/2);
        ofTranslate(0,0,gui->ndi_scale);
        ofImage(ndi_pixels).draw(-ofImage(ndi_pixels).getWidth()/2,-ofImage(ndi_pixels).getHeight()/2);
        //ofImage(ndi_pixels).draw(0,0);
        ofPopMatrix();
    }
    ndi_fbo.end();
    
    
    
}

float ofApp::lfo(float amp, float rate,int shape){
    
    return amp*(sin(rate)+1.0)*.5;
}

//-----------------------------------
void ofApp::lfo_update(){
    
    //ch1
    //ch1_theta_hue+=.01*(gui->ch1_hue_lfo_theta);
    
    //osc0
    
    //osc0_basic
    osc0_rate_theta+=0.01*gui->gui_osc0_rate_theta;
    osc0_frequency_theta+=0.01*gui->gui_osc0_frequency_theta;
    osc0_amp_theta+=0.01*gui->gui_osc0_amp_theta;
    osc0_width_theta+=0.01*gui->gui_osc0_width_theta;
    osc0_radial_theta+=0.01*gui->gui_osc0_radial_theta;
    
    
    //osc1->osc0 mods
    osc0_rm_theta+=0.01*gui->gui_osc0_rm_theta;
    osc0_pm_theta+=0.01*gui->gui_osc0_pm_theta;
    osc0_pwm_theta+=0.01*gui->gui_osc0_pwm_theta;
    osc0_modulation_rotate2_theta+=0.01*gui->gui_osc0_modulation_rotate2_theta;
    
    
    //osc0_m->osc0 mods
    osc0_m_rm_theta+=0.01*gui->gui_osc0_m_rm_theta;
    osc0_m_pm_theta+=0.01*gui->gui_osc0_m_pm_theta;
    osc0_pwm2_theta+=0.01*gui->gui_osc0_pwm2_theta;
    osc0_modulation_rotate_theta+=0.01*gui->gui_osc0_modulation_rotate_theta;
   
    //osc0 external mod
    osc0_ext_input_pm_theta+=0.01*gui->gui_osc0_ext_input_pm_theta;
    osc0_ext_input_rm_theta+=0.01*gui->gui_osc0_ext_input_rm_theta;
    osc0_ext_input_scale_theta+=0.01*gui->gui_osc0_ext_input_scale_theta;
    osc0_ext_input_x_displace_theta+=0.01*gui->gui_osc0_ext_input_x_displace_theta;
    osc0_ext_input_y_displace_theta+=0.01*gui->gui_osc0_ext_input_y_displace_theta;
    osc0_ext_input_rotate_theta+=0.01*gui->gui_osc0_ext_input_rotate_theta;
    
    //osc0 internal feedback
    osc0_feedback_pm_theta+=0.01*gui->gui_osc0_feedback_pm_theta;
    osc0_feedback_rm_theta+=0.01*gui->gui_osc0_feedback_rm_theta;
    osc0_feedback_scale_theta+=0.01*gui->gui_osc0_feedback_scale_theta;
    osc0_feedback_x_displace_theta+=0.01*gui->gui_osc0_feedback_x_displace_theta;
    osc0_feedback_y_displace_theta+=0.01*gui->gui_osc0_feedback_y_displace_theta;
    osc0_feedback_rotate_theta+=0.01*gui->gui_osc0_feedback_rotate_theta;

    
    //osc0 color and filters
    osc0_powmod_theta+=.01*gui->gui_osc0_powmod_theta;
    osc0_blur_amount_theta+=.01*gui->gui_osc0_blur_amount_theta;
    osc0_blur_radius_theta+=.01*gui->gui_osc0_blur_radius_theta;
    osc0_sharpen_amount_theta+=.01*gui->gui_osc0_sharpen_amount_theta;
    osc0_sharpen_radius_theta+=.01*gui->gui_osc0_sharpen_radius_theta;
    osc0_temporal_filter_theta+=.01*gui->gui_osc0_temporal_filter_theta;
    
    
    //osc0_m
    osc0_m_rate_theta+=0.01*gui->gui_osc0_m_rate_theta;
    osc0_m_frequency_theta+=0.01*gui->gui_osc0_m_frequency_theta;
    osc0_m_amp_theta+=0.01*gui->gui_osc0_m_amp_theta;
    osc0_m_radial_theta+=0.01*gui->gui_osc0_m_radial_theta;
    osc0_m_modulation_rotate_theta+=0.01*gui->gui_osc0_m_modulation_rotate_theta;
    osc0_m_width_theta+=0.01*gui->gui_osc0_m_width_theta;
    osc0_m_pwm_theta+=0.01*gui->gui_osc0_m_pwm_theta;
    osc0_m_pwm2_theta+=0.01*gui->gui_osc0_m_pwm2_theta;
    osc0_m_feedback_pm_theta+=0.01*gui->gui_osc0_m_feedback_pm_theta;
    
    //osc1
    osc1_rate_theta+=0.01*gui->gui_osc1_rate_theta;
    osc1_frequency_theta+=0.01*gui->gui_osc1_frequency_theta;
    osc1_amp_theta+=0.01*gui->gui_osc1_amp_theta;
    osc1_radial_theta+=0.01*gui->gui_osc1_radial_theta;
    osc1_rm_theta+=0.01*gui->gui_osc1_rm_theta;
    osc1_pm_theta+=0.01*gui->gui_osc1_pm_theta;
    osc1_modulation_rotate_theta+=0.01*gui->gui_osc1_modulation_rotate_theta;
    
    osc1_width_theta+=0.01*gui->gui_osc1_width_theta;
    osc1_pwm_theta+=0.01*gui->gui_osc1_pwm_theta;
    osc1_pwm2_theta+=0.01*gui->gui_osc1_pwm2_theta;
    
    //osc1_m
    osc1_m_rate_theta+=0.01*gui->gui_osc1_m_rate_theta;
    osc1_m_frequency_theta+=0.01*gui->gui_osc1_m_frequency_theta;
    osc1_m_amp_theta+=0.01*gui->gui_osc1_m_amp_theta;
    osc1_m_radial_theta+=0.01*gui->gui_osc1_m_radial_theta;
    osc1_m_rm_theta+=0.01*gui->gui_osc1_m_rm_theta;
    osc1_m_pm_theta+=0.01*gui->gui_osc1_m_pm_theta;
    osc1_m_modulation_rotate_theta+=0.01*gui->gui_osc1_m_modulation_rotate_theta;
    
    osc1_m_width_theta+=0.01*gui->gui_osc1_m_width_theta;
    osc1_m_pwm_theta+=0.01*gui->gui_osc1_m_pwm_theta;
    osc1_m_pwm2_theta+=0.01*gui->gui_osc1_m_pwm2_theta;
    
    //osc1 external mod
    osc1_ext_input_pm_theta+=0.01*gui->gui_osc1_ext_input_pm_theta;
    osc1_ext_input_rm_theta+=0.01*gui->gui_osc1_ext_input_rm_theta;
    osc1_ext_input_scale_theta+=0.01*gui->gui_osc1_ext_input_scale_theta;
    osc1_ext_input_x_displace_theta+=0.01*gui->gui_osc1_ext_input_x_displace_theta;
    osc1_ext_input_y_displace_theta+=0.01*gui->gui_osc1_ext_input_y_displace_theta;
    osc1_ext_input_rotate_theta+=0.01*gui->gui_osc1_ext_input_rotate_theta;
    
    //osc1 internal feedback
    osc1_feedback_pm_theta+=0.01*gui->gui_osc1_feedback_pm_theta;
    osc1_feedback_rm_theta+=0.01*gui->gui_osc1_feedback_rm_theta;
    osc1_feedback_scale_theta+=0.01*gui->gui_osc1_feedback_scale_theta;
    osc1_feedback_x_displace_theta+=0.01*gui->gui_osc1_feedback_x_displace_theta;
    osc1_feedback_y_displace_theta+=0.01*gui->gui_osc1_feedback_y_displace_theta;
    osc1_feedback_rotate_theta+=0.01*gui->gui_osc1_feedback_rotate_theta;
    
    
    //osc1 color and filters
    osc1_powmod_theta+=.01*gui->gui_osc1_powmod_theta;
    osc1_blur_amount_theta+=.01*gui->gui_osc1_blur_amount_theta;
    osc1_blur_radius_theta+=.01*gui->gui_osc1_blur_radius_theta;
    osc1_sharpen_amount_theta+=.01*gui->gui_osc1_sharpen_amount_theta;
    osc1_sharpen_radius_theta+=.01*gui->gui_osc1_sharpen_radius_theta;
    osc1_temporal_filter_theta+=.01*gui->gui_osc1_temporal_filter_theta;
    
    
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    
    
    
    
    
    
    if(key=='q'){qq+=.01;cout<<qq<<endl;}
    if(key=='w'){qq-=.01;cout<<qq<<endl;}
    
    if(key=='0'){
        
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
    
    
}

//--------------------------------------------------------------
//---------------------
void ofApp:: midibiz(){
    /*
    for(unsigned int i = 0; i < midiMessages.size(); ++i) {
        
        ofxMidiMessage &message = midiMessages[i];
        
        
        
        
        
        
        if(message.status < MIDI_SYSEX) {
            //text << "chan: " << message.channel;
            if(message.status == MIDI_CONTROL_CHANGE) {
                //  cout << "message.control"<< message.control<< endl;
                //  cout << "message.value"<< message.value<< endl;
                
                if(message.control==45){
                    if(message.value==127){
                        p_lock_record_switch=1;
                    }
                    
                    
                    if(message.value==0){
                        p_lock_record_switch=0;
                    }
                }
                
                
                
                
                
                
                
                //osc m camera pm switches
                
                if(message.control==38){
                    if(message.value==127){
                        osc_cam_pm_switch=1;
                    }
                    
                    if(message.value==0){
                        osc_cam_pm_switch=0;
                    }
                }
                
                //rm/pm scaling switches
                
                
                
                //osc0
                if(message.control==34){
                    if(message.value==127){
                        osc0_pm_rm_switch=1;
                    }
                    
                    if(message.value==0){
                        osc0_pm_rm_switch=0;
                    }
                }
                
                if(message.control==50){
                    if(message.value==127){
                        osc0_pm_rm_switch=2;
                    }
                    
                    if(message.value==0){
                        osc0_pm_rm_switch=0;
                    }
                }
                
                if(message.control==66){
                    if(message.value==127){
                        osc0_pm_rm_switch=3;
                    }
                    
                    if(message.value==0){
                        osc0_pm_rm_switch=0;
                    }
                }
                
                //osc1
                if(message.control==37){
                    if(message.value==127){
                        osc1_pm_rm_switch=1;
                    }
                    
                    if(message.value==0){
                        osc1_pm_rm_switch=0;
                    }
                }
                
                if(message.control==53){
                    if(message.value==127){
                        osc1_pm_rm_switch=2;
                    }
                    
                    if(message.value==0){
                        osc1_pm_rm_switch=0;
                    }
                }
                
                if(message.control==69){
                    if(message.value==127){
                        osc1_pm_rm_switch=3;
                    }
                    
                    if(message.value==0){
                        osc1_pm_rm_switch=0;
                    }
                }
                
                
                
                //overflow switches
                if(message.control==60){
                    if(message.value==127){
                        overflow_switch=1;
                    }
                    
                    if(message.value==0){
                        overflow_switch=0;
                    }
                }
                
                if(message.control==61){
                    if(message.value==127){
                        overflow_switch=2;
                    }
                    
                    if(message.value==0){
                        overflow_switch=0;
                    }
                }
                
                if(message.control==62){
                    if(message.value==127){
                        overflow_switch=3;
                    }
                    
                    if(message.value==0){
                        overflow_switch=0;
                    }
                }
                
                
                
                
                if(message.control==46){
                    if(message.value==127){
                        draw_switch=1;
                    }
                    
                    if(message.value==0){
                        draw_switch=0;
                    }
                }
                
                
                if(message.control==32){
                    if(message.value==127){
                        osc0_mod_switch=1;
                        
                    }
                    
                    if(message.value==0){
                        osc0_mod_switch=0;
                        
                    }
                }
                
         
                if(message.control==35){
                    if(message.value==127){
                        osc1_mod_switch=1;
                        
                    }
                    
                    if(message.value==0){
                        osc1_mod_switch=0;
                        
                    }
                }
                
         
                
                //osc0 axis switches
                if(message.control==33){
                    if(message.value==127){
                        osc0_axis_switch=1;
                        
                    }
                    
                    if(message.value==0){
                        osc0_axis_switch=0;
                        
                    }
                }
                
                if(message.control==49){
                    if(message.value==127){
                        osc0_axis_switch=2;
                        
                    }
                    
                    if(message.value==0){
                        osc0_axis_switch=0;
                        
                    }
                }
                
                if(message.control==65){
                    if(message.value==127){
                        osc0_axis_switch=3;
                        
                    }
                    
                    if(message.value==0){
                        osc0_axis_switch=0;
                        
                    }
                }
                
                //osc1_m axis switches
                if(message.control==36){
                    if(message.value==127){
                        osc1_axis_switch=1;
                        
                        
                    }
                    
                    if(message.value==0){
                        osc1_axis_switch=0;
                        
                    }
                }
                
                if(message.control==52){
                    if(message.value==127){
                        osc1_axis_switch=2;
                        
                    }
                    
                    if(message.value==0){
                        osc1_axis_switch=0;
                        
                    }
                }
                
                if(message.control==68){
                    if(message.value==127){
                        osc1_axis_switch=3;
                        //cout<<"YOOOOO"<<endl;
                        
                    }
                    
                    if(message.value==0){
                        osc1_axis_switch=0;
                        
                    }
                }
                
                
                //shapes
                
                //osc0
                if(message.control==48){
                    if(osc0_mod_switch==0){
                        if(message.value==127){
                            osc0_shape=1;
                            
                        }
                        
                        if(message.value==0){
                            osc0_shape=0;
                            
                        }
                    }
                    
                    if(osc0_mod_switch==1){
                        if(message.value==127){
                            osc0_m_shape=1;
                            
                        }
                        
                        if(message.value==0){
                            osc0_m_shape=0;
                            
                        }
                    }
                }
                
                if(message.control==64){
                    if(osc0_mod_switch==0){
                        if(message.value==127){
                            osc0_shape=2;
                            
                        }
                        
                        if(message.value==0){
                            osc0_shape=0;
                            
                        }
                    }
                    
                    if(osc0_mod_switch==1){
                        if(message.value==127){
                            osc0_m_shape=2;
                            
                        }
                        
                        if(message.value==0){
                            osc0_m_shape=0;
                            
                        }
                    }
                }
                
                //osc1
                if(message.control==51){
                    if(osc1_mod_switch==0){
                        if(message.value==127){
                            osc1_shape=1;
                            
                        }
                        
                        if(message.value==0){
                            osc1_shape=0;
                            
                        }
                    }
                    
                    if(osc1_mod_switch==1){
                        if(message.value==127){
                            osc1_m_shape=1;
                            
                        }
                        
                        if(message.value==0){
                            osc1_m_shape=0;
                            
                        }
                    }
                }
                
                if(message.control==67){
                    if(osc1_mod_switch==0){
                        if(message.value==127){
                            osc1_shape=2;
                            
                        }
                        
                        if(message.value==0){
                            osc1_shape=0;
                            
                        }
                    }
                    
                    if(osc1_mod_switch==1){
                        if(message.value==127){
                            osc1_m_shape=2;
                            
                        }
                        
                        if(message.value==0){
                            osc1_m_shape=0;
                            
                        }
                    }
                }
                
                //osc_rate_swithce
                
                if(message.control==39){
                    if(message.value==127){
                        osc_m_rate_switch=1;
                    }
                    if(message.value==0){
                        osc_m_rate_switch=0;
                    }
                }
                
                
                //nanokontrol2 controls
                if(message.control==16){
                    
                    if(osc0_mod_switch==0){
                        p_lock[0][p_lock_increment]=(message.value-63.0)/63.0;
                        
                    }
                    
                    if(osc0_mod_switch==1){
                        p_lock[16][p_lock_increment]=(message.value-63.0)/63.0;
                        
                    }
                    
                }
                
                
                
                
                if(message.control==17){
                    
                    if(osc0_mod_switch==0){
                        
                        
                        p_lock[1][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    if(osc0_mod_switch==1){
                        
                        
                        p_lock[17][p_lock_increment]=(message.value)/127.00;
                        
                        
                    }
                }
                
                
                if(message.control==18){
                    
                    if(osc0_mod_switch==0){
                        
                        p_lock[2][p_lock_increment]=(message.value-63.0)/63.00;
                        
                    }
                    
                    if(osc0_mod_switch==1){
                        
                        p_lock[18][p_lock_increment]=(message.value-63.0)/63.00;
                        
                        
                        
                    }
                }
                
                
                if(message.control==19){
                    
                    if(osc1_mod_switch==0){
                        
                        
                        p_lock[3][p_lock_increment]=(message.value-63.0)/63.00;
                        
                    }
                    
                    if(osc1_mod_switch==1){
                        p_lock[19][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                }
                
                
                if(message.control==20){
                    
                    if(osc1_mod_switch==0){
                        p_lock[4][p_lock_increment]=(message.value)/127.00;
                    }
                    if(osc1_mod_switch==1){
                        p_lock[20][p_lock_increment]=(message.value)/127.00;
                    }
                }
                
                
                if(message.control==21){
                    
                    if(osc1_mod_switch==0){
                        
                        
                        p_lock[5][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                    
                    if(osc1_mod_switch==1){
                        
                        
                        p_lock[21][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                }
                
                
                if(message.control==22){
                    
                    if(osc_cam_pm_switch==0){
                        p_lock[6][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    if(osc_cam_pm_switch==1){
                        p_lock[22][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    
                }
                
                
                if(message.control==23){
                    if(osc_m_rate_switch==0){
                        
                        
                        p_lock[7][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                    if(osc_m_rate_switch==1){
                        
                        
                        p_lock[23][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                    //osc0_rate_mod=(message.value)/127.0;
                    
                }
                
                if(message.control==120){
                    
                    if(osc0_mod_switch==0){
                        p_lock[8][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    if(osc0_mod_switch==1){
                        
                        p_lock[24][p_lock_increment]=(message.value)/127.0f;
                    }
                    
                    
                    
                }
                
                if(message.control==121){
                    
                    if(osc0_axis_switch==0){
                        if(osc0_mod_switch==0){
                            
                            
                            p_lock[9][p_lock_increment]=(message.value)/127.0;
                        }
                        
                        if(osc0_mod_switch==1){
                            
                            
                            p_lock[25][p_lock_increment]=(message.value)/127.0;
                        }
                    }
                    
                    if(osc0_axis_switch==1){
                        if(osc0_mod_switch==0){
                            osc0_spiral=.05*(message.value)/127.0;
                            
                            p_lock[32][p_lock_increment]=(message.value)/127.0;
                        }
                        
                        if(osc0_mod_switch==1){
                            p_lock[38][p_lock_increment]=(message.value)/127.0;
                        }
                    }
                    
                    if(osc0_axis_switch==2){
                        if(osc0_mod_switch==0){
                            p_lock[33][p_lock_increment]=(message.value-63.0)/63.0;
                        }
                        
                        if(osc0_mod_switch==1){
                            p_lock[39][p_lock_increment]=(message.value-63.0)/63.0;
                        }
                    }
                    
                    if(osc0_axis_switch==3){
                        if(osc0_mod_switch==0){
                            //osc0_modulation_rotate=(message.value-63.0)/63.0;
                            
                            p_lock[34][p_lock_increment]=(message.value)/127.0;
                            
                        }
                        
                        if(osc0_mod_switch==1){
                            //osc0_m_modulation_rotate=(message.value-63.0)/63.0;
                            
                            p_lock[40][p_lock_increment]=(message.value)/127.0;
                        }
                        
                    }
                }
                
                if(message.control==122){
                    //c11=(message.value-63.0)/63.00;
                    
                    if(osc0_mod_switch==0){
                        osc0_pm=(message.value)/127.00;
                        
                        p_lock[10][p_lock_increment]=(message.value)/127.00;
                        
                        //osc0_pm=(message.value-63.0)/63.0;
                    }
                    
                    if(osc0_mod_switch==1){
                        osc0_m_pm=(message.value)/127.00;
                        
                        p_lock[26][p_lock_increment]=(message.value)/127.00;
                    }
                }
                
                
                if(message.control==123){
                    // c12=(message.value-63.0)/63.00;
                    
                    if(osc1_mod_switch==0){
                        osc1_amp=(message.value)/127.00;
                        
                        p_lock[11][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    if(osc1_mod_switch==1){
                        osc1_m_amp=(message.value)/127.00;
                        
                        p_lock[27][p_lock_increment]=(message.value)/127.00;
                    }
                }
                
                
                
                if(message.control==124){
                   
                    //c10=(message.value)/127.00;
                    if(osc1_axis_switch==0){
                        if(osc1_mod_switch==0){
                            osc1_angle=(message.value-63.0)/63.0;
                            
                            p_lock[12][p_lock_increment]=(message.value-63.0f)/63.0f;
                            
                        }
                        
                        if(osc1_mod_switch==1){
                            osc1_m_angle=(message.value-63.0)/63.0;
                            
                            p_lock[28][p_lock_increment]=(message.value-63.0f)/63.0f;
                            
                            
                        }
                    }
                    
                    if(osc1_axis_switch==1){
                        if(osc1_mod_switch==0){
                            p_lock[35][p_lock_increment]=(message.value)/127.0;
                            
                        }
                        
                        if(osc1_mod_switch==1){
                            //osc1_m_spiral=.05*(message.value-63.0)/63.0;
                            p_lock[41][p_lock_increment]=(message.value)/127.0;
                        }
                    }
                    
                    if(osc1_axis_switch==2){
                        if(osc1_mod_switch==0){
                            p_lock[36][p_lock_increment]=(message.value-63.0)/63.0;
                        }
                        
                        if(osc1_mod_switch==1){
                            p_lock[42][p_lock_increment]=(message.value-63.0)/63.0;
                        }
                    }
                    
                    if(osc1_axis_switch==3){
                        if(osc1_mod_switch==0){
                            p_lock[37][p_lock_increment]=(message.value)/127.0;
                        }
                        
                        if(osc1_mod_switch==1){
                            p_lock[43][p_lock_increment]=(message.value)/127.0;
                        }
                        
                    }
                    
                    
                }
                
                if(message.control==125){
                    // c14=(message.value-63.0)/63.0;
                   
                    if(osc1_mod_switch==0){
                        osc1_pm=(message.value)/127.00;
                        
                        p_lock[13][p_lock_increment]=(message.value)/127.00;
                        //osc1_pm=(message.value-63.0)/63.0;
                    }
                    
                    if(osc1_mod_switch==1){
                        osc1_m_pm=(message.value)/127.00;
                        
                        p_lock[29][p_lock_increment]=(message.value)/127.00;
                        //osc1_pm=(message.value-63.0)/63.0;
                    }
                }
                
                if(message.control==126){
                    //c15=(message.value-63.0)/63.0;
                    osc1_cam_pm=(message.value)/127.00;
                    if(osc_cam_pm_switch==0){
                        p_lock[14][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    if(osc_cam_pm_switch==1){
                        p_lock[30][p_lock_increment]=(message.value)/127.00;
                    }
                    
                    
                    
                }
                
                if(message.control==127){
                    if(osc_m_rate_switch==0){
                        osc1_rate_mod=(message.value-63.0)/63.00;
                        
                        p_lock[15][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                    if(osc_m_rate_switch==1){
                        osc1_m_rate_mod=(message.value-63.0)/63.00;
                        
                        p_lock[31][p_lock_increment]=(message.value-63.0)/63.00;
                    }
                    
                }
                
                
                
                
                
                
                
                
                if(message.control==58){
                    if(message.value==127){
                        for(int i=0;i<p_lock_number;i++){
                            for(int j=0;j<p_lock_size;j++){
                                p_lock[i][j]=0;
                                
                                p_lock[1][j]=.5;
                                p_lock[8][j]=1.0;
                                
                                p_lock[17][j]=.5;
                                p_lock[24][j]=1.0;
                                
                                p_lock[4][j]=.5;
                                p_lock[11][j]=1.0;
                                
                                p_lock[20][j]=.5;
                                p_lock[27][j]=1.0;
                            }
                            
                            
                        }
                        
                        //do some initializing
                        
                    }	
                }
                
                
                //text << "\tctl: " << message.control;
                //ofDrawRectangle(x + ofGetWidth()*0.2, y + 12,
                //	ofMap(message.control, 0, 127, 0, ofGetWidth()*0.2), 10);
            }
            
            
            //text << " "; // pad for delta print
        }//
        
        
    }
    */
    
    
    
    
}
