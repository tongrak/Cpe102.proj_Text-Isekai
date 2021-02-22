#include<SFML\Graphics.hpp>
#include<iostream>

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height /2 )- 480);

	window.create(sf::VideoMode(1024, 1024), "Text ADVENTURE", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	while (window.isOpen())

	{
		sf::Event Event;

		//Event Start the loop
		while (window.pollEvent(Event)) 
		{
			switch (Event.type) 
			{
			case sf::Event::Closed:
				window.close();

			}

		}
		window.clear();
		window.display();
		
	}

	return 0;
}