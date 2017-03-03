#pragma once
#include <SDL.h>
#include <vector>

#include "Object.h"
#include "TerrainGenerator.h"

class Environment {
	std::vector<Object> terrain;
	Object player;

	TerrainGenerator terrGen;

	int width;
	int height;
	double speedX;
	double gravity;

	const int BUILDING_SPACING = 15;
	const int BUILDING_WIDTH = 50;

	void addTerrain(int xLoc);
	void createInitTerrain();
public:
	Environment();
	Environment(int width, int height, double gravity);
	~Environment();

	void tick();
	void render(SDL_Renderer* renderer);
};

