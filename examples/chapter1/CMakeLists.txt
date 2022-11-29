add_executable(hello-window hello_window.cpp)
target_link_libraries(hello-window PRIVATE glfw glad::glad Silence::Silence)

SET_TARGET_PROPERTIES(hello-window 
  PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/chapter1/)