#include "FigureManager.h"

FigureManager::FigureManager() {}
FigureManager::~FigureManager() {}



void FigureManager::draw(sf::RenderTarget& object, sf::RenderStates states)const
{
	for (auto& figure : figure_vector)
		object.draw(*figure, states);
}

void FigureManager::setTexture()
{
		for (auto& figure : figure_vector)
		{
			auto down_cast_pawn = std::dynamic_pointer_cast<Pawn>(figure);
			auto down_cast_queen = std::dynamic_pointer_cast<Queen>(figure);

			if (down_cast_pawn != nullptr)
				{
					if(figure->getColor() == BLACK)
						figure->setTexture(pawn_texture_black);
					else
						figure->setTexture(pawn_texture_white);

				}
			else if (down_cast_queen != nullptr)
				{
					if (figure->getColor() == BLACK)
						figure->setTexture(queen_texture_black);
					else
						figure->setTexture(queen_texture_white);
					}

			else continue;
		}
}

void FigureManager::loadTexture()
{
	if (!pawn_texture_black.loadFromFile("Img/czerwonePion.png"))throw std::runtime_error("Black pawn texture failed to load!");
	if (!queen_texture_black.loadFromFile("Img/czerwonePion.png"))throw std::runtime_error("Black queen texture failed to load!");
	if (!pawn_texture_white.loadFromFile("Img/whitePawn.png"))throw std::runtime_error("White pawn texture failed to load!");
	if (!queen_texture_white.loadFromFile("Img/whitePawn.png"))throw std::runtime_error("White queen texture failed to load!");

}




/*
	(row +column)%2 forumla is responsible for the fact that we play on black fields only
	+10 is an offset 

	BLACK
	  ------------------ 
	 |	0 b 0 b 0 b 0 b  |
	 |	b 0 b 0 b 0 b 0  |
	 |	0 b 0 b 0 b 0 b  |
	 |	0 0 0 0 0 0 0 0  |
	 |	0 0 0 0 0 0 0 0  |
	 |	w 0 w 0 w 0 w 0  |
	 |	0 w 0 w 0 w 0 w  |
	 |	w 0 w 0 w 0 w 0  |
	  -------------------	
	WHITE
*/

void FigureManager::setFiguresOnStartingPositions() 
{
	for(int column = 0; column < 8;	++column)
		for (int row = 0; row < 8; ++row)
		{
			if ((row + column) % 2)
			{
				if (column < 3)
					figure_vector.push_back(std::make_unique<Pawn>(column * 100 + 10, row * 100 + 10, BLACK));

				else if (column > 4)
					figure_vector.push_back(std::make_unique<Pawn>(column * 100 + 10, row * 100 + 10, WHITE));
			}
		}
}

void FigureManager::getFiguresPositions()
{
	//std::pair<std::shared_ptr<IFigure>, sf::Vector2f> _pair;
	std::pair<int, int> _pair_i;
	std::pair<std::shared_ptr<IFigure>, std::pair<int, int> > _pair;

	for (auto& figure : figure_vector)
	{	
	//	_pair.first = figure;
	//_pair.second = figure->getPosition();
	//position_vector.push_back(_pair);
	
		_pair_i = convertToIndex(figure->getPosition());
		_pair.first = figure;
		_pair.second = _pair_i;


		position_vector2.push_back(_pair);
	}
}

std::pair<int, int>	FigureManager::convertToIndex(sf::Vector2f sf_vec)
{
	int tmp_x = (int)sf_vec.x%100;
	int tmp_y = (int)sf_vec.y%100;
	sf_vec.x = (sf_vec.x -tmp_x) / 100;
	sf_vec.y = (sf_vec.y - tmp_y) / 100;

	return std::make_pair<int, int>((int)sf_vec.x, (int)sf_vec.y);

}


bool FigureManager::checkIfFigure(sf::Vector2f sf_vec, FIGURE_COLORS tour)
{
	std::pair<int, int> index = convertToIndex(sf_vec);
	bool tmp = false;
	for (auto& figure : position_vector2)
	{
		if (figure.second == index)
		{
			if (figure.first->getColor() == tour)
				tmp = true;
		}
	}
		return tmp;
}

bool FigureManager::checkIfAnotherFigure(sf::Vector2f sf_vec)
{
	std::pair<int, int> index = convertToIndex(sf_vec);
	bool tmp = false;
	for (auto& figure : position_vector2)
		if (figure.second == index)
			tmp =  true;

	return tmp;
}