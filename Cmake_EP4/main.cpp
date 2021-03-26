#include <iostream>


#include "Adder/adder.h"
#include <GLFW/glfw3.h>
//here is code that changed
#include <YGconfig.h>


int main(int argc, char * argv[])
{
    std::cout << "hello form CMake Tutorial EP4 | Versioning Source Code\n"; 
    std::cout << add(100.1f ,150.2f)<< '\n';
    std::cout<< argv[0]<< "Version  : YG_VERSION_MAJOR "<< YG_VERSION_MAJOR << " YG_VERSION_MINOR" << YG_VERSION_MINOR <<'\n';
    GLFWwindow* window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();



    return 0;
}