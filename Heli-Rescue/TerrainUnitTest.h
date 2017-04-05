#include "TerrainGenerator.h"
#include <iostream>
#include <cassert>
#include <time.h>

class TerrainUnitTest
{
public:

	static void TerrainUnitTest::ConstructorTest()
	{
		TerrainGenerator *testing = new TerrainGenerator();

		assert(testing->getBuffer().size() > 0);
		std::cout << "Constructor filled Buffer" << std::endl;
	}

	static void TerrainUnitTest::refillBufferTest()
	{
		TerrainGenerator *testingAttention = new TerrainGenerator();

		testingAttention->refillBuffer();
		assert(testingAttention->getBuffer().size()  <= 20);
		std::cout << "Buffer stays below size 20" << std::endl;

		int returnValue = testingAttention->getBuffer().back();

		int testValue = testingAttention->getNext();
		assert(testValue = returnValue);
		std::cout << "returning correct value" << std::endl;

		assert(returnValue != testingAttention->getBuffer().back());
		std::cout << "Popping correct value from buffer" << std::endl;
	}

};