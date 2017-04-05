#include "TerrainGenerator.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

TerrainGenerator::TerrainGenerator() {
	seed = time(NULL);
	srand(seed);
	refillBuffer();
}
TerrainGenerator::TerrainGenerator(int seed) : seed(seed) {
	srand(seed);
	refillBuffer();
}
TerrainGenerator::~TerrainGenerator() {

}

void TerrainGenerator::tick() {
	refillBuffer();
}

void TerrainGenerator::refillBuffer() {
	while (buffer.size() < 20) {
		static const int MAX_HEIGHT = 350;
		static const int MIN_HEIGHT = 50;
		static int prevHeight = 150;
		int height = 0;
		while (height > MAX_HEIGHT || height < MIN_HEIGHT) {
			height = prevHeight + (rand() % 150 - 75);
		}
		buffer.push_back(height);
		prevHeight = height;
	}
}

int TerrainGenerator::getSeed() {
	return seed;
}
int TerrainGenerator::getNext() {
	int returnValue = buffer.back();
	buffer.pop_back();
	return returnValue;
}

std::vector<int> TerrainGenerator::getBuffer()
{
	return buffer;
}