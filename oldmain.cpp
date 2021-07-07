#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <SDL.h>
#include <OpenGL/gl3.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

int main (int argc, char* argv[]) {
	
	SDL_Init(SDL_INIT_VIDEO);
    std::cout << "Subsystems initialized\n";

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window *window = SDL_CreateWindow(
        "SDL/OpenGL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1200,
        600,
        SDL_WINDOW_OPENGL);
    if (window)
        std::cout << "Window Created\n";


    SDL_GL_CreateContext(window);
    
    SDL_Event event;
    int running = 1;

    float posx = 0.0f;
    float posy = 0.0f;

    float width = 250.0f;
    float height = 250.0f;

    float positions[] {
        posx,  posy + height, 0.0f, 0.0f, //bottomleft
        posx,  posy, 1.0f, 0.0f, //topleft
        posx + width, posy, 1.0f, 1.0f, //topright
        posx + width, posy + height, 0.0f, 1.0f, //bottomright
    };

    unsigned int indicies[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    VertexArray va;
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indicies, 6);

    glm::mat4 proj = glm::ortho(0.0, 1200.0, 600.0, 0.0);

    Shader shader("shaders/basic.shader");
    shader.Bind();
    //shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
    shader.SetUniformMat4f("u_MVP", proj);
    
    Texture texture("assets/blackcircle1.png");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

    Renderer renderer;

    //float r = 0.0f;
    //float increment = 0.05f;

    glClearColor(0.0f, 0.7f, 0.2f, 1.0f);

    glm::vec3 translationA(500, 100, 0);
    glm::vec3 translationB(100, 200, 0);

    while(running) {
        
        renderer.Clear();
        
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
            glm::mat4 mvp = proj * model;
            shader.SetUniformMat4f("u_MVP", mvp);
            
            renderer.Draw(va, ib, shader);
        }

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
            glm::mat4 mvp = proj * model;
            shader.SetUniformMat4f("u_MVP", mvp);
            
            renderer.Draw(va, ib, shader);
        }
        //GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

        /* if (r < 0.0f)
            increment = 0.05f;
        else if (r > 1.0f)
            increment = -0.05f;
        
        r += increment; */

        SDL_GL_SwapWindow(window);

        

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            
        }
    
    }

    std::cout<<glGetString(GL_VERSION)<<std::endl;
    
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

