#version 460
out vec4 FragColor;
out vec4 textureOut;
in vec3 ourColour;
in vec2 FragCord;
uniform sampler2D TextureUnifor;



void main()
{
  textureOut = texture(TextureUnifor, FragCord);
  //FragColor = vec4(ourColour, 1.0f);
	
    

}