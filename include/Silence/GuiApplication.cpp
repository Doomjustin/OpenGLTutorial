#include "GuiApplication.h"
#include "Silence/GuiApplication.h"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <cstdlib>


namespace sil {

int GuiApplication::MajorVersion = 3;
int GuiApplication::MinirVersion = 3;

int GuiApplication::Width = 800;
int GuiApplication::Height = 600;

void GuiApplication::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  // make sure the viewport matches the new window dimensions; note that width and 
  // height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}


GuiApplication::GuiApplication(const std::string& title)
  : Application{}, 
    window_{ nullptr }
{
  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MajorVersion);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MinirVersion);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window_ = glfwCreateWindow(Width, Height, title.c_str(), NULL, NULL);
  if (window_ == nullptr) {
    SPDLOG_ERROR("Failed to create GLFW window");
    glfwTerminate();
    throw "Failed to create GLFW window";
  }

  glfwMakeContextCurrent(window_);
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
  
  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    SPDLOG_ERROR("Failed to initialize GLAD");    
    throw "Failed to initialize GLAD";
  }    
} 

GuiApplication::~GuiApplication()
{
  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
}

int GuiApplication::exec(int argc, char* argv[])
{

  while (!glfwWindowShouldClose(window_)) {
    tick();
  }

  return EXIT_SUCCESS;
}

void GuiApplication::tick()
{
  processInput();

  // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
  // -------------------------------------------------------------------------------
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void GuiApplication::processInput()
{
  if(glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window_, true);
}

} // namespace sil