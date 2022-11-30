add_executable(base-template base_template.cpp)
target_link_libraries(base-template PRIVATE spdlog::spdlog glad::glad glfw fmt::fmt Silence::Silence)

add_subdirectory(chapter1)
add_subdirectory(chapter2)