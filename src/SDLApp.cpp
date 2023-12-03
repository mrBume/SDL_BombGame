#include "SDLApp.hpp"

#include <iostream>

SDLApp::SDLApp(const char *title, int x, int y, int w, int h)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    else
        std::cout << "SDL video system is ready to go\n";

    if (IMG_Init(IMG_INIT_PNG) < 0)
        std::cout << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
    else
        std::cout << "SDL Image system is ready to go\n";

    m_window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDLApp::~SDLApp()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void SDLApp::setRunningFlag(bool val)
{
    m_gameIsRunning = val;
}

void SDLApp::setEventCallback(void (*callback)(void))
{
    m_eventCallback = callback;
}

void SDLApp::setRenderCallback(void (*callback)(void))
{
    m_renderCallback = callback;
}

void SDLApp::runLoop()
{
    while (m_gameIsRunning)
    {
        Uint64 start = SDL_GetPerformanceCounter();

        // Do event loop
        m_eventCallback();

        // Do physics loop

        // Do rendering loop
        m_renderCallback();

        Uint64 end = SDL_GetPerformanceCounter();

        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        // Cap to 60 FPS
        if (elapsedMS < 16.666f)
            SDL_Delay(static_cast<Uint32>(16.666f - elapsedMS));
    }
}

SDL_Renderer *SDLApp::getRenderer() const
{
    return m_renderer;
}
