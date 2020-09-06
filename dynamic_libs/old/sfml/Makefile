SRC=SfmlGraphics.cpp

DEP=SfmlGraphics.hpp

LIB=sfml.so

SFML=-I$(HOME)/.brew/Cellar/sfml/2.4.2_1/include -L$(HOME)/.brew/lib -lsfml-graphics -lsfml-window -lsfml-audio

$(LIB): $(SRC) $(DEP)
	clang++ -shared -fPIC -o $(LIB) $(SRC) $(SFML)


clean:
	rm -f $(LIB)

re:
	make clean
	make