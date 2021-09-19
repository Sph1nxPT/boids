#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2() { _x = 0.0f, _y = 0.0f; };
	Vector2(float x, float y) : _x(x), _y(y) {};

	float X() const { return _x; };
	float Y() const { return _y; };

	void setX(float newX) { _x = newX; };
	void setY(float newY) { _y = newY; };

	bool operator!=(const Vector2& v2) const { return (_x != v2.X() || _y != v2.Y()); };
	bool operator==(const Vector2& v2) const { return (_x == v2.X() && _y == v2.Y()); };

	Vector2 operator+(const Vector2& v2) const { return Vector2(_x + v2.X(), _y + v2.Y()); };
	Vector2 operator-(const Vector2& v2) const { return Vector2(_x - v2.X(), _y - v2.Y()); };

	Vector2 operator*(const float& scalar) const { return Vector2(_x * scalar, _y * scalar); };
	Vector2 operator/(const float& scalar) const { return Vector2(_x / scalar, _y / scalar); };

	float length() const { return std::sqrt(_x*_x + _y*_y); };

	void normalize();
	void setMagnitude(float newMagnitude);
	void limitMagnitude(float limit);

	static float dot(const Vector2& v1, const Vector2& v2) { return v1.X() * v2.X() + v1.Y() * v2.Y(); };
	static float distance(const Vector2& v1, const Vector2& v2) { return (v2 - v1).length(); }

private:
	float _x;
	float _y;
};
