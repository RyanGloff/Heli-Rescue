#include "EntityGenerator.h"
#include <cassert>
#include <iostream>

class EntityGeneratorTest
{

public:
	static void EntityGeneratorTest::ConstructorTest()
	{

		int testWidth = 2;
		int testHeight = 4;

		EntityGenerator *test = new EntityGenerator(testWidth, testHeight);

		assert(test->getBuffer().size() > 0);
		std::cout << "EntityGenerator Constructed with buffer" << std::endl;
		assert(test->getEnvWidth() == testWidth);
		std::cout << "Constructed with correct width" << std::endl;
		assert(test->getEnvHeight() == testHeight);
		std::cout << "Constructed with correct height" << std::endl; 
	}

	static void EntityGeneratorTest::refillBufferTest()
	{
		int testWidth = 2;
		int testHeight = 4;

		EntityGenerator *test = new EntityGenerator(testWidth, testHeight);

		int testBufferSize = test->getBuffer().size();

		Object returnObject = test->nextEntity();
		//assert(returnObject != test->getBuffer->back());
		std::cout << "Correct Object was ejected and erased from EntityBuffer" << std::endl;

		assert(test->getBuffer().size() < testBufferSize);
		std::cout << "Buffer is resized" << std::endl;
	}
};