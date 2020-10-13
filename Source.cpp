#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <iostream>
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

	virtual void Draw(sf::RenderWindow& window, sf::Color color = sf::Color::White) = 0;
	virtual double GetArea() = 0;
	virtual double GetDiameter() = 0;
};

class Circle :public Shape
{
private:
	double _radius;
public:
	Circle(glm::vec2 position, double radius) :
		_radius{ radius }
	{
		_position = position;
	}

	virtual void Draw(sf::RenderWindow& window, sf::Color color = sf::Color::White)
	{
		sf::CircleShape circle(_radius);
		circle.setPointCount(1000);
		circle.setFillColor(color);
		circle.setPosition(_position.x - _radius, _position.y - _radius);
		window.draw(circle);
	}

	virtual double GetArea()
	{
		return glm::pi<double>() * glm::pow(_radius, 2);
	}

	virtual double GetDiameter()
	{
		return glm::pi<double>() * _radius * 2;
	}

	double GetRadius()
	{
		return _radius;
	}
};

int main()
{
	Circle circle1(glm::vec2(400, 300), 100);
	Circle circle2(glm::vec2(600, 300), 100);
	if (glm::distance(circle1.GetPosition(), circle2.GetPosition()) <= circle1.GetRadius() + circle2.GetRadius())
	{
		std::cout << "Circle collision detected!" << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "sfml");
	sf::Event event;
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		circle1.Draw(window);
		circle2.Draw(window, sf::Color::Red);
		window.display();
	}
	return 0;
}