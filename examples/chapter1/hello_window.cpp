#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Silence/GuiApplication.h>

#include <cstdlib>
#include <iostream>


int main(int argc, char* argv[])
{
  sil::Application* app = new sil::GuiApplication{};
  app->exec(argc, argv);

  return 0;
}