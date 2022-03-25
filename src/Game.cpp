#include "Game.hpp"

Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initStateData();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::initVariables() {
	this->window = NULL;
	this->dt = 0.0f;
}

void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(this->SCREEN_WIDTH, this->SCREEN_HEIGHT), this->SCREEN_TITLE, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(this->FRAMERATE_LIMIT);
	this->window->setVerticalSyncEnabled(this->IS_VERTICAL_SYNC_ENABLED);
}

void Game::initStateData()
{
	this->stateData.window = this->window;
	this->stateData.states = &this->states;
}

void Game::initStates()
{
	this->states.push(new MainMenuState(&this->stateData));
}

void Game::updateDt() {
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed) { this->window->close(); }
	}
}

void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		if (this->window->hasFocus())
		{
			this->states.top()->update(this->dt);

			if (this->states.top()->getQuit())
			{
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
			}
		}
	}
	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render() {
	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::endApplication() {
	std::cout << "Thanks for playing !" << "\n";
}