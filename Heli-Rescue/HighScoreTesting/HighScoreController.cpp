#include "HighScoreController.h"
#include <fstream>
#include <iostream>

HighScoreController::HighScoreController () {

}

void HighScoreController::writeScore (int score, std::string name) {
  std::ofstream fileOut;
  fileOut.open("data.dat", std::ios::app);
  fileOut << name << std::endl;
  fileOut << score << std::endl;
  fileOut.close();
}

std::vector<Score> HighScoreController::getScores () {
  std::vector<Score> highScores;
  std::ifstream fileIn("data.dat");
  int score;
  std::string name;
  std::string scoreInput;
  while (getLine(fileIn, name, nullptr)) {
    getLine(fileIn, &scoreInput, nullptr);
    score = std::atoi(scoreInput);
    std::cout << "Getting a new listing..." << std::endl;
    highScores.push_back(*(new Score(score, name)));
  }
  fileIn.close();
  return highScores;
}
