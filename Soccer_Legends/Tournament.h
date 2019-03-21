#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include "Team.h"
#include "League.h"
#include <vector>
class Tournament {
    public:
        Tournament(std::vector<Team*> teams, std::string name);
        void playUEFACLFormat();
    private:
        std::vector<Team*> teams;
        std::string name;
        void populateGroups(std::vector<League*>& groups, int numGroups, int groupSize);
};
#endif