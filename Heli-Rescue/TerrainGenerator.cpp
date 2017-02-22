#include "TerrainGenerator.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

TerrainGenerator::TerrainGenerator() {
	srand(time(NULL));
	seed = rand();
}
TerrainGenerator::TerrainGenerator(int seed) : seed(seed) {
	srand(seed);
}
TerrainGenerator::~TerrainGenerator() {

}

void TerrainGenerator::tick() {
	while (buffer.size() < 2000) {
		static const int MAX_HEIGHT = 350;
		static const int MIN_HEIGHT = 50;
		static const int MAX_SPEED = 3;
		static double height = 100;
		static double speed = 0;
		double accel = (rand() % MAX_SPEED - (MAX_SPEED / 2)) / 90.0;
		speed += accel;
		if (speed > MAX_SPEED) {
			speed = MAX_SPEED;
		} else if (speed < -MAX_SPEED) {
			speed = -MAX_SPEED;
		}
		if (height > MAX_HEIGHT && speed > 0 || height < MIN_HEIGHT && speed < 0) {
			speed = 0;
		}
		height += speed;
		buffer.push_back(height);
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
