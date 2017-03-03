#include "Object.h"

Object::Object() {

}
Object::Object(double x, double y, double width, double height, bool gravity) : x(x), y(y), width(width), height(height), gravity(gravity) {
	xSpeed = 0;
	ySpeed = 0;
}


Object::~Object() {

}

void Object::tick() {
	x += xSpeed;
	y += ySpeed;
}
void Object::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	
	SDL_Rect rect;
	rect.x = (int) x;
	rect.y = (int) y;
	rect.w = (int) width;
	rect.h = (int) height;

	SDL_RenderFillRect(renderer, &rect);
}

bool Object::checkCollision(Object* obj1, Object* obj2) {
	if (obj1->getX() + obj1->getWidth() > obj2->getX() && obj1->getX() < obj2->getX() + obj2->getWidth()) {
		if (obj1->getY() + obj1->getHeight() > obj2->getY() && obj1->getY() < obj2->getY() + obj2->getHeight()) {
			return true;
		}
	} 
	return false;
}

double Object::getX() {
	return x;
}
double Object::getY() {
	return y;
}
double Object::getWidth() {
	return width;
}
double Object::getHeight() {
	return height;
}
double Object::getXSpeed() {
	return xSpeed;
}
double Object::getYSpeed() {
	return ySpeed;
}
bool Object::getGravityEnabled() {
	return gravity;
}

void Object::setX(double x) {
	this->x = x;
}
void Object::setY(double y) {
	this->y = y;
}
void Object::setWidth(double width) {
	this->width = width;
}
void Object::setHeight(double height) {
	this->height = height;
}
void Object::setXSpeed(double xSpeed) {
	this->xSpeed = xSpeed;
}
void Object::setYSpeed(double ySpeed) {
	this->ySpeed = ySpeed;
}
void Object::setGravityEnabled(bool gravity) {
	this->gravity = gravity;
}