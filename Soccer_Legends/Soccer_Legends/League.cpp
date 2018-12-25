#include "League.h"

League::League(std::string league_name, int league_id) : name(league_name), id(league_id), teams(0) {

}

League::League(std::string league_name, int league_id, std::vector<Team*> league_teams)
	: name(league_name), id(league_id)
{
	teams = league_teams;
}

void League::addTeam(Team* team) {
	teams.push_back(team);
}

std::string League::getName() {
	return name;
}

void League::printTeams() {
	for (const auto& team : teams) {
		team->printTeamBio();
	}
}