#ifndef MAIN_MENU_STATE_HPP_INCLUDED
#define MAIN_MENU_STATE_HPP_INCLUDED

#include <iostream>

#include "SFML/Graphics.hpp"

#include "State.hpp"
#include "GameNormalState.hpp"

class MainMenuState : public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::Font comicSansMS;

	const int BUTTON_TEXT_SIZE = 24;
	sf::RectangleShape playButton;
	sf::Text playButtonText;
	sf::RectangleShape settingsButton;
	sf::Text settingsButtonText;
	sf::RectangleShape exitButton;
	sf::Text exitButtonText;

	const float BUTTON_HEIGHT = 50.0f;
	const float BUTTON_WIDTH = 300.0f;

	// Functions
	void initImages();
	void initSounds();
	void initFonts();
	void initVariables();

	bool checkCollisionClickWithButton(sf::RectangleShape button);
public:
	MainMenuState(StateData* state_data);
	virtual ~MainMenuState();

	// Functions
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

#endif // MAIN_MENU_STATE_HPP_INCLUDED
