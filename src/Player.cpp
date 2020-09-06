#include "Player.hpp"

Player::Player() {}

Player::Player(std::string name) : _name(name) {
    this->_score = 0;
    //std::cout << "Player: " << _name << " created\n";
}

Player::~Player() {}

Player    &Player::operator=(Player const &rhs) {
    this->_name = rhs.getName();
    this->_score = rhs.getScore();
    this->_locations = rhs.getLocations();
    return *this;
}

Player::Player(Player const &rhs) {
    this->_name =  rhs.getName();
    this->_locations = rhs.getLocations();
    this->_score = rhs.getScore();
}

std::string Player::getName() const {
    return this->_name;
}

bool        Player::addLocation(int x, int y) {
    std::vector<std::pair <int, int> >::iterator it;
    it = this->_locations.begin();
    this->_locations.insert(it, std::make_pair(x, y));
    return true;
}

std::vector<std::pair <int, int> > Player::getLocations() const {
    return this->_locations;
}

int         Player::getScore() const {
    return this->_score;
}

void        Player::movePlayer(eInput dir, bool ate_fruit) {
    std::vector<std::pair <int, int> >::iterator it;
    it = this->_locations.begin();

    switch (dir) {
        case UP:
            addLocation(_locations[0].first, _locations[0].second - 1);
            break;
        case DOWN:
            addLocation(_locations[0].first, _locations[0].second + 1);
            break;
        case LEFT:
            addLocation(_locations[0].first - 1, _locations[0].second);
            break;
        case RIGHT:
            addLocation(_locations[0].first + 1, _locations[0].second);
            break;
        default:
            break;
    }
    if (!ate_fruit) {
        this->_locations.pop_back();
    }
}

void        Player::addScore(int points) {
    this->_score += points;
}