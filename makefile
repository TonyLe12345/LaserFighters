# Compiler
CXX = g++ 

# Compiler flags
CFLAGS = -Wall -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.1/include

# Linker flags
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Executable name
EXEC = laser_fighters_2000

# Source files
SRCS = AssetManager.cpp Game.cpp main.cpp MainMenuState.cpp StateMachine.cpp laserFighters2000.cpp player.cpp laser.cpp GameOverState.cpp Ship.cpp CharacterSelect.cpp CharacterSelectP2.cpp flea.cpp goliath.cpp arachne.cpp healthbar.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

# Clean
clean:
	rm -f $(OBJS) $(EXEC)
