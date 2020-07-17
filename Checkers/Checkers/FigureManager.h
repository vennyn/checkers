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
	void	getFiguresPositions();
	bool	checkIfFigure(sf::Vector2f sf_vec, FIGURE_COLORS tour);
	bool	checkIfAnotherFigure(sf::Vector2f sf_vec);
	std::pair<int, int>	convertToIndex(sf::Vector2f sf_vec);

private:
	//std::vector<std::pair<std::shared_ptr<IFigure>, sf::Vector2f>>position_vector;
	std::vector<std::pair<std::shared_ptr<IFigure>, std::pair<int, int>>>position_vector2;
	std::vector<std::shared_ptr<IFigure>> figure_vector;
	sf::Texture pawn_texture_black;
	sf::Texture queen_texture_black;
	sf::Texture pawn_texture_white;
	sf::Texture queen_texture_white;
};
