#include "Environment.h"

Environment::Environment() {}
Environment::Environment(int width, int height, double gravity) : gravity(gravity), width(width), height(height) {
	speedX = 5;
	// Adding the player to the screen
	player = *(new Object(100, 10, 10, 10, true));
	
	createInitTerrain();
}
Environment::~Environment() {
	
}

void Environment::tick() {
	terrGen.tick();

	// Terrain Generation
	Object last = terrain.back();
	if (last.getX() < width) {
		addTerrain(last.getX() + BUILDING_SPACING + BUILDING_WIDTH);
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

	// Player Collision with terrain
	for (int i = 0; i < terrain.size(); i++) {
		if (Object::checkCollision(&terrain.at(i) , &player)) {
			std::cout << "Collision" << std::endl;
		}
	}

	// Removing old buildings from the terrain
	if (terrain.front().getX() < -terrain.front().getWidth()) {
		terrain.erase(terrain.begin());
	}
}
void Environment::render(SDL_Renderer* renderer) {
	player.render(renderer);
	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).render(renderer);
	}
}

void Environment::addTerrain(int xLoc) {
	int buildingHeight = terrGen.getNext();
	Object obj(xLoc, height - buildingHeight, BUILDING_WIDTH, buildingHeight, false);
	obj.setXSpeed(-speedX);
	terrain.push_back(obj);
}

void Environment::createInitTerrain() {
	for (int i = 0; i < width / (BUILDING_SPACING + BUILDING_WIDTH); i++) {
		addTerrain(i * (BUILDING_WIDTH + BUILDING_SPACING));
	}
}
