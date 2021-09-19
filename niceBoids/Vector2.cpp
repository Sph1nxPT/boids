#include <Vector2.h>

void Vector2::normalize() {
	float len = this->length();
	_x = _x / len; 
	_y = _y / len;
}

void Vector2::setMagnitude(float newMagnitude) {
	normalize();
	_x = _x * newMagnitude;
	_y = _y * newMagnitude;
}

void Vector2::limitMagnitude(float limit) {
	if (this->length() > limit) setMagnitude(limit);
}
