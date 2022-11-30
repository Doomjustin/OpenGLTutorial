set(SILENCE_RESOURCE_DIR ${PROJECT_SOURCE_DIR}/resource)
message(STATUS "[Silence] resource dir: ${SILENCE_RESOURCE_DIR}")

set(SILENCE_CONFIG_FILE ${PROJECT_SOURCE_DIR}/resource/application.json)
message(STATUS "[Silence] config file: ${SILENCE_CONFIG_FILE}")

configure_file(
  ${PROJECT_SOURCE_DIR}/include/Silence/Config.h.in
  ${PROJECT_SOURCE_DIR}/include/Silence/Config.h
)


add_library(Silence
  STATIC 
    Application.h
    GuiApplication.h
    Utility.h    
    Config.h
    FragmentShader.h
    VertexShader.h
    ShaderProgram.h
    GuiApplication.cpp
    FragmentShader.cpp
    VertexShader.cpp
    ShaderProgram.cpp
)

target_link_libraries(Silence PRIVATE fmt::fmt spdlog::spdlog glfw glad::glad)
target_include_directories(Silence PUBLIC ${PROJECT_SOURCE_DIR}/include/)

add_library(Silence::Silence ALIAS Silence)