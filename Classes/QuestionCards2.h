#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class QuestionCards2 : public sf::Drawable
{
private:
    sf::RectangleShape background, box1, box2, box3;
    sf::Text questionTxt, answer1Txt, answer2Txt, answer3Txt;
    sf::Text hint;
    sf::Font font;
    sf::Sprite image;
    string question;
    int correctAnswer, selectedAnswer = -1;
    string answer1, answer2, answer3;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    QuestionCards2(string question, int correctAnswer, sf::Font font, sf::Sprite image, string answer1, string answer2, string answer3);
    string getQuestion();
    string getAnswer(int number);
    int getCorrectAnswer();
    void setBackgroundSize(int width, int height);
    void selectAnswer(int number);
    void setHint(string text);
    int getSelected();
};