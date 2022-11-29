#ifndef OPENGL_TUTORIAL_SILENCE_UTILITY_H
#define OPENGL_TUTORIAL_SILENCE_UTILITY_H


namespace sil {

// 抄袭自Qt的QT_DISABLE_COPY
#define SIL_DISABLE_COPY(Class) \
  Class(const Class& other) = delete;\
  Class& operator=(const Class& other) = delete;

// 抄袭自Qt的QT_DISABLE_COPY_MOVE
#define SIL_DISABLE_COPY_MOVE(Class) \
  SIL_DISABLE_COPY(Class) \
  Class(Class&& other) noexcept = delete; \
  Class& operator=(Class&& other) noexcept = delete;

#define SIL_DEFAULT_MOVE(Class) \
  Class(Class&& other) noexcept = default; \
  Class& operator=(Class&& other) noexcept = default;

  
} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_UTILITY_H 