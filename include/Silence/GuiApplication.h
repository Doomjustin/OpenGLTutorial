#ifndef OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H
#define OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H

#include "Application.h"
#include "Utility.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>


namespace sil {

constexpr static const char* WINDOW_TITLE = "OpenGL Tutorial";


class GuiApplication: public Application {
public:
  GuiApplication(const std::string& title = WINDOW_TITLE);

  SIL_DISABLE_COPY(GuiApplication)
  
  SIL_DEFAULT_MOVE(GuiApplication)

  ~GuiApplication();

  int exec(int argc, char* argv[]) override;

private:
  GLFWwindow* window_;

  static int MajorVersion;
  static int MinirVersion;

  static int Width;
  static int Height;

  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

  void processInput();

  void tick();
};
  
} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H 