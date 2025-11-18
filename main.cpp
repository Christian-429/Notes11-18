
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class RainbowScreen : public Drawable
{
public:
	RainbowScreen(int pixelWidth, int pixelHeight);
	void draw(RenderTarget& target, RenderStates states) const override; // window.draw(..)
	void update();
private:
	VertexArray v;
	Vector2f pixelSize;
};

RainbowScreen::RainbowScreen(int pixelWidth, int pixelHeight)
{
	pixelSize = { pixelWidth, pixelHeight };
	v.setPrimitiveType(Points);
	v.resize(pixelWidth * pixelHeight);
}
void RainbowScreen::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(v);
}













int main()
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;

	VideoMode vm(pixelWidth, pixelHeight);
	RenderWindow window(vm, "Rainbow screen", Style::Default);

	//Each loop is one frame
	while (window.isOpen())
	{
		//input
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					cout << "Left mouse button was pressed\n";
					cout << "Mouse x: " << event.mouseButton.x << endl;
					cout << "Mouse y: " << event.mouseButton.y << endl;
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//update
		float radius = 150.0;
		RectangleShape rectangle;
		rectangle.setSize(Vector2f(100, 50));
		CircleShape circle(150);
		circle.setFillColor(Color::Magenta);
		rectangle.setFillColor(Color::Yellow);
		circle.setPosition(pixelWidth / 2, pixelHeight / 2);
		circle.setOrigin(radius, radius);
		rectangle.setPosition(pixelWidth / 2, pixelHeight / 2);
		
		//draw
		window.clear();
		window.draw(circle);
		window.draw(rectangle);
		window.display();
	}
}