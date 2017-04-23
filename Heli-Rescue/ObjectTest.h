#pragma once
#include <iostream>
#include <cassert>
#include "Object.h"
#include "Window.h"

class ObjectTest {

	public:
		static void ObjectTest::ConstructorTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;
			std::string imgPath = "assets/heli.png";

			Object *test = new Object(x, y, width, height, gravity, imgPath);

			assert(test->getX() == x);
			std::cout << "Constructed with correct X";
			assert(test->getY() == y);
			std::cout << "Constructed with correct Y";
			assert(test->getWidth() == width);
			std::cout << "Constructed with correct width";
			assert(test->getHeight() == height);
			std::cout << "Constructed with correct height";
			assert(test->getGravityEnabled() == gravity);
			std::cout << "Constructed with gravity disabled";
			
			assert(test->getXSpeed() == 0);
			std::cout << "Constructed with x speed 0";
			assert(test->getYSpeed() == 0);
			std::cout << "Constructed with y speed 0";

		}
		
		static void ObjectTest::TickTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;
			std::string imgPath = "assets/heli.png";

			Object *test = new Object(x, y, width, height, gravity, imgPath);

			test->tick();

			assert(test->getXSpeed() == x);
			std::cout << "xSpeed equals x";
			assert(test->getYSpeed() == y);
			std::cout << "ySpeed equals y";
		}

		static void ObjectTest::RenderTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;
			std::string imgPath = "assets/heli.png";

			Object *test = new Object(x, y, width, height, gravity, imgPath);
			
			assert(test->render->rect->x == x);
			std::cout << "rect.x equals x";
			assert(test->render->rect->y == y);
			std::cout << "rect.y equals y";
			assert(test->render->rect->w == width);
			std::cout << "rect.w equals width";
			assert(test->render->rect->h == height);
			std::cout << "rect.h equals height";
		}

		static void ObjectTest::CollisionTest() {
			double x1 = 100;
			double y1 = 10;
			double width1 = 50;
			double height1 = 50;
			bool gravity1 = false;

			Object *test1 = new Object(x1, y1, width1, height1, gravity1);

			double x2 = 500;
			double y2 = 500;
			double width2 = 500;
			double height2 = 500;
			bool gravity2 = false;

			Object *test2 = new Object(x2, y2, width2, height2, gravity2);

			assert(test1->checkCollision(test1, test2) == true);
			assert(test2->checkCollision(test1, test2) == true);
			std::cout << "test1 and test2 should collide and are colliding";

			test2->setX(1);
			test2->setY(1);
			test2->setWidth(1);
			test2->setHeight(1);

			assert(test1->checkCollision(test1, test2) == false);
			assert(test2->checkCollision(test1, test2) == false);
			std::cout << "test1 and test2 should NOT collide and are NOT colliding";
		}

		static void ObjectTest::xTest() {
			double x = 0;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;

			Object *test = new Object(x, y, width, height, gravity);

			test->setX(100);
			assert(test->getX() == 100);
			std::cout << "x is set and retrieved correctly";
		}

		static void ObjectTest::yTest() {
			double x = 100;
			double y = 0;
			double width = 50;
			double height = 50;
			bool gravity = false;
	
			Object *test = new Object(x, y, width, height, gravity);

			test->setY(10);
			assert(test->getY() == 10);
			std::cout << "y is set and retrieved correctly";
		}

		static void ObjectTest::WidthTest() {
			double x = 100;
			double y = 10;
			double width = 0;
			double height = 50;
			bool gravity = false;

			Object *test = new Object(x, y, width, height, gravity);

			test->setWidth(50);
			assert(test->getWidth() == 50);
			std::cout << "width is set and retrieved correctly";
		}

		static void ObjectTest::HeightTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 0;
			bool gravity = false;

			Object *test = new Object(x, y, width, height, gravity);

			test->setHeight(50);
			assert(test->getHeight() == 50);
			std::cout << "height is set and retrieved correctly";
		}

		static void ObjectTest::GravityTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;

			Object *test = new Object(x, y, width, height, gravity);

			test->setGravityEnabled(true);
			assert(test->getGravityEnabled() == true);
			std::cout << "gravity is set and retrieved correctly";
		}

		static void ObjectTest::SpeedTest() {
			double x = 100;
			double y = 10;
			double width = 50;
			double height = 50;
			bool gravity = false;

			Object *test = new Object(x, y, width, height, gravity);

			test->setXSpeed(10);
			assert(test->getXSpeed() == 10.0);
			test->setYSpeed(15);
			assert(test->getYSpeed == 15.0);
			std::cout << "xSpeed and ySpeed are set and retrieved correctly";
		}

};


