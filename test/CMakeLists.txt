list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(AddCatch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)


add_executable(test-shader test_shader.cpp)
target_link_libraries(test-shader PRIVATE Silence::Silence glfw spdlog::spdlog glad::glad)