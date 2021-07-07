#pragma once
struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;

class Window {
public:

private:
	int _width;
	int _height;

	SDL_Window* _SDLWindow;
	SDL_Surface* _SDLScreenSurface;
	SDL_Renderer* _SDLRenderer;

public:
	Window(int width, int height);
	~Window();

	bool init();
	void simulate();
	void close();

private:

	void clear();
};
