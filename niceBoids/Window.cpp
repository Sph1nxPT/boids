#include <Window.h>
#include <SDL.h>
#include <stdio.h>

Window::Window(int width, int height) : _width(width), _height(height) {
	_SDLWindow = nullptr;
	_SDLScreenSurface = nullptr;
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

		if (_SDLWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			_SDLScreenSurface = SDL_GetWindowSurface(_SDLWindow);
		}
	}

	return success;
}

bool Window::loadResources()
{
	bool success = true;
	return success;
}

void Window::update()
{
	bool quit = false;

	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		//Update the surface
		SDL_UpdateWindowSurface(_SDLWindow);
	}
}

void Window::close()
{
	//Destroy window
	SDL_DestroyWindow(_SDLWindow);
	_SDLWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

