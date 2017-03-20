#pragma once
#include <SDL.h>
#include <vector>
#include "Object.h"
#include "TerrainGenerator.h"
#include "EntityGenerator.h"

class Environment {
	std::vector<Object> terrain;
	std::vector<Object> entities;
	Object player;

	TerrainGenerator terrGen;
	EntityGenerator entGen;

	int width;
	int height;
	double speedX;
	double gravity;

	const int BUILDING_SPACING = 15;
	const int BUILDING_WIDTH = 50;

	void addTerrain(int xLoc);
	void addEntity();
	void createInitTerrain();
public:
	Environment();
	Environment(int width, int height, double gravity);
	~Environment();

	void tick();
	void render(SDL_Renderer* renderer);
	Object& getPlayer();
};

