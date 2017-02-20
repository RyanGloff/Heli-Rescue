#pragma once
#include <SDL.h>
#include <vector>
class TerrainGenerator {
private:
	std::vector<int> buffer;
	std::vector<int> terrainValues;

	int seed;
public:
	TerrainGenerator();
	TerrainGenerator(int seed);
	~TerrainGenerator();

	void tick();
	
	int getSeed();
	int getNext();
};

