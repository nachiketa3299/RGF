#ifndef RGF_WINDOW_H
#define RGF_WINDOW_H
#include <GLFW/glfw3.h>

namespace rgf
{

typedef void (*RenderFunction)(double timeSinceLastFrame);

class Window
{
public:
    Window(int height, int width, bool fullscreen, char* title);
    ~Window();

    auto Initialize() -> void;

    auto SetRenderFunction() -> void;

    // Getters
    auto GetHeight() const -> int;
    auto GetWidth() const -> int;
    auto IsFullScreen() const -> bool;
    auto IsClosed() const -> bool;

    auto Close() -> void;

private:
    GLFWwindow* m_window;
    int         m_height;
    int         m_width;
    bool        m_bfullscreen;
    char*       m_title;
    double      m_time_since_last_frame;
    double      m_last_frame_time;
};

} // namespace rgf

#endif // RGF_WINDOW_H
