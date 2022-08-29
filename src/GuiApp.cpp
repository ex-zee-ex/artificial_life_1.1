/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"




void GuiApp::setup(){
    
    ofBackground(0);
    //floatValue=0.0;
    
    gui.setup();
    
}
  //----------------------------------
    void GuiApp::update() {
       
    }


//------------------------------
    void GuiApp::draw() {
        
        float osc_pm_range=100;
        
        
        
        auto mainSettings = ofxImGui::Settings();
        
        ImGui::StyleColorsAndrei();
        
        ofSetBackgroundColor(backgroundColor);
        
        gui.begin();
       
        
        int gui_hscaler=170;
        int gui_vscaler=80;
        
        
        
        ImGui::SetNextWindowPos(ImVec2(0*gui_hscaler, 0*gui_vscaler), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
        
        if (ofxImGui::BeginWindow("osc0", mainSettings, false))
        {
            //ImGui::Text("nothin happening here yet");
            if (ImGui::CollapsingHeader("parameters")){
                const float spacing = 10;
                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 5));
                ImGui::PushStyleVar(ImGuiStyleVar_IndentSpacing, 200.0f);
                //ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(200, 0));
                //input select
                //ImGui::PushItemWidth(20);
                ImGui::Checkbox("texmod", &texmod_osc0_switch);
                
                ImGui::Text("select texmod ");
                const char* items2[] = { "cam1","cam2","ndi","internal feedback" };
                static int item_current2 = 0;
                ImGui::Combo("combo2", &item_current2, items2, IM_ARRAYSIZE(items2));
                if(item_current2==0){osc0_texmod_select=0;}
                if(item_current2==1){osc0_texmod_select=1;}
                if(item_current2==2){osc0_texmod_select=2;}
                if(item_current2==3){osc0_texmod_select=3;}
                ImGui::SliderFloat("texmod scale", &osc0_texmod_scale, -1, 1);
                
                
                if (ImGui::CollapsingHeader("basic")){
                    const char* items[] = { "sin","square", "saw","ramp","triangle","parabolic","cubic","quartic", "quintic" };
                    static int item_current = 0;
                    ImGui::Combo("osc0 waveshape", &item_current, items, IM_ARRAYSIZE(items));
                    if(item_current==0){gui_osc0_shape=0;}
                    if(item_current==1){gui_osc0_shape=1;}
                    if(item_current==2){gui_osc0_shape=2;}
                    if(item_current==3){gui_osc0_shape=3;}
					if (item_current == 4) { gui_osc0_shape = 4; }
					if (item_current == 5) { gui_osc0_shape = 5; }
					if (item_current == 6) { gui_osc0_shape = 6; }
					if (item_current == 7) { gui_osc0_shape = 7; }
					if (item_current == 8) { gui_osc0_shape = 8; }
                    
                    ImGui::SliderFloat("rate", &gui_osc0_rate, -1,1);
                    
                    if(texmod_osc0_switch==false){
                        ImGui::SliderFloat("frequency", &gui_osc0_frequency, 0,1);
                        ImGui::SliderFloat("amp", &gui_osc0_amp, 0, 1);
                        ImGui::SliderFloat("osc width", &gui_osc0_width, -1, 1);
                        ImGui::SliderFloat("angle", &gui_osc0_angle, -1, 1);
                        ImGui::SliderFloat("radial", &gui_osc0_spiral, -1, 1);
                    }
                    
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod frequency", &texmod_gui_osc0_frequency, -1,1);
                        ImGui::SliderFloat("texmod amp", &texmod_gui_osc0_amp, -1, 1);
                        ImGui::SliderFloat("texmod osc width", &texmod_gui_osc0_width, -1, 1);
                        ImGui::SliderFloat("texmod angle", &texmod_gui_osc0_angle, -1, 1);
                        ImGui::SliderFloat("texmod radial", &texmod_gui_osc0_spiral, -1, 1);
                    }
                    
                    ImGui::SliderFloat("rotate", &gui_osc0_rotate, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("osc1 mods")){
                    
                    ImGui::SliderFloat("rate mod", &gui_osc0_rate_mod, -1,1);
                    
                    if(texmod_osc0_switch==false){
                        ImGui::SliderFloat("osc1 rm", &gui_osc0_rm, -1, 1);
                        ImGui::SliderFloat("osc1 pm", &gui_osc0_pm, -1,1);
                        ImGui::SliderFloat("pm cutoff", &gui_osc0_pm_cutoff, 0,1);
                        ImGui::SliderFloat("pwm", &gui_osc0_pwm, -1, 1);
                        ImGui::SliderFloat("rotate_mod2", &gui_osc0_modulation_rotate2, -1, 1);
                    }
                    
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod osc1 rm", &texmod_gui_osc0_rm, -1, 1);
                        ImGui::SliderFloat("texmod osc1 pm", &texmod_gui_osc0_pm, -1,1);
                        ImGui::SliderFloat("texmod pm cutoff", &texmod_gui_osc0_pm_cutoff, -1,1);
                        ImGui::SliderFloat("texmod pwm", &texmod_gui_osc0_pwm, -1, 1);
                        ImGui::SliderFloat("texmod rotate_mod2", &texmod_gui_osc0_modulation_rotate2, -1, 1);
                    }
                }
                
                
                
                if (ImGui::CollapsingHeader("osc0_m mods")){
                    if(texmod_osc0_switch==false){
                        ImGui::SliderFloat("osc0_m rm", &gui_osc0_m_rm, -1, 1);
                        ImGui::SliderFloat("osc0_mpm", &gui_osc0_m_pm, -1, 1);
                        ImGui::SliderFloat("pwm 2", &gui_osc0_pwm2, -1, 1);
                        ImGui::SliderFloat("rotate_mod", &gui_osc0_modulation_rotate, -1, 1);
                    }
                    
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod osc0_m rm", &texmod_gui_osc0_m_rm, -1, 1);
                        ImGui::SliderFloat("texmod osc0_m pm", &texmod_gui_osc0_m_pm, -1, 1);
                        ImGui::SliderFloat("texmod pwm 2", &texmod_gui_osc0_pwm2, -1, 1);
                        ImGui::SliderFloat("texmod rotate_mod", &texmod_gui_osc0_modulation_rotate, -1, 1);
                    }
                }
                
                if (ImGui::CollapsingHeader("external input mods")){
                    
                    if(texmod_osc0_switch==false){
                        ImGui::SliderFloat("ext_input pm", &gui_osc0_ext_input_pm, -1,1);
                        ImGui::SliderFloat("ext_input rm", &gui_osc0_ext_input_rm, -1,1);
                        ImGui::SliderFloat("ext_input scale", &gui_osc0_ext_input_scale, -1, 1);
                        ImGui::SliderFloat("ext_input x displace", &gui_osc0_ext_input_x_displace, -1, 1);
                        ImGui::SliderFloat("ext_input y displace", &gui_osc0_ext_input_y_displace, -1, 1);
                        ImGui::SliderFloat("ext_input rotate", &gui_osc0_ext_input_rotate, -1, 1);
                    }
                        
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod ext_input pm", &texmod_gui_osc0_ext_input_pm, -1,1);
                        ImGui::SliderFloat("texmod ext_input rm", &texmod_gui_osc0_ext_input_rm, -1,1);
                        ImGui::SliderFloat("texmod ext_input scale", &texmod_gui_osc0_ext_input_scale, -1, 1);
                        ImGui::SliderFloat("texmod ext_input x displace", &texmod_gui_osc0_ext_input_x_displace, -1, 1);
                        ImGui::SliderFloat("texmod ext_input y displace", &texmod_gui_osc0_ext_input_y_displace, -1, 1);
                        ImGui::SliderFloat("texmod vext_input rotate", &texmod_gui_osc0_ext_input_rotate, -1, 1);
                    }
                    
                    ImGui::Checkbox("ext_input x mirror", &gui_osc0_ext_input_x_mirror);
                    ImGui::Checkbox("ext_input y mirror", &gui_osc0_ext_input_y_mirror);
                }
                
                if (ImGui::CollapsingHeader("internal feedback mods")){
                   
                    if(texmod_osc0_switch==false){
                        ImGui::SliderFloat("feedback pm", &gui_osc0_feedback_pm, -1,1);
                        ImGui::SliderFloat("feedback rm", &gui_osc0_feedback_rm, -1,1);
                        ImGui::SliderFloat("feedback scale", &gui_osc0_feedback_scale, -1,1);
                        ImGui::SliderFloat("feedback x displace", &gui_osc0_feedback_x_displace, -1,1);
                        ImGui::SliderFloat("feedback y displace", &gui_osc0_feedback_y_displace, -1,1);
                        ImGui::SliderFloat("feedback rotate", &gui_osc0_feedback_rotate, -1,1);
                    }
                        
                        
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod feedback pm", &texmod_gui_osc0_feedback_pm, -1,1);
                        ImGui::SliderFloat("texmod feedback rm", &texmod_gui_osc0_feedback_rm, -1,1);
                        ImGui::SliderFloat("texmod feedback scale", &texmod_gui_osc0_feedback_scale, -1,1);
                        ImGui::SliderFloat("texmod feedback x displace", &texmod_gui_osc0_feedback_x_displace, -1,1);
                        ImGui::SliderFloat("texmod feedback y displace", &texmod_gui_osc0_feedback_y_displace, -1,1);
                        ImGui::SliderFloat("texmod feedback rotate", &texmod_gui_osc0_feedback_rotate, -1,1);
                    }
                    
                    ImGui::Checkbox("feedback x mirror", &gui_osc0_feedback_x_mirror);
                    ImGui::Checkbox("feedback y mirror", &gui_osc0_feedback_y_mirror);
                }
                
				if (ImGui::CollapsingHeader("colorizer solarizer")) {
					ImGui::SliderFloat("bright band1", &osc0BrightBand1, -1, 1);
					ImGui::SliderFloat("sat band1", &osc0SaturationBand1, 0, 1);
					ImGui::SliderFloat("hue band1", &osc0HueBand1, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band2", &osc0BrightBand2, -1, 1);
					ImGui::SliderFloat("sat band2", &osc0SaturationBand2, 0, 1);
					ImGui::SliderFloat("hue band2", &osc0HueBand2, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band3", &osc0BrightBand3, -1, 1);
					ImGui::SliderFloat("sat band3", &osc0SaturationBand3, 0, 1);
					ImGui::SliderFloat("hue band3", &osc0HueBand3, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band4", &osc0BrightBand4, -1, 1);
					ImGui::SliderFloat("sat band4", &osc0SaturationBand4, 0, 1);
					ImGui::SliderFloat("hue band4", &osc0HueBand4, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band5", &osc0BrightBand5, -1, 1);
					ImGui::SliderFloat("sat band5", &osc0SaturationBand5, 0, 1);
					ImGui::SliderFloat("hue band5", &osc0HueBand5, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band6", &osc0BrightBand6, -1, 1);
					ImGui::SliderFloat("sat band6", &osc0SaturationBand6, 0, 1);
					ImGui::SliderFloat("hue band6", &osc0HueBand6, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band7", &osc0BrightBand7, -1, 1);
					ImGui::SliderFloat("sat band7", &osc0SaturationBand7, 0, 1);
					ImGui::SliderFloat("hue band7", &osc0HueBand7, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band8", &osc0BrightBand8, -1, 1);
					ImGui::SliderFloat("sat band8", &osc0SaturationBand8, 0, 1);
					ImGui::SliderFloat("hue band8", &osc0HueBand8, 0, 1);
				}

                if (ImGui::CollapsingHeader("filters")){
                    
                    if(texmod_osc0_switch==false){
						ImGui::SliderFloat("bitcrush mix", &osc0BitCrushMix, 0, 1);
						ImGui::SliderInt("bitcrush amount", &osc0BitCrush, 0, bitCrushC);
                        ImGui::SliderFloat("powmod", &gui_osc0_powmod, 0, 5);
                        ImGui::SliderFloat("temporal_filter", &gui_osc0_temporal_filter, -2,2);
                        ImGui::SliderFloat("blur_amount", &gui_osc0_blur_amount, -2,2);
                        ImGui::SliderFloat("blur_radius", &gui_osc0_blur_radius, 0,10);
                        ImGui::SliderFloat("sharpen_amount", &gui_osc0_sharpen_amount, -.5,.5);
                        ImGui::SliderFloat("sharpen_radius", &gui_osc0_sharpen_radius, 0,10);
                    }
                        
                    if(texmod_osc0_switch==true){
                        ImGui::SliderFloat("texmod powmod", &texmod_gui_osc0_powmod, 0, 5);
                        ImGui::SliderFloat("texmod temporal_filter", &texmod_gui_osc0_temporal_filter, -2,2);
                        ImGui::SliderFloat("texmod blur_amount", &texmod_gui_osc0_blur_amount, -2,2);
                        ImGui::SliderFloat("texmod blur_radius", &texmod_gui_osc0_blur_radius, -10,10);
                        ImGui::SliderFloat("texmod sharpen_amount", &texmod_gui_osc0_sharpen_amount, -1,1);
                        ImGui::SliderFloat("texmod sharpen_radius", &texmod_gui_osc0_sharpen_radius, -10,10);
                    }
   
                    
                    const char* items2[] = { "clamp","wrap","foldover" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){gui_osc0_overflow_switch=0;}
                    if(item_current2==1){gui_osc0_overflow_switch=1;}
                    if(item_current2==2){gui_osc0_overflow_switch=2;}
                    if(item_current2==3){gui_osc0_overflow_switch=3;}
                }
				
				

                ImGui::PopStyleVar(2);
            }
            ImGui::Separator();
            
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Look For Originality");
                
                const float spacing = 10;
                //ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(spacing, spacing));
                
                
                if (ImGui::CollapsingHeader("lfo basic")){
                    ImGui::SliderFloat("rate rate (lol)", &gui_osc0_rate_theta, 0, 20);
                    ImGui::SliderFloat("rate amp", &gui_osc0_rate_amp, -10, 10);
                    ImGui::SliderFloat("frequency rate", &gui_osc0_frequency_theta, 0, 20);
                    ImGui::SliderFloat("frequency amp", &gui_osc0_frequency_amp, -1, 1);
                    ImGui::SliderFloat("amp rate", &gui_osc0_amp_theta, 0, 20);
                    ImGui::SliderFloat("amp amp (lololol)", &gui_osc0_amp_amp, -1, 1);
                    ImGui::SliderFloat("width rate", &gui_osc0_width_theta, 0, 20);
                    ImGui::SliderFloat("width amp", &gui_osc0_width_amp, -1, 1);
                    ImGui::SliderFloat("radial rate", &gui_osc0_radial_theta, 0, 20);
                    ImGui::SliderFloat("radial amp", &gui_osc0_radial_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("lfo osc1 mods")){
                    ImGui::SliderFloat("osc1 rm rate", &gui_osc0_rm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 rm amp", &gui_osc0_rm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 pm rate", &gui_osc0_pm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 pm amp", &gui_osc0_pm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 pwm rate", &gui_osc0_pwm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 pwm amp", &gui_osc0_pwm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 mod rotate rate", &gui_osc0_modulation_rotate2_theta, 0, 20);
                    ImGui::SliderFloat("osc1 mod rotate amp", &gui_osc0_modulation_rotate2_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("lfo osc0_m mods")){
                    ImGui::SliderFloat("osc0_m rm rate", &gui_osc0_m_rm_theta, 0, 20);
                    ImGui::SliderFloat("osc0_m rm amp", &gui_osc0_m_rm_amp, -1, 1);
                    ImGui::SliderFloat("osc0_m pm rate", &gui_osc0_m_pm_theta, 0, 20);
                    ImGui::SliderFloat("osc0_m pm amp", &gui_osc0_m_pm_amp, -1, 1);
                    ImGui::SliderFloat("osc0_m pwm2 rate", &gui_osc0_pwm2_theta, 0, 20);
                    ImGui::SliderFloat("osc0_m pwm2 amp", &gui_osc0_pwm2_amp, -1, 1);
                    ImGui::SliderFloat("osc0_m mod rotate rate", &gui_osc0_modulation_rotate_theta, 0, 20);
                    ImGui::SliderFloat("osc0_m mod rotate amp", &gui_osc0_modulation_rotate_amp, -1, 1);
                }
               
                if (ImGui::CollapsingHeader("lfo external input mods")){
                    ImGui::SliderFloat("ext input pm rate", &gui_osc0_ext_input_pm_theta, 0, 20);
                    ImGui::SliderFloat("ext input pm amp", &gui_osc0_ext_input_pm_amp, -1, 1);
                    ImGui::SliderFloat("ext input rm rate", &gui_osc0_ext_input_rm_theta, 0, 20);
                    ImGui::SliderFloat("ext input rm amp", &gui_osc0_ext_input_rm_amp, -1, 1);
                    ImGui::SliderFloat("ext input scale rate", &gui_osc0_ext_input_scale_theta, 0, 20);
                    ImGui::SliderFloat("ext input scale amp", &gui_osc0_ext_input_scale_amp, -1, 1);
                    ImGui::SliderFloat("ext input x displace rate", &gui_osc0_ext_input_x_displace_theta, 0, 20);
                    ImGui::SliderFloat("ext input x displace amp", &gui_osc0_ext_input_x_displace_amp, -1, 1);
                    ImGui::SliderFloat("ext input y displace rate", &gui_osc0_ext_input_y_displace_theta, 0, 20);
                    ImGui::SliderFloat("ext input y displace amp", &gui_osc0_ext_input_y_displace_amp, -1, 1);
                    ImGui::SliderFloat("ext input rotate rate", &gui_osc0_ext_input_rotate_theta, 0, 20);
                    ImGui::SliderFloat("ext input rotate amp", &gui_osc0_ext_input_rotate_amp, -1, 1);
                    
                }
                
                if (ImGui::CollapsingHeader("lfo internal feedback mods")){
                    ImGui::SliderFloat("feedback pm rate", &gui_osc0_feedback_pm_theta, 0, 20);
                    ImGui::SliderFloat("feedback pm amp", &gui_osc0_feedback_pm_amp, -1, 1);
                    ImGui::SliderFloat("feedback rm rate", &gui_osc0_feedback_rm_theta, 0, 20);
                    ImGui::SliderFloat("feedback rm amp", &gui_osc0_feedback_rm_amp, -1, 1);
                    ImGui::SliderFloat("feedback scale rate", &gui_osc0_feedback_scale_theta, 0, 20);
                    ImGui::SliderFloat("feedback scale amp", &gui_osc0_feedback_scale_amp, -1, 1);
                    ImGui::SliderFloat("feedback x displace rate", &gui_osc0_feedback_x_displace_theta, 0, 20);
                    ImGui::SliderFloat("feedback x displace amp", &gui_osc0_feedback_x_displace_amp, -1, 1);
                    ImGui::SliderFloat("feedback y displace rate", &gui_osc0_feedback_y_displace_theta, 0, 20);
                    ImGui::SliderFloat("feedback y displace amp", &gui_osc0_feedback_y_displace_amp, -1, 1);
                    ImGui::SliderFloat("feedback rotate rate", &gui_osc0_feedback_rotate_theta, 0, 20);
                    ImGui::SliderFloat("feedback rotate amp", &gui_osc0_feedback_rotate_amp, -1, 1);
                 
                }
                
                if (ImGui::CollapsingHeader("lfo color and filters")){
                    
                    ImGui::SliderFloat("powmod rate", &gui_osc0_powmod_theta, 0, 20);
                    ImGui::SliderFloat("powmod amp", &gui_osc0_powmod_amp, -5, 5);
                    ImGui::SliderFloat("blur amount rate", &gui_osc0_blur_amount_theta, 0, 20);
                    ImGui::SliderFloat("blur amount amp", &gui_osc0_blur_amount_amp, -2, 2);
                    ImGui::SliderFloat("blur radius rate", &gui_osc0_blur_radius_theta, 0, 20);
                    ImGui::SliderFloat("blur radius amp", &gui_osc0_blur_radius_amp, -10, 10);
                    ImGui::SliderFloat("sharpen amount rate", &gui_osc0_sharpen_amount_theta, 0, 20);
                    ImGui::SliderFloat("sharpen amount amp", &gui_osc0_sharpen_amount_amp, -1, 1);
                    ImGui::SliderFloat("sharpen radius rate", &gui_osc0_sharpen_radius_theta, 0, 20);
                    ImGui::SliderFloat("sharpen radius amp", &gui_osc0_sharpen_radius_amp, -10, 10);
                    ImGui::SliderFloat("temporal filter rate", &gui_osc0_temporal_filter_theta, 0, 20);
                    ImGui::SliderFloat("temporal filter amp", &gui_osc0_temporal_filter_amp, -2, 2);
                    
                    
                   
                }
            //ImGui::PopStyleVar();
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 0*gui_vscaler));
        
        if (ofxImGui::BeginWindow("osc0_m", mainSettings, false))
        {
            //ImGui::Text("nothin happening here yet");
            if (ImGui::CollapsingHeader("collapsible folder")){
                
            ImGui::Checkbox("texmod", &texmod_osc0_m_switch);
                
                if (ImGui::CollapsingHeader("basics")){
					const char* items[] = { "sin","square", "saw","ramp","triangle","parabolic","cubic","quartic","quintic" };
					static int item_current = 0;
					ImGui::Combo("osc0_m waveshape", &item_current, items, IM_ARRAYSIZE(items));
					if (item_current == 0) { gui_osc0_m_shape = 0; }
					if (item_current == 1) { gui_osc0_m_shape = 1; }
					if (item_current == 2) { gui_osc0_m_shape = 2; }
					if (item_current == 3) { gui_osc0_m_shape = 3; }
					if (item_current == 4) { gui_osc0_m_shape = 4; }
					if (item_current == 5) { gui_osc0_m_shape = 5; }
					if (item_current == 6) { gui_osc0_m_shape = 6; }
					if (item_current == 7) { gui_osc0_m_shape = 7; }
					if (item_current == 8) { gui_osc0_m_shape = 8; }
                    ImGui::SliderFloat("rate", &gui_osc0_m_rate, -1,1);
                    
                    if(texmod_osc0_m_switch==false){
                        ImGui::SliderFloat("frequency", &gui_osc0_m_frequency, 0,1);
                        ImGui::SliderFloat("amp", &gui_osc0_m_amp, 0, 1);
                        ImGui::SliderFloat("osc width", &gui_osc0_m_width, -1, 1);
                        ImGui::SliderFloat("angle", &gui_osc0_m_angle, -1, 1);
                        ImGui::SliderFloat("radial", &gui_osc0_m_spiral, -1, 1);
                    }
                    
                    if(texmod_osc0_m_switch==true){
                        ImGui::SliderFloat("texmod frequency", &texmod_gui_osc0_m_frequency, -1,1);
                        ImGui::SliderFloat("texmod amp", &texmod_gui_osc0_m_amp, -1, 1);
                        ImGui::SliderFloat("texmod osc width", &texmod_gui_osc0_m_width, -1, 1);
                        ImGui::SliderFloat("texmod angle", &texmod_gui_osc0_m_angle, -1, 1);
                        ImGui::SliderFloat("texmod radial", &texmod_gui_osc0_m_spiral, -1, 1);
                    }
                    
                    ImGui::SliderFloat("rotate", &gui_osc0_m_rotate, -1, 1);
                }
                    
                if (ImGui::CollapsingHeader("mods")){
                    ImGui::SliderFloat("rate mod", &gui_osc0_m_rate_mod, -1,1);
                    
                    if(texmod_osc0_m_switch==false){
                        ImGui::SliderFloat("rotate_mod", &gui_osc0_m_modulation_rotate, -1, 1);
                        ImGui::SliderFloat("pwm", &gui_osc0_m_pwm, -1, 1);
                        ImGui::SliderFloat("pwm 2", &gui_osc0_m_pwm2, -1, 1);
                        ImGui::SliderFloat("feedback pm", &gui_osc0_m_feedback_pm, -1, 1);
                    }
                    
                    if(texmod_osc0_m_switch==true){
                        ImGui::SliderFloat("texmod rotate_mod", &texmod_gui_osc0_m_modulation_rotate, -1, 1);
                        ImGui::SliderFloat("texmod pwm", &texmod_gui_osc0_m_pwm, -1, 1);
                        ImGui::SliderFloat("texmod pwm 2", &texmod_gui_osc0_m_pwm2, -1, 1);
                        ImGui::SliderFloat("texmod feedback pm", &texmod_gui_osc0_m_feedback_pm, -1, 1);
                    }
                }
                
            }
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Lots Of Funiculitus");
                if (ImGui::CollapsingHeader("basics lfos")){
                    ImGui::SliderFloat("rate rate (lol)", &gui_osc0_m_rate_theta, 0, 20);
                    ImGui::SliderFloat("rate amp", &gui_osc0_m_rate_amp, -10, 10);
                    ImGui::SliderFloat("frequency rate", &gui_osc0_m_frequency_theta, 0, 20);
                    ImGui::SliderFloat("frequency amp", &gui_osc0_m_frequency_amp, -1, 1);
                    ImGui::SliderFloat("amp rate", &gui_osc0_m_amp_theta, 0, 20);
                    ImGui::SliderFloat("amp amp (lololol)", &gui_osc0_m_amp_amp, -1, 1);
                    ImGui::SliderFloat("radial rate", &gui_osc0_m_radial_theta, 0, 20);
                    ImGui::SliderFloat("radial amp", &gui_osc0_m_radial_amp, -1, 1);
                    ImGui::SliderFloat("width rate", &gui_osc0_m_width_theta, 0, 20);
                    ImGui::SliderFloat("width amp", &gui_osc0_m_width_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("mods lfos")){
                    ImGui::SliderFloat("mod rotate rate", &gui_osc0_m_modulation_rotate_theta, 0, 20);
                    ImGui::SliderFloat("mod rotate amp", &gui_osc0_m_modulation_rotate_amp, -1, 1);
                    ImGui::SliderFloat("pwm rate", &gui_osc0_m_pwm_theta, 0, 20);
                    ImGui::SliderFloat("pwm amp", &gui_osc0_m_pwm_amp, -1, 1);
                    ImGui::SliderFloat("pwm2 rate", &gui_osc0_m_pwm2_theta, 0, 20);
                    ImGui::SliderFloat("pwm2 amp", &gui_osc0_m_pwm2_amp, -1, 1);
                    ImGui::SliderFloat("feedback pm rate", &gui_osc0_m_feedback_pm_theta, 0, 20);
                    ImGui::SliderFloat("feedback pm amp", &gui_osc0_m_feedback_pm_amp, -1, 1);
                }
            }
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
      
        ///**************OSC 1 BIZ**************************///
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 1*gui_vscaler));
        
        if (ofxImGui::BeginWindow("osc1", mainSettings, false))
        {
            //ImGui::Text("nothin happening here yet");
            if (ImGui::CollapsingHeader("collapsible folder")){
                const float spacing = 10;
                //ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(spacing, spacing));
                //input select
                //ImGui::PushItemWidth(20);
                ImGui::Checkbox("texmod", &texmod_osc1_switch);
                
                ImGui::Text("select texmod ");
                const char* items2[] = { "cam1","cam2","ndi","internal feedback" };
                static int item_current2 = 0;
                ImGui::Combo("combo2", &item_current2, items2, IM_ARRAYSIZE(items2));
                if(item_current2==0){osc1_texmod_select=0;}
                if(item_current2==1){osc1_texmod_select=1;}
                if(item_current2==2){osc1_texmod_select=2;}
                if(item_current2==3){osc1_texmod_select=3;}
                ImGui::SliderFloat("texmod scale", &osc1_texmod_scale, -1, 1);
                
                if (ImGui::CollapsingHeader("basic")){
					const char* items[] = { "sin","square", "saw","ramp","triangle","parabolic","cubic","quartic","quintic" };
					static int item_current = 0;
					ImGui::Combo("osc1 waveshape", &item_current, items, IM_ARRAYSIZE(items));
					if (item_current == 0) { gui_osc1_shape = 0; }
					if (item_current == 1) { gui_osc1_shape = 1; }
					if (item_current == 2) { gui_osc1_shape = 2; }
					if (item_current == 3) { gui_osc1_shape = 3; }
					if (item_current == 4) { gui_osc1_shape = 4; }
					if (item_current == 5) { gui_osc1_shape = 5; }
					if (item_current == 6) { gui_osc1_shape = 6; }
					if (item_current == 7) { gui_osc1_shape = 7; }
					if (item_current == 8) { gui_osc1_shape = 8; }
                    
                    ImGui::SliderFloat("rate", &gui_osc1_rate, -1,1);
                    
                    if(texmod_osc1_switch==false){
                        ImGui::SliderFloat("frequency", &gui_osc1_frequency, 0,1);
                        ImGui::SliderFloat("amp", &gui_osc1_amp, 0, 1);
                        ImGui::SliderFloat("osc width", &gui_osc1_width, -1, 1);
                        ImGui::SliderFloat("angle", &gui_osc1_angle, -1, 1);
                        ImGui::SliderFloat("radial", &gui_osc1_spiral, -1, 1);
                    }
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod frequency", &texmod_gui_osc1_frequency, -1,1);
                        ImGui::SliderFloat("texmod amp", &texmod_gui_osc1_amp, -1, 1);
                        ImGui::SliderFloat("texmod osc width", &texmod_gui_osc1_width, -1, 1);
                        ImGui::SliderFloat("texmod angle", &texmod_gui_osc1_angle, -1, 1);
                        ImGui::SliderFloat("texmod radial", &texmod_gui_osc1_spiral, -1, 1);
                    }
                    
                    ImGui::SliderFloat("rotate", &gui_osc1_rotate, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("osc0 mods")){
                    
                    ImGui::SliderFloat("rate mod", &gui_osc1_rate_mod, -1,1);
                    
                    if(texmod_osc1_switch==false){
                        ImGui::SliderFloat("osc0 rm", &gui_osc1_rm, -1, 1);
                        ImGui::SliderFloat("osc0 pm", &gui_osc1_pm, -1,1);
                        ImGui::SliderFloat("pm cutoff", &gui_osc1_pm_cutoff, 0,1);
                        ImGui::SliderFloat("pwm", &gui_osc1_pwm, -1, 1);
                        ImGui::SliderFloat("rotate_mod2", &gui_osc1_modulation_rotate2, -1, 1);
                    }
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod osc0 rm", &texmod_gui_osc1_rm, -1, 1);
                        ImGui::SliderFloat("texmod osc0 pm", &texmod_gui_osc1_pm, -1,1);
                        ImGui::SliderFloat("texmod pm cutoff", &texmod_gui_osc1_pm_cutoff, -1,1);
                        ImGui::SliderFloat("texmod pwm", &texmod_gui_osc1_pwm, -1, 1);
                        ImGui::SliderFloat("texmod rotate_mod2", &texmod_gui_osc1_modulation_rotate2, -1, 1);
                    }
                }
                
                
                
                if (ImGui::CollapsingHeader("osc1_m mods")){
                    if(texmod_osc1_switch==false){
                        ImGui::SliderFloat("osc1_m rm", &gui_osc1_m_rm, -1, 1);
                        ImGui::SliderFloat("osc1_m pm", &gui_osc1_m_pm, -1, 1);
                        ImGui::SliderFloat("pwm 2", &gui_osc1_pwm2, -1, 1);
                        ImGui::SliderFloat("rotate_mod", &gui_osc1_modulation_rotate, -1, 1);
                    }
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod osc1_m rm", &texmod_gui_osc1_m_rm, -1, 1);
                        ImGui::SliderFloat("texmod osc1_m pm", &texmod_gui_osc1_m_pm, -1, 1);
                        ImGui::SliderFloat("texmod pwm 2", &texmod_gui_osc1_pwm2, -1, 1);
                        ImGui::SliderFloat("texmod rotate_mod", &texmod_gui_osc1_modulation_rotate, -1, 1);
                    }
                }
                
                if (ImGui::CollapsingHeader("external input mods")){
                    
                    if(texmod_osc1_switch==false){
                        ImGui::SliderFloat("ext_input pm", &gui_osc1_ext_input_pm, -1,1);
                        ImGui::SliderFloat("ext_input rm", &gui_osc1_ext_input_rm, -1,1);
                        ImGui::SliderFloat("ext_input scale", &gui_osc1_ext_input_scale, -1, 1);
                        ImGui::SliderFloat("ext_input x displace", &gui_osc1_ext_input_x_displace, -1, 1);
                        ImGui::SliderFloat("ext_input y displace", &gui_osc1_ext_input_y_displace, -1, 1);
                        ImGui::SliderFloat("ext_input rotate", &gui_osc1_ext_input_rotate, -1, 1);
                    }
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod ext_input pm", &texmod_gui_osc1_ext_input_pm, -1,1);
                        ImGui::SliderFloat("texmod ext_input rm", &texmod_gui_osc1_ext_input_rm, -1,1);
                        ImGui::SliderFloat("texmod ext_input scale", &texmod_gui_osc1_ext_input_scale, -1, 1);
                        ImGui::SliderFloat("texmod ext_input x displace", &texmod_gui_osc1_ext_input_x_displace, -1, 1);
                        ImGui::SliderFloat("texmod ext_input y displace", &texmod_gui_osc1_ext_input_y_displace, -1, 1);
                        ImGui::SliderFloat("texmod vext_input rotate", &texmod_gui_osc1_ext_input_rotate, -1, 1);
                    }
                    
                    ImGui::Checkbox("ext_input x mirror", &gui_osc1_ext_input_x_mirror);
                    ImGui::Checkbox("ext_input y mirror", &gui_osc1_ext_input_y_mirror);
                }
                
                if (ImGui::CollapsingHeader("internal feedback mods")){
                    
                    if(texmod_osc1_switch==false){
                        ImGui::SliderFloat("feedback pm", &gui_osc1_feedback_pm, -1,1);
                        ImGui::SliderFloat("feedback rm", &gui_osc1_feedback_rm, -1,1);
                        ImGui::SliderFloat("feedback scale", &gui_osc1_feedback_scale, -1,1);
                        ImGui::SliderFloat("feedback x displace", &gui_osc1_feedback_x_displace, -1,1);
                        ImGui::SliderFloat("feedback y displace", &gui_osc1_feedback_y_displace, -1,1);
                        ImGui::SliderFloat("feedback rotate", &gui_osc1_feedback_rotate, -1,1);
                    }
                    
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod feedback pm", &texmod_gui_osc1_feedback_pm, -1,1);
                        ImGui::SliderFloat("texmod feedback rm", &texmod_gui_osc1_feedback_rm, -1,1);
                        ImGui::SliderFloat("texmod feedback scale", &texmod_gui_osc1_feedback_scale, -1,1);
                        ImGui::SliderFloat("texmod feedback x displace", &texmod_gui_osc1_feedback_x_displace, -1,1);
                        ImGui::SliderFloat("texmod feedback y displace", &texmod_gui_osc1_feedback_y_displace, -1,1);
                        ImGui::SliderFloat("texmod feedback rotate", &texmod_gui_osc1_feedback_rotate, -1,1);
                    }
                    
                    ImGui::Checkbox("feedback x mirror", &gui_osc1_feedback_x_mirror);
                    ImGui::Checkbox("feedback y mirror", &gui_osc1_feedback_y_mirror);
                }
                
                if (ImGui::CollapsingHeader("color and filters")){
                    
                    if(texmod_osc1_switch==false){
						ImGui::SliderFloat("bitcrush mix", &osc1BitCrushMix, 0, 1);
						ImGui::SliderInt("bitcrush amount", &osc1BitCrush, 0, bitCrushC);
                        ImGui::SliderFloat("powmod", &gui_osc1_powmod, 0, 5);
                        ImGui::SliderFloat("temporal_filter", &gui_osc1_temporal_filter, -2,2);
                        ImGui::SliderFloat("blur_amount", &gui_osc1_blur_amount, -2,2);
                        ImGui::SliderFloat("blur_radius", &gui_osc1_blur_radius, 0,10);
                        ImGui::SliderFloat("sharpen_amount", &gui_osc1_sharpen_amount, -.5,.5);
                        ImGui::SliderFloat("sharpen_radius", &gui_osc1_sharpen_radius, 0,10);
                    }
                    
                    if(texmod_osc1_switch==true){
                        ImGui::SliderFloat("texmod powmod", &texmod_gui_osc1_powmod, 0, 5);
                        ImGui::SliderFloat("texmod temporal_filter", &texmod_gui_osc1_temporal_filter, -2,2);
                        ImGui::SliderFloat("texmod blur_amount", &texmod_gui_osc1_blur_amount, -2,2);
                        ImGui::SliderFloat("texmod blur_radius", &texmod_gui_osc1_blur_radius, -10,10);
                        ImGui::SliderFloat("texmod sharpen_amount", &texmod_gui_osc1_sharpen_amount, -1,1);
                        ImGui::SliderFloat("texmod sharpen_radius", &texmod_gui_osc1_sharpen_radius, -10,10);
                    }
                    
                    
                    
                    
                    
                    const char* items2[] = { "clamp","wrap","foldover" };
                    static int item_current2 = 0;
                    ImGui::Combo("overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
                    if(item_current2==0){gui_osc1_overflow_switch=0;}
                    if(item_current2==1){gui_osc1_overflow_switch=1;}
                    if(item_current2==2){gui_osc1_overflow_switch=2;}
                    if(item_current2==3){gui_osc1_overflow_switch=3;}
                }
                
				if (ImGui::CollapsingHeader("colorizer solarizer")) {
					ImGui::SliderFloat("bright band1", &osc1BrightBand1, -1, 1);
					ImGui::SliderFloat("sat band1", &osc1SaturationBand1, 0, 1);
					ImGui::SliderFloat("hue band1", &osc1HueBand1, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band2", &osc1BrightBand2, -1, 1);
					ImGui::SliderFloat("sat band2", &osc1SaturationBand2, 0, 1);
					ImGui::SliderFloat("hue band2", &osc1HueBand2, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band3", &osc1BrightBand3, -1, 1);
					ImGui::SliderFloat("sat band3", &osc1SaturationBand3, 0, 1);
					ImGui::SliderFloat("hue band3", &osc1HueBand3, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band4", &osc1BrightBand4, -1, 1);
					ImGui::SliderFloat("sat band4", &osc1SaturationBand4, 0, 1);
					ImGui::SliderFloat("hue band4", &osc1HueBand4, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band5", &osc1BrightBand5, -1, 1);
					ImGui::SliderFloat("sat band5", &osc1SaturationBand5, 0, 1);
					ImGui::SliderFloat("hue band5", &osc1HueBand5, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band6", &osc1BrightBand6, -1, 1);
					ImGui::SliderFloat("sat band6", &osc1SaturationBand6, 0, 1);
					ImGui::SliderFloat("hue band6", &osc1HueBand6, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band7", &osc1BrightBand7, -1, 1);
					ImGui::SliderFloat("sat band7", &osc1SaturationBand7, 0, 1);
					ImGui::SliderFloat("hue band7", &osc1HueBand7, 0, 1);
					ImGui::Separator();
					ImGui::SliderFloat("bright band8", &osc1BrightBand8, -1, 1);
					ImGui::SliderFloat("sat band8", &osc1SaturationBand8, 0, 1);
					ImGui::SliderFloat("hue band8", &osc1HueBand8, 0, 1);
				}

                //ImGui::PopStyleVar();
            }
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Love On (the) Futon s");
                
                const float spacing = 10;
                //ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(spacing, spacing));
                
                
                if (ImGui::CollapsingHeader("lfo basic")){
                    
                    ImGui::SliderFloat("rate rate (lol)", &gui_osc1_rate_theta, 0, 20);
                    ImGui::SliderFloat("rate amp", &gui_osc1_rate_amp, -10, 10);
                    
                    ImGui::SliderFloat("frequency rate", &gui_osc1_frequency_theta, 0, 20);
                    ImGui::SliderFloat("frequency amp", &gui_osc1_frequency_amp, -1, 1);
                    
                    ImGui::SliderFloat("amp rate", &gui_osc1_amp_theta, 0, 20);
                    ImGui::SliderFloat("amp amp (lololol)", &gui_osc1_amp_amp, -1, 1);
                    
                    ImGui::SliderFloat("width rate", &gui_osc1_width_theta, 0, 20);
                    ImGui::SliderFloat("width amp", &gui_osc1_width_amp, -1, 1);
                    
                    ImGui::SliderFloat("radial rate", &gui_osc1_radial_theta, 0, 20);
                    ImGui::SliderFloat("radial amp", &gui_osc1_radial_amp, -1, 1);
                    
                    
                    
                }
                
                if (ImGui::CollapsingHeader("lfo osc0 mods")){
                    ImGui::SliderFloat("osc1 rm rate", &gui_osc1_rm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 rm amp", &gui_osc1_rm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 pm rate", &gui_osc1_pm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 pm amp", &gui_osc1_pm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 pwm rate", &gui_osc1_pwm_theta, 0, 20);
                    ImGui::SliderFloat("osc1 pwm amp", &gui_osc1_pwm_amp, -1, 1);
                    ImGui::SliderFloat("osc1 mod rotate rate", &gui_osc1_modulation_rotate2_theta, 0, 20);
                    ImGui::SliderFloat("osc1 mod rotate amp", &gui_osc1_modulation_rotate2_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("lfo osc1_m mods")){
                    ImGui::SliderFloat("osc1_m rm rate", &gui_osc1_m_rm_theta, 0, 20);
                    ImGui::SliderFloat("osc1_m rm amp", &gui_osc1_m_rm_amp, -1, 1);
                    ImGui::SliderFloat("osc1_m pm rate", &gui_osc1_m_pm_theta, 0, 20);
                    ImGui::SliderFloat("osc1_m pm amp", &gui_osc1_m_pm_amp, -1, 1);
                    ImGui::SliderFloat("osc1_m pwm2 rate", &gui_osc1_pwm2_theta, 0, 20);
                    ImGui::SliderFloat("osc1_m pwm2 amp", &gui_osc1_pwm2_amp, -1, 1);
                    ImGui::SliderFloat("osc1_m mod rotate rate", &gui_osc1_modulation_rotate_theta, 0, 20);
                    ImGui::SliderFloat("osc1_m mod rotate amp", &gui_osc1_modulation_rotate_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("lfo external input mods")){
                    ImGui::SliderFloat("ext input pm rate", &gui_osc1_ext_input_pm_theta, 0, 20);
                    ImGui::SliderFloat("ext input pm amp", &gui_osc1_ext_input_pm_amp, -1, 1);
                    ImGui::SliderFloat("ext input rm rate", &gui_osc1_ext_input_rm_theta, 0, 20);
                    ImGui::SliderFloat("ext input rm amp", &gui_osc1_ext_input_rm_amp, -1, 1);
                    ImGui::SliderFloat("ext input scale rate", &gui_osc1_ext_input_scale_theta, 0, 20);
                    ImGui::SliderFloat("ext input scale amp", &gui_osc1_ext_input_scale_amp, -1, 1);
                    ImGui::SliderFloat("ext input x displace rate", &gui_osc1_ext_input_x_displace_theta, 0, 20);
                    ImGui::SliderFloat("ext input x displace amp", &gui_osc1_ext_input_x_displace_amp, -1, 1);
                    ImGui::SliderFloat("ext input y displace rate", &gui_osc1_ext_input_y_displace_theta, 0, 20);
                    ImGui::SliderFloat("ext input y displace amp", &gui_osc1_ext_input_y_displace_amp, -1, 1);
                    ImGui::SliderFloat("ext input rotate rate", &gui_osc1_ext_input_rotate_theta, 0, 20);
                    ImGui::SliderFloat("ext input rotate amp", &gui_osc1_ext_input_rotate_amp, -1, 1);
                    
                }
                
                if (ImGui::CollapsingHeader("lfo internal feedback mods")){
                    ImGui::SliderFloat("feedback pm rate", &gui_osc1_feedback_pm_theta, 0, 20);
                    ImGui::SliderFloat("feedback pm amp", &gui_osc1_feedback_pm_amp, -1, 1);
                    ImGui::SliderFloat("feedback rm rate", &gui_osc1_feedback_rm_theta, 0, 20);
                    ImGui::SliderFloat("feedback rm amp", &gui_osc1_feedback_rm_amp, -1, 1);
                    ImGui::SliderFloat("feedback scale rate", &gui_osc1_feedback_scale_theta, 0, 20);
                    ImGui::SliderFloat("feedback scale amp", &gui_osc1_feedback_scale_amp, -1, 1);
                    ImGui::SliderFloat("feedback x displace rate", &gui_osc1_feedback_x_displace_theta, 0, 20);
                    ImGui::SliderFloat("feedback x displace amp", &gui_osc1_feedback_x_displace_amp, -1, 1);
                    ImGui::SliderFloat("feedback y displace rate", &gui_osc1_feedback_y_displace_theta, 0, 20);
                    ImGui::SliderFloat("feedback y displace amp", &gui_osc1_feedback_y_displace_amp, -1, 1);
                    ImGui::SliderFloat("feedback rotate rate", &gui_osc1_feedback_rotate_theta, 0, 20);
                    ImGui::SliderFloat("feedback rotate amp", &gui_osc1_feedback_rotate_amp, -1, 1);
                    
                }
                
                if (ImGui::CollapsingHeader("lfofilters")){
                    
                    ImGui::SliderFloat("powmod rate", &gui_osc1_powmod_theta, 0, 20);
                    ImGui::SliderFloat("powmod amp", &gui_osc1_powmod_amp, -5, 5);
                    ImGui::SliderFloat("blur amount rate", &gui_osc1_blur_amount_theta, 0, 20);
                    ImGui::SliderFloat("blur amount amp", &gui_osc1_blur_amount_amp, -2, 2);
                    ImGui::SliderFloat("blur radius rate", &gui_osc1_blur_radius_theta, 0, 20);
                    ImGui::SliderFloat("blur radius amp", &gui_osc1_blur_radius_amp, -10, 10);
                    ImGui::SliderFloat("sharpen amount rate", &gui_osc1_sharpen_amount_theta, 0, 20);
                    ImGui::SliderFloat("sharpen amount amp", &gui_osc1_sharpen_amount_amp, -1, 1);
                    ImGui::SliderFloat("sharpen radius rate", &gui_osc1_sharpen_radius_theta, 0, 20);
                    ImGui::SliderFloat("sharpen radius amp", &gui_osc1_sharpen_radius_amp, -10, 10);
                    ImGui::SliderFloat("temporal filter rate", &gui_osc1_temporal_filter_theta, 0, 20);
                    ImGui::SliderFloat("temporal filter amp", &gui_osc1_temporal_filter_amp, -2, 2);
                    
                    
                    
                }
                //ImGui::PopStyleVar();
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 1*gui_vscaler));
        
        if (ofxImGui::BeginWindow("osc1_m", mainSettings, false))
        {
            //ImGui::Text("nothin happening here yet");
            if (ImGui::CollapsingHeader("collapsible folder")){
                
                ImGui::Checkbox("texmod", &texmod_osc1_m_switch);
                
                if (ImGui::CollapsingHeader("basics")){
					const char* items[] = { "sin","square", "saw","ramp","triangle","parabolic","cubic","quartic","quintic" };
					static int item_current = 0;
					ImGui::Combo("osc1 m waveshape", &item_current, items, IM_ARRAYSIZE(items));
					if (item_current == 0) { gui_osc1_m_shape = 0; }
					if (item_current == 1) { gui_osc1_m_shape = 1; }
					if (item_current == 2) { gui_osc1_m_shape = 2; }
					if (item_current == 3) { gui_osc1_m_shape = 3; }
					if (item_current == 4) { gui_osc1_m_shape = 4; }
					if (item_current == 5) { gui_osc1_m_shape = 5; }
					if (item_current == 6) { gui_osc1_m_shape = 6; }
					if (item_current == 7) { gui_osc1_m_shape = 7; }
					if (item_current == 8) { gui_osc1_m_shape = 8; }
                    
                    ImGui::SliderFloat("rate", &gui_osc1_m_rate, -1,1);
                    
                    if(texmod_osc1_m_switch==false){
                        ImGui::SliderFloat("frequency", &gui_osc1_m_frequency, 0,1);
                        ImGui::SliderFloat("amp", &gui_osc1_m_amp, 0, 1);
                        ImGui::SliderFloat("osc width", &gui_osc1_m_width, -1, 1);
                        ImGui::SliderFloat("angle", &gui_osc1_m_angle, -1, 1);
                        ImGui::SliderFloat("radial", &gui_osc1_m_spiral, -1, 1);
                    }
                    
                    if(texmod_osc1_m_switch==true){
                        ImGui::SliderFloat("texmod frequency", &texmod_gui_osc1_m_frequency, -1,1);
                        ImGui::SliderFloat("texmod amp", &texmod_gui_osc1_m_amp, -1, 1);
                        ImGui::SliderFloat("texmod osc width", &texmod_gui_osc1_m_width, -1, 1);
                        ImGui::SliderFloat("texmod angle", &texmod_gui_osc1_m_angle, -1, 1);
                        ImGui::SliderFloat("texmod radial", &texmod_gui_osc1_m_spiral, -1, 1);
                    }
                    
                    ImGui::SliderFloat("rotate", &gui_osc1_m_rotate, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("mods")){
                    ImGui::SliderFloat("rate mod", &gui_osc1_m_rate_mod, -1,1);
                    
                    if(texmod_osc1_m_switch==false){
                        ImGui::SliderFloat("rotate_mod", &gui_osc1_m_modulation_rotate, -1, 1);
                        ImGui::SliderFloat("pwm", &gui_osc1_m_pwm, -1, 1);
                        ImGui::SliderFloat("pwm 2", &gui_osc1_m_pwm2, -1, 1);
                        ImGui::SliderFloat("feedback pm", &gui_osc1_m_feedback_pm, -1, 1);
                    }
                    
                    if(texmod_osc1_m_switch==true){
                        ImGui::SliderFloat("texmod rotate_mod", &texmod_gui_osc1_m_modulation_rotate, -1, 1);
                        ImGui::SliderFloat("texmod pwm", &texmod_gui_osc1_m_pwm, -1, 1);
                        ImGui::SliderFloat("texmod pwm 2", &texmod_gui_osc1_m_pwm2, -1, 1);
                        ImGui::SliderFloat("texmod feedback pm", &texmod_gui_osc1_m_feedback_pm, -1, 1);
                    }
                }
                
            }
            
            ImGui::Separator();
            
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Les Oefs Frigides");
                if (ImGui::CollapsingHeader("basics lfos")){
                    ImGui::SliderFloat("rate rate (lol)", &gui_osc1_m_rate_theta, 0, 20);
                    ImGui::SliderFloat("rate amp", &gui_osc1_m_rate_amp, -10, 10);
                    ImGui::SliderFloat("frequency rate", &gui_osc1_m_frequency_theta, 0, 20);
                    ImGui::SliderFloat("frequency amp", &gui_osc1_m_frequency_amp, -1, 1);
                    ImGui::SliderFloat("amp rate", &gui_osc1_m_amp_theta, 0, 20);
                    ImGui::SliderFloat("amp amp (lololol)", &gui_osc1_m_amp_amp, -1, 1);
                    ImGui::SliderFloat("radial rate", &gui_osc1_m_radial_theta, 0, 20);
                    ImGui::SliderFloat("radial amp", &gui_osc1_m_radial_amp, -1, 1);
                    ImGui::SliderFloat("width rate", &gui_osc1_m_width_theta, 0, 20);
                    ImGui::SliderFloat("width amp", &gui_osc1_m_width_amp, -1, 1);
                }
                
                if (ImGui::CollapsingHeader("mods lfos")){
                    ImGui::SliderFloat("mod rotate rate", &gui_osc1_m_modulation_rotate_theta, 0, 20);
                    ImGui::SliderFloat("mod rotate amp", &gui_osc1_m_modulation_rotate_amp, -1, 1);
                    ImGui::SliderFloat("pwm rate", &gui_osc1_m_pwm_theta, 0, 20);
                    ImGui::SliderFloat("pwm amp", &gui_osc1_m_pwm_amp, -1, 1);
                    ImGui::SliderFloat("pwm2 rate", &gui_osc1_m_pwm2_theta, 0, 20);
                    ImGui::SliderFloat("pwm2 amp", &gui_osc1_m_pwm2_amp, -1, 1);
                    ImGui::SliderFloat("feedback pm rate", &gui_osc1_m_feedback_pm_theta, 0, 20);
                    ImGui::SliderFloat("feedback pm amp", &gui_osc1_m_feedback_pm_amp, -1, 1);
                }
            }
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
        
       
        
        
        mainSettings.windowPos=ImVec2(ImVec2(1*gui_hscaler, 2*gui_vscaler));
        
        if (ofxImGui::BeginWindow("global", mainSettings, false))
        {
            if (ImGui::CollapsingHeader("collapsible folder")){
                
            ImGui::Checkbox("osc draw switch", &osc_draw_switch);
                
            const char* items[] = { "cam1","cam2","ndi" };
            static int item_current = 0;
            ImGui::Combo("ext input selecte", &item_current, items, IM_ARRAYSIZE(items));
            if(item_current==0){gui_ext_input_switch=0;}
            if(item_current==1){gui_ext_input_switch=1;}
            if(item_current==2){gui_ext_input_switch=2;}
            
            ImGui::SliderInt("ndi scale", &ndi_scale, -400, 400);
                
                //maybe add a resolution/upscaler in here...
            }
            
        }
        ofxImGui::EndWindow(mainSettings);
        /*
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 2*gui_vscaler));
        
        if (ofxImGui::BeginWindow("gui customize", mainSettings, false)){
           ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
           if (ImGui::CollapsingHeader("gigantic style editor")){
               ImGui::ShowStyleEditor(&my_style);
           }
        }
        ofxImGui::EndWindow(mainSettings);
         */
        gui.end();
    }


//---------------------------




