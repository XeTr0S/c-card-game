CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude
SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:src/%.c=build/%.o)

ifeq ($(OS),Windows_NT)
    EXT     = .exe
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
else
    LDFLAGS = -lraylib -lm
endif
TARGET  = build/cardclash$(EXT)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: run clean
