#version 120

varying vec2 texCoordVarying;

uniform sampler2DRect tex0;
uniform sampler2DRect ext_input;
uniform sampler2DRect last_frame;
uniform sampler2DRect texmod;

uniform vec2 feedback_dimensions;
uniform vec2 texmod_dimensions;


uniform float width;
uniform float height;
uniform float osc0_texmod_scale;

//NEW
//bitcrush
uniform float osc0BitCrushMix;
uniform float osc0BitCrush;
uniform float osc0BitCrushDenom;

//color eq
uniform float osc0HueBand1;
uniform float osc0HueBand2;
uniform float osc0HueBand3;
uniform float osc0HueBand4;

uniform float osc0SaturationBand1;
uniform float osc0SaturationBand2;
uniform float osc0SaturationBand3;
uniform float osc0SaturationBand4;

uniform float osc0BrightBand1;
uniform float osc0BrightBand2;
uniform float osc0BrightBand3;
uniform float osc0BrightBand4;

uniform float osc0HueBand5;
uniform float osc0HueBand6;
uniform float osc0HueBand7;
uniform float osc0HueBand8;

uniform float osc0SaturationBand5;
uniform float osc0SaturationBand6;
uniform float osc0SaturationBand7;
uniform float osc0SaturationBand8;

uniform float osc0BrightBand5;
uniform float osc0BrightBand6;
uniform float osc0BrightBand7;
uniform float osc0BrightBand8;

//osc0 basics
uniform int osc0_shape;
uniform float osc0_rate;
uniform float osc0_frequency;
uniform float osc0_amp;
uniform float osc0_angle;
uniform float osc0_width;
uniform float osc0_spiral;
uniform float osc0_rotate;

//texmod osc0 bascics
uniform float texmod_osc0_frequency;
uniform float texmod_osc0_amp;
uniform float texmod_osc0_angle;
uniform float texmod_osc0_width;
uniform float texmod_osc0_spiral;

//osc1->osc0 modulate
uniform float osc0_rm;
uniform float osc0_pm;
uniform float osc0_pm_cutoff;
uniform float osc0_pwm;
uniform float osc0_modulation_rotate2;

//texmod osc1->osc0 modulate
uniform float texmod_osc0_rm;
uniform float texmod_osc0_pm;
uniform float texmod_osc0_pm_cutoff;
uniform float texmod_osc0_pwm;
uniform float texmod_osc0_modulation_rotate2;

//osc0_m->osc0 modulate
uniform float osc0_m_rm;
uniform float osc0_m_pm;
uniform float osc0_pwm2;
uniform float osc0_modulation_rotate;

//texmod osc0_m->osc0 modulate
uniform float texmod_osc0_m_rm;
uniform float texmod_osc0_m_pm;
uniform float texmod_osc0_pwm2;
uniform float texmod_osc0_modulation_rotate;

//osc0 ext input
uniform vec2 ext_input_dimensions;
uniform float osc0_ext_input_scale;
uniform float osc0_ext_input_pm;
uniform float osc0_ext_input_rm;
uniform float osc0_ext_input_x_displace;
uniform float osc0_ext_input_y_displace;
uniform float osc0_ext_input_rotate;
uniform int osc0_ext_input_y_mirror;
uniform int osc0_ext_input_x_mirror;

//texmod osc0 ext input
uniform float texmod_osc0_ext_input_scale;
uniform float texmod_osc0_ext_input_pm;
uniform float texmod_osc0_ext_input_rm;
uniform float texmod_osc0_ext_input_x_displace;
uniform float texmod_osc0_ext_input_y_displace;
uniform float texmod_osc0_ext_input_rotate;

//osc0 feedback
uniform float osc0_feedback_pm;
uniform float osc0_feedback_rm;
uniform float osc0_feedback_x_displace;
uniform float osc0_feedback_y_displace;
uniform float osc0_feedback_scale;
uniform float osc0_feedback_rotate;
uniform int osc0_feedback_x_mirror;
uniform int osc0_feedback_y_mirror;

//texmodosc0 feedback
uniform float texmod_osc0_feedback_pm;
uniform float texmod_osc0_feedback_rm;
uniform float texmod_osc0_feedback_x_displace;
uniform float texmod_osc0_feedback_y_displace;
uniform float texmod_osc0_feedback_scale;
uniform float texmod_osc0_feedback_rotate;

//filters
uniform float osc0_powmod;
uniform float osc0_temporal_filter;
uniform int osc0_overflow_switch;

//texmod filters
uniform float texmod_osc0_powmod;
uniform float texmod_osc0_temporal_filter;

//osc0_m basic
uniform int osc0_m_shape;
uniform float osc0_m_rate;
uniform float osc0_m_frequency;
uniform float osc0_m_amp;
uniform float osc0_m_angle;
uniform float osc0_m_spiral;
uniform float osc0_m_width;
uniform float osc0_m_rotate;

//texmod osc0_basic
uniform float texmod_osc0_m_frequency;
uniform float texmod_osc0_m_amp;
uniform float texmod_osc0_m_angle;
uniform float texmod_osc0_m_spiral;
uniform float texmod_osc0_m_width;

//osc0_m mods
uniform float osc0_m_pwm;
uniform float osc0_m_pwm2;
uniform float osc0_m_modulation_rotate;
uniform float osc0_m_feedback_pm;

//texmod osc0_m mods
uniform float texmod_osc0_m_pwm;
uniform float texmod_osc0_m_pwm2;
uniform float texmod_osc0_m_modulation_rotate;
uniform float texmod_osc0_m_feedback_pm;






float map(float value, float min1, float max1, float min2, float max2) {
    return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

//lets make everything from 0-1 here for now
float oscillate(float theta,int shape,float pwm){
    float osc=0.0;
    //float pwm=osc0_width;
    
    if(shape==0){
        osc=(sin(theta)+1.0)*.5;
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
    }
    
    //squarewave..
    if(shape==1){
        osc=sign(sin(theta)+pwm);
    }
    
    //saw
    if(shape==2){
        osc=fract(-theta/6.18);
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
    }
    
    //ramp
    if(shape==3){
        osc=fract(theta/6.18);
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
    }
	//triangle
	if(shape==4){
        osc=fract(theta/6.18);
		osc=abs(osc-.5)*2.0;
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
    }
	//parabola
	if(shape==5){
		osc=( (sin(theta)+1.0)*.5 )*( (sin(theta)+1.0)*.5 );
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
	}
	//cubic
	if(shape==6){
		osc=(sin(theta)*sin(theta)*sin(theta)+1.0)*.5;
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
	}
	//quartic
	if(shape==7){
		osc=( (sin(theta)+1.0)*.5 )*( (sin(theta)+1.0)*.5 )*( (sin(theta)+1.0)*.5 )*( (sin(theta)+1.0)*.5 );
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
	}
	//quintic
	if(shape==8){
		osc=(sin(theta)*sin(theta)*sin(theta)*sin(theta)*sin(theta)+1.0)*.5;
        osc=clamp(osc+pwm,0,1);
        if(pwm<0.0){
            osc=map(osc,0.0,1.0+pwm,0.0,1.0);
        }
	}
    return osc;
    
}

//whoops we can't do waveshaping this time without completely rewriting the code lol
//suppose this is an agrument in favor of being slightly more functional from the get go
//tho might not have even gotten this far if it was functional so hmmm
float waveShaper(float waveValue,float amount, int type, int bipolarSwitch){
	float outWaveValue;
	//powmapping

	return outWaveValue;
}

vec2 wrapCoord(vec2 coord,vec2 dim){
    
    if(abs(coord.x)>dim.x){coord.x=abs(dim.x-coord.x);}
    if(abs(coord.y)>dim.y){coord.y=abs(dim.y-coord.y);}
    
    coord.x=mod(coord.x,dim.x);
    coord.y=mod(coord.y,dim.y);
    
    
    
    return coord;
}

vec2 rotate(vec2 coord,float theta){
    vec2 center_coord=vec2(coord.x-width/2,coord.y-height/2);
    vec2 rotate_coord=vec2(0,0);
    float spiral=abs(coord.x+coord.y)/2*width;
    coord.x=spiral+coord.x;
    coord.y=spiral+coord.y;
    rotate_coord.x=center_coord.x*cos(theta)-center_coord.y*sin(theta);
    rotate_coord.y=center_coord.x*sin(theta)+center_coord.y*cos(theta);
    
    
    rotate_coord=rotate_coord+vec2(width/2,height/2);
    
    return rotate_coord;
    
    
}//endrotate

vec3 rgb2hsb(in vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsb2rgb(in vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

float colorQuantize(float inColor, float amount, float amountInvert){
	
	inColor=inColor*amount;
	inColor=floor(inColor);
	inColor=inColor*amountInvert;

	return inColor;
}

void main()
{
    vec2 texmod_coords=texCoordVarying
    -vec2(width/2,height/2);
    
    texmod_coords=texmod_coords*(1.0+osc0_texmod_scale);
    
    texmod_coords=texmod_coords+vec2(texmod_dimensions.x/2,texmod_dimensions.y/2);
    
    //texmod_coords=wrapCoord(texmod_coords,texmod_dimensions);
    
    
    vec4 texmod_color=texture2DRect(texmod,texmod_coords);
    if(abs(texmod_coords.x-texmod_dimensions.x/2)>=texmod_dimensions.x/2||abs(texmod_coords.y-texmod_dimensions.y/2)>=texmod_dimensions.y/2){
        texmod_color=vec4(0.0,0.0,0.0,1.0);
    }
    
    float texmod_bright=.299*texmod_color.r+.587*texmod_color.g+.114*texmod_color.b;
    
    vec4 color=vec4(0.0,0.0,0.0,1.0);
    
    
    vec4 osc_mod_1=texture2DRect(tex0,texCoordVarying-vec2(2.0,2.0));
    float om1_bright=.299*osc_mod_1.r+.587*osc_mod_1.g+.114*osc_mod_1.b;
    
    
    vec2 feedback_coords=texCoordVarying;
    
    //x mirror and y mirror biz
    //do this analog style maybe tho?
    if(osc0_feedback_x_mirror==1){
        if(texCoordVarying.x>width/2){
            feedback_coords.x=width-feedback_coords.x;
        }
    }
    
    if(osc0_feedback_y_mirror==1){
        if(texCoordVarying.y>height/2){
            feedback_coords.y=height-feedback_coords.y;
        }
    }
    
    feedback_coords=feedback_coords-vec2(width/2,height/2);
    
    feedback_coords=(1.0
                      +osc0_feedback_scale
                      +texmod_osc0_feedback_scale*texmod_bright
                      )*feedback_coords;
    feedback_coords=feedback_coords
    +vec2(osc0_feedback_x_displace
          +texmod_osc0_feedback_x_displace*texmod_bright
          ,osc0_feedback_y_displace
          +texmod_osc0_feedback_y_displace*texmod_bright)
    +vec2(feedback_dimensions.x/2,feedback_dimensions.y/2);
    
    
 
    
    feedback_coords=rotate(feedback_coords
                            ,osc0_feedback_rotate
                            +texmod_osc0_feedback_rotate*texmod_bright);
    vec4 feedback_color=texture2DRect(last_frame,feedback_coords);
    
    if(abs(feedback_coords.x-feedback_dimensions.x/2)>=feedback_dimensions.x/2||abs(feedback_coords.y-feedback_dimensions.y/2)>=feedback_dimensions.y/2){
        feedback_color=vec4(0.0,0.0,0.0,1.0);
    }
    
    
    
    float feedback_bright=.299*feedback_color.r+.587*feedback_color.g+.114*feedback_color.b;
    
    
    
    
    //ext input
    vec2 ext_input_coords=texCoordVarying;
    
    if(osc0_ext_input_x_mirror==1){
        if(texCoordVarying.x>width/2){
            ext_input_coords.x=width-ext_input_coords.x;
        }
    }
    
    if(osc0_ext_input_y_mirror==1){
        if(texCoordVarying.y>height/2){
            ext_input_coords.y=height-ext_input_coords.y;
        }
    }
    
    ext_input_coords=ext_input_coords-vec2(width/2,height/2);
    ext_input_coords=(1.0
                      +osc0_ext_input_scale
                      +texmod_osc0_ext_input_scale*texmod_bright
                      )*ext_input_coords;
    ext_input_coords=ext_input_coords
    +vec2(osc0_ext_input_x_displace
          +texmod_osc0_ext_input_x_displace*texmod_bright
          ,osc0_ext_input_y_displace
          +texmod_osc0_ext_input_y_displace*texmod_bright)
     +vec2(ext_input_dimensions.x/2,ext_input_dimensions.y/2);
    
    
    
    ext_input_coords=rotate(ext_input_coords
                            ,osc0_ext_input_rotate
                            +texmod_osc0_ext_input_rotate*texmod_bright);

    vec4 ext_input_color=texture2DRect(ext_input,ext_input_coords);
    
    if(abs(ext_input_coords.x-ext_input_dimensions.x/2)>=ext_input_dimensions.x/2||abs(ext_input_coords.y-ext_input_dimensions.y/2)>=ext_input_dimensions.y/2){
        ext_input_color=vec4(0.0,0.0,0.0,1.0);
    }
    
     float ext_input_bright=.299*ext_input_color.r+.587*ext_input_color.g+.114*ext_input_color.b;
    
    
    
    
    //oscillators
    vec2 m_axis=vec2(0.0,0.0);
    
    float osc0_spiral_new=(osc0_spiral+texmod_osc0_spiral*texmod_bright)
                          *distance(texCoordVarying, vec2(width/2,height/2));
    
    float osc0_m_spiral_new=(osc0_m_spiral
                             +texmod_osc0_m_spiral*texmod_bright
                             )*distance(texCoordVarying, vec2(width/2,height/2));
    
    float osc0_dummy=(osc0_amp
                     +texmod_osc0_amp*texmod_bright
                     )*oscillate(osc0_rate
                                +rotate(texCoordVarying,
                                        osc0_angle
                                        +texmod_osc0_angle*texmod_bright).x
                                *(osc0_frequency
                                  +texmod_osc0_frequency*texmod_bright)
                                ,osc0_shape
                                ,osc0_width
                                +texmod_osc0_width*texmod_bright
                                +(osc0_pwm
                                  +texmod_osc0_pwm*texmod_bright
                                  )*om1_bright);
    
    float osc0_m_dummy_arg=(osc0_m_feedback_pm
                            +texmod_osc0_m_feedback_pm*texmod_bright
                            )*feedback_bright
                            +osc0_m_rate
                            +osc0_m_spiral_new
                            +(rotate(texCoordVarying,
                                     osc0_m_angle
                                     +texmod_osc0_m_angle*texmod_bright
                                     +osc0_m_rotate
                                     +(osc0_m_modulation_rotate
                                       +texmod_osc0_m_modulation_rotate*texmod_bright
                                       )*osc0_dummy).x+.01)
                            *(osc0_m_frequency
                              +texmod_osc0_frequency*texmod_bright);
    
    
    float osc0_m_dummy=(osc0_m_amp
                        +texmod_osc0_amp*texmod_bright
                        )*oscillate(osc0_m_dummy_arg
                                 ,osc0_m_shape
                                 ,osc0_m_width
                                    +texmod_osc0_m_width*texmod_bright
                                    +(osc0_m_pwm
                                      +texmod_osc0_m_pwm*texmod_bright
                                      )*osc0_dummy
                                    +(osc0_m_pwm2
                                      +texmod_osc0_m_pwm2*texmod_bright
                                      )*om1_bright);
    
    
   
    
    
    m_axis=osc0_m_spiral_new
           +rotate(texCoordVarying
                   ,osc0_m_angle
                   +texmod_osc0_m_angle*texmod_bright
                   +osc0_m_rotate
                    +(osc0_m_modulation_rotate
                      +texmod_osc0_m_modulation_rotate*texmod_bright
                      )*osc0_dummy);
    
    float osc0_m_arg=osc0_m_rate+(m_axis.x+.01)
                        *(osc0_m_frequency
                          +texmod_osc0_m_frequency*texmod_bright)
                        +(osc0_m_feedback_pm
                          +texmod_osc0_m_feedback_pm*texmod_bright
                          )*feedback_bright;
    
    float osc0_m_width_dummy=osc0_m_width
                            +texmod_osc0_m_width*texmod_bright
                            +(osc0_m_pwm2
                              +osc0_m_pwm2*texmod_bright
                              )*om1_bright
                            +(osc0_m_pwm
                              +texmod_osc0_m_pwm*texmod_bright
                              )*osc0_dummy;
    
    float osc0_m=(osc0_m_amp
                  +texmod_osc0_m_amp*texmod_bright
                  )*oscillate(osc0_m_arg,osc0_m_shape,osc0_m_width_dummy);
    
    
    
    
    //try out this new filter thing
    
    
    float clampit=clamp(om1_bright-osc0_pm_cutoff-texmod_osc0_pm_cutoff*texmod_bright
                        ,0.0,1.0);
    
    
    float filtered_pm=om1_bright*(1.0-clampit)
                        +(osc0_pm_cutoff
                          +texmod_osc0_pm_cutoff*texmod_bright
                        )*clampit;
    
    //float filtered=om1_bright;
    //
    
    float filtered_rm=om1_bright*om1_bright;
    //float filtered_rm=om1_bright;
    
    vec2 axis=osc0_spiral_new
    +rotate(texCoordVarying,
            osc0_angle
            +texmod_osc0_angle*texmod_bright
            +osc0_rotate
            +(osc0_modulation_rotate
              +texmod_osc0_modulation_rotate*texmod_bright
              )*osc0_m
            +(osc0_modulation_rotate2
              +texmod_osc0_modulation_rotate2*texmod_bright
              )*om1_bright
            );
    
    float osc0_amp_dummy=osc0_amp
                        +texmod_osc0_amp*texmod_bright
                        +(osc0_rm
                        +texmod_osc0_rm*texmod_bright
                          )*filtered_rm
                        +(osc0_m_rm
                          +texmod_osc0_m_rm*texmod_bright
                          )*osc0_m
                        +(osc0_ext_input_rm
                          +texmod_osc0_ext_input_rm*texmod_bright
                          )*ext_input_bright
                        +(osc0_feedback_rm
                          +texmod_osc0_feedback_rm*texmod_bright
                          )*feedback_bright;
    
    float osc0_arg_dummy=osc0_rate
                        +axis.x*(osc0_frequency
                                 +texmod_osc0_frequency*texmod_bright
                                 +(osc0_m_pm
                                   +texmod_osc0_m_pm*texmod_bright
                                   )*osc0_m
                                 +(osc0_pm
                                   +texmod_osc0_pm*texmod_bright
                                   )*filtered_pm)
                        +feedback_bright*
                        (osc0_feedback_pm
                         +texmod_osc0_feedback_pm*texmod_bright)
                        +(osc0_ext_input_pm
                          +texmod_osc0_ext_input_pm*texmod_bright
                          )*ext_input_bright;
    
    float osc0_width_dummy=osc0_width
                          +texmod_osc0_width*texmod_bright
                          +(osc0_pwm
                            +texmod_osc0_pwm*texmod_bright
                            )*om1_bright
                          +(osc0_pwm2
                            +texmod_osc0_pwm2*texmod_bright
                            )*osc0_m;
    
    float osc0=osc0_amp_dummy*oscillate(osc0_arg_dummy,osc0_shape,osc0_width_dummy);
    
    //overflows
    color.rgb=vec3(osc0);
    if(osc0_overflow_switch==1){
        color.rgb=fract(abs(color.rgb));
    }
    
    if(osc0_overflow_switch==2){
        if(abs(color.r)>1.0){
            color.rgb=vec3(1.0)-fract(abs(color.rgb));
        }
    }
    
    if(osc0_overflow_switch==3){
        if(color.r>1.0){
            color.rgb=vec3(fract(color.r-tan(color.r*.25+osc0_arg_dummy)));
        }
    }
    
	//bitcrush
	color.r=mix( color.r, colorQuantize(color.r,osc0BitCrush,osc0BitCrushDenom), osc0BitCrushMix );
	color.g=color.r;
	color.b=color.r;

	//8 bands
	vec3 colorizedRgb=vec3(0,0,0);
	float osc0Bright=color.g;

	//assign bands
	vec3 colorizedHsb1=vec3(osc0HueBand1,osc0SaturationBand1,color.g+osc0BrightBand1);
	vec3 colorizedHsb2=vec3(osc0HueBand2,osc0SaturationBand2,color.g+osc0BrightBand2);
	vec3 colorizedHsb3=vec3(osc0HueBand3,osc0SaturationBand3,color.g+osc0BrightBand3);
	vec3 colorizedHsb4=vec3(osc0HueBand4,osc0SaturationBand4,color.g+osc0BrightBand4);
	vec3 colorizedHsb5=vec3(osc0HueBand5,osc0SaturationBand5,color.g+osc0BrightBand5);
	vec3 colorizedHsb6=vec3(osc0HueBand6,osc0SaturationBand6,color.g+osc0BrightBand6);
	vec3 colorizedHsb7=vec3(osc0HueBand7,osc0SaturationBand7,color.g+osc0BrightBand7);
	vec3 colorizedHsb8=vec3(osc0HueBand8,osc0SaturationBand8,color.g+osc0BrightBand8);

	//convert to rgb
	vec3 colorizedRgb1=hsb2rgb(colorizedHsb1);
	vec3 colorizedRgb2=hsb2rgb(colorizedHsb2);
	vec3 colorizedRgb3=hsb2rgb(colorizedHsb3);
	vec3 colorizedRgb4=hsb2rgb(colorizedHsb4);
	vec3 colorizedRgb5=hsb2rgb(colorizedHsb5);
	vec3 colorizedRgb6=hsb2rgb(colorizedHsb6);
	vec3 colorizedRgb7=hsb2rgb(colorizedHsb7);
	vec3 colorizedRgb8=hsb2rgb(colorizedHsb8);
	
	//soft keying together
	//skip the 1/8 and do increments of 1/7th insted
	if(color.g<.142){
		colorizedRgb=mix(colorizedRgb1,colorizedRgb2,color.g*7.0);
	}
	if(color.g>.142 && color.g<.284){
		colorizedRgb=mix(colorizedRgb2,colorizedRgb3,(color.g-.142)*7.0);
	}
	if(color.g>.284 && color.g<.426){
		colorizedRgb=mix(colorizedRgb3,colorizedRgb4,(color.g-.284)*7.0);
	}
	if(color.g>.426 && color.g<.568){
		colorizedRgb=mix(colorizedRgb4,colorizedRgb5,(color.g-.426)*7.0);
	}
	if(color.g>.568 && color.g<.71){
		colorizedRgb=mix(colorizedRgb5,colorizedRgb6,(color.g-.568)*7.0);
	}
	if(color.g>.71 && color.g<.852){
		colorizedRgb=mix(colorizedRgb6,colorizedRgb7,(color.g-.71)*7.0);
	}
	if(color.g>.852){
		colorizedRgb=mix(colorizedRgb7,colorizedRgb8,(color.g-.852)*7.0);
	}



	color.rgb=colorizedRgb;

	color.rgb=pow(color.rgb,vec3(osc0_powmod+texmod_osc0_powmod*texmod_bright));

    //temporal filter
    vec4 last_frame_color=texture2DRect(last_frame,texCoordVarying);
    color.rgb=mix(color.rgb
                  ,last_frame_color.rgb
                  ,osc0_temporal_filter
                  +texmod_osc0_temporal_filter*texmod_bright);
    
    gl_FragColor = color;
    //gl_FragColor = texmod_color;
   
}
