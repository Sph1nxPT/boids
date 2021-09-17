#pragma once
struct SDL_Renderer;

#include <Vector2.h>
#include <vector>

class Boid
{
public:
	Boid(Vector2 position, Vector2 velocity, Vector2 acceleration, float radius) : 
		_position(position), _velocity(velocity), _acceleration(acceleration), _r(radius) {
		_id = _idCount++;
	};

	void update(float deltaTime);
	void draw(SDL_Renderer* renderer);

	const Vector2& getPosition() const { return _position; };
	const Vector2& getVelocity() const { return _velocity; };
	const Vector2& getAcceleration() const { return _acceleration; };
	const unsigned int getId() const { return _id; };

	void setPosition(const Vector2& newPosition) { _position = newPosition; }

	void clampPositionInSpace(float xi, float xf, float yi, float yf);

	bool operator!=(const Boid& other) const { return other.getId() != _id; };
	bool operator==(const Boid& other) const { return other.getId() == _id; };

	void align(const std::vector<Boid> boids);

private:
	Vector2 _position;
	Vector2 _velocity;
	Vector2 _acceleration;

	float _r;
	unsigned int _id;

	static unsigned int _idCount;
};

