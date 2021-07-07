#include <Window.h>
#include <World.h>

#include <SDL.h>
#include <stdio.h>

Window::Window(int width, int height) : _width(width), _height(height) {
	_SDLWindow = nullptr;
	_SDLScreenSurface = nullptr;
	_SDLRenderer = nullptr;
}

Window::~Window() {
	close();
}

bool Window::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		_SDLWindow = SDL_CreateWindow("boids boids boids", 
									  SDL_WINDOWPOS_UNDEFINED, 
			                          SDL_WINDOWPOS_UNDEFINED,
									  _width, 
									  _height, 
			                          SDL_WINDOW_SHOWN);

		if (_SDLWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			_SDLScreenSurface = SDL_GetWindowSurface(_SDLWindow);
			_SDLRenderer = SDL_CreateRenderer(_SDLWindow, -1, SDL_RENDERER_ACCELERATED);
		}
	}

	return success;
}

void Window::simulate()
{
	bool quit = false;

	SDL_Event e;

	World world(_width, _height);

	world.initializeWorld();

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		world.update();

		clear();
		world.draw(_SDLRenderer);

		SDL_RenderPresent(_SDLRenderer);
	}
}

void Window::clear() {
	SDL_SetRenderDrawColor(_SDLRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(_SDLRenderer);
}

void Window::close()
{
	//Destroy window
	SDL_DestroyWindow(_SDLWindow);
	_SDLWindow = nullptr;

	SDL_DestroyRenderer(_SDLRenderer);
	_SDLRenderer = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
