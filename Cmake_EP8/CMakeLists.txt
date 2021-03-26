cmake_minimum_required(VERSION 3.20.0)

project(YoonguuSong_Project VERSION 1.0)


#new lines for using find_library()
#FIND LIBRARY FOR CMAKE 3.13.4 (NO [REQUIRED] IN CMAKE YET)
find_library(myglewlib glew NAMES glew2 GLEW GLEW2 DOC "glew library")
message("myglewlib : ${myglewlib}")
if (${myglewlib})
    message(FATAL_ERROR "no glew, sad day")
else()
    message(STATUS "glew directory :  ${myglewlib}")
endif()

find_library(myglulib glu NAMES GLU DOC "glu library")
if (${myglulib})
    message(FATAL_ERROR "no glu, sad day")
else()
    message(STATUS "glu directory :  ${myglulib}")
endif()

find_library(mygllib gl NAMES GL DOC "gl library")
if (${myglewlib})
    message(FATAL_ERROR "no gl, sad day")
else()
    message(STATUS "gl directory :  ${mygllib}")
endif()



option(USE_ADDER "A simple library for adding 2 floats" ON)
if(USE_ADDER)
    message("USE_ADDER : ${USE_ADDER}")
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIB_DIRS "Adder")
    message("EXTRA_LIB_DIRS : ${EXTRA_LIB_DIRS}")

    list(APPEND EXTRA_INCLUDE_DIRS "Adder")
    message("EXTRA_INCLUDE_DIRS : ${EXTRA_INCLUDE_DIRS}")

    list(APPEND EXTRA_LINKS adder)
    message("EXTRA_LINKS : ${EXTRA_LINKS}")
    
endif()

configure_file(YGconfig.h.in YGconfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})








add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/src
    ${EXTRA_LIB_DIRS}
)


target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)


install(TARGETS ${PROJECT_NAME} DESTINATION bin)
message("DESTINATION : ${DESTINATION}")
install(FILES "${PROJECT_BINARY_DIR}/YGconfig.h" DESTINATION include)
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")


include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)



