add_executable(hello-shader hello_shader.cpp)

target_link_libraries(hello-shader PRIVATE glfw glad::glad Silence::Silence)

SET_TARGET_PROPERTIES(hello-shader 
  PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/chapter3/)