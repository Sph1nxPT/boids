#pragma once
struct SDL_Renderer;

#include <Vector2.h>

class Boid
{
public:
	Boid(Vector2 position, Vector2 velocity, float radius) : _position(position), _velocity(velocity), _r(radius) {};

	void update(float deltaTime);
	void draw(SDL_Renderer* renderer);

	const Vector2& getPosition() const { return _position; };
	const Vector2& getVelocity() const { return _velocity; };

	void setPosition(const Vector2& newPosition) { _position = newPosition; }

	void clampPositionInSpace(float xi, float xf, float yi, float yf);

private:
	Vector2 _position;
	Vector2 _velocity;
	
	float _r;
};

