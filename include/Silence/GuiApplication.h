#ifndef OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H
#define OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H

#include "Application.h"
#include "Utility.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <array>


namespace sil {

constexpr static const char* WINDOW_TITLE = "OpenGL Tutorial";

constexpr static const std::array<float, 4> DEFAULT_COLOR{ 0.2f, 0.3f, 0.3f, 1.0f };


class GuiApplication: public Application {
public:
  GuiApplication(const std::string& title = WINDOW_TITLE, const std::array<float, 4>& color = DEFAULT_COLOR);

  SIL_DISABLE_COPY(GuiApplication)
  
  SIL_DEFAULT_MOVE(GuiApplication)

  ~GuiApplication();

  int exec(int argc, char* argv[]) override;

  void clear_color(const std::array<float, 4> color) noexcept { clear_color_ = color; }

private:
  GLFWwindow* window_;
  std::array<float, 4> clear_color_;

  static int MajorVersion;
  static int MinirVersion;

  static int Width;
  static int Height;

  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

  void processInput();
  void tick();
  void clear();
};
  
} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_GUI_APPLICATION_H 