#include "League.h"
#include <iostream>
#include <algorithm>

bool whichTeamIsBetter(Team* team1, Team* team2);

League::League(std::string league_name, int league_id, double league_money) : name(league_name), id(league_id), money(league_money), teams(0), standings(0), season_games(0) {

}

League::League(std::string league_name) : name(league_name), teams(0), standings(0), season_games(0) {

}

void League::playSeasonSingleRoundRobin() {
	reset_season();
	play_round_robin();
	calculateStandings();
}

void League::playSeasonDoubleRoundRobin() {
	reset_season();
	play_round_robin();
	play_round_robin();
	calculateStandings();
}

void League::playSeasonDoubleRoundRobinWithMoney() {
	playSeasonDoubleRoundRobin();

}

void League::printStandings() {
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
	standings.push_back(team);
}

std::string League::getName() {
	return name;
}

Team* League::getTeam(int index) {
	if (index < 0 || index >= size()) {
		std::cerr << "League::getTeam() index " << index << " out of bounds" << std::endl;
		return NULL;
	}
	else {
		return teams[index];
	}
}

Team* League::getTeamRanked(int index) {
	if (index < 0 || index >= size()) {
		std::cerr << "League::getTeam() index " << index << " out of bounds" << std::endl;
		return NULL;
	}
	else {
		return standings[index];
	}
}

int League::size() {
	return teams.size();
}

void League::calculateStandings() {
	std::sort(standings.begin(), standings.end(), whichTeamIsBetter);
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

void League::play_round_robin() {
	for (unsigned int home = 0; home < teams.size(); home++) {
		for (unsigned int away = home + 1; away < teams.size(); away++) {
			Game* match = new Game(teams[home], teams[away]);
			match->playSeasonGame();
			season_games.push_back(match);
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

void League::deal_money_to_teams() {
	
}

bool whichTeamIsBetter(Team* team1, Team* team2) {
	// true means team1 should be ranked higher
	// false means team2 should be ranked higher
	if (team1->getSeasonPoints() > team2->getSeasonPoints()) {
		return true;
	}
	else if (team1->getSeasonPoints() == team2->getSeasonPoints()) {
		if (team1->getSeasonGD() >= team2->getSeasonGD()) {
			return true;
		}
		else if (team1->getSeasonGD() == team2->getSeasonGD()) {
			return team1->getSeasonGoals() > team2->getSeasonGoals();
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}