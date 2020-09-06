SRC=NcursesGraphics.cpp

DEP=NcursesGraphics.hpp

LIB=ncurses1.so

NCURSES=-lncurses

$(LIB): $(SRC) $(DEP)
	g++ -shared -fPIC -o $(LIB) $(SRC) $(NCURSES)


clean:
	rm -f $(LIB)

re:
	make clean
	make
