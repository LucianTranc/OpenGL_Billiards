# OpenGL Billiards
A billiards physics simulator that lets the user interact with ball collision physics and play billiards by themselves :( (local multiplayer will be the next feature)

# Demo
https://www.youtube.com/watch?v=SN1hIYnKvBE&ab_channel=LuciTranc

# What I Learned
* C++ Experience
* C++ Class abstraction
* Basic OpenGL rendering techiques

# To Compile
* To run this game you must have the OpenGL function definitions in your system somewhere. I created this game on MacOS were it comes preinstalled. I use -framework OpenGL
in the linking stage but this might differ on other operating systems
* I use SDL2, SDL2_image and SDL2_ttf in this project. These can be downloaded from https://www.libsdl.org/download-2.0.php, https://www.libsdl.org/projects/SDL_ttf/, https://www.libsdl.org/projects/SDL_image/
* The INC_PATH variable in the makefile might need to be modified to point to where you store these libraries in your system.
* run "make"
