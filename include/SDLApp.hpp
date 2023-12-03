#ifndef SDLAPP_HPP
#define SDLAPP_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SDLApp
{
public:
    // Constructor
    SDLApp(const char *title, int x, int y, int w, int h);
    // Destructor
    ~SDLApp();
    // Handle Events
    void setEventCallback(void (*callback)(void));
    // Handle Render
    void setRenderCallback(void (*callback)(void));
    // Loop our application
    void runLoop();
    // Retrieve the renderer
    SDL_Renderer *getRenderer() const;

    void setRunningFlag(bool val);

private:
    // Pointer to our SDL Window
    SDL_Window *m_window = nullptr;
    // Pointer to our SDL renderer
    SDL_Renderer *m_renderer = nullptr;
    // Pointer to event Handler
    void (*m_eventCallback)(void);
    // Pointer to render Handler
    void (*m_renderCallback)(void);

    bool m_gameIsRunning = true;
};

#endif // SDLAPP_HPP