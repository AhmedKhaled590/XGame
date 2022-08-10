<<<<<<< HEAD
#version 330 core

void main(){
    const vec3 TRIANGLE[3] = vec3[3](
        vec3(-1.0, -1.0, 0.0),
        vec3( 3.0, -1.0, 0.0),
        vec3(-1.0,  3.0, 0.0)
    );

    gl_Position = vec4(TRIANGLE[gl_VertexID], 1.0);
=======
#version 330

out vec2 tex_coord;

void main(){

    // These positions and their texture coordinates define a fullscreen triangle 
    vec2 positions[] = vec2[](
        vec2(-1.0, -1.0),
        vec2( 3.0, -1.0),
        vec2(-1.0,  3.0)
    );

    // The texture coordinates are picked such that the texture coordinates
    // at the bottom left corner of the screen are (0,0) and
    // at the top right corner of the screen are (1,1)
    vec2 tex_coords[] = vec2[](
        vec2( 0.0,  0.0),
        vec2( 2.0,  0.0),
        vec2( 0.0,  2.0)
    );

    gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);
    tex_coord = tex_coords[gl_VertexID];
>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
}