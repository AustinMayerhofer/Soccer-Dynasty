#include <iostream>
#include <vector>
#include "World.h"
#include "Team.h"

void check_arguments(int argc) {
	if (argc != 3) {
		std::cerr << "Usage: ./ISL_Legends <Leagues_file> <Teams_file>" << std::endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	check_arguments(argc);
	World earth(argv[1], argv[2]);
	earth.league(1)->playSeason();
	return 0;
}