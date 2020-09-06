#include "SfmlGraphics.hpp"

SfmlGraphics::SfmlGraphics() : _SCREEN_WIDTH(100), _SCREEN_HEIGHT(100) {}

SfmlGraphics::SfmlGraphics(int x, int y) : _SCREEN_WIDTH(x), _SCREEN_HEIGHT(y) {
    sf::RenderWindow window(sf::VideoMode(_SCREEN_WIDTH, _SCREEN_HEIGHT), "Test Window");
    window.display();
}

void        SfmlGraphics::draw_frame(int size) {

}

SfmlGraphics::~SfmlGraphics() {
    std::cout << "SDL destructor called\n";
}

void        SfmlGraphics::draw_snake(int x, int y) {
    //sf::Window window(sf::VideoMode(800, 600), "Win");
}

void        SfmlGraphics::draw_fruit(int x, int y) {
    std::cout << "DL says fruit location:  " << x << ":" << y << std::endl;
}

void        SfmlGraphics::draw_score(int score) {
    std::cout << "DL says score: " << score << std::endl;
}

void        SfmlGraphics::delete_self() {
    delete this;
}

int         SfmlGraphics::getInput() {
    return -1;
}

IGraphics     *createGraphics(int x, int y) {
    return new SfmlGraphics(x, y);
}