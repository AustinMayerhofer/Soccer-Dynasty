#ifndef GAME_H
#define GAME_H

#include "Team.h"

class Game
{
public:
	Game(Team* home, Team* away);
	void play();

private:
	int generate_team_goals(Team* team, Team* opponent);
};

#endif