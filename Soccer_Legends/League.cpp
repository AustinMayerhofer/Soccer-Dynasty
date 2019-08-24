#include "League.h"
#include <iostream>

League::League(std::string league_name, int league_id) : name(league_name), id(league_id), teams(0), season_games(0) {

}

League::League(std::string league_name) : name(league_name), teams(0), season_games(0) {

}

void League::playSeason() {
	reset_season();
	play_round_robin_double_header();
	printStandings();
}

void League::printStandings() {
	std::vector<Team*> standings = teams;

	// insertion sort
	for (unsigned int i = 0; i < standings.size(); i++) {
		for (unsigned int j = i; j > 0; j--) {
			if (standings[j]->getSeasonPoints() > standings[j-1]->getSeasonPoints()) {
				std::swap(standings[j], standings[j-1]);
			}
			else if (standings[j]->getSeasonPoints() == standings[j-1]->getSeasonPoints()) {
				if (standings[j]->getSeasonGD() > standings[j-1]->getSeasonGD()) {
					std::swap(standings[j], standings[j-1]);
				}
			}
			else {
				break;
			}
		}
	}

	for (unsigned int i = 0; i < standings.size(); i++) {
		std::cout << i + 1 << ". ";
		standings[i]->printSeasonInfo();
		std::cout << std::endl;
	}

}

void League::printTeams() {
	for (const auto& team : teams) {
		team->printTeamBio();
	}
}

void League::addTeam(Team* team) {
	teams.push_back(team);
}

std::string League::getName() {
	return name;
}

void League::play_round_robin_double_header() {
	for (unsigned int home = 0; home < teams.size(); home++) {
		for (unsigned int away = 0; away < teams.size(); away++) {
			if (home != away) {
				Game* match = new Game(teams[home], teams[away]);
				match->playSeasonGame();
				season_games.push_back(match);
			}
		}
	}
}

void League::reset_season() {
	for (auto& team : teams) {
		team->resetSeason();
	}

	for (auto& game : season_games) {
		delete game;
	}
}