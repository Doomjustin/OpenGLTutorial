#include "ShaderProgram.h"
#include "VertexShader.h"
#include "FragmentShader.h"

#include <glad/glad.h>
#include <spdlog/spdlog.h>


namespace sil {

static constexpr int INFO_LOG_SIZE = 512;


ShaderProgram::ShaderProgram(const std::string_view vertex_shader_file, const std::string_view fragment_shader_file)
  : id_{ glCreateProgram() }
{
  VertexShader vertex_shader{ vertex_shader_file };
  FragmentShader fragment_shader{ fragment_shader_file };

  SPDLOG_INFO("Shader Program ID: {}", id_);

  glAttachShader(id_, vertex_shader.id());
  glAttachShader(id_, fragment_shader.id());
  glLinkProgram(id_);

  int success;
  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    char info_log[INFO_LOG_SIZE];
    glGetProgramInfoLog(id_, INFO_LOG_SIZE, nullptr, info_log);
    SPDLOG_WARN("Shader Program link error: {}", info_log);\

    glDeleteProgram(id_);
    throw "Shader Program link error";
  }
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(id_);
}

void ShaderProgram::use()
{
  glUseProgram(id_);
}

void ShaderProgram::uniform(const std::string& name, bool value) const
{
  glUniform1i(glGetUniformLocation(id_, name.c_str()), static_cast<int>(value));
}

void ShaderProgram::uniform(const std::string& name, int value) const
{
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::uniform(const std::string& name, float value) const
{
  glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::uniform(const std::string& name, float x, float y, float z, float w)
{
  glUniform4f(glGetUniformLocation(id_, name.c_str()), x, y, z, w);
}

void ShaderProgram::uniform(const std::string& name, float x, float y, float z)
{
  glUniform3f(glGetUniformLocation(id_, name.c_str()), x, y, z);
}

} // namespace sil