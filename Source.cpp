#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <iostream>

class Shape
{
protected:
	glm::vec2 position;
public:
	virtual double GetArea() = 0;
	virtual double GetDiameter() = 0;
};

class Circle :public Shape
{
private:
	double radius;
public:
	Circle(glm::vec2&& position, double radius)
	{
		this->position = position;
		this->radius = radius;
	}
	virtual double GetArea()
	{
		return glm::pi<float>() * glm::pow(radius, 2);
	}

	virtual double GetDiameter()
	{
		return glm::pi<float>() * radius * 2;
	}
};

double GetArea(Shape& shape)
{
	return shape.GetArea();
}

double GetDiameter(Shape& shape)
{
	return shape.GetDiameter();
}

int main()
{
	Circle circle(glm::vec2(400, 300), 5);
	std::cout << GetArea(circle);
	return 0;
}