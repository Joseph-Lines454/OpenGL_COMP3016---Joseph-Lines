#version 460
out vec4 FragColour;
out vec4 textureOut;
in vec3 ourColour;
in vec2 FragCord;
uniform sampler2D TextureUnifor;
uniform bool istextureTrue;
uniform bool isMultipletextureTrue;
uniform vec3 ColourUni;

uniform sampler2D textureOne;
uniform sampler2D textureTwo;

void main()
{   
   if (istextureTrue)
    FragColour = mix(texture(textureOne, FragCord), texture(textureTwo, FragCord), 0.5);
   
   else
    FragColour = vec4(ourColour,1.0f);

}
