cmake_minimum_required(VERSION 3.14)

project(MyProject VERSION 1.0.0)
set (USE_BOOST_DYNAMIC_LIBRARIES ON)
message(" USE_BOOST_DYNAMIC_LIBRARIES : ${USE_BOOST_DYNAMIC_LIBRARIES}")
message("this is MyProejct")
#add_executable(cmake-good main.cpp)
add_executable(cmake_good main.cpp)
