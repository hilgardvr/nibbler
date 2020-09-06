#include "GameEngine.hpp"

GameEngine::GameEngine() {}

GameEngine::GameEngine(int width, int height) : _width(width), _height(height) {}

GameEngine::~GameEngine() {}

GameEngine  &GameEngine::operator=(GameEngine const &rhs) {
    this->_width = rhs.getWidth();
    this->_height = rhs.getHeight();
    return *this;
}

GameEngine::GameEngine(GameEngine const &src) {
    this->_width = src.getWidth();
    this->_height = src.getHeight();
}

int         GameEngine::getWidth() const {
    return this->_width;
}

int         GameEngine::getHeight() const {
    return this->_height;
}

void	GameEngine::dlerror_wrapper() {
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

IGraphics       *GameEngine::initGraphics(eGraphicsOption option) {
    std::string libPath;

    switch (option) {
        case E_NCURSES1:
            libPath = "dynamic_libs/ncurses1/ncurses1.so";
            break;
        case E_NCURSES2:
            libPath = "dynamic_libs/ncurses2/ncurses2.so";
            break;
        case E_NCURSES3:
            libPath = "dynamic_libs/ncurses3/ncurses3.so";
            break;
        /*case E_SDL2:
            libPath = "dynamic_libs/sdl/sdl.so";
            break;
        case E_SFML:
            libPath = "dynamic_libs/sdl/sdl.so";
            break;
        case E_ALEGRO:
            libPath = "dynamic_libs/sdl/sdl.so";
            break;*/
        default:
            libPath = "dynamic_libs/ncurses/ncurses.so";
            break;
    }

	const char *dynamic_lib = libPath.c_str();
	_dl_handle = dlopen(dynamic_lib, RTLD_NOW | RTLD_LOCAL);
	if (!_dl_handle) {
		dlerror_wrapper();
	}

	IGraphics	*(*createGraphics)(int, int);
	createGraphics = (IGraphics *(*)(int, int)) dlsym(_dl_handle, "createGraphics");
	if (!createGraphics) {
		dlerror_wrapper();
	}

	IGraphics *graphics = createGraphics(this->_width, this->_height);
    return graphics;
}

void        GameEngine::closeDynamicLib() {
    dlclose(_dl_handle);
}


std::pair <int, int>   generateFruitLocations(int x_size, int y_size) {
    srand(time(0));
    int x = (rand() % (x_size - 2)) + 1;
    int y = (rand() % (y_size - 2)) + 1;
    return std::make_pair(x, y);
}

bool        checkSnakeBody(std::pair <int, int> location_to_check, Player *p1) {
    std::vector<std::pair <int, int> > player_locs = p1->getLocations();
    for (size_t i = 1; i < player_locs.size(); i++) {
        if (player_locs[i].first == location_to_check.first && player_locs[i].second == location_to_check.second) {
            return false;
        }
    }
    return true;
}

void        GameEngine::runGame(Player *p1, int x_size, int y_size) {

    eInput input = eInput(0);
    int sleepTime = 300000;
    std::pair <int, int> fruitLocation = generateFruitLocations(x_size, y_size);
    bool eat_fruit = false;

    if ((_graphics = this->initGraphics(E_NCURSES1)) == NULL) {
        return;
    }


    while (true) {
        _graphics->clear_view();

        eInput temp_input = eInput(_graphics->getInput());
        switch (temp_input) {
            case NO_CHANGE:
                p1->movePlayer(input, eat_fruit);
                break;
            case GRAPH_1:
                _graphics->delete_self();
                closeDynamicLib();
                _graphics = this->initGraphics(E_NCURSES1);
                break;
            case GRAPH_2:
                _graphics->delete_self();
                closeDynamicLib();
                _graphics = this->initGraphics(E_NCURSES2);
                break;
            case GRAPH_3:
                _graphics->delete_self();
                closeDynamicLib();
                _graphics = this->initGraphics(E_NCURSES3);
                break;
            case EXIT:
                _graphics->delete_self();
                closeDynamicLib();
                return;
            default:
                input = temp_input;
                p1->movePlayer(input, eat_fruit);
                break;
        }
        // draw frame
        _graphics->draw_frame();

        std::vector<std::pair <int, int> > player_locs = p1->getLocations();
        std::pair<int, int> head = player_locs.front();
        eat_fruit = false;

        //draw snake
        for (size_t i = 0; i < player_locs.size(); i++) {

            //if snake head @ fruit location
            if (i == 0 && player_locs[i].first == fruitLocation.first &&
                player_locs[i].second == fruitLocation.second) {
                    while ( !(checkSnakeBody(fruitLocation = generateFruitLocations(x_size, y_size), p1))) {}
                    eat_fruit = true;
                    p1->addScore(1);
                    sleepTime = sleepTime / 100 * 90;
            }
            //if snake crashes into border
            else if (player_locs[i].first <= 0 || player_locs[i].second <= 0
                || player_locs[i].first >= x_size - 1 || player_locs[i].second >= y_size - 1) {
                    _graphics->delete_self();
                    closeDynamicLib();
                    return;
            }
            // if snake crashes into own body
            else if (i != 0 && (checkSnakeBody(head, p1) == false) ) {
                _graphics->delete_self();
                closeDynamicLib();
                return;
            }


            _graphics->draw_snake(player_locs[i].first, player_locs[i].second);
        }

        _graphics->draw_fruit(fruitLocation.first, fruitLocation.second);
        _graphics->draw_score(p1->getScore());
        _graphics->refresh_view();
        usleep(sleepTime);
    }
}
