#include "ScoreBoard.h"
#include <stdexcept>
#include <sstream>
using namespace std;

ScoreBoard::ScoreBoard(const string& filePath):saveFile(filePath)
{
    scores = read();
}

vector<Score> ScoreBoard::read()
{
  vector<Score> saves;
  ifstream file(saveFile.c_str());
  if(file.fail())
  {
    ofstream save;
    save.open(saveFile.c_str());
    return saves;
  }

  string name;
  int score;
  while(file >> name)
  {
      file >> score;
      saves.push_back(Score(name,score));
  }
  return saves;
}

void ScoreBoard::write(string name, int score)
{
  ofstream save;
  save.open(saveFile.c_str());
  scores.push_back(Score(name,score));
  //sorting scores
  int pos_max;

	for (int i=0; i < scores.size()-1; i++)
	{
	    pos_max = i;

		for (int j=i+1; j < scores.size(); j++)
		{

		if (scores.at(j).score > scores.at(pos_max).score)
                   pos_max=j;
		}

            if (pos_max != i)
            {
                 Score temp = scores.at(i);
                 scores.at(i) = scores.at(pos_max);
                 scores.at(pos_max) = temp;
            }
	}
  for(int i =0; i < MAXSCORES; ++i)
  {
    save << scores.at(i).name << endl;
    save << scores.at(i).score << endl;
  }

  save.close();


}

string ScoreBoard::getHighScore()
{
  stringstream score;
  score << scores.at(0).name << " " << scores.at(0).score;

  return score.str();
}
