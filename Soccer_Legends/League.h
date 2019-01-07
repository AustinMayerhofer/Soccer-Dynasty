#ifndef LEAGUE_H
#define LEAGUE_H
#include <string>
#include <vector>
#include "Team.h"
#include "Game.h"
class League
{
public:
	League(std::string league_name, int league_id);
	void playSeason();
	void printStandings();
	void printTeams();
	void addTeam(Team* team);
	std::string getName();

private:
	std::string name;
	int id;
	std::vector<Team*> teams;
	std::vector<Game*> season_games;
	void play_round_robin_double_header();
	void reset_season();
};

#endif