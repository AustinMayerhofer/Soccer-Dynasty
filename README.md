# Soccer-Legends
Text-based soccer simulator made in Visual Studio

# How to run
* $ make
* $ ./soccer_legends leagues.txt teams.txt

# Files read in

## leagues.txt
* File that contains the leagues used in the simulation
* Format: League name (string), League index (int)
* League index should start at 1 and each index should be unique (they are keys)
* No spaces between commas

## teams.txt
* File that contains the teams used in the simulation
* Format: Team name (string), Owner (string), League index (int), Offensive rating (double), Defensive rating (double)
* League indexes should match those in leagues.txt
* No spaces between commas

# TODO:
Pointer cleanup
Tournaments
User control over a team


# Notes
* https://en.wikipedia.org/wiki/List_of_professional_sports_leagues_by_revenue used to calculate money per League. All leagues are relative to the Premier League.