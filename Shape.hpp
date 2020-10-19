#pragma once
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <SFML/Graphics.hpp>

class Shape
{
protected:
	glm::vec2 _position;
public:

	glm::vec2 GetPosition()
	{
		return _position;
	}

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual double GetArea() = 0;
	virtual double GetCircuit() = 0;
	virtual void SetColor(const sf::Color& color) = 0;
};