#include "yeenboy/yeenboy.hpp"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>

#include "yeenboy/common/logger.hpp"

Yeenboy::Yeenboy(const std::filesystem::path& path)
    : m_cartridge(path), m_mmu(m_wram, m_vram, m_cartridge, m_io_controller), m_cpu(m_mmu) {
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        Logger::Error("Error when initializing SDL: {}", SDL_GetError());
    }

    if (!SDL_CreateWindowAndRenderer("Yeenboy", 160, 144, SDL_WINDOW_OPENGL, &m_window, &m_renderer)) {
        Logger::Error("Error when creating SDL window/renderer: {}", SDL_GetError());
    }
}

void Yeenboy::Init() {
    SDL_Event event;
    while (m_running) {
        u64 frame_begin = SDL_GetTicks();

        // Poll events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    m_running = false;
                    break;

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);

        u64 frame_end = SDL_GetTicks();
    }
}

Yeenboy::~Yeenboy() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}