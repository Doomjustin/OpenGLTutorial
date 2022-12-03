#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
uniform vec4 uniform_color;

void main()
{
  FragColor = vec4(vertexColor, 1.0);
  // FragColor = uniform_color;
}