#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

void error_callback(int error, const char *description) {
  std::cerr << "Error#" << error << ":" << description << std::endl;
}

int main() {
  const char *TITLE = "Create Window";
  const int SCREEN_WIDTH = 16 * 40;
  const int SCREEN_HEIGHT = 9 * 40;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    return EXIT_FAILURE;
  }
  atexit(glfwTerminate);

  auto window =
      glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE, nullptr, nullptr);
  if (!window) {
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // clang-format off
  std::cout
      << "\nGL Vendor: " << glGetString(GL_VENDOR)
      << "\nGL Renderer: " << glGetString(GL_RENDERER)
      << "\nGL Version: " << glGetString(GL_VERSION)
      << "\nGLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
      << std::endl;
  // clang-format on

  if (auto r = glewInit(); r != GLEW_OK) {
    std::cerr << "Error: " << glewGetErrorString(r) << std::endl;
    return EXIT_FAILURE;
  }

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  return EXIT_SUCCESS;
}