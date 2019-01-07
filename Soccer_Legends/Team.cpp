#include "Team.h"
#include <iostream>



Team::Team(std::string team_name, std::string team_owner, int league_identifier, double offensive_rating, double defensive_rating) :
	name(team_name), owner(team_owner), league_id(league_identifier), off_rating(offensive_rating), 
	def_rating(defensive_rating), season_wins(0), season_losses(0), season_draws(0)
{
}

void Team::printTeamBio() {
	std::cout << name << " (" << owner << ")" << std::endl;
}

void Team::printSeasonInfo() {
	std::cout << name << " " << season_wins << "-" << season_losses << "-" << season_draws << " (" << getSeasonPoints() << ") "
	<< season_goals << " : " << season_GA;
}

std::string Team::getName() {
	return name;
}

int Team::getOffRating() {
	return off_rating;
}

int Team::getDefRating() {
	return def_rating;
}

int Team::getSeasonWins() {
	return season_wins;
}

int Team::getSeasonLosses() {
	return season_losses;
}

int Team::getSeasonDraws() {
	return season_draws;
}

int Team::getSeasonGoals() {
	return season_goals;
}

int Team::getSeasonGA() {
	return season_GA;
}

int Team::getSeasonPoints() {
	return (season_wins * 3) + season_draws;
}

void Team::setSeasonWins(int wins) {
	season_wins = wins;
}

void Team::setSeasonLosses(int losses) {
	season_losses = losses;
}

void Team::setSeasonDraws(int draws) {
	season_draws = draws;
}

void Team::setSeasonGoals(int goals) {
	season_goals = goals;
}

void Team::setSeasonGA(int GA) {
	season_GA = GA;
}

void Team::resetSeason() {
	season_wins = 0;
	season_losses = 0;
	season_draws = 0;
	season_goals = 0;
	season_GA = 0;
}