#include "FragmentShader.h"

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <fstream>


namespace sil {

static constexpr int INFO_LOG_SIZE = 512;

FragmentShader::FragmentShader(const std::string_view shader_file)
  : id_{ glCreateShader(GL_FRAGMENT_SHADER) },
    file_{ shader_file },
    source_{}
{
  std::fstream fs{ file_ };
  // 读出所有数据
  while (fs)
    fs >> source_;

  SPDLOG_INFO("Fragment Shader ID: {}", id_);
  SPDLOG_INFO("Fragment Shader Source: {}", source_);

  const char* source_code = source_.c_str();
  glShaderSource(id_, 1, &source_code, nullptr);

  glCompileShader(id_);
  int success;
  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);

  if (!success) {
    char info_log[INFO_LOG_SIZE];
    glGetShaderInfoLog(id_, INFO_LOG_SIZE, nullptr, info_log);
    SPDLOG_WARN("Fragment Shader compile error: {}", info_log);

    glDeleteShader(id_);
    throw "Fragment Shader compile error";
  }
}

FragmentShader::~FragmentShader()
{
  glDeleteShader(id_);
}

} // namespace sil