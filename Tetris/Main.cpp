#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 20;
const int N = 10;

int field[M][N] = { 0 };

struct Point
{int x, y;}a[4], b[4];

// 7 groups of 4 indexes
int figures[7][4] =
{
	//These figures are used to create tetromino pieces in a 2 by 4 box.
	//Positioning of the box looks like
	// 0   1
	// 2   3
	// 4   5
	// 6   7
	//So a line block piece would look like 1, 3, 5, 7. A straight line.

	1,3,5,7, // Line block
	2,4,5,7, // Backward S or a Z tetromino piece
	3,5,4,6, // S tetromino piece
	3,5,4,7, // T tetromino piece
	2,3,5,7, // L tetromino piece
	3,5,7,6, // Backward L tetromino piece
	2,3,4,5, // Square tetromino piece
};

int main() {
	//Hurray, window works
	RenderWindow window(sf::VideoMode(1280, 720), "Tetris");
	Texture texture;
	Texture texture2;
	//Load up image into SFML
	texture.loadFromFile("image/tiles.png");
	Sprite sprite(texture);

	//This will grab the blue block only, which is the first block.
	//Looking at the file size, tiles.png is 144 by 18.
	//There are 8 blocks, which means each blocks are 18 by 18 pixels.
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	//setScale allows for resizing of the texture. In this case, 2 * x and 2 * y. Default is 1 by 1.
	sprite.setScale(2, 2);

	//Test example to see if I can import another image instead of tutorial's image.
	texture2.loadFromFile("image/tiles_v2.png");
	Sprite sprite2(texture2);
	// 7 blocks, with a file size of 3584 by 512 pixels.
	sprite2.setTextureRect(IntRect(0, 0, 512, 512));
	sprite2.setScale(0.1, 0.1);

	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) 
				window.close();
		}


		//Window.clear can be left blank. Otherwise input colours using sf::Color.
		window.clear(sf::Color::Black);

		//Draws texture
		window.draw(sprite2);
		/*sf::RectangleShape rs(sf::Vector2f(100, 100));
		window.draw(rs);*/
		window.display();
	}
}