#ifndef GAME_H
#define GAME_H

#include "Team.h"

class Game
{
public:
	int home_goals;
	int away_goals;
	Game(Team* home_team, Team* away_team);
	void playSeasonGame();
	void playKnockoutGame();
	void printGameInfo();
	Team* getWinner();

private:
	Team* home;
	Team* away;
	Team* winner;
	int generate_team_goals(Team* team, Team* opponent);
	int generate_random_goals();
	int increase_goals(int starting_goals, Team* team, Team* opponent);
	int decrease_goals(int starting_goals, Team* team, Team* opponent);
	void pick_winner_in_extra_time();
	void update_team_info(int home_goals, int away_goals);
	void update_winner();
};

#endif