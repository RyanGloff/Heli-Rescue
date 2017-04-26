#!/bin/sh

# Creating the object files
g++ -c Heli-Rescue/Display.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Sounds.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Object.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Menu.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/EntityGenerator.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/TerrainGenerator.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Environment.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Window.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/InputHandler.cpp -w -std=c++14 -I/usr/include/SDL2
g++ -c Heli-Rescue/Database.cpp -w -std=c++14
g++ -c Heli-Rescue/HighScoreController.cpp -w -std=c++14

#linking the object files together and creating the executable file
g++ Heli-Rescue/Source.cpp Database.o Display.o EntityGenerator.o Environment.o HighScoreController.o InputHandler.o Menu.o Object.o Sounds.o TerrainGenerator.o Window.o -w -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lmysqlcppconn -std=c++14 -I/usr/include/SDL2

#Removing all the old object files
rm Display.o
rm Sounds.o
rm Object.o
rm Menu.o
rm EntityGenerator.o
rm TerrainGenerator.o
rm Environment.o
rm Window.o
rm InputHandler.o
rm Database.o
rm HighScoreController.o

# Runs the executable
#./a.out
