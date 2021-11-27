#include <iostream>
#include <SFML/Graphics.hpp>
//comment
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Escape Room Proiect");
    sf::Texture background;
    sf::Sprite backgroundObj;
    sf::Font font;
    sf::Text text;

    if (!background.loadFromFile("background.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Font could not be loaded";
        return 1;
    }

    text.setFont(font);

    backgroundObj.setTexture(background);
    backgroundObj.setScale(1280 / backgroundObj.getLocalBounds().width, 720 / backgroundObj.getLocalBounds().height);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        text.setString("Escape Room");
        text.setCharacterSize(32);
        text.setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
        text.setPosition(1280/2 - text.getLocalBounds().width / 2, 0);

        window.clear();
        window.draw(backgroundObj);
        window.draw(text);
        window.display();
    }

    return 0;
}
