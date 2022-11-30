#ifndef OPENGL_TUTORIAL_SILENCE_VERTEX_BUFFER_OBJECT_H
#define OPENGL_TUTORIAL_SILENCE_VERTEX_BUFFER_OBJECT_H

#include <vector>
#include <array>


namespace sil {

class VertexBufferObject {
public:
  using VertexType = std::array<float, 4>;
  
public:

  void add_vertex(float x, float y, float z, float alpha)
  {
    VertexType new_vertex{ x, y, z, alpha };
    add_vertex(new_vertex);
  }

  void add_vertex(const VertexType& new_vertex)
  {
    buffer_.emplace_back(new_vertex);
  }

  void add_vertices(const std::vector<VertexType>& vertices)
  {
    buffer_.insert(buffer_.end(), vertices.begin(), vertices.end());
  }

private:
  unsigned int id_;
  std::vector<VertexType> buffer_;
};

} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_VERTEX_BUFFER_OBJECT_H