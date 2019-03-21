soccer_dynasty: Main.o Game.o League.o Random.o Team.o World.o Tournament.o
	g++ -g -Wall -Werror -std=c++11 -o soccer_dynasty Main.o Game.o League.o Random.o Team.o World.o Tournament.o

Main.o: Main.cpp World.h Team.h
	g++ -g -Wall -Werror -c -std=c++11 Main.cpp World.h Team.h

Game.o: Game.cpp Team.h Random.h
	g++ -g -Wall -Werror -c -std=c++11 Game.cpp Team.h Random.h

League.o: League.cpp Team.h Game.h
	g++ -g -Wall -Werror -c -std=c++11 League.cpp Team.h Game.h

Random.o: Random.cpp
	g++ -g -Wall -Werror -c -std=c++11 Random.cpp

Team.o: Team.cpp
	g++ -g -Wall -Werror -c -std=c++11 Team.cpp

World.o: World.cpp League.h
	g++ -g -Wall -Werror -c -std=c++11 World.cpp League.h

Tournament.o: Tournament.cpp Team.h League.h
	g++ -g -Wall -Werror -c -std=c++11 Tournament.cpp Team.h League.h

clean:
	rm -rf *.o *.gch soccer_dynasty
