#ifndef GAME_H
#define GAME_H

#include "Team.h"

class Game
{
public:
	Game(Team* home_team, Team* away_team);
	void playSeasonGame();

private:
	Team* home;
	Team* away;
	int generate_team_goals(Team* team, Team* opponent);
	int generate_random_goals();
	int increase_goals(int starting_goals, Team* team, Team* opponent);
	int decrease_goals(int starting_goals, Team* team, Team* opponent);
	void update_team_info(int home_goals, int away_goals);
};

#endif