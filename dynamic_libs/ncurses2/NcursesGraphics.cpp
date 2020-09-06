#include "NcursesGraphics.hpp"

//  InvalidSize exception
NcursesGraphics::InvalidSize::InvalidSize() {}

NcursesGraphics::InvalidSize::~InvalidSize() throw () {}

const char* NcursesGraphics::InvalidSize::what() const throw() {
    return ("Command line arguments size too big or small - exiting...");
}

//  NcursesGraphics


NcursesGraphics::NcursesGraphics() : _screen_width(100), _screen_height(100) {}

NcursesGraphics::NcursesGraphics(int x, int y) : _screen_width(x), _screen_height(y) {
    initscr();      //start ncurses
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    if (max_y < y || max_x < x || y < 10 || x < 10) {
        endwin();
        throw InvalidSize();
    }
    if (has_colors() == false) {
        endwin();
        throw InvalidSize();
    }
    start_color();      //start color mode
    init_pair(1, COLOR_CYAN, COLOR_BLUE);    //create color pair
    attron(COLOR_PAIR(1));
    wbkgd(this->_window, COLOR_PAIR(1));
    mvprintw(0, 0, "Press 1 - 3 to switch libs, arrows to move and q to quit");
    noecho();       //disable echo of char's
    nodelay(stdscr, true);  //makes getch nonblocking
    notimeout(stdscr, true);
    keypad(stdscr, true); //enable keyboard input
    curs_set(0); //Don't display a cursor
    this->_window = newwin(_screen_height, _screen_width, 2, 0);  //create window
    keypad(this->_window, true);
    cbreak();       //disable bufferign of typed chars
}

NcursesGraphics::~NcursesGraphics() {
    endwin();
}

void        NcursesGraphics::draw_frame() {
    wborder(this->_window, '|', '|', '-', '-', '+', '+', '+', '+');
}

void        NcursesGraphics::draw_snake(int x, int y) {
    mvwaddch(this->_window, y, x, '#');
}

void        NcursesGraphics::draw_fruit(int x, int y) {
    mvwaddch(this->_window, y, x, '@');
}

void        NcursesGraphics::draw_score(int score) {
    mvprintw(1, 0, "Score: ");
    mvprintw(1, 7, (std::to_string(score)).c_str());
}

void        NcursesGraphics::clear_view() {
    wclear(this->_window);
}

void        NcursesGraphics::refresh_view() {
    wrefresh(this->_window);
}

void        NcursesGraphics::delete_self() {
    attroff(COLOR_PAIR(1));
    delete this;
}

int         NcursesGraphics::getInput() {
    int ch = getch();
    switch (ch) {
        //no change
        case ERR:
            return 7;
        case KEY_UP:
            return 0;
        case KEY_DOWN:
            return 1;
        case KEY_LEFT:
            return 2;
        case KEY_RIGHT:
            return 3;
        case '1':
            return 4;
        case '2':
            return 5;
        case '3':
            return 6;
        case 'q':
            return 8;

        //no change
        default:
            return 7;
    }
}

IGraphics     *createGraphics(int x, int y) {
    NcursesGraphics *ng = NULL;
    try {
        ng = new NcursesGraphics(x, y);
    } catch (NcursesGraphics::InvalidSize ex) {
        std::cerr << ex.what();
        ng = NULL;
    }
    return ng;
}
