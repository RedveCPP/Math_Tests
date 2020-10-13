#include <glm/vec2.hpp>
#include <iostream>

int main()
{
	glm::vec2 vector1(400,300);
	glm::vec2 vector2(400,300);
	vector1 += vector2;
	std::cout << vector1.x;
	return 0;
}