#version 430

out vec4 outColour;
in vec3 theColor;

void main()
{
   outColour = vec4(theColor, 1.0);
}

