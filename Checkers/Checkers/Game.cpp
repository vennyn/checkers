#include "Game.h"
#include <iostream>
Game::Game() :
	sf_main_window(sf::VideoMode(800,800), "Checkers game"),
	tour(WHITE)
{
	mainLoop();
}

Game::~Game()
{}

void Game::setFigureManagerAndMouse()
{
	_figure_menager.setFiguresOnStartingPositions();
	_figure_menager.loadTexture();
	_figure_menager.setTexture();
	_figure_menager.getFiguresPositions();

	//loading board texture and init it 
	if(!board.loadFromFile("Img/warcaby8_8.png"))throw std::runtime_error("Board teture failed to load!");
	_board.setTexture(board);

	//seting mouse in center 
	sf::Vector2i window_center(sf_main_window.getSize() / 2u);
	sf::Mouse::setPosition(window_center, sf_main_window);

}



//TO DO||	Add conditional row+col %2 to move figures only for good squares
void Game::gameLoop()
{
	bool flag_first_move = false;

	while (true) {
		while (sf_main_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i sf_vec_1 = sf::Mouse::getPosition(sf_main_window);
				if (_figure_menager.checkIfFigure((sf::Vector2f)sf_vec_1, tour) && rightSquareTest((sf::Vector2f)sf_vec_1))
				{
					flag_first_move = true;
				}
			}
			if (_event.type == sf::Event::MouseButtonReleased && flag_first_move == true)
				{
					flag_first_move = false;
					//if move is legal execute it and switch turns 
					sf::Vector2i sf_vec_1 = sf::Mouse::getPosition(sf_main_window);
					if (!_figure_menager.checkIfAnotherFigure((sf::Vector2f)sf_vec_1) && rightSquareTest((sf::Vector2f)sf_vec_1))
					{
						changeTour();
						std::cout << "Move";
					}
					//if move is illegal cancel move and dont switch turns; nothing to do
				}
			
			if (_event.type == sf::Event::Closed)
			{
				sf_main_window.close();
			}

			sf_main_window.clear(sf::Color::White);
			sf_main_window.draw(_board);
			sf_main_window.draw(_figure_menager);
			sf_main_window.display();

		}
	}

}

void Game::changeTour()
{
	if (tour == WHITE)tour = BLACK;
	else tour = WHITE;
}

void Game::mainLoop()
{
	//Menu phase 
	//_end of Menu phase


	//Game phase
	setFigureManagerAndMouse();
	gameLoop();
	//_end of Game phase


	//Ending phase
	//end of Ending phase
}

bool Game::rightSquareTest(sf::Vector2f sf_vec)
{
	std::pair<int, int> index = _figure_menager.convertToIndex(sf_vec);
	if ((index.first + index.second) % 2)return true;
	else return false;
}

void Game::move(sf::Vector2f source, sf::Vector2f destination) //i supoose that i also have to carry tour flag
{
	//1 change vectros to indexes
	//2process a way of moving for black(down), white(up), queen(similiar)
	//3change the aproach with row+col cuz queen can go anywhere
}