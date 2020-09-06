EXEC=nibbler
CC=g++
CFLAGS=-I $(IDIR)
FLAGS=-Wall -Werror -Wextra

ODIR=obj
SDIR=src

_DEPS=Player.hpp GameEngine.hpp
DEPS=$(patsubst %,$(SDIR)/%,$(_DEPS))

_OBJ=main.o Player.o GameEngine.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) all
	$(CC) -c -o $@ $< $(CFLAGS) $(FLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(FLAGS) -ldl

.PHONY: install clean fclean re all

all:
	mkdir -p obj
	cd dynamic_libs/ncurses1 && make
	cd dynamic_libs/ncurses2 && make
	cd dynamic_libs/ncurses3 && make

#install:
#	@echo Checking and installing dependencies...
#	brew list sdl2 &>/dev/null || brew install sdl2
#	brew list sfml &>/dev/null || brew install sfml
#	brew list pkg-config &>/dev/null || brew install pkg-config

clean:
	rm -f $(ODIR)/*.o

fclean:
	make clean
	rm -f $(EXEC)
	cd dynamic_libs/ncurses1 && make clean
	cd dynamic_libs/ncurses2 && make clean
	cd dynamic_libs/ncurses3 && make clean

re:
	make fclean
	make
