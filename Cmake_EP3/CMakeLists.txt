cmake_minimum_required(VERSION 3.20.0)

project(YoonguuSong_Project)

# option1
# add_executable(${PROJECT_NAME} main.cpp adder.cpp)
add_executable(${PROJECT_NAME} main.cpp)

# option1
add_subdirectory(Adder)

#option2
add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
)
#?
message("hello")
target_link_libraries(${PROJECT_NAME} adder glfw)