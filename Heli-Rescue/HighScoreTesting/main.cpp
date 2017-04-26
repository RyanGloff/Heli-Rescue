#include <iostream>
#include "HighScoreController.h"

int main () {
  HighScoreController hsc;
  // Works correctly

  //hsc.writeScore(100, "Ryan");
  //hsc.writeScore(200, "Person 2");
  //hsc.writeScore(300, "Person 3");


  std::vector<Score> highScores = hsc.getScores();
  for (Score s : highScores) {
    std::cout << s.toString() << std::endl;
  }

  return 0;
}
