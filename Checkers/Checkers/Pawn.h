#pragma once
#include "IFigure.h"
class Pawn : public IFigure
{
public:
	Pawn(int column , int row, FIGURE_COLORS);
	FIGURE_COLORS const getColor();
	void	setPosition(int row, int col);
	const	sf::Vector2f getPosition();
	void	setTexture(sf::Texture& texture_figure);
	void	draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
	FIGURE_COLORS	_figure_color;
	sf::Sprite		_figure_sprite;
	int col;
	int row;
};