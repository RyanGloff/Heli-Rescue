#include "HighScoreController.h"

HighScoreController::HighScoreController () {
  db = new Database("Heli-Rescue Client", "Pa55word", "heli-rescue", "150.156.209.235");
}

void HighScoreController::addScore (int score, std::string name) {
  std::ostringstream oss;
  oss << "INSERT INTO scores(score, firstName) VALUES (" << score << ", '" << name << "');";

  std::string stmt = oss.str();
  std::cout << "Running SQL Statement: " << stmt << std::endl;
  db->executePrepStatement(stmt);
}

std::vector<Score> HighScoreController::getScores () {
  std::vector<Score> scores;
  sql::ResultSet *res = db->executeQuery("SELECT * FROM scores");
  int iteration = 0;
  while (res->next()) {
    std::cout << "Iteration: " << iteration << std::endl;
    iteration++;
    std::cout << res->getString("firstName") << " - ";
    std::cout << res->getString("score") << std::endl;
    std::string name = res->getString("firstName").c_str();
    int score = std::stoi(res->getString("score").c_str());
    Score s(score, name);
    scores.push_back(s);
  }
  std::cout << scores.size() << std::endl;
  return scores;
}
