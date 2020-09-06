#ifndef IGRAPHICS_HPP
#define IGRAPHICS_HPP

class IGraphics {
    public:
        virtual void        draw_frame() = 0;
        virtual void        draw_snake(int x, int y) = 0;
        virtual void        draw_fruit(int x, int y) = 0;
        virtual void        draw_score(int score) = 0;
        virtual void        clear_view() = 0;
        virtual void        refresh_view() = 0;
        virtual void        delete_self() = 0;
        virtual int         getInput() = 0;
};

#endif
