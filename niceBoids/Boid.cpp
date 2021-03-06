#include "Boid.h"
#include <SDL.h>

#define PERCEPTION_RADIUS 100

unsigned int Boid::_idCount = 0;

void Boid::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    int offsetx, offsety, d;
    int status;
    
    offsetx = 0;
    offsety = _r;
    d = _r - 1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawLine(renderer, _position.X() - offsety, _position.Y() + offsetx, _position.X() + offsety, _position.Y() + offsetx);
        status += SDL_RenderDrawLine(renderer, _position.X() - offsetx, _position.Y() + offsety, _position.X() + offsetx, _position.Y() + offsety);
        status += SDL_RenderDrawLine(renderer, _position.X() - offsetx, _position.Y() - offsety, _position.X() + offsetx, _position.Y() - offsety);
        status += SDL_RenderDrawLine(renderer, _position.X() - offsety, _position.Y() - offsetx, _position.X() + offsety, _position.Y() - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (_r - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void Boid::update(float deltaTime) {
    _velocity = _velocity + _acceleration * deltaTime;
    _position = _position + _velocity * deltaTime;
}

void Boid::clampPositionInSpace(float xi, float xf, float yi, float yf) {

    if (_position.X() > xf) {
        _position.setX(xi);
    }
    else if (_position.X() < xi) {
        _position.setX(xf);
    }

    if (_position.Y() > yf) {
        _position.setY(yi);
    }
    else if (_position.Y() < yi) {
        _position.setY(yf);
    }
}

void Boid::align(const std::vector<Boid> boids) {
    Vector2 steeringForce;
    int total = 0;

    for (const Boid& other : boids) {

        float distance = Vector2::distance(_position, other.getPosition());

        if (other != *this && distance < PERCEPTION_RADIUS) {
            steeringForce = steeringForce + other.getVelocity();
            total++;
        }

    }
    if (total > 0) {
        steeringForce = steeringForce / total;
        steeringForce = steeringForce - _velocity;
    }

    _acceleration = steeringForce;
}