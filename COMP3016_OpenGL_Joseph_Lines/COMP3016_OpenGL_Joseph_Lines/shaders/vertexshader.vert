//specify type of opengl as well as version of openGL
#version 460 core
//declare input vertex attributes in vertex shader - only using positoon data. Vec3 because 3D cord
layout (location = 0) in vec3 vecIn;

void main()
{
  gl_Position = vec4(vecIn.x,vecIn.y,vecIn.z, 1.0);
}