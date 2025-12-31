#version 460
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 textureIn;
out vec3 ourColour;
out vec2 FragCord;
void main()
{
  //Vertex data does not need to be passed out
  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
  //Colour data needs to go to fragementshader
  ourColour = aColour;
  //TextureCord needs to go to fragementshader
  FragCord = textureIn;
}