#include "QuestionMultipleAnswers.h"

QuestionMultipleAnswers::QuestionMultipleAnswers(string question, int correctAnswer, sf::Font font, string answer1, string answer2, string answer3)
{
    this->font = font;

    this->question = question;
    this->correctAnswer = correctAnswer;
    this->answer1 = answer1;
    this->answer2 = answer2;
    this->answer3 = answer3;

    this->background.setSize(sf::Vector2f(550, 470));
    this->background.setPosition(1280 / 2 - this->background.getSize().x / 2, 720 / 2 - this->background.getSize().y / 2);
    this->background.setFillColor(sf::Color::Blue);

    this->questionTxt.setString(this->question);
    this->questionTxt.setCharacterSize(24);
    this->questionTxt.setFillColor(sf::Color::White);
    this->questionTxt.setStyle(sf::Text::Bold);
    this->questionTxt.setFont(this->font);
    // Put the question txt at the top of the background box
    this->questionTxt.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->questionTxt.getLocalBounds().width) / 2, this->background.getPosition().y + this->questionTxt.getLocalBounds().height);

    // Show possible answers and their checkboxes
    this->box1.setSize(sf::Vector2f(this->background.getSize().x / 2 - 100, this->background.getSize().y / 8));
    this->box1.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->box1.getSize().x) / 2, this->background.getPosition().y + 70 + this->questionTxt.getLocalBounds().height + this->box1.getSize().y + 10);
    this->box1.setFillColor(sf::Color::White);
    this->box1.setOutlineColor(sf::Color::Black);
    this->box1.setOutlineThickness(2);

    this->answer1Txt.setString(this->answer1);
    this->answer1Txt.setCharacterSize(24);
    this->answer1Txt.setFillColor(sf::Color::Black);
    this->answer1Txt.setStyle(sf::Text::Bold);
    this->answer1Txt.setFont(this->font);
    this->answer1Txt.setPosition(this->box1.getPosition().x + (this->box1.getSize().x - this->answer1Txt.getLocalBounds().width) / 2, this->box1.getPosition().y + (this->box1.getSize().y - this->answer1Txt.getLocalBounds().height) / 2);

    this->box2.setSize(sf::Vector2f(this->background.getSize().x / 2 - 100, this->background.getSize().y / 8));
    this->box2.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->box2.getSize().x) / 2, this->background.getPosition().y + 70 + this->questionTxt.getLocalBounds().height + 10 + this->box1.getSize().y + 10 + this->box2.getSize().y);
    this->box2.setFillColor(sf::Color::White);
    this->box2.setOutlineColor(sf::Color::Black);
    this->box2.setOutlineThickness(2);

    this->answer2Txt.setString(this->answer2);
    this->answer2Txt.setCharacterSize(24);
    this->answer2Txt.setFillColor(sf::Color::Black);
    this->answer2Txt.setStyle(sf::Text::Bold);
    this->answer2Txt.setFont(this->font);
    this->answer2Txt.setPosition(this->box2.getPosition().x + (this->box2.getSize().x - this->answer2Txt.getLocalBounds().width) / 2, this->box2.getPosition().y + (this->box2.getSize().y - this->answer2Txt.getLocalBounds().height) / 2);

    this->box3.setSize(sf::Vector2f(this->background.getSize().x / 2 - 100, this->background.getSize().y / 8));
    this->box3.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->box3.getSize().x) / 2, this->background.getPosition().y + 70 + this->questionTxt.getLocalBounds().height + 10 + this->box1.getSize().y + 10 + this->box2.getSize().y + 10 + this->box3.getSize().y);
    this->box3.setFillColor(sf::Color::White);
    this->box3.setOutlineColor(sf::Color::Black);
    this->box3.setOutlineThickness(2);

    this->answer3Txt.setString(this->answer3);
    this->answer3Txt.setCharacterSize(24);
    this->answer3Txt.setFillColor(sf::Color::Black);
    this->answer3Txt.setStyle(sf::Text::Bold);
    this->answer3Txt.setFont(this->font);
    this->answer3Txt.setPosition(this->box3.getPosition().x + (this->box3.getSize().x - this->answer3Txt.getLocalBounds().width) / 2, this->box3.getPosition().y + (this->box3.getSize().y - this->answer3Txt.getLocalBounds().height) / 2);

    this->hint.setString("Press Enter to submit your answer and 1, 2 or 3 to select an answer.");
    this->hint.setCharacterSize(12);
    this->hint.setFillColor(sf::Color::White);
    this->hint.setStyle(sf::Text::Bold);
    this->hint.setFont(this->font);
    this->hint.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->hint.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->hint.getLocalBounds().height - 10);

    this->selectAnswer(1);
};
void QuestionMultipleAnswers::ChangeColor(sf::Color color)
{
    this->background.setFillColor(color);
}
void QuestionMultipleAnswers::selectAnswer(int number)
{
    this->selectedAnswer = number;

    this->box1.setFillColor(sf::Color::White);
    this->box2.setFillColor(sf::Color::White);
    this->box3.setFillColor(sf::Color::White);

    if (number == 1)
        this->box1.setFillColor(sf::Color::Red);
    else if (number == 2)
        this->box2.setFillColor(sf::Color::Red);
    else
        this->box3.setFillColor(sf::Color::Red);
};

int QuestionMultipleAnswers::getSelected()
{
    return this->selectedAnswer;
};

void QuestionMultipleAnswers::setHint(string text)
{
    this->hint.setString(text);
    this->hint.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->hint.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->hint.getLocalBounds().height - 10);
};

string QuestionMultipleAnswers::getQuestion()
{
    return this->question;
};

string QuestionMultipleAnswers::getAnswer(int number)
{
    switch (number)
    {
    case 1:
        return this->answer1;
    case 2:
        return this->answer2;
    case 3:
        return this->answer3;
    default:
        return "";
    };
};

int QuestionMultipleAnswers::getCorrectAnswer()
{
    return this->correctAnswer;
};

void QuestionMultipleAnswers::setBackgroundSize(int width, int height)
{
    this->background.setSize(sf::Vector2f(width, height));
};

void QuestionMultipleAnswers::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->background);
    target.draw(this->box1);
    target.draw(this->box2);
    target.draw(this->box3);
    target.draw(this->questionTxt);
    target.draw(this->answer1Txt);
    target.draw(this->answer2Txt);
    target.draw(this->answer3Txt);
    target.draw(this->hint);
};