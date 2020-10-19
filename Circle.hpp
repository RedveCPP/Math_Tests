#pragma once
#include "Shape.hpp"

class Circle :public Shape
{
private:
	double _radius;
	sf::CircleShape circle;
public:
	Circle(glm::vec2 position, double radius) :
		_radius{ radius }
	{
		circle.setFillColor(sf::Color::White);
		circle.setRadius(radius);
		_position = position;
	}

	virtual void Draw(sf::RenderWindow& window)
	{
		circle.setPointCount(1000);
		circle.setPosition(_position.x - _radius, _position.y - _radius);
		window.draw(circle);
	}

	virtual double GetArea()
	{
		return glm::pi<double>() * glm::pow(_radius, 2);
	}

	virtual double GetCircuit()
	{
		return glm::pi<double>() * _radius * 2;
	}

	double GetRadius()
	{
		return _radius;
	}

	virtual void SetColor(const sf::Color& color)
	{
		circle.setFillColor(color);
	}

	void Move(glm::vec2 moveVector)
	{
		_position += moveVector;
	}
};

void CircleEvents(Circle& object, sf::Event& event)
{
	if (event.key.code == sf::Keyboard::A)
	{
		object.Move(glm::vec2(-1, 0));
	}

	if (event.key.code == sf::Keyboard::D)
	{
		object.Move(glm::vec2(1, 0));
	}

	if (event.key.code == sf::Keyboard::W)
	{
		object.Move(glm::vec2(0, -1));
	}

	if (event.key.code == sf::Keyboard::S)
	{
		object.Move(glm::vec2(0, 1));
	}
}