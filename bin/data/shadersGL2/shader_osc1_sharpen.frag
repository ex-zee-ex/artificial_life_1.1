#version 120


uniform sampler2DRect tex0;

uniform sampler2DRect texmod;

varying vec2 texCoordVarying;

uniform float osc1_sharpen_amount;
uniform float osc1_sharpen_boost;
uniform float osc1_sharpen_radius;

uniform float texmod_osc1_sharpen_amount;
uniform float texmod_osc1_sharpen_boost;
uniform float texmod_osc1_sharpen_radius;

uniform float width;
uniform float height;

uniform vec2 texmod_dimensions;

vec3 rgb2hsb(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsb2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}


void main()
{
    
    vec4 color_sharpen=vec4(0.0,0.0,0.0,1.0);
    
    vec2 texmod_coords=texCoordVarying
    -vec2(width/2,height/2)
    +vec2(texmod_dimensions.x/2,texmod_dimensions.y/2);
    vec4 texmod_color=texture2DRect(texmod,texmod_coords);
    if(abs(texmod_coords.x-texmod_dimensions.x/2)>=texmod_dimensions.x/2||abs(texmod_coords.y-texmod_dimensions.y/2)>=texmod_dimensions.y/2){
        texmod_color=vec4(0.0,0.0,0.0,1.0);
    }
    float texmod_bright=texmod_color.r*.299+texmod_color.g*.587+texmod_color.b*.114;
    
    float sharpen_radius_mod=texmod_bright*texmod_osc1_sharpen_radius+osc1_sharpen_radius;
    
    /*
     unsharp mask zones
    vec3 color_unsharp=texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius,sharpen_radius)).rgb
                      +texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius,-sharpen_radius)).rgb
                      +texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius,-sharpen_radius)).rgb
                      +texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius,sharpen_radius)).rgb;
    
    color_unsharp*=.25;
    
    color_sharpen.rgb=texture2DRect(tex0,texCoordVarying).rgb-sharpen_amount*color_unsharp;
     
     */
    float color_sharpen_bright=0.0;
    
    color_sharpen_bright=
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,0)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,0)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(0,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(0,-sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius_mod,-sharpen_radius_mod)).rgb).z+
    rgb2hsb(texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius_mod,-sharpen_radius_mod)).rgb).z;
    
    color_sharpen_bright=color_sharpen_bright/8.0;
    
    vec4 original_color=texture2DRect(tex0,texCoordVarying);
    vec3 original_color_hsb=rgb2hsb(original_color.rgb);
    original_color_hsb.z-=(osc1_sharpen_amount
                           +texmod_osc1_sharpen_amount*texmod_bright
                           )*color_sharpen_bright;
    
    //original_color_hsb.z*=(1.0+sharpen_boost+texmod_sharpen_boost*texmod_bright);
    //original_color_hsb.z*=(1.0+abs(sharpen_amount)*2.0);
    if(osc1_sharpen_amount>0){
        original_color_hsb.z*=(1.0+osc1_sharpen_amount*2.0);
    }
    color_sharpen=vec4(hsb2rgb(original_color_hsb),1.0);
    
    /*
    color_sharpen.rgb=
                texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius,0)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius,0)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(0,sharpen_radius)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(0,-sharpen_radius)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius,sharpen_radius)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius,sharpen_radius)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(sharpen_radius,-sharpen_radius)).rgb+
                texture2DRect(tex0,texCoordVarying+vec2(-sharpen_radius,-sharpen_radius)).rgb;
    
     
    
    
    
    color_sharpen=texture2DRect(tex0,texCoordVarying)-sharpen_amount*color_sharpen;
    
    */
  //color_sharpen=color_sharpen/9;
    
    
    /*
    vec3 color_sharpen_hsb=rgb2hsv(vec3(color_sharpen.r,color_sharpen.g,color_sharpen.b));
    
    color_sharpen_hsb.b=(sharpen_boost+1.0)*color_sharpen_hsb.b;
    
    color_sharpen_hsb.b=(sharpen_boost+1.0)*color_sharpen_hsb.b;
    
    color_sharpen=vec4(hsv2rgb(vec3(color_sharpen_hsb.r,color_sharpen_hsb.g,color_sharpen_hsb.b)),1.0);
   */
    
    //color_sharpen.rgb=1.0-color_sharpen.rgb;
    
    
    
    gl_FragColor =color_sharpen;
}
