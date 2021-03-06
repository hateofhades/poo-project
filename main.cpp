#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Classes/QuestionPopup.h"
#include "Classes/Button.h"
#include "Classes/Maze.h"
#include "Classes/QuestionMultipleAnswers.h"
#include "Classes/QuestionCards.h"
#include "Classes/QuestionCards2.h"
#include "Classes/QuestionWordSearch.h"

using namespace std;

string returnTime(int timeElapsed)
{
    int min = 0;
    char dp = ':';
    min = timeElapsed / 60;
    if (timeElapsed > 60)
        timeElapsed -= 60;
    string timer = std::to_string(min);
    timer.push_back(dp);
    timer.append(std::to_string(timeElapsed));
    return timer;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Escape Room Proiect");
    sf::Texture background, mainMenuBackground, cursor, leftArrow, logo, cardsImage, wordSearch, questionEight, audio_on, audio_off;
    sf::Sprite backgroundObj, mainMenuBackgroundObj, cursorObj, leftArrowObj, logoObj, cardsObj, wordSearchObj, questionEightObj, audio_onObj, audio_offObj;
    sf::Font font;
    sf::Text text;
    sf::Clock clock1; // starts the global clock
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("Sources/Sounds/sound.wav"))
    {
        return -1;
    }

    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);

    if (!audio_on.loadFromFile("./Sources/Images/on.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!audio_off.loadFromFile("./Sources/Images/off.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!background.loadFromFile("./Sources/Images/background.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!questionEight.loadFromFile("./Sources/Images/question_eight.png"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!mainMenuBackground.loadFromFile("./Sources/Images/mainmenu.jpg"))
    {
        cout << "Background could not be loaded";
        return 1;
    }

    if (!font.loadFromFile("./Sources/Fonts/times new roman.ttf"))
    {
        cout << "Font could not be loaded";
        return 1;
    }

    if (!cursor.loadFromFile("./Sources/Images/cursor.png"))
    {
        cout << "Failed to load cursor.png";
        return 1;
    }

    if (!logo.loadFromFile("./Sources/Images/erasmus_logo.png"))
    {
        cout << "Failed to load erasmus_logo.png";
        return 1;
    }

    if (!leftArrow.loadFromFile("./Sources/Images/left_arrow.png"))
    {
        cout << "Failed to load left_arrow.png";
        return 1;
    }

    if (!cardsImage.loadFromFile("./Sources/Images/cards.png"))
    {
        cout << "Failed to load cards.png";
        return 1;
    }

    if (!wordSearch.loadFromFile("./Sources/Images/word_search.png"))
    {
        cout << "Failed to load word_search.png";
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
    logoObj.setTexture(logo);
    logoObj.setScale(0.2, 0.2);
    cardsObj.setTexture(cardsImage);
    cardsObj.setScale(0.9, 0.9);
    cardsObj.setPosition(400, 180);
    wordSearchObj.setTexture(wordSearch);
    wordSearchObj.setScale(0.7, 0.7);
    wordSearchObj.setPosition(365, 230);
    questionEightObj.setTexture(questionEight);
    questionEightObj.setScale(0.9, 0.9);
    questionEightObj.setPosition(440, 160);

    Button startButton(1280 / 2 - 150, 300, 300, 50, "Start", font, sf::Color::Black, sf::Color::White);
    Button rulesButton(1280 / 2 - 150, 370, 300, 50, "Guide", font, sf::Color::Black, sf::Color::White);
    Button creditsButton(1280 / 2 - 150, 440, 300, 50, "Credits", font, sf::Color::Black, sf::Color::White);
    Button ArrowButton(0, 0, 85, 35, "", font, sf::Color::Transparent, sf::Color::Transparent);
    Button ExitButton(1280 / 2 - 150, 370, 300, 50, "Exit", font, sf::Color::Black, sf::Color::White);
    Button AudioButton(1200, 55, 52, 50, "", font, sf::Color::Transparent, sf::Color::Transparent);
    Button Link1(309, 358, 510, 75, "", font, sf::Color::Transparent, sf::Color::White);
    Button Link2(309, 458, 510, 75, "", font, sf::Color::Transparent, sf::Color::Transparent);

    Button *buttons[100];
    int numButons = 0;

    buttons[numButons++] = &startButton;
    buttons[numButons++] = &rulesButton;
    buttons[numButons++] = &creditsButton;
    buttons[numButons++] = &ArrowButton;
    buttons[numButons++] = &ExitButton;
    buttons[numButons++] = &AudioButton;
    buttons[numButons++] = &Link1;
    buttons[numButons++] = &Link2;

    int test = 0;
    int poz_cursor_x = 640;
    int poz_cursor_y = 360;
    int input_is_wrong = 2;
    int link = 0;

    window.setMouseCursorVisible(false); // hide mouse cursor

    QuestionPopup questionPopup_1("\nFind the answer below.\nWhich is the inhibitor in an enzymatic\nhydrolysis of wheat straw bioprocess?", "glucose", font);
    questionPopup_1.addPhoto("./Sources/Images/question.png");
    Maze mazePopup("\nWhat is the cause of toxic H2O2 formation?", "celular respiration", font);
    mazePopup.ChangeColor(sf::Color{240, 166, 7, 200});

    QuestionMultipleAnswers multipleAnswer("Based on Gaden model, the yield of substrate\nconversion vs the glucose concentration is:", 3, font, "directly\nproportional", "no connection", "inversely\nproportional");
    multipleAnswer.ChangeColor(sf::Color{178, 237, 40, 200});
    QuestionMultipleAnswers multipleAnswer2("The dependence of product accumulation \nvs inhibitor concentration is: ", 1, font, "Exponential", "Parabolic", "Linear");
    multipleAnswer2.ChangeColor(sf::Color{134, 138, 127, 200});
    QuestionCards multipleCards("The following playing cards are given. In black we have the real \nvalues of product concentration, and in red the modeled values [* 10 g / L), \nfor 4 successive values of inhibitor concentration (0, 10, 25, 40). \nSpecify whether it is a model with inhibition or not.", 2, font, cardsObj, "Yes", "No answer can be given", "No");
    QuestionCards2 multipleCards2("The equation is a generalization of:", 2, font, cardsObj, "Michaelis-Meneten equation", "Monod equation", "Miller equation");

    QuestionWordSearch questionWordSearch_1("Fill in the blanks with the words you find below\nand obtain the password in order to continue.\n\n_________ is the most abundant organic compound in the world\nand is constantly replenished by photosynthesis.\n__________", "cellulose", font);
    QuestionWordSearch questionWordSearch_2("\nThe enzymatic hydrolysis is a process performed\nin ____________ system, involving the action of soluble\nenzyme (cellulase) on insoluble substrate. \n\n________o_", "heterogeneous", font);
    QuestionWordSearch questionWordSearch_3("\nIn general, cellulases secreted by fungi \nconsistof three major classes of components: \nendoglucanases, _______________ and beta-glucosidases.  \n\n_nh___t_on", "cellobiohydrolases", font);
    QuestionWordSearch questionWordSearch_4("\nCongratulations!\nYou have obtained the password:\n\ninhibition\n", "inhibition", font);

    int sound_is_on = 1;
    sound.play();
    audio_onObj.setTexture(audio_on);
    audio_onObj.setScale(0.160, 0.160);
    audio_onObj.setPosition(1200, 57);

    audio_offObj.setTexture(audio_off);
    audio_offObj.setScale(0.07, 0.065);
    audio_offObj.setPosition(1201.5, 63);

    while (window.isOpen())
    {
        sf::Time elapsed1 = clock1.getElapsedTime();
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

                if (Link1.isOver(poz_cursor_x, poz_cursor_y) && link == 1)
                // WIN32 = we're in windows
                #ifdef _WIN32
                // Windows
                system("start https://drive.google.com/file/d/1d6DwTIV_LtSjXWFPe7bejttgaXbjGDgt/view?usp=sharing");
                #else
                system("xdg-open https://drive.google.com/file/d/1d6DwTIV_LtSjXWFPe7bejttgaXbjGDgt/view?usp=sharing");
                #endif

                if (Link2.isOver(poz_cursor_x, poz_cursor_y) && link == 1)
                // WIN32 = we're in windows
                #ifdef _WIN32
                // Windows
                system("start https://drive.google.com/file/d/1LoWLbg70tpKp38s76LcxKC7EWLAzOphT/view?usp=sharing");
                #else
                system("xdg-open https://drive.google.com/file/d/1LoWLbg70tpKp38s76LcxKC7EWLAzOphT/view?usp=sharing");
                #endif

                switch (test)
                {
                case 0:
                    if (startButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 4;
                        clock1.restart();
                        elapsed1 = clock1.getElapsedTime();
                    }
                    if (rulesButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        test = 2;
                        link = 1;
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
                        link = 0;
                    }
                    break;
                case -2 ... - 1:
                    if (ExitButton.isOver(poz_cursor_x, poz_cursor_y))
                    {
                        window.close();
                    }
                    break;
                }

                if (AudioButton.isOver(poz_cursor_x, poz_cursor_y))
                {
                    if (sound_is_on == 1)
                    {
                        sound.pause();
                        sound_is_on = 0;
                    }
                    else
                    {
                        sound.play();
                        sound_is_on = 1;
                    }
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
                        if (buttons[i] == &Link1 || buttons[i] == &Link2)
                            (*buttons[i]).setBackgroundColor(sf::Color{237, 206, 183, 100});
                    }
                    else
                    {
                        (*buttons[i]).setBackgroundColor(sf::Color::Black);
                        if (buttons[i] == &ArrowButton || buttons[i] == &AudioButton || buttons[i] == &Link1 || buttons[i] == &Link2)
                        {
                            (*buttons[i]).setBackgroundColor(sf::Color::Transparent);
                        }
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                // question 1
                if (event.key.code == sf::Keyboard::Backspace && test == 4)
                {
                    questionPopup_1.setInputAnswer(questionPopup_1.getInputAnswer().substr(0, questionPopup_1.getInputAnswer().size() - 1));
                }

                // question 2
                else if (event.key.code == sf::Keyboard::Backspace && test == 5)
                {
                    mazePopup.setInputAnswer(mazePopup.getInputAnswer().substr(0, mazePopup.getInputAnswer().size() - 1));
                }

                // question 5
                if (event.key.code == sf::Keyboard::Backspace && test == 8)
                {
                    questionWordSearch_1.setInputAnswer(questionWordSearch_1.getInputAnswer().substr(0, questionWordSearch_1.getInputAnswer().size() - 1));
                }
                if (event.key.code == sf::Keyboard::Backspace && test == 9)
                {
                    questionWordSearch_2.setInputAnswer(questionWordSearch_2.getInputAnswer().substr(0, questionWordSearch_2.getInputAnswer().size() - 1));
                }
                if (event.key.code == sf::Keyboard::Backspace && test == 10)
                {
                    questionWordSearch_3.setInputAnswer(questionWordSearch_3.getInputAnswer().substr(0, questionWordSearch_3.getInputAnswer().size() - 1));
                }
                if (event.key.code == sf::Keyboard::Backspace && test == 11)
                {
                    questionWordSearch_4.setInputAnswer(questionWordSearch_4.getInputAnswer().substr(0, questionWordSearch_4.getInputAnswer().size() - 1));
                }

                // For mazes!
                if (event.key.code == sf::Keyboard::Up && test == 5)
                {
                    mazePopup.moveUp();
                }
                else if (event.key.code == sf::Keyboard::Down && test == 5)
                {
                    mazePopup.moveDown();
                }
                else if (event.key.code == sf::Keyboard::Left && test == 5)
                {
                    mazePopup.moveLeft();
                }
                else if (event.key.code == sf::Keyboard::Right && test == 5)
                {
                    mazePopup.moveRight();
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
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
                    else if (test == 5)
                    {
                        if (mazePopup.getInputAnswer() == mazePopup.getCorrectAnswer())
                        {
                            mazePopup.setInputAnswer("");
                            test = 6;
                        }
                        else
                        {
                            mazePopup.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 6)
                    {
                        if (multipleAnswer.getSelected() == multipleAnswer.getCorrectAnswer())
                        {
                            test = 7;
                        }
                        else
                        {
                            multipleAnswer.setHint("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 7)
                    {
                        if (multipleCards.getSelected() == multipleCards.getCorrectAnswer())
                        {
                            test = 8;
                        }
                        else
                        {
                            multipleCards.setHint("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 8)
                    {
                        if (questionWordSearch_1.getInputAnswer() == questionWordSearch_1.getCorrectAnswer())
                        {
                            test = 9;
                        }
                        else
                        {
                            questionWordSearch_1.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 9)
                    {
                        if (questionWordSearch_2.getInputAnswer() == questionWordSearch_2.getCorrectAnswer())
                        {
                            test = 10;
                        }
                        else
                        {
                            questionWordSearch_2.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 10)
                    {
                        if (questionWordSearch_3.getInputAnswer() == questionWordSearch_3.getCorrectAnswer())
                        {
                            test = 11;
                        }
                        else
                        {
                            questionWordSearch_3.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 11)
                    {
                        if (questionWordSearch_4.getInputAnswer() == questionWordSearch_4.getCorrectAnswer())
                        {
                            test = 12;
                        }
                        else
                        {
                            questionWordSearch_4.setInputAnswer("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 12)
                    {
                        if (multipleAnswer2.getSelected() == multipleAnswer2.getCorrectAnswer())
                        {
                            test = 13;
                        }
                        else
                        {
                            multipleAnswer2.setHint("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                    else if (test == 13)
                    {
                        if (multipleCards2.getSelected() == multipleCards2.getCorrectAnswer())
                        {
                            test = -1;
                        }
                        else
                        {
                            multipleCards2.setHint("Your answer is wrong!");
                            input_is_wrong = 1;
                        }
                    }
                }
            }
            // delete all text at once if input answer is wrong
            if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 4)
            {
                questionPopup_1.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 5)
            {
                mazePopup.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (test == 6 && (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad1 || event.key.code == sf::Keyboard::Numpad2 || event.key.code == sf::Keyboard::Numpad3))
            {
                int selected = (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) ? 1 : (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) ? 2
                                                                                                                                                                                                         : 3;
                multipleAnswer.selectAnswer(selected);
                input_is_wrong = 0;
                multipleAnswer.setHint("Press Enter to submit your answer and 1, 2 or 3 to select an answer.");
            }
            else if (test == 7 && (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad1 || event.key.code == sf::Keyboard::Numpad2 || event.key.code == sf::Keyboard::Numpad3))
            {
                int selected = (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) ? 1 : (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) ? 2
                                                                                                                                                                                                         : 3;
                multipleCards.selectAnswer(selected);
                input_is_wrong = 0;
                multipleCards.setHint("Press Enter to submit your answer and 1, 2 or 3 to select an answer.");
            }
            else if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 8)
            {
                questionWordSearch_1.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 9)
            {
                questionWordSearch_2.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 10)
            {
                questionWordSearch_3.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (event.key.code != sf::Keyboard::Enter && event.type == sf::Event::KeyPressed && input_is_wrong == 1 && test == 11)
            {
                questionWordSearch_4.setInputAnswer("");
                input_is_wrong = 0;
            }
            else if (test == 12 && (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad1 || event.key.code == sf::Keyboard::Numpad2 || event.key.code == sf::Keyboard::Numpad3))
            {
                int selected = (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) ? 1 : (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) ? 2
                                                                                                                                                                                                         : 3;
                multipleAnswer2.selectAnswer(selected);
                input_is_wrong = 0;
                multipleAnswer2.setHint("Press Enter to submit your answer and 1, 2 or 3 to select an answer.");
            }
            else if (test == 13 && (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad1 || event.key.code == sf::Keyboard::Numpad2 || event.key.code == sf::Keyboard::Numpad3))
            {
                int selected = (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) ? 1 : (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) ? 2
                                                                                                                                                                                                         : 3;
                multipleCards2.selectAnswer(selected);
                input_is_wrong = 0;
                multipleCards2.setHint("Press Enter to submit your answer and 1, 2 or 3 to select an answer.");
            }

            if (event.type == sf::Event::TextEntered)
            {
                if (test == 4)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionPopup_1.setInputAnswer(questionPopup_1.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (test == 5)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        mazePopup.setInputAnswer(mazePopup.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (test == 8)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionWordSearch_1.setInputAnswer(questionWordSearch_1.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (test == 9)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionWordSearch_2.setInputAnswer(questionWordSearch_2.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (test == 10)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionWordSearch_3.setInputAnswer(questionWordSearch_3.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (test == 11)
                {
                    if (event.text.unicode >= 32 && event.text.unicode <= 126)
                    {
                        questionWordSearch_4.setInputAnswer(questionWordSearch_4.getInputAnswer() + static_cast<char>(event.text.unicode));
                    }
                }
            }
        }

        if (elapsed1.asSeconds() > 20 * 60)
            test = -2;

        window.clear();
        switch (test)
        {
        case 2: // rules menu
        {
            window.draw(mainMenuBackgroundObj);
            window.draw(ArrowButton);
            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            text.setString("Guide:");
            text.setCharacterSize(40);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 150);
            window.draw(text);

            window.draw(Link1);
            window.draw(Link2);
            text.setString("\n\n- Follow the instructions for each question to solve the puzzles.\n- You have a time limit of 20 minutes.\n- Click the arrow in the upper left corner to return \nto the main menu.\n\n- Link to documentation:\nhttps://drive.google.com/file/d/1d6DwTIV_\nLtSjXWFPe7bejttgaXbjGDgt/view?usp=sharing\n\n- Link to Bioprocess Intelligent Control (Part 3):\nhttps://drive.google.com/file/d/1LoWLbg70tpKp\n38s76LcxKC7EWLAzOphT/view?usp=sharing");
            text.setCharacterSize(22);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 180);
            window.draw(text);
            break;
        }
        case 3: // credits
        {
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
            text.setString("This application was developed by the following students from\nUniversity POLITEHNICA Bucharest \nAutomatic Control & Computer Science Faculty \nwithin the Erasmus+ Project 2020-1-CZ01-KA226-HE-094408\n\nGrigore Iulia-Andreea, 323AC\nBonciu Alin, 323AC\nCodescu Elisabeta Maria, 322AC\nPurcaru Iulia-Mihaela, 323AC\nSerban Andrei, 323AC\nVirlan Adrian, 323AC\n\nTeachers: M. Caramihai & Daniel Chis");
            text.setCharacterSize(22);
            text.setPosition(1280 / 2 - text.getLocalBounds().width / 2, 230);
            window.draw(text);

            logoObj.setPosition(1000, 600);
            window.draw(logoObj);
            break;
        }
        case 4: // question 1
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionPopup_1);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 5: // question 2
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(mazePopup);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 6: // question 3
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(multipleAnswer);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 7: // question 4
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(multipleCards);
            window.draw(cardsObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 8: // question 5-1
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionWordSearch_1);
            window.draw(wordSearchObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 9: // question 5-2
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionWordSearch_2);
            window.draw(wordSearchObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }

        case 10: // question 5-3
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionWordSearch_3);
            window.draw(wordSearchObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 11: // question 5-4
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(questionWordSearch_4);
            window.draw(wordSearchObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 12: // question 6
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(multipleAnswer2);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case 13: // question 7
        {
            window.draw(backgroundObj);
            window.draw(ArrowButton);

            leftArrowObj.setPosition(0, 0);
            window.draw(leftArrowObj);

            window.draw(multipleCards2);
            window.draw(questionEightObj);

            window.draw(text);

            text.setFillColor(sf::Color::Magenta);
            text.setString(returnTime(int(elapsed1.asSeconds())));
            text.setCharacterSize(30);
            text.setPosition(1200, 20);
            window.draw(text);
            break;
        }
        case -1: // won the game
        {
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

            window.draw(ExitButton);
            break;
        }
        case -2: // lost the game
        {
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
            window.draw(ExitButton);
            break;
        }
        default: // main menu
        {
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
        }

        window.draw(AudioButton);
        if (sound_is_on == 1)
        {
            window.draw(audio_onObj);
        }
        else
        {
            window.draw(audio_offObj);
        }
        // draw cursor
        cursorObj.setPosition(poz_cursor_x, poz_cursor_y);
        cursorObj.setPosition(poz_cursor_x, poz_cursor_y);
        window.draw(cursorObj);
        // update display
        window.display();
    }

    return 0;
}
