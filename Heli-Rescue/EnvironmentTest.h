#include "Environment.h "
#include <iostream>
#include <cassert>

class EnvironmentTest
{
public:

	static void ConstructorTest()
	{
		int testWidth = 6;
		int testHeight = 8;
		double testGravity = 0;

		Environment *testEnv = new Environment(testWidth, testHeight, testGravity);

		assert(testEnv->getBG().getWidth() == testWidth);
		assert(testEnv->getBG().getHeight() == testHeight);
		std::cout << "Environment constructed with correct values" << std::endl;
	}

};