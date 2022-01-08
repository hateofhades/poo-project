#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Button : public sf::Drawable
{
private:
    int positionX, positionY, width, height;
    sf::Text text;
    sf::RectangleShape rect;
    sf::Font font;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    Button();
    Button(int positionX, int positionY, int width, int height, string text, sf::Font font, sf::Color buttonColor, sf::Color textColor);
    bool isOver(int mouseX, int mouseY);
    void setString(string text);
    void setBackgroundColor(sf::Color color);
};