#pragma once

#include <string>
#include <vector>

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
  int getName () {return score;}
  std::string toString () {return score + " " + name;}
};

class HighScoreController {
public:
  HighScoreController();

  void writeScore (int, std::string);
  std::vector<Score> getScores ();

  std::string toString ();
};
