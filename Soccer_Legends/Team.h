#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team
{
public:
	Team(std::string team_name, std::string team_owner, int league_identifier, double offensive_rating, double defensive_rating);
	void printTeamBio();
	void printSeasonInfo();
	std::string getName();
	int getOffRating();
	int getDefRating();
	int getSeasonWins();
	int getSeasonLosses();
	int getSeasonDraws();
	int getSeasonGoals();
	int getSeasonGA();
	int getSeasonGD();
	int getSeasonPoints();
	void setSeasonWins(int wins);
	void setSeasonLosses(int losses);
	void setSeasonDraws(int draws);
	void setSeasonGoals(int goals);
	void setSeasonGA(int GA);
	void resetSeason();

private:
	std::string name;
	std::string owner;
	int league_id;
	double off_rating;
	double def_rating;
	int season_wins;
	int season_losses;
	int season_draws;
	int season_goals;
	int season_GA;

};

#endif