add_executable(hello-triangle hello_triangle.cpp)
target_link_libraries(hello-triangle PRIVATE glfw glad::glad)

SET_TARGET_PROPERTIES(hello-triangle 
  PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/chapter2/)