#pragma once
struct SDL_Renderer;

class Boid
{
public:
	Boid(float x, float y, float radius);

	void draw(SDL_Renderer* renderer);

private:
	float _x;
	float _y;
	float _r;
};

