#include "World.h"
#include <sstream>


World::World(std::string leagues_file, std::string teams_file)
{
	read_leagues_file(leagues_file);
	read_teams_file(teams_file);
}

League* World::league(std::string league_name) {
	for (auto& league : leagues) {
		if (league->getName() == league_name)
			return league;
	}

	std::cerr << "No league found for league name \"" << league_name << "\"" << std::endl;
	system("Pause");  // FIXME
	exit(1);
}

League* World::league(int league_id) {
	return leagues.at(league_id - 1);
}

void World::read_leagues_file(std::string name) {
	std::ifstream file;
	std::string line;

	open_file(file, name);

	// iterate through each line in the file
	while (getline(file, line)) {
		std::string league_name, league_id;
		std::stringstream league_info(line);

		// obtain the tokens in the line
		getline(league_info, league_name, ',');
		getline(league_info, league_id);
		add_league(league_name, std::stoi(league_id));
	}
}

void World::read_teams_file(std::string name) {
	std::ifstream file;
	std::string line;

	open_file(file, name);

	// iterate through each line in the file
	while (getline(file, line)) {
		std::string team_name, owner, league_id, off_rating, def_rating;
		std::stringstream team_info(line);

		// obtain the tokens in the line
		getline(team_info, team_name, ',');
		getline(team_info, owner, ',');
		getline(team_info, league_id, ',');
		getline(team_info, off_rating, ',');
		getline(team_info, def_rating);
		add_team(team_name, owner, std::stoi(league_id), std::stod(off_rating), std::stod(def_rating));
	}
}

void World::open_file(std::ifstream& stream, std::string file_name) {
	stream.open(file_name);
	if (!stream.is_open()) {
		throw_file_error();
	}
}

void World::throw_file_error(std::string file_name) {
	std::cerr << "Error: could not load file " << file_name << std::endl;
	system("Pause");  // FIXME
	exit(1);
}

void World::add_league(std::string league_name, int league_id) {
	leagues.push_back(new League(league_name, league_id));
}

void World::add_team(std::string team_name, std::string owner, int league_id, double off_rating, double def_rating) {
	int league_index = league_id - 1;  // league_id starts at 1. Arrays are 0-based
	leagues.at(league_index)->addTeam(new Team(team_name, owner, league_id, off_rating, def_rating));
}