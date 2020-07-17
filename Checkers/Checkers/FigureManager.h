#pragma once
#include "config.h"
#include "IFigure.h"
#include "Pawn.h"
#include "Queen.h"
class FigureManager : public sf::Drawable
{
public:

	FigureManager();
	~FigureManager();

	void	setFiguresOnStartingPositions();
	void	draw(sf::RenderTarget& object, sf::RenderStates states)const override;
	void	setTexture();
	void	loadTexture();
private:
	std::vector<std::shared_ptr<IFigure>> figure_vecotr;
	sf::Texture pawn_texture_black;
	sf::Texture queen_texture_black;
	sf::Texture pawn_texture_white;
	sf::Texture queen_texture_white;
};
