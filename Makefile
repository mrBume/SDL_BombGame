TARGET = bombman

CC = g++

OUTPUT = bin

SOURCES = src/main.cpp src/SDLApp.cpp src/AnimatedSprite.cpp src/Character.cpp

INCLUDE = -I include

LIBS = -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

CXXFLAGS = -g3

all: $(OUTPUT)
	$(CC) $(INCLUDE) -o $(OUTPUT)/$(TARGET) $(CXXFLAGS) $(SOURCES) $(LIBS)

$(OUTPUT):
	mkdir $(OUTPUT)

clean:
	rmdir /S /Q $(OUTPUT)