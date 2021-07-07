#pragma once
class SDL_Window;
class SDL_Surface;

class Window {
public:

private:
	int _width;
	int _height;

	SDL_Window* _SDLWindow;
	SDL_Surface* _SDLScreenSurface;

public:
	Window(int width, int height);
	~Window();

	bool init();
	bool loadResources();
	void update();
	void close();

private:
};
