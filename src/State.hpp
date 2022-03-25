#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <stack>
#include <unordered_map>

#include "SFML/Graphics.hpp"

class State;

class StateData
{
public:
	StateData() { states = NULL; window = NULL; };

	// Variables
	sf::RenderWindow* window;
	std::stack<State*>* states;
};

class State
{
private:

protected:
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool quit;
	bool paused;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Ressources
	std::unordered_map<std::string, sf::Texture> textures;
public:
	State(StateData* state_data);
	virtual ~State();

	// Accessors
	const bool& getQuit() const;

	// Functions
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePositions(sf::View* view = NULL);
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif // STATE_HPP_INCLUDED