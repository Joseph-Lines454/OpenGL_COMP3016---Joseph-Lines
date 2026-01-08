# OpenGL_COMP3016---Joseph-Lines


Video:

Instructions now how to run:

Controls:
Use Mouse to move around
Use awsd to move around the scene.

Dpendences Used:
CMAKE/ASSIMP
OPENGL
GLEW/GLAD (GLAD is used) KHR is within opengl folder and is apart of GLAD
GLFW
GLM
LEARNOPENGL (Loading models, used within lab for loading models)
FastNoiseLite.h


GamePlay Description:

Unfortunatly, the game isnt playable, however the user is able to move around the scene using their keyboard and mouse. The user is able to speed up by pressing shift. The user has the ability to move around smoothly. Whats in the scence? A signiture (image of my name),a 3D cube with mixed textures as well as a biome which has been split in half with sand and a planes biome.

Use of AI description:

AI has been used in an assistive capacity for learning as well as debugging. For example when storing indicies and verticies inside a vector and call the glVertexAttrivPointer, I wasnt passing a pointer correctly. AI was also used for learning. An example of this is when i wanted to find out more infromation about concepts such as how MVP worked as well as concepts like cross product when reading about the mathematics.

Below I have attached a pdf of some of the prompts to show how i used AI for learning and debugging.

Ai has been used in an assistive capacity to help enchance knowledge and has been used for debugging. 

[OpenGL_AI_PROMPTS.pdf](https://github.com/user-attachments/files/24498898/OpenGL_AI_PROMPTS.pdf)


All work is origonal. Below is a list of resources used to learn opengl and apply opengl:
LearnOpenGL: https://learnopengl.com/ - Main resource for learning and applying openGL
COMP 3016 Labs (used this for procedural generation)
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
Camera and Movement Test Table

<img width="643" height="470" alt="image" src="https://github.com/user-attachments/assets/cd7b2a5b-e232-49a9-af55-98c21e1f9074" />

Model Loading Test Table

<img width="625" height="374" alt="image" src="https://github.com/user-attachments/assets/9b39a609-55cf-4386-b4b1-391ae1519691" />

Textures/Mixing Textures Test Table

<img width="636" height="393" alt="image" src="https://github.com/user-attachments/assets/2050fcf8-de5c-4522-8605-fa0da78e58d6" />

Rendering Shape

<img width="658" height="570" alt="image" src="https://github.com/user-attachments/assets/9a84016b-adaa-4ad8-a2a2-045abd1e5793" />



Sample Screens

Image of main play area (Rendering Biomes as well as objects)

<img width="1050" height="613" alt="image" src="https://github.com/user-attachments/assets/08bfc167-fabd-49a2-8349-f4af4f52b726" />

<img width="1279" height="711" alt="image" src="https://github.com/user-attachments/assets/2f7bb8a0-f626-4f14-919d-05461c1cda26" />

UML Diagrams

<img width="1252" height="809" alt="image" src="https://github.com/user-attachments/assets/f6e3615c-6b87-485b-9ad4-01f8815e3fa2" />




Evalution:

What was implemented was implemented well and to a good standard, however this project falls short of being playable. This project could be improved by more functionality by allowing the user into interact with different elements. The projects astectics could have been improved by implementing at a minium basic lighting. Somthing I that would done differently is allowing more time for the assigment, if more time was allowed a much better result could have been produced. Overall, this project could have been much better. 
