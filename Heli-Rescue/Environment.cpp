#include "Environment.h"
#include "Sounds.h"
#include "Display.h"

Sounds coll("assets/coll.wav", "effect");
int Display::score = 0;
int Display::lives = 3;

Environment::Environment() {}
Environment::Environment(int width, int height, double gravity) : gravity(gravity), width(width), height(height) {
	speedX = 5;
	// Adding the player to the screen
	bg = *(new Object(0, 0, width, height, false, "assets/bg.png"));
	player = *(new Object(100, 10, 50, 50, false, "assets/heli.png"));
	entGen = *(new EntityGenerator(width, height));

	createInitTerrain();
}
Environment::~Environment() {
	delete &entGen;
}

void Environment::tick() {
	terrGen.tick();
	entGen.tick();

	// Terrain and People Generation
	Object last = terrain.back();
	if (last.getX() < width) {
		addTerrain(last.getX() + BUILDING_SPACING + BUILDING_WIDTH);
	}

	// Terrain updating
	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).tick();
	}

	// People updating
	for (int i = 0; i < people.size(); i++) {
		people.at(i).tick();
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
	if (player.getY() < 0) {
		player.setY(0);
	} else if (player.getY() > height - player.getHeight()) {
		player.setY(0);
	} 
	if (player.getX() < 0) {
		player.setX(100);
	} else if (player.getX() > width - player.getWidth()) {
		player.setX(100);
	}
	player.tick();

	// Player collision with terrain
	for (int i = 0; i < terrain.size(); i++) {

		if (Object::checkCollision(&terrain.at(i), &player)) {
			player.setY(10);
			player.setYSpeed(0);
			coll.play();
			Display::lives--;
			std::cout << "Player collided with the terrain" << std::endl;
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
			player.setY(0);
			player.setYSpeed(0);
			entities.erase(entities.begin() + i);
			coll.play();
			Display::lives--;
			std::cout << "The player collided with an entity" << std::endl;
		}
	}

	// Player-Person collision
	for (int i = 0; i < people.size(); i++) {
		if (Object::checkCollision(&player, &people.at(i))) {
			people.erase(people.begin() + i);
			Display::score ++;
			std::cout << "You saved a civilian" << std::endl;
		}
	}

	// Person-Entity collision
	for (int ent = 0; ent < entities.size(); ent++) {
		for (int per = 0; per < people.size(); per++) {
			if (Object::checkCollision(&entities.at(ent), &people.at(per))) {
				people.erase(people.begin() + per);
			}
		}
	}

	// Removing old buildings from the terrain
	if (terrain.size() != 0) {
		if (terrain.front().getX() + terrain.front().getWidth() < 0) {
			terrain.erase(terrain.begin());
		}
	}

	// Removing old people from the environment
	if (people.size() != 0) {
		if (people.front().getX() + people.front().getWidth() < 0) {
			people.erase(people.begin());
		}
	}

}
void Environment::render(SDL_Renderer* renderer) {
	bg.render(renderer);
	player.render(renderer);

	for (int i = 0; i < terrain.size(); i++) {
		terrain.at(i).render(renderer);
	}
	for (int i = 0; i < entities.size(); i++) {
		entities.at(i).render(renderer);
	}
	for (int i = 0; i < people.size(); i++) {
		people.at(i).render(renderer);
	}
}

void Environment::addTerrain(int xLoc) {
	static int personGap = 0;
	static int gap = 30;
	int buildingHeight = terrGen.getNext();
	Object obj(xLoc, height - buildingHeight, BUILDING_WIDTH, buildingHeight, false,"assets/building.png");
	obj.setXSpeed(-speedX);
	terrain.push_back(obj);
	if (personGap == gap) {
		Object person(obj.getX(), obj.getY() - 87, 45, 87, false, "assets/person.png");
		person.setXSpeed(-speedX);
		people.push_back(person);
		personGap = 0;
		gap = 10 + rand() % 5;
	}
	personGap++;
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
