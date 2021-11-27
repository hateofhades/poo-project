#include <iostream>
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
    Button(){

    };
    Button(int positionX, int positionY, int width, int height, string text, sf::Font font, sf::Color buttonColor, sf::Color textColor)
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
    }
    bool isOver(int mouseX, int mouseY)
    {
        if ((mouseX >= this->positionX && mouseX <= this->positionX + width) && (mouseY >= this->positionY && mouseY <= this->positionY + height))
            return true;
        return false;
    }
    void setString(string text)
    {
        this->text.setString(text);
    }
    void setBackgroundColor(sf::Color color)
    {
        this->rect.setFillColor(color);
    }
};

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->rect);
    target.draw(this->text);
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Escape Room Proiect");
    sf::Texture background, mainMenuBackground;
    sf::Sprite backgroundObj, mainMenuBackgroundObj;
    sf::Font font;
    sf::Text text;

    if (!background.loadFromFile("background.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!mainMenuBackground.loadFromFile("mainmenu.jpg"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!font.loadFromFile("times new roman.ttf"))
    {
        cout << "Font could not be loaded";
        return 1;
    }

    text.setFont(font);

    backgroundObj.setTexture(background);
    backgroundObj.setScale(1280 / backgroundObj.getLocalBounds().width, 720 / backgroundObj.getLocalBounds().height);
    mainMenuBackgroundObj.setTexture(mainMenuBackground);
    mainMenuBackgroundObj.setScale(1280 / mainMenuBackgroundObj.getLocalBounds().width, 720 / mainMenuBackgroundObj.getLocalBounds().height);

    Button startButton(1280 / 2 - 150, 300, 300, 50, "Start", font, sf::Color::Black, sf::Color::White);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (startButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    startButton.setString("sal");
                    
                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                if (startButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    startButton.setBackgroundColor(sf::Color::Blue);
                }
                else
                {
                    startButton.setBackgroundColor(sf::Color::Black);
                }
            }
        }
        window.clear();
        window.draw(mainMenuBackgroundObj);

        text.setString("Learning about a bioprocess");
        text.setCharacterSize(32);
        text.setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
        text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 150);
        window.draw(text);
        text.setString("The Escape Room Version");
        text.setCharacterSize(18);
        text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 182);
        window.draw(text);

        window.draw(startButton);

        window.display();
    }

    return 0;
}
