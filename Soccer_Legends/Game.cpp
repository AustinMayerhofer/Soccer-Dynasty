#include "Game.h"
#include "Random.h"
#include <iostream>

Game::Game(Team* home_team, Team* away_team) : home(home_team), away(away_team), winner(NULL) {
	
}

void Game::playSeasonGame() {
	home_goals = generate_team_goals(home, away);
	away_goals = generate_team_goals(away, home);

	update_team_info(home_goals, away_goals);
	update_winner();

}

// TODO: Update team info?
// TODO: Add something that indicates if a game went into ET
void Game::playKnockoutGame() {
	home_goals = generate_team_goals(home, away);
	away_goals = generate_team_goals(away, home);

	if (home_goals == away_goals) {
		pick_winner_in_extra_time();
	}

	update_winner();

}

void Game::printGameInfo() {
	std::cout << home->getName() << " " << home_goals << "-" << away_goals << " " << away->getName();
}

Team* Game::getWinner() {
	return winner;
}

int Game::generate_team_goals(Team* team, Team* opponent) {
	 int goals = generate_random_goals();

	 if (team->getOffRating() > opponent->getDefRating()) {
		 goals = increase_goals(goals, team, opponent);
	 }
	 else if (team->getOffRating() < opponent->getDefRating()) {
		 goals = decrease_goals(goals, team, opponent);
	 }

	 return goals;
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

int Game::increase_goals(int starting_goals, Team* team, Team* opponent) {
	int goals_added = 0;
	double rating_diff = team->getOffRating() - opponent->getDefRating();
	rating_diff *= 10;  // multiplier to have no decimal
	Random rand;

	int LOOPS = 10;

	for (int i = 0; i < LOOPS; i++) {
		int num = rand.randInt(1, 1000);
		if (num <= rating_diff) {
			goals_added++;
		}
	}

	if (goals_added == LOOPS) {
		do {
			int num = rand.randInt(1, 1000);
			if (num <= rating_diff) {
				goals_added++;
			}
			else {
				break;
			}
		} while (goals_added < 30);
	}

	int final_goals = starting_goals + goals_added;

	return final_goals;
}

int Game::decrease_goals(int starting_goals, Team* team, Team* opponent) {
	if (starting_goals == 0) return 0;

	int goals_decreased = 0;
	double rating_diff = opponent->getDefRating() - team->getOffRating();
	rating_diff *= 10;
	Random rand;

	int LOOPS = 15;  // higher number of more randomness

	for (int i = 0; i < LOOPS; i++) {
		int num = rand.randInt(1, 1000);
		if (num <= rating_diff) {
			goals_decreased++;
		}
	}

	if (goals_decreased == LOOPS) {
		do {
			int num = rand.randInt(1, 1000);
			if (num <= rating_diff) {
				goals_decreased++;
			}
			else {
				break;
			}
		}while (goals_decreased < starting_goals);
	}

	int final_goals = starting_goals - goals_decreased;
	if (final_goals < 0) final_goals = 0;

	return final_goals;

}

// chooses a winner if a knockout game is tied
void Game::pick_winner_in_extra_time() {
	Random rand;
	int home_win_probability = home->getOffRating() + home->getDefRating();
	int away_win_probability = away->getOffRating() + away->getDefRating();
	int result = rand.randInt(1, home_win_probability + away_win_probability);

	if (result <= home_win_probability) {
		home_goals += 1;
	}
	else {
		away_goals += 1;
	}
	
}

void Game::update_team_info(int home_goals, int away_goals) {
	if (home_goals > away_goals) {
		home->setSeasonWins(home->getSeasonWins() + 1);
		away->setSeasonLosses(away->getSeasonLosses() + 1);
	}
	else if (home_goals < away_goals) {
		home->setSeasonLosses(home->getSeasonLosses() + 1);
		away->setSeasonWins(away->getSeasonWins() + 1);
	}
	else {
		home->setSeasonDraws(home->getSeasonDraws() + 1);
		away->setSeasonDraws(away->getSeasonDraws() + 1);
	}

	home->setSeasonGoals(home->getSeasonGoals() + home_goals);
	home->setSeasonGA(home->getSeasonGA() + away_goals);
	away->setSeasonGoals(away->getSeasonGoals() + away_goals);
	away->setSeasonGA(away->getSeasonGA() + home_goals);
}

void Game::update_winner() {
	if (home_goals > away_goals) {
		winner = home;
	}
	else if (home_goals < away_goals) {
		winner = away;
	}
	else {
		winner = NULL;
	}
	
}