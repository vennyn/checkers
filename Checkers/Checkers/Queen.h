#pragma once
#include "IFigure.h"


class Queen : public IFigure
{
public:
	Queen(int row, int col,FIGURE_COLORS);
	FIGURE_COLORS const getColor();
	const	sf::Vector2f getPosition();
	void	setPosition(int row, int col);
	void	setTexture(sf::Texture& texture_figure);
	void	draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	FIGURE_COLORS	_figure_color;
	sf::Sprite		_figure_sprite;
	int row;
	int col;
};