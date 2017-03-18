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
	std::cout << "Adding new entity" << std::endl;
	Object* returnObject = &entityBuffer.back();
	entityBuffer.pop_back();
	return *returnObject;
}

void EntityGenerator::refillBuffer() {
	while (entityBuffer.size() <= 3) {
		double x = envWidth + rand() % 50;
		double y = rand() % 50;
		double speedX = (rand() % 5);
		Object obj(x, y, 50, 50, false);
		obj.setXSpeed(-speedX);
		entityBuffer.push_back(obj);
	}
}
