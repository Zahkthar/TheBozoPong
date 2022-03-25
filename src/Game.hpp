#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stack>

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "MainMenuState.hpp"

class Game {
    
private:
    // Variables
    StateData stateData;
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 720;
    const std::string SCREEN_TITLE = "Bozo-Pong";

    const int FRAMERATE_LIMIT = 60;
    const bool IS_VERTICAL_SYNC_ENABLED = true;

    // Initialization
    void initVariables();
    void initWindow();
    void initStateData();
    void initStates();
public:
    // Constructors/Destructors
    Game();
    ~Game();

    // Functions
    void run();

    void update();
    void updateDt();
    void updateSFMLEvents();

    void render();

    void endApplication();
};


#endif //GAME_HPP_INCLUDED