#version 460
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 textureIn;

out vec3 ourColour;
out vec2 FragCord;
uniform mat4 Model_View_Projection;


void main()
{
  gl_Position = Model_View_Projection * vec4(aPos.x,aPos.y,aPos.z, 1.0);
  ourColour = aColour;
  FragCord = textureIn;
}