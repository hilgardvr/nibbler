#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <vector>
#include <iostream>

#include "eInput.hpp"

class Player {
    public:
        Player(std::string name);
        ~Player();
        Player &operator=(Player const &rhs);
        Player(Player const &src);

        std::string                         getName() const;
        bool                                addLocation(int x, int y);
        std::vector<std::pair <int, int> >  getLocations() const;
        int                                 getScore() const;
        void                                movePlayer(eInput dir, bool ate_fruit);
        void                                addScore(int points);

    private:
        Player();
        std::string                         _name;
        int                                 _score;
        std::vector<std::pair <int, int> >  _locations;
};

#endif