#pragma once

#include "ofMain.h"
//#include "ofxDatGui.h"
#include "ofxImGui.h"
class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
    
    //gui variables
    ofxImGui::Gui gui;
    ImGuiStyle my_style;
    ImVec4 backgroundColor;
 
    //ndi
    int ndi_scale=0;
   
    //global
    bool osc_draw_switch=0;
    int gui_ext_input_switch=0;
    
    //osc0
	//NEW
	//osc0 colorizer/Solarizer
	float osc0HueBand1 = 0;
	float osc0HueBand2 = 0;
	float osc0HueBand3 = 0;
	float osc0HueBand4 = 0;

	float osc0SaturationBand1 = 0;
	float osc0SaturationBand2 = 0;
	float osc0SaturationBand3 = 0;
	float osc0SaturationBand4 = 0;

	float osc0BrightBand1 = 0;
	float osc0BrightBand2 = 0;
	float osc0BrightBand3 = 0;
	float osc0BrightBand4 = 0;

	float osc0HueBand5 = 0;
	float osc0HueBand6 = 0;
	float osc0HueBand7 = 0;
	float osc0HueBand8 = 0;

	float osc0SaturationBand5 = 0;
	float osc0SaturationBand6 = 0;
	float osc0SaturationBand7 = 0;
	float osc0SaturationBand8 = 0;

	float osc0BrightBand5 = 0;
	float osc0BrightBand6 = 0;
	float osc0BrightBand7 = 0;
	float osc0BrightBand8 = 0;

	//osc1 colorizer/Solarizer
	float osc1HueBand1 = 0;
	float osc1HueBand2 = 0;
	float osc1HueBand3 = 0;
	float osc1HueBand4 = 0;

	float osc1SaturationBand1 = 0;
	float osc1SaturationBand2 = 0;
	float osc1SaturationBand3 = 0;
	float osc1SaturationBand4 = 0;

	float osc1BrightBand1 = 0;
	float osc1BrightBand2 = 0;
	float osc1BrightBand3 = 0;
	float osc1BrightBand4 = 0;

	float osc1HueBand5 = 0;
	float osc1HueBand6 = 0;
	float osc1HueBand7 = 0;
	float osc1HueBand8 = 0;

	float osc1SaturationBand5 = 0;
	float osc1SaturationBand6 = 0;
	float osc1SaturationBand7 = 0;
	float osc1SaturationBand8 = 0;

	float osc1BrightBand5 = 0;
	float osc1BrightBand6 = 0;
	float osc1BrightBand7 = 0;
	float osc1BrightBand8 = 0;

	//OSC0 bitcrush
	int bitCrushC = 24;
	int osc0BitCrush = bitCrushC;
	float osc0BitCrushMix = 0;

	//OSC1 bitcrush
	int osc1BitCrush = bitCrushC;
	float osc1BitCrushMix = 0;

    //osc0_basic
    int gui_osc0_shape=0;
    float gui_osc0_rate=0;
    float gui_osc0_angle=0;
    float gui_osc0_frequency=.1;
    float gui_osc0_amp=1;
    float gui_osc0_spiral=0;
    float gui_osc0_rotate=0;
    float gui_osc0_width=0;
    
    //TEXMODosc0 basic
    bool texmod_osc0_switch=false;
    float osc0_texmod_select=0;
    float osc0_texmod_scale=0;
    
    float texmod_gui_osc0_angle=0;
    float texmod_gui_osc0_frequency=0;
    float texmod_gui_osc0_amp=0;
    float texmod_gui_osc0_spiral=0;
    float texmod_gui_osc0_width=0;
    
    
    //osc1->osc0 modulations
    float gui_osc0_pwm=0;
    float gui_osc0_rm=0;
    float gui_osc0_pm=0;
    float gui_osc0_pm_cutoff=0;
    float gui_osc0_rate_mod=0;
    float gui_osc0_modulation_rotate2=0;
    
    //TEXMODosc1->osc0 modulations
    float texmod_gui_osc0_pwm=0;
    float texmod_gui_osc0_rm=0;
    float texmod_gui_osc0_pm=0;
    float texmod_gui_osc0_pm_cutoff=0;
    float texmod_gui_osc0_modulation_rotate2=0;
    
    //osc0_m->osc0 modulations
    float gui_osc0_modulation_rotate=0;
    float gui_osc0_pwm2=0;
    float gui_osc0_m_rm=0;
    float gui_osc0_m_pm=0;
    
    //texmodosc0_m->osc0 modulations
    float texmod_gui_osc0_modulation_rotate=0;
    float texmod_gui_osc0_pwm2=0;
    float texmod_gui_osc0_m_rm=0;
    float texmod_gui_osc0_m_pm=0;
    
    
    //osc0 ext input modulations
    float gui_osc0_ext_input_pm=0;
    float gui_osc0_ext_input_rm=0;
    float gui_osc0_ext_input_scale=0;
    float gui_osc0_ext_input_x_displace=0;
    float gui_osc0_ext_input_y_displace=0;
    float gui_osc0_ext_input_rotate=0;
    bool gui_osc0_ext_input_x_mirror=false;
    bool gui_osc0_ext_input_y_mirror=false;
    
    
    //texmod osc0 ext input modulations
    float texmod_gui_osc0_ext_input_pm=0;
    float texmod_gui_osc0_ext_input_rm=0;
    float texmod_gui_osc0_ext_input_scale=0;
    float texmod_gui_osc0_ext_input_x_displace=0;
    float texmod_gui_osc0_ext_input_y_displace=0;
    float texmod_gui_osc0_ext_input_rotate=0;
    
    //osc0_int feedback stuffs
    float gui_osc0_feedback_pm=0;
    float gui_osc0_feedback_rm=0;
    float gui_osc0_feedback_scale=0;
    bool gui_osc0_feedback_x_mirror=false;
    bool gui_osc0_feedback_y_mirror=false;
    float gui_osc0_feedback_x_displace=0;
    float gui_osc0_feedback_y_displace=0;
    float gui_osc0_feedback_rotate=0;
    
    
    //texmod osc0_int feedback stuffs
    float texmod_gui_osc0_feedback_pm=0;
    float texmod_gui_osc0_feedback_rm=0;
    float texmod_gui_osc0_feedback_scale=0;
    float texmod_gui_osc0_feedback_x_displace=0;
    float texmod_gui_osc0_feedback_y_displace=0;
    float texmod_gui_osc0_feedback_rotate=0;
    
    //osc0 filters
    float gui_osc0_powmod=1;
    float gui_osc0_blur_amount=0;
    float gui_osc0_blur_radius=1;
    float gui_osc0_sharpen_amount=0;
    float gui_osc0_sharpen_radius=1;
    float gui_osc0_temporal_filter=0;
    int gui_osc0_overflow_switch=0;
    
    //texmod osc0filters

    float texmod_gui_osc0_powmod=0;
    float texmod_gui_osc0_temporal_filter=0;
    float texmod_gui_osc0_blur_amount=0;
    float texmod_gui_osc0_blur_radius=0;
    float texmod_gui_osc0_sharpen_amount=0;
    float texmod_gui_osc0_sharpen_radius=0;
    
    
    //osc0 lfos
    
   
    
    //osc0 basic lfos
    float gui_osc0_rate_theta=0;
    float gui_osc0_rate_amp=0;
    float gui_osc0_frequency_theta=0;
    float gui_osc0_frequency_amp=0;
    float gui_osc0_amp_theta=0;
    float gui_osc0_amp_amp=0;
    float gui_osc0_radial_theta=0;
    float gui_osc0_radial_amp=0;
    float gui_osc0_width_theta=0;
    float gui_osc0_width_amp=0;
    
    //osc0 osc1->osc0 modulation lfos
    float gui_osc0_rm_theta=0;
    float gui_osc0_rm_amp=0;
    float gui_osc0_pm_theta=0;
    float gui_osc0_pm_amp=0;
    float gui_osc0_pwm_theta=0;
    float gui_osc0_pwm_amp=0;
    float gui_osc0_modulation_rotate2_theta=0;
    float gui_osc0_modulation_rotate2_amp=0;
    
    //osc0 osc0m->osc0 modulation lfos
    float gui_osc0_m_rm_theta=0;
    float gui_osc0_m_rm_amp=0;
    float gui_osc0_m_pm_theta=0;
    float gui_osc0_m_pm_amp=0;
    float gui_osc0_modulation_rotate_theta=0;
    float gui_osc0_modulation_rotate_amp=0;
    float gui_osc0_pwm2_theta=0;
    float gui_osc0_pwm2_amp=0;

    //osc0_ext input lfo
    float gui_osc0_ext_input_pm_theta=0;
    float gui_osc0_ext_input_pm_amp=0;
    float gui_osc0_ext_input_rm_theta=0;
    float gui_osc0_ext_input_rm_amp=0;
    float gui_osc0_ext_input_scale_theta=0;
    float gui_osc0_ext_input_scale_amp=0;
    float gui_osc0_ext_input_x_displace_theta=0;
    float gui_osc0_ext_input_x_displace_amp=0;
    float gui_osc0_ext_input_y_displace_theta=0;
    float gui_osc0_ext_input_y_displace_amp=0;
    float gui_osc0_ext_input_rotate_theta=0;
    float gui_osc0_ext_input_rotate_amp=0;
    
    //osc0_int feedback lof
    float gui_osc0_feedback_pm_theta=0;
    float gui_osc0_feedback_pm_amp=0;
    float gui_osc0_feedback_rm_theta=0;
    float gui_osc0_feedback_rm_amp=0;
    float gui_osc0_feedback_scale_theta=0;
    float gui_osc0_feedback_scale_amp=0;
    float gui_osc0_feedback_x_displace_theta=0;
    float gui_osc0_feedback_x_displace_amp=0;
    float gui_osc0_feedback_y_displace_theta=0;
    float gui_osc0_feedback_y_displace_amp=0;
    float gui_osc0_feedback_rotate_theta=0;
    float gui_osc0_feedback_rotate_amp=0;
    
    //osc0 color and filter lfos
    

    float gui_osc0_powmod_theta=0;
    float gui_osc0_powmod_amp=0;
    float gui_osc0_blur_amount_theta=0;
    float gui_osc0_blur_amount_amp=0;
    float gui_osc0_blur_radius_theta=0;
    float gui_osc0_blur_radius_amp=0;
    float gui_osc0_sharpen_amount_theta=0;
    float gui_osc0_sharpen_amount_amp=0;
    float gui_osc0_sharpen_radius_theta=0;
    float gui_osc0_sharpen_radius_amp=0;
    float gui_osc0_temporal_filter_theta=0;
    float gui_osc0_temporal_filter_amp=0;
    
    
    //osc0_m
    
    //osc0_m basic
    int gui_osc0_m_shape=0;
    float gui_osc0_m_width=0;
    float gui_osc0_m_rate=0;
    float gui_osc0_m_angle=0;
    float gui_osc0_m_frequency=.1;
    float gui_osc0_m_amp=1;
    float gui_osc0_m_spiral=0;
    float gui_osc0_m_rotate=0;
    
    //texmod osc0 basic
    bool texmod_osc0_m_switch=false;
    float texmod_gui_osc0_m_width=0;
    float texmod_gui_osc0_m_rate=0;
    float texmod_gui_osc0_m_angle=0;
    float texmod_gui_osc0_m_frequency=0;
    float texmod_gui_osc0_m_amp=0;
    float texmod_gui_osc0_m_spiral=0;
   

    //osc0_m mods
    float gui_osc0_m_rate_mod=0;
    float gui_osc0_m_modulation_rotate=0;
    float gui_osc0_m_pwm=0;
    float gui_osc0_m_pwm2=0;
    float gui_osc0_m_feedback_pm=0;
    
    //texmod osc0_m mods
    float texmod_gui_osc0_m_modulation_rotate=0;
    float texmod_gui_osc0_m_pwm=0;
    float texmod_gui_osc0_m_pwm2=0;
    float texmod_gui_osc0_m_feedback_pm=0;
    
    //osc0_m lfos
    float gui_osc0_m_rate_theta=0;
    float gui_osc0_m_rate_amp=0;
    float gui_osc0_m_frequency_theta=0;
    float gui_osc0_m_frequency_amp=0;
    float gui_osc0_m_amp_theta=0;
    float gui_osc0_m_amp_amp=0;
    float gui_osc0_m_radial_theta=0;
    float gui_osc0_m_radial_amp=0;
    float gui_osc0_m_width_theta=0;
    float gui_osc0_m_width_amp=0;
    
    float gui_osc0_m_modulation_rotate_theta=0;
    float gui_osc0_m_modulation_rotate_amp=0;
    float gui_osc0_m_pwm_theta=0;
    float gui_osc0_m_pwm_amp=0;
    float gui_osc0_m_pwm2_theta=0;
    float gui_osc0_m_pwm2_amp=0;
    float gui_osc0_m_feedback_pm_theta=0;
    float gui_osc0_m_feedback_pm_amp=0;
    
    
    //osc1
    //osc1_basic
    int gui_osc1_shape=0;
    float gui_osc1_rate=0;
    float gui_osc1_angle=0;
    float gui_osc1_frequency=.1;
    float gui_osc1_amp=1;
    float gui_osc1_spiral=0;
    float gui_osc1_rotate=0;
    float gui_osc1_width=0;
    
    //TEXMODosc1 basic
    bool texmod_osc1_switch=false;
    float osc1_texmod_select=0;
    float osc1_texmod_scale=0;
    
    float texmod_gui_osc1_angle=0;
    float texmod_gui_osc1_frequency=0;
    float texmod_gui_osc1_amp=0;
    float texmod_gui_osc1_spiral=0;
    float texmod_gui_osc1_width=0;
    
    
    //osc0->osc1 modulations
    float gui_osc1_pwm=0;
    float gui_osc1_rm=0;
    float gui_osc1_pm=0;
    float gui_osc1_pm_cutoff=0;
    float gui_osc1_rate_mod=0;
    float gui_osc1_modulation_rotate2=0;
    
    //TEXMODosc0->osc1 modulations
    float texmod_gui_osc1_pwm=0;
    float texmod_gui_osc1_rm=0;
    float texmod_gui_osc1_pm=0;
    float texmod_gui_osc1_pm_cutoff=0;
    float texmod_gui_osc1_modulation_rotate2=0;
    
    //osc1_m->osc1 modulations
    float gui_osc1_modulation_rotate=0;
    float gui_osc1_pwm2=0;
    float gui_osc1_m_rm=0;
    float gui_osc1_m_pm=0;
    
    //texmodosc1_m->osc1 modulations
    float texmod_gui_osc1_modulation_rotate=0;
    float texmod_gui_osc1_pwm2=0;
    float texmod_gui_osc1_m_rm=0;
    float texmod_gui_osc1_m_pm=0;
    
    
    //osc1 ext input modulations
    float gui_osc1_ext_input_pm=0;
    float gui_osc1_ext_input_rm=0;
    float gui_osc1_ext_input_scale=0;
    float gui_osc1_ext_input_x_displace=0;
    float gui_osc1_ext_input_y_displace=0;
    float gui_osc1_ext_input_rotate=0;
    bool gui_osc1_ext_input_x_mirror=false;
    bool gui_osc1_ext_input_y_mirror=false;
    
    
    //texmod osc1 ext input modulations
    float texmod_gui_osc1_ext_input_pm=0;
    float texmod_gui_osc1_ext_input_rm=0;
    float texmod_gui_osc1_ext_input_scale=0;
    float texmod_gui_osc1_ext_input_x_displace=0;
    float texmod_gui_osc1_ext_input_y_displace=0;
    float texmod_gui_osc1_ext_input_rotate=0;
    
    //osc1_int feedback stuffs
    float gui_osc1_feedback_pm=0;
    float gui_osc1_feedback_rm=0;
    float gui_osc1_feedback_scale=0;
    bool gui_osc1_feedback_x_mirror=false;
    bool gui_osc1_feedback_y_mirror=false;
    float gui_osc1_feedback_x_displace=0;
    float gui_osc1_feedback_y_displace=0;
    float gui_osc1_feedback_rotate=0;
    
    
    //texmod osc1_int feedback stuffs
    float texmod_gui_osc1_feedback_pm=0;
    float texmod_gui_osc1_feedback_rm=0;
    float texmod_gui_osc1_feedback_scale=0;
    float texmod_gui_osc1_feedback_x_displace=0;
    float texmod_gui_osc1_feedback_y_displace=0;
    float texmod_gui_osc1_feedback_rotate=0;
    
    //osc1 filters

    float gui_osc1_powmod=1;
    float gui_osc1_blur_amount=0;
    float gui_osc1_blur_radius=1;
    float gui_osc1_sharpen_amount=0;
    float gui_osc1_sharpen_radius=1;
    float gui_osc1_temporal_filter=0;
    int gui_osc1_overflow_switch=0;
    
    //texmod osc1filters

    float texmod_gui_osc1_powmod=0;
    float texmod_gui_osc1_temporal_filter=0;
    float texmod_gui_osc1_blur_amount=0;
    float texmod_gui_osc1_blur_radius=0;
    float texmod_gui_osc1_sharpen_amount=0;
    float texmod_gui_osc1_sharpen_radius=0;
    
    
    //osc1 lfos
    
    
    
    //osc1 basic lfos
    float gui_osc1_rate_theta=0;
    float gui_osc1_rate_amp=0;
    float gui_osc1_frequency_theta=0;
    float gui_osc1_frequency_amp=0;
    float gui_osc1_amp_theta=0;
    float gui_osc1_amp_amp=0;
    float gui_osc1_radial_theta=0;
    float gui_osc1_radial_amp=0;
    float gui_osc1_width_theta=0;
    float gui_osc1_width_amp=0;
    
    //osc1 osc0->osc1 modulation lfos
    float gui_osc1_rm_theta=0;
    float gui_osc1_rm_amp=0;
    float gui_osc1_pm_theta=0;
    float gui_osc1_pm_amp=0;
    float gui_osc1_pwm_theta=0;
    float gui_osc1_pwm_amp=0;
    float gui_osc1_modulation_rotate2_theta=0;
    float gui_osc1_modulation_rotate2_amp=0;
    
    //osc1 osc1m->osc1 modulation lfos
    float gui_osc1_m_rm_theta=0;
    float gui_osc1_m_rm_amp=0;
    float gui_osc1_m_pm_theta=0;
    float gui_osc1_m_pm_amp=0;
    float gui_osc1_modulation_rotate_theta=0;
    float gui_osc1_modulation_rotate_amp=0;
    float gui_osc1_pwm2_theta=0;
    float gui_osc1_pwm2_amp=0;
    
    //osc1_ext input lfo
    float gui_osc1_ext_input_pm_theta=0;
    float gui_osc1_ext_input_pm_amp=0;
    float gui_osc1_ext_input_rm_theta=0;
    float gui_osc1_ext_input_rm_amp=0;
    float gui_osc1_ext_input_scale_theta=0;
    float gui_osc1_ext_input_scale_amp=0;
    float gui_osc1_ext_input_x_displace_theta=0;
    float gui_osc1_ext_input_x_displace_amp=0;
    float gui_osc1_ext_input_y_displace_theta=0;
    float gui_osc1_ext_input_y_displace_amp=0;
    float gui_osc1_ext_input_rotate_theta=0;
    float gui_osc1_ext_input_rotate_amp=0;
    
    //osc1_int feedback lof
    float gui_osc1_feedback_pm_theta=0;
    float gui_osc1_feedback_pm_amp=0;
    float gui_osc1_feedback_rm_theta=0;
    float gui_osc1_feedback_rm_amp=0;
    float gui_osc1_feedback_scale_theta=0;
    float gui_osc1_feedback_scale_amp=0;
    float gui_osc1_feedback_x_displace_theta=0;
    float gui_osc1_feedback_x_displace_amp=0;
    float gui_osc1_feedback_y_displace_theta=0;
    float gui_osc1_feedback_y_displace_amp=0;
    float gui_osc1_feedback_rotate_theta=0;
    float gui_osc1_feedback_rotate_amp=0;
    
    //osc1 filter lfos
    float gui_osc1_powmod_theta=0;
    float gui_osc1_powmod_amp=0;
    float gui_osc1_blur_amount_theta=0;
    float gui_osc1_blur_amount_amp=0;
    float gui_osc1_blur_radius_theta=0;
    float gui_osc1_blur_radius_amp=0;
    float gui_osc1_sharpen_amount_theta=0;
    float gui_osc1_sharpen_amount_amp=0;
    float gui_osc1_sharpen_radius_theta=0;
    float gui_osc1_sharpen_radius_amp=0;
    float gui_osc1_temporal_filter_theta=0;
    float gui_osc1_temporal_filter_amp=0;
    
    
    //osc1_m
    
    //osc1_m basic
    int gui_osc1_m_shape=0;
    float gui_osc1_m_width=0;
    float gui_osc1_m_rate=0;
    float gui_osc1_m_angle=0;
    float gui_osc1_m_frequency=.1;
    float gui_osc1_m_amp=1;
    float gui_osc1_m_spiral=0;
    float gui_osc1_m_rotate=0;
    
    //texmod osc1 basic
    bool texmod_osc1_m_switch=false;
    float texmod_gui_osc1_m_width=0;
    float texmod_gui_osc1_m_rate=0;
    float texmod_gui_osc1_m_angle=0;
    float texmod_gui_osc1_m_frequency=0;
    float texmod_gui_osc1_m_amp=0;
    float texmod_gui_osc1_m_spiral=0;
    
    
    //osc1_m mods
    float gui_osc1_m_rate_mod=0;
    float gui_osc1_m_modulation_rotate=0;
    float gui_osc1_m_pwm=0;
    float gui_osc1_m_pwm2=0;
    float gui_osc1_m_feedback_pm=0;
    
    //texmod osc1_m mods
    float texmod_gui_osc1_m_modulation_rotate=0;
    float texmod_gui_osc1_m_pwm=0;
    float texmod_gui_osc1_m_pwm2=0;
    float texmod_gui_osc1_m_feedback_pm=0;
    
    //osc1_m lfos
    float gui_osc1_m_rate_theta=0;
    float gui_osc1_m_rate_amp=0;
    float gui_osc1_m_frequency_theta=0;
    float gui_osc1_m_frequency_amp=0;
    float gui_osc1_m_amp_theta=0;
    float gui_osc1_m_amp_amp=0;
    float gui_osc1_m_radial_theta=0;
    float gui_osc1_m_radial_amp=0;
    float gui_osc1_m_width_theta=0;
    float gui_osc1_m_width_amp=0;
    
    float gui_osc1_m_modulation_rotate_theta=0;
    float gui_osc1_m_modulation_rotate_amp=0;
    float gui_osc1_m_pwm_theta=0;
    float gui_osc1_m_pwm_amp=0;
    float gui_osc1_m_pwm2_theta=0;
    float gui_osc1_m_pwm2_amp=0;
    float gui_osc1_m_feedback_pm_theta=0;
    float gui_osc1_m_feedback_pm_amp=0;
    
    
   };
