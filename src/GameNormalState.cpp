#include "GameNormalState.hpp"

void GameNormalState::initImages() {
	if (!this->clownHeadTexture.loadFromFile("../res/Images/clown_head.png"))
	{
		throw("Error : GameNormalState : Could not clown head image");
	}
	if (!this->backgroundTexture.loadFromFile("../res/Images/background_image.jpg"))
	{
		throw("Error : GameNormalState : Could not load background image");
	}
}

void GameNormalState::initSounds() {
	if (!this->backgroundMusic.openFromFile("../res/Sounds/background_music.ogg"))
	{
		throw("Error : GameNormalState : Could not open background music");
	}
}

void GameNormalState::initFonts() {
	if (!this->comicSansMS.loadFromFile("../res/Fonts/comic.ttf"))
	{
		throw("Error : GameNormalState : Could not load font");
	}
}

void GameNormalState::initVariables() {
	// Configuration du background
	this->backgroundTexture.setSmooth(true);
	this->background.setTexture(&this->backgroundTexture);
	this->background.setFillColor(sf::Color(60, 60, 60, 255));
	this->background.setSize(sf::Vector2f(1080, 720));
	this->background.setPosition(sf::Vector2f(0, 0));

	// Configuration de la musique de fond
	this->backgroundMusic.setVolume(this->generalVolume);

	// Configuration des raquettes
	this->leftPaddle.setSize(sf::Vector2f(this->PADDLE_WIDTH, this->PADDLE_HEIGHT));
	this->leftPaddle.setOrigin(sf::Vector2f(this->PADDLE_WIDTH / 2, this->PADDLE_HEIGHT / 2));
	this->leftPaddle.setPosition(sf::Vector2f(this->PADDLE_WIDTH / 2, this->stateData->window->getSize().y / 2.0f));
	this->leftPaddle.setFillColor(sf::Color::Green);
	this->leftPaddle.setOutlineThickness(5.0f);
	this->leftPaddle.setOutlineColor(sf::Color::Black);

	this->rightPaddle.setSize(sf::Vector2f(this->PADDLE_WIDTH, this->PADDLE_HEIGHT));
	this->rightPaddle.setOrigin(sf::Vector2f(this->PADDLE_WIDTH / 2, this->PADDLE_HEIGHT / 2));
	this->rightPaddle.setPosition(sf::Vector2f(this->stateData->window->getSize().x - this->PADDLE_WIDTH / 2, this->stateData->window->getSize().y / 2.0f));
	this->rightPaddle.setFillColor(sf::Color::Green);
	this->rightPaddle.setOutlineThickness(5.0f);
	this->rightPaddle.setOutlineColor(sf::Color::Black);

	// Configuration de la balle
	this->theBall.setTexture(this->clownHeadTexture);
	this->theBall.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, this->stateData->window->getSize().y / 2.0f));
	this->theBall.setOrigin(sf::Vector2f(this->theBall.getTexture()->getSize().x / 2.0f, this->theBall.getTexture()->getSize().y / 2.0f));

	// Configuration de la barre centrale
	this->centralBar.setSize(sf::Vector2f(this->CENTRAL_BAR_WIDTH, this->CENTRAL_BAR_HEIGHT));
	this->centralBar.setOrigin(sf::Vector2f(this->centralBar.getSize().x / 2.0f, this->centralBar.getSize().y / 2.0f));
	this->centralBar.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, this->stateData->window->getSize().y / 2.0f));
	this->centralBar.setFillColor(sf::Color::Black);

	// Configuration des textes de score
	this->leftPlayerScoreText.setFont(this->comicSansMS);
	this->leftPlayerScoreText.setString(std::to_string(this->leftPlayerScore));
	this->leftPlayerScoreText.setCharacterSize(this->SCORE_TEXT_SIZE);
	this->leftPlayerScoreText.setFillColor(sf::Color::White);
	this->leftPlayerScoreText.setPosition(sf::Vector2f(0.25f * this->stateData->window->getSize().x, 0.85f * this->stateData->window->getSize().y));
	
	this->rightPlayerScoreText.setFont(this->comicSansMS);
	this->rightPlayerScoreText.setString(std::to_string(this->rightPlayerScore));
	this->rightPlayerScoreText.setCharacterSize(this->SCORE_TEXT_SIZE);
	this->rightPlayerScoreText.setFillColor(sf::Color::White);
	this->rightPlayerScoreText.setPosition(sf::Vector2f(0.75f * this->stateData->window->getSize().x, 0.85f * this->stateData->window->getSize().y));
}

void GameNormalState::resetGame() {
	// Configuration des raquettes
	this->paddleVy = 250.0f;
	this->leftPaddle.setPosition(sf::Vector2f(this->PADDLE_WIDTH / 2, this->stateData->window->getSize().y / 2.0f));
	this->rightPaddle.setPosition(sf::Vector2f(this->stateData->window->getSize().x - this->PADDLE_WIDTH / 2, this->stateData->window->getSize().y / 2.0f));

	this->isBallStuck = true;
	this->ballVx = 250.0f;
	this->ballVy = 250.0f;
	this->theBall.setRotation(0.0f);
	this->ballRotationSpeed = 200.0f;
	this->theBall.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, this->stateData->window->getSize().y / 2.0f));

	this->leftPlayerScoreText.setString(std::to_string(this->leftPlayerScore));
	this->rightPlayerScoreText.setString(std::to_string(this->rightPlayerScore));

	this->backgroundMusic.stop();
}

void GameNormalState::increaseBallSpeed() {
	if (std::abs(this ->ballVx) < 750) {
		if (this->ballVx > 0) {
			this->ballVx = this->ballVx + this->INCREASE_BALL_SPEED_EVERY_HIT;
		}
		else {
			this->ballVx = this->ballVx - this->INCREASE_BALL_SPEED_EVERY_HIT;
		}

		if (this->ballVy > 0) {
			this->ballVy = this->ballVy + this->INCREASE_BALL_SPEED_EVERY_HIT;
		}
		else {
			this->ballVy = this->ballVy - this->INCREASE_BALL_SPEED_EVERY_HIT;
		}
	}

	this->ballRotationSpeed += this->INCREASE_BALL_ROTATION_SPEED_EVERY_HIT;
}

void GameNormalState::increasePaddleSpeed() {
	this->paddleVy = this->paddleVy + this->INCREASE_PADDLE_SPEED_EVERY_HIT;
}

GameNormalState::GameNormalState(StateData* state_data) : State(state_data)
{
	this->initImages();
	this->initSounds();
	this->initFonts();
	this->initVariables();
}

GameNormalState::~GameNormalState()
{

}

void GameNormalState::updateInput(const float& dt)
{
	// Changer les variables relatives aux touches
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true) {
		this->endState();
	}

	if (isBallStuck == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true) {
		this->isBallStuck = false;
		this->backgroundMusic.play();
		this->backgroundMusic.setLoop(true);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && this->leftPaddle.getPosition().y - this->PADDLE_HEIGHT / 2.0f - this->leftPaddle.getOutlineThickness() > 0) {
		this->leftPaddle.setPosition(this->leftPaddle.getPosition().x, this->leftPaddle.getPosition().y - (this->paddleVy * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->leftPaddle.getPosition().y + this->PADDLE_HEIGHT / 2.0f + this->leftPaddle.getOutlineThickness() < this->stateData->window->getSize().y) { 
		this->leftPaddle.setPosition(this->leftPaddle.getPosition().x, this->leftPaddle.getPosition().y + (this->paddleVy * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->rightPaddle.getPosition().y - this->PADDLE_HEIGHT / 2.0f - this->rightPaddle.getOutlineThickness() > 0) { 
		this->rightPaddle.setPosition(this->rightPaddle.getPosition().x, this->rightPaddle.getPosition().y - (this->paddleVy * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->rightPaddle.getPosition().y + this->PADDLE_HEIGHT / 2.0f + this->rightPaddle.getOutlineThickness() < this->stateData->window->getSize().y) { 
		this->rightPaddle.setPosition(this->rightPaddle.getPosition().x, this->rightPaddle.getPosition().y + (this->paddleVy * dt));
	}
}

void GameNormalState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	if (isBallStuck == false) {
		this->theBall.setPosition(sf::Vector2f(this->theBall.getPosition().x + (this->ballVx * dt), this->theBall.getPosition().y + (this->ballVy * dt)));
		this->theBall.setRotation(this->theBall.getRotation() + (this->ballRotationSpeed * dt));

		// Gestion des collisions avec les murs horizontaux
		if (this->theBall.getPosition().y + this->BALL_RADIUS >= this->stateData->window->getSize().y - this->ballCollisionSecurity ||
			this->theBall.getPosition().y - this->BALL_RADIUS <= 0 + this->ballCollisionSecurity) {
			this->ballVy = -this->ballVy;
		}

		// Collision avec la raquette gauche
		if (this->theBall.getPosition().x - this->BALL_RADIUS <= this->leftPaddle.getPosition().x + this->PADDLE_WIDTH / 2.0f + this->ballCollisionSecurity &&
			this->theBall.getPosition().y + this->BALL_RADIUS >= this->leftPaddle.getPosition().y - this->PADDLE_HEIGHT / 2.0f - this->ballCollisionSecurity &&
			this->theBall.getPosition().y - this->BALL_RADIUS <= this->leftPaddle.getPosition().y + this->PADDLE_HEIGHT / 2.0f + this->ballCollisionSecurity) {
			this->ballVx = -this->ballVx;
			increaseBallSpeed();
			increasePaddleSpeed();
		}

		// Collisions avec la raquette droite
		if (this->theBall.getPosition().x + this->BALL_RADIUS >= this->rightPaddle.getPosition().x - this->PADDLE_WIDTH / 2.0f - this->ballCollisionSecurity &&
			this->theBall.getPosition().y + this->BALL_RADIUS >= this->rightPaddle.getPosition().y - this->PADDLE_HEIGHT / 2.0f + this->ballCollisionSecurity &&
			this->theBall.getPosition().y - this->BALL_RADIUS <= this->rightPaddle.getPosition().y + this->PADDLE_HEIGHT / 2.0f + this->ballCollisionSecurity) {
			this->ballVx = -this->ballVx;
			increaseBallSpeed();
			increasePaddleSpeed();
		}

		// Gestion des collisions avec les murs verticaux
		if (this->theBall.getPosition().x + this->BALL_RADIUS >= this->stateData->window->getSize().x) {
			std::cout << "GAME OVER !" << std::endl;
			this->leftPlayerScore++;
			resetGame();
		}
		if (this->theBall.getPosition().x - this->BALL_RADIUS <= 0) {
			std::cout << "GAME OVER !" << std::endl;
			this->rightPlayerScore++;
			resetGame();
		}
	}
}

void GameNormalState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	target->draw(this->centralBar);
	target->draw(this->leftPlayerScoreText);
	target->draw(this->rightPlayerScoreText);

	target->draw(this->leftPaddle);
	target->draw(this->rightPaddle);
	target->draw(this->theBall);
}