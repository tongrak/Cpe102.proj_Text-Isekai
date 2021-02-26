#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <math.h>
#include <iostream>
#include <sstream>

//#include "Header.h"

int main() {
  /*  sf::String Operator;
    string player_name;
    std::cout << player_name*/


    sf::RenderWindow window(sf::VideoMode(1048, 1048), "Text adventure", sf::Style::Close | sf::Style::Resize );

    sf::Texture texture;

    texture.setRepeated(true);

    

    if (!texture.loadFromFile("C:/Game file/background/CAVE 1.jpg")) {
        std::cout << "Load failed" << std::endl;

        system("pause");

    }

    sf::Sprite sprite;

    sprite.setTexture(texture);
    //sprite.setTextureRect(sf::IntRect(0, 0, 1000,1000 ));
    sprite.setPosition(sf::Vector2f(200,100));



    sf::Font font;
    if (!font.loadFromFile("C:/Game file/Font/ArialCE.ttf")) {
        std::cout << "Load FONT Failed" << std::endl;

        system("pause");
    }
    font.loadFromFile("ArialCE.ttf");

    sf::String sentence;
    sf::Text text(sentence, font, 40);
    text.setPosition(0, 600);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold || sf::Text::Underlined);


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
                
                break;

            case sf::Event::Resized:
                printf("%i,%i\n", Event.size.width, Event.size.height);
                break;
            case sf::Event::TextEntered:
                if (Event.type == sf::Event::TextEntered) {
                    if (Event.text.unicode >= 32 && Event.text.unicode <= 126 && sentence.getSize() < 20)
                    {
                        sentence += (char)Event.text.unicode;
                    }
                    else if (Event.text.unicode == 8 && sentence.getSize() > 0)
                    {
                        sentence.erase(sentence.getSize() - 1, sentence.getSize());
                    }
                    else if (Event.text.unicode == 13 && sentence.getSize()) 
                    {
                        for (unsigned int i = 0; i < sentence.getSize(); i++)
                            putchar(tolower(sentence[i]));
                        //usethisline to Enter Event
                    }

                    text.setString(sentence);
                    break;

                }      
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();

    }

    return 0;
}
