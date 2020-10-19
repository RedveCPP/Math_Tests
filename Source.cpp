#include "Circle.hpp"

int main()
{
	Circle circle1(glm::vec2(200, 300), 100);
	Circle circle2(glm::vec2(400, 300), 50);

	sf::RenderWindow window(sf::VideoMode(800, 600), "sfml");
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
			CircleEvents(circle2, event);
		}

		if (glm::distance(circle1.GetPosition(), circle2.GetPosition()) <= circle1.GetRadius() + circle2.GetRadius())
		{
			circle2.SetColor(sf::Color::Green);
		}
		else
		{
			circle2.SetColor(sf::Color::White);
		}

		circle1.Draw(window);
		circle2.Draw(window);
		window.display();
	}
	return 0;
}