# OpenGL_COMP3016---Joseph-Lines


Video:

Instructions now how to run:

Controls:
Use Mouse to move around
Use awsd to move around the scene.

Dpendences Used:
CMAKE/ASSIMP
OPENGL
GLEW/GLAD (GLAD is used)
GLFW
GLM
KHR - This apart of GLAD
LEARNOPENGL (Loading models, used within lab for loading models)

GamePlay Description:

Unfortunatly, the game isnt playable, however the user is able to move around the scene using their keyboard and mouse. The user is able to speed up by pressing shift. The user has the ability to move around smoothly. Whats in the scence? A signiture (image of my name),a 3D cube with mixed textures as well as a biome which has been split in half with sand and a planes biome.

Use of AI description:

AI has been used in an assistive capacity for learning as well as debugging. For example when storing indicies and verticies inside a vector and call the glVertexAttrivPointer, I wasnt passing a pointer correctly. AI was also used for learning. An example of this is when i wanted to find out more infromation about concepts such as how MVP worked as well as concepts like cross product when reading about the mathematics.

Below I have attached a pdf of some of the prompts to show how i used AI for learning and debugging.

Ai has been used in an assistive capacity to help enchance knowledge and has been used for debugging. 

[OpenGL_AI_PROMPTS.pdf](https://github.com/user-attachments/files/24498898/OpenGL_AI_PROMPTS.pdf)

All work is origonal. Below is a list of resources used to learn opengl and apply opengl:
LearnOpenGL: https://learnopengl.com/
COMP 3016 Labs
Stack Overflow - General bugs
Camera and Movement: https://www.youtube.com/watch?v=86_pQCKOIPk

Exception handling
I have included some examples of expection handling within the program.
<img width="473" height="208" alt="image" src="https://github.com/user-attachments/assets/d7c7b840-6d42-4e28-9e8b-a13a5780fbf8" />
Image above terminates the GLFW window if the window object is null


<img width="723" height="188" alt="image" src="https://github.com/user-attachments/assets/987fcf1c-f427-48a0-b567-773796a2e5fc" />
The image above shows that the user is unable to generate a texture if the data we get from stbi_loader is null
<img width="738" height="348" alt="image" src="https://github.com/user-attachments/assets/1d5128a3-f0d7-4cdf-b508-9ba8a11cee93" />
Within the 3D initialization class if another texture is not provided, the program crashes, this stops the program from crashing if a texture is not defined.


Testing







Evalution:

What was implemented was implemented well and to a good standard, however this project falls short of being playable. This project could be improved by more functionality by allowing the user into interact with different elements. The projects astectics could have been improved by implementing at a minium basic lighting. Somthing I that would done differently is allowing more time for the assigment, if more time was allowed a much better result could have been produced. Overall, this project could have been much better. 
