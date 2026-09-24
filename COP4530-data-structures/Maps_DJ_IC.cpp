#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ChampionData {

  string name;
  int wins;
  vector<int> winning_years;
  int year;
  string country;
  string coach;
  string captain;
};

// read file
map<string, ChampionData> readFile(string filename) { // why contained here?
  ifstream infile;
  infile.open(filename);

  // default in case of infile error
  map<string, ChampionData> cd;

  ChampionData champ;
  string line;
  if (infile) {
    getline(infile, line); // Skips the first line (not data)
    while (getline(infile, line)) {
      istringstream iss(line);
      string year_str, country, coach, captain;
      getline(iss, year_str, '\t'); // Gets the values, skipping by tab
      getline(iss, country, '\t');
      getline(iss, coach, '\t');
      getline(iss, captain, '\n');
      int year = stoi(year_str);
      auto it = cd.find(country);
      if (it != cd.end()) {
        ChampionData champ;
        champ.country = country;
        champ.coach = coach;
        champ.captain = captain;
        it->second.wins++;
        it->second.winning_years.push_back(year);
      } else {
        ChampionData champ;      // Creating object champ
        champ.country = country; // Initializing Champ variables
        champ.coach = coach;
        champ.captain = captain;
        champ.wins = 1;
        champ.winning_years.push_back(year);
        cd.insert(make_pair(country, champ)); // Inserting Key
      }
    }
    infile.close();
  }
  return cd;
}

int main() {
  map<string, ChampionData> champs =
      readFile("world_cup_champions.txt"); // Creates object and reads

  cout << "FIFA World Cup Winners" << endl << endl;
  cout << "Country         Wins  Years" << endl;
  cout << "=======         ====  =====" << endl;

  for (const auto &champ : champs) { // Orders Countries alphabetically
    cout << left << setw(16) << champ.second.country << setw(6)
         << champ.second.wins;
    for (size_t i = 0; i < champ.second.winning_years.size(); i++) {
      cout << left << setw(4) << champ.second.winning_years[i];
      if (i < champ.second.winning_years.size() - 1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
  return 0;
}
