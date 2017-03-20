#pragma once
#include <SDL.h>
#include <iostream>
class Object {
private:
	double x;
	double y;
	double width;
	double height;
	double xSpeed;
	double ySpeed;

	bool gravity;
	SDL_Texture *objectTexture;
	SDL_Surface* objectSurface;
public:
	Object();
	Object(double x, double y, double width, double height, bool gravity);
	Object(double x, double y, double width, double height, bool gravity, const std::string &imgPath);
	~Object();

	void tick();
	void render(SDL_Renderer* renderer);

	static bool checkCollision(Object* obj1, Object* obj2);

	double getX();
	double getY();
	double getWidth();
	double getHeight();
	double getXSpeed();
	double getYSpeed();
	bool getGravityEnabled();

	void setX(double x);
	void setY(double y);
	void setWidth(double width);
	void setHeight(double height);
	void setXSpeed(double xSpeed);
	void setYSpeed(double ySpeed);
	void setGravityEnabled(bool gravity);
};

