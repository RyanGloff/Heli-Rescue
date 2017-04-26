#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Database.h"

class Score {
private:
  int score;
  std::string name;
public:
  Score(int score, std::string name) {
    this->score = score;
    this->name = name;
  }

  int getScore () {return score;}
  std::string getName () {return name;}

  std::string toString () {
    std::ostringstream oss;
    oss << name << " - " << score;
    return oss.str();
  }
};

class HighScoreController {
private:
  Database* db = nullptr;
public:
  HighScoreController();

  void addScore(int, std::string);
  std::vector<Score> getScores ();
};
