#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team
{
public:
	Team(std::string team_name, std::string team_owner, int league_identifier, double offensive_rating, double defensive_rating);
	void printTeamBio();

private:
	std::string name;
	std::string owner;
	int league_id;
	double off_rating;
	double def_rating;
	int wins;
	int losses;
	int draws;

};

#endif