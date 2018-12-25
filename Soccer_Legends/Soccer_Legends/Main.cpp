#include <iostream>
#include <vector>
#include "World.h"
#include "Team.h"

void check_arguments(int argc) {
	if (argc != 3) {
		std::cerr << "Usage: ./ISL_Legends <Teams_file> <Leagues_file>" << std::endl;
		system("Pause");  // FIXME
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	check_arguments(argc);
	World earth(argv[1], argv[2]);
	earth.league("Second Division")->printTeams();
	system("Pause");  // FIXME
	return 0;
}