#include "World.h"

World::World(int width, int height) : _width(width), _height(height) {

}

void World::initializeWorld() {
	_boids.emplace_back(_width * 0.5f, _height * 0.5f, 100.0f);
}

void World::update() {

}

void World::draw(SDL_Renderer* renderer) {
	for (Boid individual : _boids) {
		individual.draw(renderer);
	}
}
