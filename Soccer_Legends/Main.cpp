#include <iostream>
#include <vector>
#include "World.h"
#include "Team.h"
#include "Random.h"

void check_arguments(int argc) {
	if (argc != 3) {
		std::cerr << "Usage: ./soccer_dynasty <Leagues_file> <Teams_file>" << std::endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	check_arguments(argc);
	World earth(argv[1], argv[2]);
	
	//earth.league(1)->playSeasonDoubleRoundRobin();
	//earth.league(1)->printStandings();

	std::vector<Team*> intl_teams;
	std::vector<Team*> WC_teams;

	for (int i = 0; i < earth.league(5)->size(); i++) {
		intl_teams.push_back(earth.league(5)->getTeam(i));
	}

	for (int i = 0; i < 32; i++) {
		Random rand;
		int index = rand.randInt(0, intl_teams.size() - 1);
		WC_teams.push_back(intl_teams[index]);
		intl_teams.erase(intl_teams.begin() + index);
	}

	Tournament WC(WC_teams, "World Cup");
	WC.playWorldCupFormat();

	return 0;
}