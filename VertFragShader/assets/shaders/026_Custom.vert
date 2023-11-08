
#version 450 core

in vec4 position;

out VS_OUT
{
    vec4 color;
} vs_out;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

// I don't understand why changing things here do not change my result
void main(void)
{
    gl_Position = vec4(1, 1, 1, 1);
    vs_out.color = vec4(1, 1, 1, 1);
}
