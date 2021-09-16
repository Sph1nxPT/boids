#pragma once
#include <Boid.h>
#include <vector>

struct SDL_Renderer;

class World
{
	public:
		World(int width, int height) : _width(width), _height(height) {};

		void initializeWorld();
		void update(float deltaTime);
		void draw(SDL_Renderer* renderer);

	private:
		void clampPosition(Boid& boid);
		float clamp(float value, float max);

		int _width;
		int _height;

		std::vector<Boid> _boids;
};

