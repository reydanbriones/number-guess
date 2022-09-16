
CC = g++
CFLAGS = -g -Wall

SRC_DIR = src
OBJ_DIR = build

_SRCS = main.cpp game.cpp
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
_OBJS = $(_SRCS:.cpp=.o)
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))

MAIN = game

default: $(MAIN)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean:
	rm -rf build
	rm $(MAIN)
