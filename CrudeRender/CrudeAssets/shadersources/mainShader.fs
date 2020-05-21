#version 410 core

layout (location = 0) out vec4 o_Colour;

uniform vec4 u_Colour;

void main()
{
    o_Colour = u_Colour;
}
