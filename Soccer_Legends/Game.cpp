#include "Game.h"
#include "Random.h"

Game::Game(Team* home, Team* away) {
	
}

void Game::play() {
	//int home_goals;
	//int away_goals;
}

int Game::generate_team_goals(Team* team, Team* opponent) {
	return 0;
}

int Game::generate_random_goals() {
	Random rand;
	int num = rand.randInt(1, 1000);

	if (num >= 1 && num <= 292) {
		return 0;
	}
	else if (num >= 293 && num <= 615) {
		return 1;
	}
	else if (num >= 616 && num <= 829) {
		return 2;
	}
	else if (num >= 830 && num <= 939) {
		return 3;
	}
	else if (num >= 940 && num <= 983) {
		return 4;
	}
	else if (num >= 984 && num <= 994) {
		return 5;
	}
	else if (num >= 995 && num <= 999) {
		return 6;
	}
	else {
		return 7;
	}

}