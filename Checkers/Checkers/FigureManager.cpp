#include "FigureManager.h"

FigureManager::FigureManager() {}
FigureManager::~FigureManager() {}



void FigureManager::draw(sf::RenderTarget& object, sf::RenderStates states)const
{
	for (auto& figure : figure_vecotr)
		object.draw(*figure, states);
}

void FigureManager::setTexture()
{
		for (auto& figure : figure_vecotr)
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
	if (!pawn_texture_black.loadFromFile(""))throw std::runtime_error("Black pawn texture failed to load!");
	if (!queen_texture_black.loadFromFile(""))throw std::runtime_error("Black queen texture failed to load!");
	if (!pawn_texture_white.loadFromFile(""))throw std::runtime_error("White pawn texture failed to load!");
	if (!queen_texture_white.loadFromFile(""))throw std::runtime_error("White queen texture failed to load!");

}




/*
	(row +column)%2 forumla is responsible for the fact that we play on black fields only
	+10 is an offset 

	BLACK
		------------------
	 |	b 0 b 0 b 0 b 0  |
	 |	0 b 0 b 0 b 0 b  |
	 |	b 0 b 0 b 0 b 0  |
	 |	0 0 0 0 0 0 0 0  |
	 |	0 0 0 0 0 0 0 0  |
	 |	0 w 0 w 0 w 0 w  |
	 |	w 0 w 0 w 0 w 0  |
	 |	0 w 0 w 0 w 0 w  |
	  -------------------	

	WHITE
*/

void FigureManager::setFiguresOnStartingPositions() 
{
	for(int row=0;row<8;++row)
		for (int column = 0; column < 8; ++column)
		{
			if ((row + column) % 2)
			{
				if (row < 3)
					figure_vecotr.push_back(std::make_unique<Pawn>(row * 100 + 10, column * 100 + 10, BLACK));

				else if (row > 4)
					figure_vecotr.push_back(std::make_unique<Pawn>(row * 100 + 10, column * 100 + 10, WHITE));
			}
		}
}