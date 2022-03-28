#version 330 core

out vec4 frag_color;

//TODO(DONE): Define uniforms for the center and the side-length
uniform vec2 center;
uniform float side_length;
uniform vec4 inside_color = vec4(1.0, 0.0, 0.0, 1.0);
uniform vec4 outside_color = vec4(0.0, 0.0, 0.0, 1.0);

void main(){
    //TODO(DONE): Write code that will draw the diamond
   //draw a diamond ∣x − xc  ∣ + ∣y − yc  ∣
    //where xc and yc are the center coordinates and side_length is the side length
    //the diamond should be filled with the inside color
    //the outside should be the outside color
    //the diamond should be centered at the origin
    float x = abs(gl_FragCoord.x - center.x);
    float y = abs(gl_FragCoord.y - center.y);
    if(x + y <= side_length/2){
        frag_color = inside_color;
    }
    else{
        frag_color = outside_color;
    }


}