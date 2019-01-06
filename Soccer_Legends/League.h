#ifndef LEAGUE_H
#define LEAGUE_H
#include <string>
#include <vector>
#include "Team.h"
class League
{
public:
	League(std::string league_name, int league_id);
	League(std::string league_name, int league_id, std::vector<Team*> league_teams);
	void printTeams();
	void addTeam(Team* team);
	std::string getName();

private:
	std::string name;
	int id;
	std::vector<Team*> teams;
};

#endif