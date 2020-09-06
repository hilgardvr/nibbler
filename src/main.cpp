#include <iostream>

#include "Player.hpp"
#include "GameEngine.hpp"

int		main(int ac, char** av) {
	if (ac != 3) {
		std::cout << "\n\tInvalid number of arguments\n";
		std::cout << "\n\tUsage ./nibbler (width) (height)\n\n";
		return (1);
	}

	int gameWidth;
	int gameHeight;
	try {
		gameWidth = std::stoi(av[1]);
		gameHeight = std::stoi(av[2]);
        if (gameWidth < 5 || gameHeight < 5){
            throw std::invalid_argument("Too small");
        }
	} catch (std::invalid_argument) {
		std::cout << "\n\tInvalid args\n";
		std::cout << "\n\tHeight or width argument is not valid - exiting\n";
		std::cout << "\n\tUsage ./nibbler (width) (height)\n\n";
		return (1);
	}

	Player *p1 = new Player("Playa");
	for (int ctr = 0; ctr < 4; ctr++) {
		p1->addLocation( (gameWidth / 2 - 4) + ctr, gameHeight / 2);
	}

	GameEngine *engine = new GameEngine(gameWidth, gameHeight);
	engine->runGame(p1, gameWidth, gameHeight);

    std::cout << "Game over - your score: " << p1->getScore() << std::endl;
	delete p1;
	delete engine;
	return 0;
}
