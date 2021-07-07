#include "Boid.h"
#include <SDL.h>

Boid::Boid(float x, float y, float radius) : _x(x), _y(y) , _r(radius) {}

void Boid::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    int offsetx, offsety, d;
    int status;
    
    offsetx = 0;
    offsety = _r;
    d = _r - 1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawLine(renderer, _x - offsety, _y + offsetx, _x + offsety, _y + offsetx);
        status += SDL_RenderDrawLine(renderer, _x - offsetx, _y + offsety, _x + offsetx, _y + offsety);
        status += SDL_RenderDrawLine(renderer, _x - offsetx, _y - offsety, _x + offsetx, _y - offsety);
        status += SDL_RenderDrawLine(renderer, _x - offsety, _y - offsetx, _x + offsety, _y - offsetx);

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
