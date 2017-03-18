#pragma once
#include <vector>
#include "Object.h"
class EntityGenerator {
private:
	std::vector<Object> entityBuffer;

	int envWidth;
	int envHeight;

	void refillBuffer();
public:
	EntityGenerator();
	EntityGenerator(int envWidth, int envHeight);
	~EntityGenerator();

	void tick();

	Object nextEntity();
	
};

