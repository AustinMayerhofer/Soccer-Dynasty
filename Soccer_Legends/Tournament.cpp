#include "Tournament.h"
#include <iostream>

Tournament::Tournament(std::vector<Team*> teams, std::string name) : teams(teams), name(name) {

}

void Tournament::playWorldCupFormat() {
    // FIXME: free League pointers at end of method
    std::vector<League*> groups;
    std::vector<Team*> knockout_round(16);
    int KO_index = 0; // keeps track of team placement
    populateGroups(groups, 8, 4);

    // Group stage
    for (auto& group : groups) {
        // Simulate group
        group->playSeasonSingleRoundRobin();

        // Print results
        std::cout << group->getName() << std::endl;
        group->printStandings();
        std::cout << std::endl;
        
        // Algorithm to advance top 2 to knockout stage, with placement in mind
        knockout_round[KO_index] = group->getTeamRanked(0);
        if (KO_index < 8) { KO_index += 9; } else { KO_index -= 7; }
        knockout_round[KO_index] = group->getTeamRanked(1);
        if (KO_index < 8) { KO_index += 1; } else { KO_index -= 1; }
    }

    // Knockout stage
    std::cout << std::endl << "Round of 16:" << std::endl;
    knockoutRoundSingleElim(knockout_round);
    std::cout << std::endl << "Quarterfinals:" << std::endl;
    knockoutRoundSingleElim(knockout_round);
    std::cout << std::endl << "Semifinals:" << std::endl;
    knockoutRoundSingleElim(knockout_round);
    std::cout << std::endl << "Finals:" << std::endl;
    knockoutRoundSingleElim(knockout_round);

    // Pointer cleanup
    for (auto& group : groups) {
        delete group;
    }
}

void Tournament::populateGroups(std::vector<League*>& groups, int numGroups, int groupSize) {
    // Check number of teams is valid
    if (numGroups * groupSize != static_cast<int>(teams.size())) {
        std::cerr << "Invalid group sizes/number of groups compared to number of teams in " << name << std::endl;
        exit(1);
    }

    // Populate the groups
    for (int i = 0; i < numGroups; i++) {
        groups.push_back(new League("Group " + std::to_string(i + 1)));
        for (int j = i * groupSize; j < (i+1) * groupSize; j++) {
            groups[i]->addTeam(teams[j]);
        }
    }
}

void Tournament::knockoutRoundSingleElim(std::vector<Team*>& teams) {
    for (unsigned int i = 0; i < teams.size(); i++) {
        Game KO_game(teams[i], teams[i+1]);
        KO_game.playKnockoutGame();
        KO_game.printGameInfo();
        std::cout << std::endl;

        if (KO_game.getWinner() == teams[i])
            teams.erase(teams.begin() + i + 1);
        else
            teams.erase(teams.begin() + i);
        
    }
}