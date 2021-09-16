#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2() = default;
	Vector2(float x, float y) : _x(x), _y(y) {};
	Vector2(const Vector2& v2) { _x = v2.X(); _y = v2.Y(); };

	inline float X() const { return _x; };
	inline float Y() const { return _y; };

	inline bool operator!=(const Vector2& v2) { return (_x != v2.X() || _y != v2.Y()); };
	inline bool operator==(const Vector2& v2) { return (_x == v2.X() && _y == v2.Y()); };

	inline Vector2 operator+(const Vector2& v2) { return Vector2(_x + v2.X(), _y + v2.Y()); };
	inline Vector2 operator-(const Vector2& v2) { return Vector2(_x - v2.X(), _y - v2.Y()); };
	
	inline Vector2 operator*(const float& scalar) { return Vector2(_x * scalar, _y * scalar); };
	inline Vector2 operator/(const float& scalar) { return Vector2(_x / scalar, _y / scalar); };

	inline float length() { return std::sqrt(_x*_x + _y*_y); };
	inline Vector2 normalize() { float len = this->length(); return Vector2(_x / len, _y / len); };

	inline static float dot(const Vector2& v1, const Vector2& v2) { return v1.X() * v2.X() + v1.Y() * v2.Y(); };

private:
	float _x;
	float _y;
};
