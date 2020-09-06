SRC=NcursesGraphics.cpp

DEP=NcursesGraphics.hpp

LIB=ncurses2.so

NCURSES=-lncurses

$(LIB): $(SRC) $(DEP)
	g++ -shared -fPIC -o $(LIB) $(SRC) $(NCURSES)


clean:
	rm -f $(LIB)

re:
	make clean
	make
