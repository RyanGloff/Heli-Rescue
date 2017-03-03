#pragma once
#include <SDL.h>
#include <vector>
class TerrainGenerator {
private:
	std::vector<int> buffer;

	int seed;
public:
	TerrainGenerator();
	TerrainGenerator(int seed);
	~TerrainGenerator();

	void tick();

	void refillBuffer();
	
	int getSeed();
	int getNext();
};

