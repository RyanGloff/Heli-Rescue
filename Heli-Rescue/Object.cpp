#include "Object.h"
#include "SDL_image.h"
#include <iostream>
#include "Window.h"

 
SDL_Renderer *Window::renderer;
SDL_Surface *Window::surface;


Object::Object() {

}

Object::Object(double x, double y, double width, double height, bool gravity) : x(x), y(y), width(width), height(height), gravity(gravity) {
	double xSpeed = 0;
	double ySpeed = 0;
}

Object::Object(double x,double y,double width,double height,bool gravity,const std::string &imgPath): 
	x(x), y(y), width(width), height(height), gravity(gravity) {

	SDL_Surface* surface = IMG_Load(imgPath.c_str());
	if (surface == NULL) {
		std::cerr << "failed to create surface\n";
	}
	objectTexture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (objectTexture == NULL) {
		std::cerr << "failed to create texture\n";
	}
	SDL_FreeSurface(surface);

	double xSpeed = 0;
	double ySpeed = 0;
}



Object::~Object() {
	SDL_DestroyTexture(objectTexture);
}

void Object::tick() {
	x += xSpeed;
	y += ySpeed;
}
void Object::render(SDL_Renderer* renderer) {
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	if (objectTexture) {
		SDL_RenderCopy(renderer, objectTexture, nullptr, &rect);
	
	}

	else {

		SDL_SetRenderDrawColor(renderer, 200, 10, 120, 255);//purple square
		rect.x = x;
		rect.y = y;
		rect.w = width;
		rect.h = height;
		SDL_RenderFillRect(renderer, &rect);
	}
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