#include <SFML/Graphics.hpp>

using namespace sf;



int main() {
	//Hurray, window works
	RenderWindow window(sf::VideoMode(600, 600), "Tetris");
	Texture texture;

	texture.loadFromFile("image/tiles.png");
	Sprite sprite(texture);

	//setScale allows for resizing of the texture. In this case, 2 * x and 2 * y.
	sprite.setScale(2, 2);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) 
				window.close();
		}


		window.clear(sf::Color::Black);
		window.draw(sprite);
		/*sf::RectangleShape rs(sf::Vector2f(100, 100));
		window.draw(rs);*/
		window.display();
	}
}