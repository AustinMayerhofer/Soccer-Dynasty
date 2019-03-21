#include "Tournament.h"
#include <iostream>

Tournament::Tournament(std::vector<Team*> teams, std::string name) : teams(teams), name(name) {

}

void Tournament::playUEFACLFormat() {
    // FIXME: free League pointers at end of method
    std::vector<League*> groups;
    populateGroups(groups, 5, 4); // FIXME: Make it 8, 4

    // FIXME: testing to make sure populateGroups works correctly
    for (unsigned int i = 0; i < groups.size(); i++) {
        std::cout << groups[i]->getName() << std::endl;
        groups[i]->printStandings();
    }

}

void Tournament::populateGroups(std::vector<League*>& groups, int numGroups, int groupSize) {
    if (numGroups * groupSize != static_cast<int>(teams.size())) {
        std::cerr << "Invalid group sizes/number of groups compared to number of teams in " << name << std::endl;
        exit(1);
    }

    for (int i = 0; i < numGroups; i++) {
        groups.push_back(new League("Group " + (i + 1)));
        for (int j = i * groupSize; j < (i+1) * groupSize; j++) {
            groups[j % groupSize]->addTeam(teams[j]);
        }
    }
}