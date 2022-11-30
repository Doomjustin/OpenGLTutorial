#ifndef OPENGL_TUTORIAL_SILENCE_FRAGMENT_SHADER_H
#define OPENGL_TUTORIAL_SILENCE_FRAGMENT_SHADER_H

#include "Utility.h"

#include <string>
#include <string_view>


namespace sil {

class FragmentShader {
public:
  FragmentShader(const std::string_view shader_file);

  SIL_DISABLE_COPY(FragmentShader)

  SIL_DEFAULT_MOVE(FragmentShader)

  ~FragmentShader();

  constexpr unsigned int id() const noexcept { return id_; }
  // 目测没什么用，可以优化
  std::string source() const noexcept { return source_; }
  const std::string source() noexcept { return source_; }

private:
  unsigned int id_;
  std::string file_;
  std::string source_;
};


} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_FRAGMENT_SHADER_H 