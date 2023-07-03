#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Play Ludo", sf::Style::Titlebar | sf::Style::Close);

    sf::Texture backgroundImage;
    if (!backgroundImage.loadFromFile(".\\assets\\ludo_mini.png"))
    {
        return -1;
    }

    sf::Texture Bluepiece;
    if (!Bluepiece.loadFromFile(".\\assets\\blue_disc.png"))
    {
        return -1;
    }

    // Create the sprite and set its texture
    sf::Sprite bpiece;
    bpiece.setTexture(Bluepiece);

    // Set the position of the sprite
    bpiece.setPosition(314, 298);

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(bpiece);
        window.display();
    }

    return 0;
}