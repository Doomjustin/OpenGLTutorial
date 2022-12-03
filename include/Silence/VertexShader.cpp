#include "VertexShader.h"
#include "Config.h"
#include "Utility.h"

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <fstream>


namespace sil {

static constexpr int INFO_LOG_SIZE = 512;

VertexShader::VertexShader(const std::string_view file)
  : id_{ glCreateShader(GL_VERTEX_SHADER) },
    file_{ file },
    source_{}
{
  if (file_.starts_with(":"))
    file_ = std::string{ RESOURCE_DIR } + '/' + trim(file_.substr(1));
  else
    file_ = trim(file_);

  std::fstream fs{ file_ };
  // 读出所有数据
  std::string line;
  while (fs) {
    std::getline(fs, line);
    source_ += (line + '\n');
    line.clear();
  }
  SPDLOG_INFO("Vertex Shader ID: {}", id_);
  SPDLOG_INFO("Vertex Shader Source: {}", source_);

  const char* source_code = source_.c_str();
  glShaderSource(id_, 1, &source_code, nullptr);

  glCompileShader(id_);
  int success;
  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);

  if (!success) {
    char info_log[INFO_LOG_SIZE];
    glGetShaderInfoLog(id_, INFO_LOG_SIZE, nullptr, info_log);
    SPDLOG_WARN("Vertex Shader compile error: {}", info_log);
    
    glDeleteShader(id_);
    throw "Vertex Shader compile error";
  }
}

VertexShader::~VertexShader()
{
  glDeleteShader(id_);
}

} // namespace sil