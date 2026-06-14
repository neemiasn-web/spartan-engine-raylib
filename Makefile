CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lraylib -lflecs -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/spartan_engine

SOURCES = src/main.c src/world.c src/player.c src/ecs_module.c src/audio_module.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: setup $(TARGET)

setup:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(TARGET)

.PHONY: all setup clean run
