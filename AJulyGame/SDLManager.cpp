#include "SDLManager.h"



SDLManager::SDLManager()
{
	width = 1366;// (int)(640.0f / 480.0f*650.0f);
	height = 768;// (int)650.0f;
	srand(time(0));
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
	window = SDL_CreateWindow("AJulyGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	bool running = true;
	SDL_Event mainEvent;
	while (running) {
		while (SDL_PollEvent(&mainEvent)) {
			if (SDL_QUIT == mainEvent.type) {
				running = false;
			}
			if (SDL_KEYDOWN == mainEvent.type) {
				if (SDLK_ESCAPE == mainEvent.key.keysym.sym)
					running = false;
			}
			if (mainEvent.type == SDL_WINDOWEVENT) {
				if (mainEvent.window.type == SDL_WINDOWEVENT_RESIZED) {
					SDL_GetWindowSize(window, &width, &height);
				}
			}
		}
		//SDL_GL_SwapWindow(window);
		SDL_SetRenderDrawColor(renderer,1.0f, 1.0f, 1.0f, 1.0f);
		SDL_RenderClear(renderer);
		/*Draw here*/

		SDL_RenderPresent(renderer);
	}
}


SDLManager::~SDLManager()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
}

int main(int argc, char**args) {
	SDLManager sdlManager;
	return 0;
}