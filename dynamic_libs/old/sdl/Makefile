SRC=SdlGraphics.cpp

DEP=SdlGraphics.hpp

LIB=sdl.so

SDL2=$(shell pkg-config --cflags --libs sdl2)

$(LIB): $(SRC) $(DEP)
	g++ -shared -fPIC -o $(LIB) $(SRC) $(SDL2)


clean:
	rm -f $(LIB)

re:
	make clean
	make