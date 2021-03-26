#include <iostream>

//here is code that changed
// #include "Adder/adder.h"
#include <GLFW/glfw3.h>
#include <YGconfig.h>
#ifdef USE_ADDER
    //because our header is lowercase in Adder subdirectory
    #include <adder.h>
#endif



int main(int argc, char* argv[])
{
    std::cout << "hello form CMake Tutorial EP5 | Making Libs Optional\n"; 
    
    //here is code that changed
#ifdef USE_ADDER
    std::cout << "using Adder lib : " << add(100.1f ,150.2f)<< '\n';
#else
    std::cout << "without add"<< '\n';
#endif

    std::cout<< argv[0]<< "Version  : YG_VERSION_MAJOR "<< YG_VERSION_MAJOR << " YG_VERSION_MINOR : " << YG_VERSION_MINOR <<'\n';
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