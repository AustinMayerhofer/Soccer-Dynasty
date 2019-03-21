#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <fstream>
#include <iostream>
#include "League.h"
class World
{
public:
	World(std::string leagues_file, std::string teams_file);
	League* league(std::string league_name);
	League* league(int league_id);

private:
	std::vector<League*> leagues;
	std::vector<Tournament*> tournaments;

	// file reading
	void read_leagues_file(std::string name);
	void read_teams_file(std::string name);
	void open_file(std::ifstream& stream, std::string file_name);
	void throw_file_error(std::string file_name = "");
	void add_league(std::string league_name, int league_id);
	void add_team(std::string team_name, std::string owner, int league_id, double off_rating, double def_rating);
};

#endif