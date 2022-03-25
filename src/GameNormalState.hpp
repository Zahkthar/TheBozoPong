#ifndef GAME_NORMAL_STATE_HPP_INCLUDED
#define GAME_NORMAL_STATE_HPP_INCLUDED

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "State.hpp"
#include "MainMenuState.hpp"

class GameNormalState : public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	float backgroundRotationSpeed = 5.0f;

	sf::Music backgroundMusic;

	float generalVolume = 1.0f;

	sf::Font comicSansMS; // Pour afficher les scores

	// Les raquettes
	sf::RectangleShape leftPaddle;
	sf::RectangleShape rightPaddle;

	const float PADDLE_HEIGHT = 100.0f;
	const float PADDLE_WIDTH = 10.0f;

	float paddleVy = 250.0f;
	const float INCREASE_PADDLE_SPEED_EVERY_HIT = 50.0f;

	// La balle
	sf::Texture clownHeadTexture;
	sf::Sprite theBall;
	float ballRotationSpeed = 200.0f;
	const float INCREASE_BALL_ROTATION_SPEED_EVERY_HIT = 200.0f;

	float ballCollisionSecurity = 2.0f;

	const float BALL_RADIUS = 13.0f;
	float ballVx = 250.0f;
	float ballVy = 250.0f;
	const float INCREASE_BALL_SPEED_EVERY_HIT = 50.0f;

	bool isBallStuck = true;

	// Les scores
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;

	sf::Text leftPlayerScoreText;
	sf::Text rightPlayerScoreText;

	const int SCORE_TEXT_SIZE = 24;

	// La barre centrale
	sf::RectangleShape centralBar;
	const float CENTRAL_BAR_HEIGHT = this->stateData->window->getSize().y * 1.0f;
	const float CENTRAL_BAR_WIDTH = 10.0f;

	// Functions
	void initImages();
	void initSounds();
	void initFonts();
	void initVariables();

	void resetGame();
	void increaseBallSpeed();
	void increasePaddleSpeed();
public:
	GameNormalState(StateData* state_data);
	virtual ~GameNormalState();

	// Functions
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

#endif // GAME_NORMAL_STATE_HPP_INCLUDED
