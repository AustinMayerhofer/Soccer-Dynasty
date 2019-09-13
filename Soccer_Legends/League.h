#ifndef LEAGUE_H
#define LEAGUE_H
#include <string>
#include <vector>
#include "Team.h"
#include "Game.h"
class League
{
public:
	League(std::string league_name, int league_id, double league_money);
	League(std::string league_name);
	void playSeasonSingleRoundRobin();
	void playSeasonDoubleRoundRobin();
	void playSeasonDoubleRoundRobinWithMoney();
	void printStandings();
	void printTeams();
	void addTeam(Team* team);
	std::string getName();
	Team* getTeam(int index);
	Team* getTeamRanked(int index);
	int size();

private:
	std::string name;
	int id;
	double money;
	std::vector<Team*> teams;
	std::vector<Team*> standings;
	std::vector<Game*> season_games;
	void calculateStandings();
	void play_round_robin_double_header();
	void play_round_robin();
	void reset_season();
	void deal_money_to_teams();
};

#endif