cmake_minimum_required(VERSION 3.14)
project(CreateWindow)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL OpenGL::GLU)
target_link_libraries(${PROJECT_NAME} PRIVATE glew_s glfw glm::glm)