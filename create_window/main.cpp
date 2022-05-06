#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

void error_callback(int err, const char *msg) {
  std::cerr << "#" << err << ":" << msg << std::endl;
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

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  return EXIT_SUCCESS;
}