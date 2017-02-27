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
	static int tickNumber = 0;
	tickNumber++;
	if (tickNumber % 15 == 0) {
		int buildingHeight = terrGen.getNext();
		Object obj(width, height - buildingHeight, 50, buildingHeight, false);
		obj.setXSpeed(-speedX);
		terrain.push_back(obj);
	}

	// Terrain updating
	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).tick();
	}

	// Player motion
	if (player.getGravityEnabled()) {
		player.setYSpeed(player.getYSpeed() + gravity);
	}
	player.tick();

	// Object Collision with terrain
	Object* obj = nullptr;
	for (int i = 0; i < terrain.size(); i++) {
		obj = &terrain.at(i);
		if (Object::checkCollision(obj, &player)) {
			std::cout << "Collision" << std::endl;
		}
	}
}
void Environment::render(SDL_Renderer* renderer) {
	player.render(renderer);
	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).render(renderer);
	}
}
