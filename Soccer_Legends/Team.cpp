#include "Team.h"
#include <iostream>



Team::Team(std::string team_name, std::string team_owner, int league_identifier, double offensive_rating, double defensive_rating) :
	name(team_name), owner(team_owner), league_id(league_identifier), off_rating(offensive_rating), def_rating(defensive_rating)
{
}

void Team::printTeamBio() {
	std::cout << name << " (" << owner << ")" << std::endl;
}