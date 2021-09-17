#include "World.h"
#include "Utils.h"

#define POPULATION 100

void World::initializeWorld() {
	for (int i = 0; i < POPULATION; i++) {

		Vector2 position(RandomFloat(0.0f, _width), RandomFloat(0.0f, _height));
		Vector2 velocity(RandomFloat(-100.0f, 100.0f), RandomFloat(-100.0f, 100.0f));
		Vector2 acceleration(0.0f, 0.0f); 

		_boids.emplace_back(position, velocity, acceleration, 2.0f);
	}
}

void World::update(float deltaTime) {
	for (Boid& individual : _boids) {
		individual.align(_boids);

		individual.update(deltaTime);
		individual.clampPositionInSpace(0.0f, _width, 0.0f, _height);
	}
}

void World::draw(SDL_Renderer* renderer) {
	for (Boid& individual : _boids) {
		individual.draw(renderer);
	}
}

