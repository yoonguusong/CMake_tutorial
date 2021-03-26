#this is for level
add_library(adder adder.cpp)

#new line for installing
install(TARGETS adder DESTINATION lib)
install(FILES adder.h DESTINATION include)