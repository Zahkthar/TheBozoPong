#include "MainMenuState.hpp"

void MainMenuState::initImages() {
	if (!this->backgroundTexture.loadFromFile("../res/Images/background_image.jpg"))
	{
		throw("Error : MainMenuState : Could not load background image");
	}
}

void MainMenuState::initSounds() {

}

void MainMenuState::initFonts() {
	if (!this->comicSansMS.loadFromFile("../res/Fonts/comic.ttf"))
	{
		throw("Error : MainMenuState : Could not load font");
	}
}

void MainMenuState::initVariables() {
	// Configuration du background
	this->backgroundTexture.setSmooth(true);
	this->background.setTexture(&this->backgroundTexture);
	this->background.setFillColor(sf::Color(60, 60, 60, 255));
	this->background.setSize(sf::Vector2f(this->stateData->window->getSize().x * 1.0f, this->stateData->window->getSize().y * 1.0f)); // * 1.0f pour r�gler un warning de type
	this->background.setPosition(sf::Vector2f(0.0f, 0.0f));

	// Configuration des bouttons	
	this->playButton.setSize(sf::Vector2f(this->BUTTON_WIDTH, this->BUTTON_HEIGHT));
	this->playButton.setOrigin(sf::Vector2f(this->BUTTON_WIDTH / 2.0f, this->BUTTON_HEIGHT / 2.0f));
	this->playButton.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, 0.50f * this->stateData->window->getSize().y));
	this->playButton.setFillColor(sf::Color::Green);
	this->playButton.setOutlineColor(sf::Color::Black);
	this->playButton.setOutlineThickness(5.0f);

	this->playButtonText.setFont(this->comicSansMS);
	this->playButtonText.setCharacterSize(this->BUTTON_TEXT_SIZE);
	this->playButtonText.setPosition(sf::Vector2f(this->playButton.getPosition().x - 0.05f * this->playButton.getSize().x, this->playButton.getPosition().y - 0.25f * this->playButton.getSize().y));
	this->playButtonText.setString("Play");

	this->settingsButton.setSize(sf::Vector2f(this->BUTTON_WIDTH, this->BUTTON_HEIGHT));
	this->settingsButton.setOrigin(sf::Vector2f(this->BUTTON_WIDTH / 2.0f, this->BUTTON_HEIGHT / 2.0f));
	this->settingsButton.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, this->playButton.getPosition().y + 2.0f * this->BUTTON_HEIGHT));
	this->settingsButton.setFillColor(sf::Color::Green);
	this->settingsButton.setOutlineColor(sf::Color::Black);
	this->settingsButton.setOutlineThickness(5.0f);

	this->settingsButtonText.setFont(this->comicSansMS);
	this->settingsButtonText.setCharacterSize(this->BUTTON_TEXT_SIZE);
	this->settingsButtonText.setPosition(sf::Vector2f(this->settingsButton.getPosition().x - 0.15f * this->settingsButton.getSize().x, this->settingsButton.getPosition().y - 0.25f * this->settingsButton.getSize().y));
	this->settingsButtonText.setString("Settings");

	this->exitButton.setSize(sf::Vector2f(this->BUTTON_WIDTH, this->BUTTON_HEIGHT));
	this->exitButton.setOrigin(sf::Vector2f(this->BUTTON_WIDTH / 2.0f, this->BUTTON_HEIGHT / 2.0f));
	this->exitButton.setPosition(sf::Vector2f(this->stateData->window->getSize().x / 2.0f, this->settingsButton.getPosition().y + 2.0f * this->BUTTON_HEIGHT));
	this->exitButton.setFillColor(sf::Color::Green);
	this->exitButton.setOutlineColor(sf::Color::Black);
	this->exitButton.setOutlineThickness(5.0f);

	this->exitButtonText.setFont(this->comicSansMS);
	this->exitButtonText.setCharacterSize(this->BUTTON_TEXT_SIZE);
	this->exitButtonText.setPosition(sf::Vector2f(this->exitButton.getPosition().x - 0.08f * this->exitButton.getSize().x, this->exitButton.getPosition().y - 0.25f * this->exitButton.getSize().y));
	this->exitButtonText.setString("Exit");
}

MainMenuState::MainMenuState(StateData* state_data) : State(state_data)
{
	this->initImages();
	this->initSounds();
	this->initFonts();
	this->initVariables();
}

MainMenuState::~MainMenuState()
{

}

bool MainMenuState::checkCollisionClickWithButton(sf::RectangleShape button) {
	if (this->mousePosWindow.x >= button.getPosition().x - (this->BUTTON_WIDTH / 2.0f) &&
		this->mousePosWindow.x <= button.getPosition().x + (this->BUTTON_WIDTH / 2.0f) &&
		this->mousePosWindow.y >= button.getPosition().y - (this->BUTTON_HEIGHT / 2.0f) &&
		this->mousePosWindow.y <= button.getPosition().y + (this->BUTTON_HEIGHT / 2.0f)) {
		return true;
	}
	return false;
}

void MainMenuState::updateInput(const float& dt)
{
	(void)dt; //We will not use this variable here.

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
		if (checkCollisionClickWithButton(this->playButton) == true) {
			this->states->push(new GameNormalState(this->stateData));
		}
		if (checkCollisionClickWithButton(this->settingsButton) == true) {
			std::cout << "In progress" << std::endl;
		}
		if (checkCollisionClickWithButton(this->exitButton) == true) {
			this->endState();
		}
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);

	target->draw(this->playButton);
	target->draw(this->settingsButton);
	target->draw(this->exitButton);

	target->draw(this->playButtonText);
	target->draw(this->settingsButtonText);
	target->draw(this->exitButtonText);
	// Afficher les boutons
}