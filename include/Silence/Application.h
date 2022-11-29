#ifndef OPENGL_TUTORIAL_SILENCE_APPLICATION_H
#define OPENGL_TUTORIAL_SILENCE_APPLICATION_H


namespace sil {

class Application {
public:
  ~Application() {}

  virtual int exec(int argc, char* argv[]) = 0;
};

} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_APPLICATION_H 