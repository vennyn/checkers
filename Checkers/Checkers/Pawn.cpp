#include "Pawn.h"

Pawn::Pawn(int column, int row, FIGURE_COLORS color):
	col(column),
	row(row),
	_figure_color(color)
{
	setPosition(row, column);
}

void Pawn::setPosition(int row, int col)
{
	this->_figure_sprite.setPosition(row, col);
}

sf::Vector2f const Pawn::getPosition()
{
	return this->_figure_sprite.getPosition();
}

void Pawn::setTexture(sf::Texture& figure_texture)
{
	this->_figure_sprite.setTexture(figure_texture);
}

void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(this->_figure_sprite);
}

FIGURE_COLORS const Pawn::getColor()
{
	return this->_figure_color;
}