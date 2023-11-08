#version 450 core

layout(vertices = 3) out;

uniform float inner;
uniform float outer;

void main() {
    if (gl_InvocationID == 0) {

        gl_TessLevelInner[0] = inner;
        gl_TessLevelOuter[0] = outer;
        gl_TessLevelOuter[1] = outer;
        gl_TessLevelOuter[2] = outer;
    }

    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}