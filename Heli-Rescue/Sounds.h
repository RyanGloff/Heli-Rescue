#pragma once

#include <SDL_mixer.h>
#include <iostream>
#include <string.h>


class Sounds {

public:
	Sounds::Sounds(std::string path,std::string type);
	Sounds::~Sounds();
public:
	void Sounds::play();
	std::string type;
	std::string soundType;
private:
	
	Mix_Music* mus;
	Mix_Chunk* eff;

};