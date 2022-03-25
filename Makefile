CXX = g++
CXXFLAGS = -W -Wall

LFLAGS_RELEASE = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
LFLAGS_DEBUG = -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d

SFML_LOCATION = lib\SFML-2.5.1
EXEC = BozoPong

# rm étant une commande unix, il faut utiliser del sous Windows
RM = del /Q /F

all: release debug

release: main.o Game.o State.o MainMenuState.o GameNormalState.o
# -O0 est le mode d'optimisation par défaut, -O3 consomme plus de mémoire mais gagne en temps d'exécution
	$(CXX) -O0 obj\main.o obj\Game.o obj\State.o obj\MainMenuState.o obj\GameNormalState.o -o bin\Release\$(EXEC) -L $(SFML_LOCATION)\lib $(LFLAGS_RELEASE)

debug: main.o Game.o State.o MainMenuState.o GameNormalState.o
	$(CXX) -g3 obj\main.o obj\Game.o obj\State.o obj\MainMenuState.o obj\GameNormalState.o -o bin\Debug\$(EXEC) -L $(SFML_LOCATION)\lib $(LFLAGS_DEBUG)


main.o: src\main.cpp
	$(CXX) $(CXXFLAGS) -o obj\main.o -c src\main.cpp -I $(SFML_LOCATION)\include

Game.o: src\Game.cpp
	$(CXX) $(CXXFLAGS) -o obj\Game.o -c src\Game.cpp -I $(SFML_LOCATION)\include

State.o: src\State.cpp
	$(CXX) $(CXXFLAGS) -o obj\State.o -c src\State.cpp -I $(SFML_LOCATION)\include

MainMenuState.o: src\MainMenuState.cpp
	$(CXX) $(CXXFLAGS) -o obj\MainMenuState.o -c src\MainMenuState.cpp -I $(SFML_LOCATION)\include

GameNormalState.o: src\GameNormalState.cpp
	$(CXX) $(CXXFLAGS) -o obj\GameNormalState.o -c src\GameNormalState.cpp -I $(SFML_LOCATION)\include

clean:
	$(RM) obj\*.o
	$(RM) bin\Debug\$(EXEC).exe
	$(RM) bin\Release\$(EXEC).exe