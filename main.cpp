#include <iostream>
#include <SFML/Graphics.hpp>
//comment
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
    sf::Texture background, mainMenuBackground, cursor, qMark, leftArrow;
    sf::Sprite backgroundObj, mainMenuBackgroundObj, cursorObj, qMarkObj, leftArrowObj;
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

    if (!cursor.loadFromFile("cursor.png"))
    {
        cout << "Failed to load cursor.png";
        return 1;
    }

    if (!qMark.loadFromFile("?.jpg"))
    {
        cout << "Failed to load ?.jpg";
        return 1;
    }

    if (!leftArrow.loadFromFile("left_arrow.png"))
    {
        cout << "Failed to load left_arrow.png";
        return 1;
    }

    text.setFont(font);

    backgroundObj.setTexture(background);
    backgroundObj.setScale(1280 / backgroundObj.getLocalBounds().width, 720 / backgroundObj.getLocalBounds().height);
    mainMenuBackgroundObj.setTexture(mainMenuBackground);
    mainMenuBackgroundObj.setScale(1280 / mainMenuBackgroundObj.getLocalBounds().width, 720 / mainMenuBackgroundObj.getLocalBounds().height);
    cursorObj.setTexture(cursor);
    cursorObj.scale(0.05, 0.05);
    leftArrowObj.setTexture(leftArrow);
    leftArrowObj.scale(0.1, 0.1);

    Button startButton(1280 / 2 - 150, 300, 300, 50, "Start", font, sf::Color::Black, sf::Color::White);
    Button rulesButton(1280 / 2 - 150, 370, 300, 50, "Rules", font, sf::Color::Black, sf::Color::White);
    Button ArrowButton(0, 0, 85, 35, "", font, sf::Color::Black, sf::Color::White);

    int test = 0;
    int poz_cursor_x = 640;
    int poz_cursor_y = 360;

    window.setMouseCursorVisible(false); //hide mouse cursor

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (test == 0)
                    if (startButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        test = 1;
                    }
                if (test == 0)
                    if (rulesButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        test = 2;
                    }
                if (test > 0)
                    if (ArrowButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        test = 0;
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

                if (rulesButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    rulesButton.setBackgroundColor(sf::Color::Blue);
                }
                else
                {
                    rulesButton.setBackgroundColor(sf::Color::Black);
                }

                if (ArrowButton.isOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    ArrowButton.setBackgroundColor(sf::Color::Blue);
                }
                else
                {
                    ArrowButton.setBackgroundColor(sf::Color::Black);
                }

                poz_cursor_x = sf::Mouse::getPosition(window).x;
                poz_cursor_y = sf::Mouse::getPosition(window).y;
            }
        }

        switch (test)
        {
        case 1: //first level

            window.clear();
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);
            break;
        case 2: //rules menu
            window.clear();
            window.draw(mainMenuBackgroundObj);
            window.draw(ArrowButton);
            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            text.setString("Reguli:");
            text.setCharacterSize(40);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 150);
            window.draw(text);
            text.setString("Apasa <= pentru a reveni la imaginea anterioara\nregula2\nregula3\nregula4");
            text.setCharacterSize(22);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 200);
            window.draw(text);
            break;
        default: //main menu

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
            window.draw(rulesButton);
        }
        //draw cursor
        cursorObj.setPosition(poz_cursor_x, poz_cursor_y);
        cursorObj.setPosition(poz_cursor_x, poz_cursor_y);
        window.draw(cursorObj);
        //update display
        window.display();
    }

    return 0;
}
