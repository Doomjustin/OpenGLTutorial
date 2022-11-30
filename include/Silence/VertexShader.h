#ifndef OPENGL_TUTORIAL_SILENCE_VERTEX_SHADER_H
#define OPENGL_TUTORIAL_SILENCE_VERTEX_SHADER_H

#include "Utility.h"

#include <string>
#include <string_view>


namespace sil {

class VertexShader {
public:
  VertexShader(const std::string_view file);

  SIL_DISABLE_COPY(VertexShader)

  SIL_DEFAULT_MOVE(VertexShader)

  ~VertexShader();

  constexpr unsigned int id() const noexcept { return id_; }
  std::string source() const noexcept { return source_; }
  const std::string source() noexcept { return source_; }

private:
  unsigned int id_;
  std::string file_;
  std::string source_;
};

} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_VERTEX_SHADER_H