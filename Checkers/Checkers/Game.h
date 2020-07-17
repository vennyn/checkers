#pragma once
#include "config.h"
#include "FigureManager.h"

static class Game
{
public:
	Game();
	~Game();

	void mainLoop();
	void gameLoop();
	void changeTour();
	void setFigureManagerAndMouse();
	bool rightSquareTest(sf::Vector2f sf_vec);
	void move(sf::Vector2f source, sf::Vector2f destination);

private:
	sf::Texture board;
	sf::Sprite _board;
	sf::RenderWindow sf_main_window;
	sf::Event _event;
	FigureManager _figure_menager;
	FIGURE_COLORS tour;
};