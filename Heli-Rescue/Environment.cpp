#include "Environment.h"

Environment::Environment() {}
Environment::Environment(int width, int height, double gravity) : gravity(gravity), width(width), height(height) {
	speedX = 5;
	// Adding the player to the screen
	player = *(new Object(100, 10, 50, 50, true,"heli.png"));
	entGen = *(new EntityGenerator(width, height));
	
	createInitTerrain();
}
Environment::~Environment() {
	delete &entGen;
}

void Environment::tick() {
	terrGen.tick();
	entGen.tick();

	// Terrain Generation
	Object last = terrain.back();
	if (last.getX() < width) {
		addTerrain(last.getX() + BUILDING_SPACING + BUILDING_WIDTH);
	}

	// Terrain updating
	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).tick();
	}

	// Entity Generation
	static int tickNumber = 0;
	static int delay = 0;
	if (tickNumber == delay) {
		delay = rand() % 90 + 45;
		tickNumber = 0;
		addEntity();
	}
	tickNumber++;

	// Entity updating
	for (int i = 0; i < entities.size(); i++) {
		entities.at(i).tick();
	}

	// Player motion
	if (player.getGravityEnabled()) {
		player.setYSpeed(player.getYSpeed() + gravity);
	}
	player.tick();

	// Player collision with terrain
	for (int i = 0; i < terrain.size(); i++) {
		
		if (Object::checkCollision(&terrain.at(i), &player)) {
			player.setY(10);
			player.setYSpeed(0);
			std::cout << "Collision" << std::endl;
		}
		// Entity-Terrain collision
		for (int ent = 0; ent < entities.size(); ent++) {
			if (Object::checkCollision(&terrain.at(i), &entities.at(ent))) {
				entities.erase(entities.begin() + ent);
			}
		}
	}

	// Player-Entity collision
	for (int i = 0; i < entities.size(); i++) {
		if (Object::checkCollision(&player, &entities.at(i))) {
			entities.erase(entities.begin() + i);
			std::cout << "The player collided with an entity" << std::endl;
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
	for (int i = 0; i < entities.size(); i++) {
		entities.at(i).render(renderer);
	}
}

void Environment::addTerrain(int xLoc) {
	int buildingHeight = terrGen.getNext();
	Object obj(xLoc, height - buildingHeight, BUILDING_WIDTH, buildingHeight, false,"building.png");
	obj.setXSpeed(-speedX);
	terrain.push_back(obj);
}

void Environment::addEntity() {
	entities.push_back(entGen.nextEntity());
}

void Environment::createInitTerrain() {
	for (int i = 0; i < width / (BUILDING_SPACING + BUILDING_WIDTH); i++) {
		addTerrain(i * (BUILDING_WIDTH + BUILDING_SPACING));
	}
}

Object& Environment::getPlayer()
{
	return player;
}
