cmake_minimum_required(VERSION 3.20.0)

project(YoonguuSong_Project VERSION 1.0)

#here is code that changed
#make file YGconfig.h.in, YGconfig.h
configure_file(YGconfig.h.in YGconfig.h)

add_executable(${PROJECT_NAME} main.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
message(" PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")



add_subdirectory(Adder)


add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
)


target_link_libraries(${PROJECT_NAME} adder glfw)