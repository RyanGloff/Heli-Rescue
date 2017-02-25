#pragma once
#include <SDL.h>
#include <vector>

#include "Object.h"
#include "TerrainGenerator.h"

class Environment {
	std::vector<int> terrain;
	Object player;

	TerrainGenerator terrGen;

	int width;
	int height;
	double speedX;
	double gravity;
public:
	Environment();
	Environment(int width, int height, double gravity);
	~Environment();

	void tick();
	void render(SDL_Renderer* renderer);
	static Object getPlayer();
};

