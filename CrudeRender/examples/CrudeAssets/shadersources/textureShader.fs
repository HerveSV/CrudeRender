#version 410 core

out vec4 FragColour;

in vec2 v_TexCoord;

uniform sampler2D u_Texture1;

void main()
{
    vec4 tex1 = texture(u_Texture1, v_TexCoord);
    FragColour = tex1;
}

