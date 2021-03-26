cmake_minimum_required(VERSION 3.20.0)

project(YoonguuSong_Project VERSION 1.0)

#here is code that changed
#adder use logic
option(USE_ADDER "A simple library for adding 2 floats" ON)
if(USE_ADDER)
    message("USE_ADDER : ${USE_ADDER}")
    add_subdirectory(Adder)

    #library that we defined in subdirectory CMakeLists.txt in Adder folder is adder
    list(APPEND EXTRA_LIB_DIRS "Adder")
    message("EXTRA_LIB_DIRS : ${EXTRA_LIB_DIRS}")

    list(APPEND EXTRA_INCLUDE_DIRS "Adder")
    message("EXTRA_INCLUDE_DIRS : ${EXTRA_INCLUDE_DIRS}")

    #be aware of "" below
    list(APPEND EXTRA_LINKS adder)
    message("EXTRA_LINKS : ${EXTRA_LINKS}")
    # target_include_directories(${PROJECT_NAME} 
    # PUBLIC Adder 
    # # PUBLIC external/glfw/include
    # )

    # target_link_directories(${PROJECT_NAME} 
    # PRIVATE Adder
    # # PRIVATE external/glfw/src
    # )
endif()

configure_file(YGconfig.h.in YGconfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")







add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    # PUBLIC Adder 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    # PRIVATE Adder
    PRIVATE external/glfw/src
    ${EXTRA_LIB_DIRS}
)


target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)