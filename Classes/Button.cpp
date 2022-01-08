#include "Button.h"

using namespace std;

Button::Button(){

};

Button::Button(int positionX, int positionY, int width, int height, string text, sf::Font font, sf::Color buttonColor, sf::Color textColor)
{
    this->positionX = positionX;
    this->positionY = positionY;
    this->width = width;
    this->height = height;
    this->font = font;
    this->text.setString(text);
    this->text.setCharacterSize(24);
    this->text.setFillColor(textColor);
    this->text.setStyle(sf::Text::Bold);
    this->text.setFont(this->font);
    this->text.setPosition(positionX + (this->width - this->text.getLocalBounds().width) / 2, positionY + (this->height / 4));
    this->rect.setSize(sf::Vector2f(this->width, this->height));
    this->rect.setPosition(positionX, positionY);
    this->rect.setFillColor(buttonColor);
};

bool Button::isOver(int mouseX, int mouseY)
{
    if ((mouseX >= this->positionX && mouseX <= this->positionX + width) && (mouseY >= this->positionY && mouseY <= this->positionY + height))
        return true;
    return false;
};

void Button::setString(string text)
{
    this->text.setString(text);
};

void Button::setBackgroundColor(sf::Color color)
{
    this->rect.setFillColor(color);
};

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->rect);
    target.draw(this->text);
};