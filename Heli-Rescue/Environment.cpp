#include "Environment.h"

Environment::Environment() {}
Environment::Environment(int width, int height, double gravity) : gravity(gravity), width(width), height(height) {
	speedX = 5;
	// Adding the player to the screen
	Object obj(100, 0, 10, 10, true);
	objectList.push_back(obj);
	player = &objectList.at(0);
}
Environment::~Environment() {
	objectList.~vector();
}

void Environment::tick() {
	terrGen.tick();

	for (int i = 0; i < speedX; i++) {
		int next = terrGen.getNext();
		terrain.push_back(terrGen.getNext());
		if (terrain.size() > width) {
			terrain.erase(terrain.begin());
		}
	}

	for (int i = 0; i < objectList.size(); i++) {
		Object* obj = &objectList.at(i);
		if (obj->getGravityEnabled()) {
			obj->setYSpeed(obj->getYSpeed() + gravity);
		}
		obj->tick();
	}
}
void Environment::render(SDL_Renderer* renderer) {
	for (int i = 0; i < objectList.size(); i++) {
		objectList.at(i).render(renderer);
	}
	for (int i = 0; i < terrain.size(); i++) {
		SDL_Rect rect;
		rect.x = i;
		rect.y = height - terrain.at(i);
		rect.w = 1;
		rect.h = terrain.at(i);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
}
