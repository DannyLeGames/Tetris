#include <SFML/Graphics.hpp>
//Testing to see if the push works

int main() {
	//Hurray, window works
	sf::RenderWindow window(sf::VideoMode(600, 600), "Tetris");
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		sf::RectangleShape rs(sf::Vector2f(100, 100));
		window.draw(rs);
		window.display();
	}
}