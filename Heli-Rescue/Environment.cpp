#include "Environment.h"

Environment::Environment() {}
Environment::Environment(int width, int height, double gravity) : gravity(gravity), width(width), height(height) {
	speedX = 5;
	// Adding the player to the screen
	player = *(new Object(100, 10, 10, 10, true));
}
Environment::~Environment() {
	
}

void Environment::tick() {
	terrGen.tick();

	// Terrain Generation
	for (int i = 0; i < speedX; i++) {
		int next = terrGen.getNext();
		terrain.push_back(terrGen.getNext());
		if (terrain.size() > width) {
			terrain.erase(terrain.begin());
		}
	}

	// Player motion
	if (player.getGravityEnabled()) {
		player.setYSpeed(player.getYSpeed() + gravity);
	}
	player.tick();

	// Object Collision with terrain
	int* obj = nullptr;
	for (int i = 0; i < terrain.size(); i++) {
		obj = &terrain.at(i);
		if (height - *obj < player.getY() + player.getHeight() && i < player.getX() + player.getWidth() && i + 1 > player.getX()) {
			player.setY(10);
			player.setYSpeed(0);
			std::cout << "Collsion" << std::endl;
		}
	}
}
void Environment::render(SDL_Renderer* renderer) {
	player.render(renderer);
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
	
Object& Environment::getPlayer()
{
	return player;
}
