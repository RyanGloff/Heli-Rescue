#include "EntityGenerator.h"
#include <time.h>

EntityGenerator::EntityGenerator() {}
EntityGenerator::EntityGenerator(int envWidth, int envHeight) : envWidth(envWidth), envHeight(envHeight) {
	refillBuffer();
}
EntityGenerator::~EntityGenerator() {

}

void EntityGenerator::tick() {
	refillBuffer();
}

Object EntityGenerator::nextEntity() {
	Object* returnObject = &entityBuffer.back();
	entityBuffer.pop_back();
	return *returnObject;
}

void EntityGenerator::refillBuffer() {
	static const int MAX_BUFFER_SIZE = 3;
	static const int MIN_Y = 500;
	static const int MIN_SPEED_X = 7;
	static const int SPEED_SPREAD = 3;

	while (entityBuffer.size() <= MAX_BUFFER_SIZE) {
		double x = envWidth;
		double y = rand() % MIN_Y;
		double speedX = MIN_SPEED_X + (rand() % SPEED_SPREAD);
		Object obj(x, y, 100, 50, false, "assets/bird.png");
		obj.setXSpeed(-speedX);
		entityBuffer.push_back(obj);
	}
}
