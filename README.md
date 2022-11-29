# Learn OpenGL and Exercise
> https://learnopengl-cn.github.io/


## Config
1. glad的配置有点麻烦，所以push了整个third-party/glad文件夹
2. Config.h 由 CMake在构建时根据Config.h.in而产生，由于涉及我本地的路径信息，并未push


## Header Tempalte
```c++
#ifndef OPENGL_TUTORIAL_SILENCE_TEMPLATE_H
#define OPENGL_TUTORIAL_SILENCE_TEMPLATE_H


namespace sil {



} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_TEMPLATE_H 
```