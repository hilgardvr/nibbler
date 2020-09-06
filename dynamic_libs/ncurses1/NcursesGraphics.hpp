#include <string>
#include <iostream>

#include <unistd.h>
#include <ncurses.h>

#include "../IGraphics.hpp"

class NcursesGraphics : public IGraphics {
    public:

        class InvalidSize : public std::exception {
            public:
                InvalidSize();
                ~InvalidSize() throw();
                virtual const char* what() const throw();
        };

        NcursesGraphics(int x, int y);
        ~NcursesGraphics();
        void        draw_frame();
        void        draw_snake(int x, int y);
        void        draw_fruit(int x, int y);
        void        draw_score(int score);
        void        clear_view();
        void        refresh_view();
        void        delete_self();
        int         getInput();
    private:
        NcursesGraphics();
        WINDOW      *_window;
        const int   _screen_width;
        const int   _screen_height;
};

extern "C" {
    IGraphics *createGraphics(int x, int y);
}
