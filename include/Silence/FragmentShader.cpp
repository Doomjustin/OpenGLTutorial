#include "FragmentShader.h"
#include "Config.h"
#include "Utility.h"

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <fstream>
#include <sstream>

namespace sil {

static constexpr int INFO_LOG_SIZE = 512;

FragmentShader::FragmentShader(const std::string_view shader_file)
  : id_{ glCreateShader(GL_FRAGMENT_SHADER) },
    file_{ shader_file },
    source_{}
{
  SPDLOG_INFO("Fragment Shader ID: {}", id_);

  if (file_.starts_with(":"))
    file_ = std::string{ RESOURCE_DIR } + '/' + trim(file_.substr(1));
  else
    file_ = trim(file_);

  std::fstream fs{};
  std::stringstream source_ss{};
  // 读出所有数据
  try {
    fs.open(file_);
    source_ss << fs.rdbuf();
    fs.close();
  }
  catch (std::ifstream::failure e) {
    SPDLOG_ERROR("read file {} error", file_);
    throw e;
  }

  source_ = source_ss.str();

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
  SPDLOG_INFO("Fragment Shader[id={}] compile succeed", id_);
}

FragmentShader::~FragmentShader()
{
  glDeleteShader(id_);
  SPDLOG_INFO("Vertex Shader[id={}] deleted", id_);
}

} // namespace sil