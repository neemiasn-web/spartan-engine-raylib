CC = gcc
RAYLIB_PATH = ../raylib-6.0_win64_mingw-w64/raylib-6.0_win64_mingw-w64
CFLAGS = -Wall -Wextra -std=gnu99 -I./include -I$(RAYLIB_PATH)/include
LDFLAGS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm -lm -lws2_32 -ldbghelp
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/spartan_engine.exe
SOURCES = src/main.c src/world.c src/player.c src/ecs_module.c src/audio_module.c src/flecs.c
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
