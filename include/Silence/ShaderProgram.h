#ifndef OPENGL_TUTORIAL_SILENCE_SHADER_PROGRAM_H
#define OPENGL_TUTORIAL_SILENCE_SHADER_PROGRAM_H

#include "Utility.h"

#include <string_view>


namespace sil {

class ShaderProgram {
public:
  ShaderProgram(const std::string_view vertex_shader_file, const std::string_view fragment_shader_file);
  ShaderProgram(unsigned int id)
    : id_{ id }
  {}

  SIL_DISABLE_COPY(ShaderProgram)

  SIL_DEFAULT_MOVE(ShaderProgram)

  ~ShaderProgram();  

  constexpr unsigned int id() const noexcept { return id_; }
  
  void use();

private:
  unsigned int id_;
};

} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_SHADER_PROGRAM_H 