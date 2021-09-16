#include "World.h"

void World::initializeWorld() {
	_boids.emplace_back(_width * 0.5f, _height * 0.5f, 2.0f);
}

void World::update() {

}

void World::draw(SDL_Renderer* renderer) {
	for (Boid individual : _boids) {
		individual.draw(renderer);
	}
}
