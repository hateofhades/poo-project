#include <iostream>
#include <math.h>
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

class QuestionPopup : public sf::Drawable
{
private:
    int hasPhoto;
    sf::Texture photo;
    sf::Sprite photoSprite;
    string correctAnswer;
    sf::Text question, inputAnswer, pressEnter;
    sf::RectangleShape background, input;
    sf::Font font;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    QuestionPopup(string question, string correctAnswer, sf::Font font)
    {
        this->hasPhoto = 0;
        this->font = font;
        this->correctAnswer = correctAnswer;

        this->background.setSize(sf::Vector2f(500, 200));
        this->background.setPosition(1280 / 2 - this->background.getSize().x / 2, 720 / 2 - this->background.getSize().y / 2);
        this->background.setFillColor(sf::Color::Blue);
        this->question.setString(question);
        this->question.setCharacterSize(24);
        this->question.setFillColor(sf::Color::White);
        this->question.setStyle(sf::Text::Bold);
        this->question.setFont(this->font);
        this->question.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->question.getLocalBounds().width) / 2, this->background.getPosition().y);
        this->input.setSize(sf::Vector2f(this->background.getSize().x - 20, 30));
        this->input.setPosition(this->background.getPosition().x + 10, this->question.getPosition().y + this->question.getLocalBounds().height + 30);
        this->input.setFillColor(sf::Color::White);

        this->inputAnswer.setString("");
        this->inputAnswer.setCharacterSize(18);
        this->inputAnswer.setFillColor(sf::Color::Black);
        this->inputAnswer.setStyle(sf::Text::Bold);
        this->inputAnswer.setFont(this->font);
        this->inputAnswer.setPosition(this->input.getPosition().x + (this->input.getSize().x - this->inputAnswer.getLocalBounds().width) / 2, this->input.getPosition().y + (this->input.getSize().y - this->inputAnswer.getLocalBounds().height) / 2);

        this->pressEnter.setString("Press Enter to submit your answer.");
        this->pressEnter.setCharacterSize(18);
        this->pressEnter.setFillColor(sf::Color::White);
        this->pressEnter.setStyle(sf::Text::Bold);
        this->pressEnter.setFont(this->font);
        this->pressEnter.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->pressEnter.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->pressEnter.getLocalBounds().height - 10);
    }

    QuestionPopup(string question, string correctAnswer, sf::Font font, int i) //constructor for question 1
    {
        this->hasPhoto = 0;
        this->font = font;
        this->correctAnswer = correctAnswer;

        this->background.setSize(sf::Vector2f(550, 470));
        this->background.setPosition(1280 / 2 - this->background.getSize().x / 2, 720 / 2 - this->background.getSize().y / 2);
        this->background.setFillColor(sf::Color::Blue);
        this->question.setString(question);
        this->question.setCharacterSize(24);
        this->question.setFillColor(sf::Color::White);
        this->question.setStyle(sf::Text::Bold);
        this->question.setFont(this->font);
        this->question.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->question.getLocalBounds().width) / 2, this->background.getPosition().y);
        this->input.setSize(sf::Vector2f(this->background.getSize().x - 20, 30));
        this->input.setPosition(this->background.getPosition().x + 10, this->question.getPosition().y + this->question.getLocalBounds().height + 30);
        this->input.setFillColor(sf::Color::White);

        this->inputAnswer.setString("");
        this->inputAnswer.setCharacterSize(18);
        this->inputAnswer.setFillColor(sf::Color::Black);
        this->inputAnswer.setStyle(sf::Text::Bold);
        this->inputAnswer.setFont(this->font);
        this->inputAnswer.setPosition(this->input.getPosition().x + (this->input.getSize().x - this->inputAnswer.getLocalBounds().width) / 2, this->input.getPosition().y + (this->input.getSize().y - this->inputAnswer.getLocalBounds().height) / 2);

        this->pressEnter.setString("Press Enter to submit your answer.");
        this->pressEnter.setCharacterSize(18);
        this->pressEnter.setFillColor(sf::Color::White);
        this->pressEnter.setStyle(sf::Text::Bold);
        this->pressEnter.setFont(this->font);
        this->pressEnter.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->pressEnter.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->pressEnter.getLocalBounds().height - 10);
    }

    void setInputAnswer(string inputAnswer)
    {
        this->inputAnswer.setString(inputAnswer);
        this->inputAnswer.setPosition(this->input.getPosition().x + (this->input.getSize().x - this->inputAnswer.getLocalBounds().width) / 2, this->input.getPosition().y + (this->input.getSize().y - this->inputAnswer.getLocalBounds().height) / 2);
    }
    string getInputAnswer()
    {
        return this->inputAnswer.getString();
    }
    string getCorrectAnswer()
    {
        return this->correctAnswer;
    }
    void addPhoto(string photoPath)
    {
        this->hasPhoto = 1;
        this->photo.loadFromFile(photoPath);
        this->photoSprite.setTexture(this->photo);
        this->photoSprite.setPosition(this->background.getPosition().x + this->background.getSize().x / 2 - this->photoSprite.getGlobalBounds().width / 2, this->input.getPosition().y + this->input.getSize().y + 10);
    }
};

void QuestionPopup::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->background);
    target.draw(this->question);
    target.draw(this->input);
    target.draw(this->inputAnswer);
    target.draw(this->pressEnter);

    if (this->hasPhoto)
    {
        target.draw(this->photoSprite);
    }
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
    Button creditsButton(1280 / 2 - 150, 440, 300, 50, "Credits", font, sf::Color::Black, sf::Color::White);
    Button ArrowButton(0, 0, 85, 35, "", font, sf::Color::Transparent, sf::Color::Transparent);
    Button RetryButton(1280 / 2 - 150, 370, 300, 50, "Retry", font, sf::Color::Black, sf::Color::White);

    Button *buttons[100];
    int numButons = 0;

    buttons[numButons++] = &startButton;
    buttons[numButons++] = &rulesButton;
    buttons[numButons++] = &creditsButton;
    buttons[numButons++] = &ArrowButton;
    buttons[numButons++] = &RetryButton;

    int test = 0;
    int poz_cursor_x = 640;
    int poz_cursor_y = 360;
    int input_is_wrong = 2;

    window.setMouseCursorVisible(false); //hide mouse cursor

    QuestionPopup questionPopup("Startup Password\nWhat is 'enzymatic hydrolysis'?", "Nu stiu", font);

    QuestionPopup questionPopup_1("Question 1\nFind the answer below.\nWhich is the inhibitor in an enzymatic\nhydrolysis of wheat straw bioprocess?", "glucose", font, 1);
    questionPopup_1.addPhoto("question.png");

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
                poz_cursor_x = sf::Mouse::getPosition(window).x;
                poz_cursor_y = sf::Mouse::getPosition(window).y;

                switch (test)
                {
                case 0:
                    if (startButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 1;
                    }
                    if (rulesButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 2;
                    }
                    if (creditsButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 3;
                    }
                    break;
                case 1 ... 10:
                    if (ArrowButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 0;
                    }
                    break;
                case -2 ... - 1:
                    if (RetryButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        //go back to main menu and undo all changes
                        test = 0;

                        questionPopup.setInputAnswer("");
                    }
                    break;
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                poz_cursor_x = sf::Mouse::getPosition(window).x;
                poz_cursor_y = sf::Mouse::getPosition(window).y;

                for (int i = 0; i < numButons; i++)
                {
                    if ((*buttons[i]).isOver(poz_cursor_x, poz_cursor_y))
                    {
                        (*buttons[i]).setBackgroundColor(sf::Color::Blue);
                    }
                    else
                    {
                        (*buttons[i]).setBackgroundColor(sf::Color::Black);
                        if (buttons[i] == &ArrowButton)
                        {
                            (*buttons[i]).setBackgroundColor(sf::Color::Transparent);
                        }
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                //password
                if (event.key.code == sf::Keyboard::Backspace && test == 1)
                {
                    questionPopup.setInputAnswer(questionPopup.getInputAnswer().substr(0, questionPopup.getInputAnswer().size() - 1));
                }

                //question 1
                if (event.key.code == sf::Keyboard::Backspace && test == 4)
                {
                    questionPopup_1.setInputAnswer(questionPopup_1.getInputAnswer().substr(0, questionPopup_1.getInputAnswer().size() - 1));
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
                    if (test == 1)
                    {
                        if (questionPopup.getInputAnswer() == questionPopup.getCorrectAnswer())
                        {
                            questionPopup.setInputAnswer("");
                            test = 4;
                        }
                        else
                        {
                            questionPopup.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }

                    if (test == 4)
                    {
                        if (questionPopup_1.getInputAnswer() == questionPopup_1.getCorrectAnswer())
                        {
                            questionPopup_1.setInputAnswer("");
                            test = 5;
                        }
                        else
                        {
                            questionPopup_1.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                }
            }
            //delete all text at once if input answer is wrong
            if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 1)
            {
                questionPopup.setInputAnswer("");
                input_is_wrong = 0;
            }

            if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 4)
            {
                questionPopup_1.setInputAnswer("");
                input_is_wrong = 0;
            }

            if (event.type == sf::Event::TextEntered)
            {
                if (test == 1)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionPopup.setInputAnswer(questionPopup.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }

                if (test == 4)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionPopup_1.setInputAnswer(questionPopup_1.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
            }
            //FOR TESTING THE FINAL MENU(WIN = UP ARROW/GAME OVER = DOWN ARROW)
            if (event.type == sf::Event::KeyPressed) //test
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    test = -1;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    test = -2;
                }
            }
            //////////////////////////////////////////////////////////////
        }

        window.clear();
        switch (test)
        {
        case 1: //startup password

            
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionPopup);

            window.draw(text);

            break;
        case 2: //rules menu
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
        case 3: //credits
            window.draw(mainMenuBackgroundObj);
            window.draw(ArrowButton);
            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            text.setString("Credits:");
            text.setCharacterSize(40);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 150);
            window.draw(text);
            text.setString("Grigore Iulia-Andreea, 323AC\nBonciu Alin, 323AC\nCodescu Elisabeta Maria, 322AC\nPurcaru Iulia-Mihaela, 323AC\nSerban Andrei, 323AC\nVirlan Adrian, 323AC");
            text.setCharacterSize(22);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 300);
            window.draw(text);
            break;
        case 4: //question 1
            window.draw(backgroundObj);

            window.draw(questionPopup_1);

            window.draw(text);

            break;

        case 5: //question 2
            window.draw(backgroundObj);

            break;

        case -1: //won the game
            window.draw(mainMenuBackgroundObj);

            text.setString("Congratulations!");
            text.setCharacterSize(60);
            text.setFillColor(sf::Color::Blue);
            text.setStyle(sf::Text::Bold);
            text.setStyle(sf::Text::Italic);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 250);
            window.draw(text);
            text.setString("You won the game!");
            text.setCharacterSize(27);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 317);
            window.draw(text);

            window.draw(RetryButton);
            break;
        case -2: //lost the game
            window.draw(mainMenuBackgroundObj);

            text.setString("Game over!");
            text.setCharacterSize(60);
            text.setFillColor(sf::Color::Blue);
            text.setStyle(sf::Text::Bold);
            text.setStyle(sf::Text::Italic);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 250);
            window.draw(text);
            text.setString("You ran out of time!");
            text.setCharacterSize(27);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 315);
            window.draw(text);
            window.draw(RetryButton);
            break;

        default: //main menu

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
            window.draw(creditsButton);

            text.setString("");
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
