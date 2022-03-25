#version 330 core

out vec4 frag_color;

//TODO(DONE): Define uniforms for the slope and the intercept

uniform float slope;
uniform float intercept;

uniform vec4 inside_color = vec4(1.0, 0.0, 0.0, 1.0);
uniform vec4 outside_color = vec4(0.0, 0.0, 0.0, 1.0);

void main(){
    //TODO(DONE): Write code that will draw the square
    float line = slope * gl_FragCoord.x + intercept;
    if(gl_FragCoord.y <= line){
        frag_color = inside_color;
    }
    else{
        frag_color = outside_color;
    }
}