#pragma once
#include "config.h"
class IFigure:	public	sf::Drawable
{
public:
	IFigure() {}
	virtual const	FIGURE_COLORS	getColor()=0;
	virtual const	sf::Vector2f getPosition()=0;
	virtual void	setTexture(sf::Texture& texture_figure)=0;
	virtual void	setPosition(int row, int col) = 0;
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
};