#pragma once
#include <Boid.h>
#include <vector>

struct SDL_Renderer;

class World
{
	public:
		World(int width, int height);

		void initializeWorld();
		void update();
		void draw(SDL_Renderer* renderer);

	private:
		int _width;
		int _height;

		std::vector<Boid> _boids;
};

