#include <SDL_mixer.h>
#include <iostream>
#include "Sounds.h"


Sounds::Sounds(std::string path,std::string type) {
	//sound file must be a .wav to work
	soundType = type;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		std::cout << "failed to init";

	if (soundType == "music") {
		mus = Mix_LoadMUS(path.c_str());
		if (mus == NULL)
			std::cout << "failed to load music";
	}
	else if (soundType == "effect") {
		eff = Mix_LoadWAV(path.c_str());
		if (eff == NULL)
			std::cout << "failed to load sound effect";
	}
}

Sounds::~Sounds() {

	Mix_FreeMusic(mus);
}

void Sounds::play() {
	if (soundType == "music") {
		if (Mix_PlayingMusic() == 0)
			Mix_PlayMusic(mus, -1);
			//std::cout << "playing music\n";
	}
	else if (soundType == "effect") {
		Mix_PlayChannel(-1, eff, 0);
		//std::cout << "playing effect\n";
	}
}

