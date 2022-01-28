#include "QuestionPopup.h"

using namespace std;

QuestionPopup::QuestionPopup(string question, string correctAnswer, sf::Font font)
{
    this->hasPhoto = 0;
    this->font = font;
    this->correctAnswer = correctAnswer;

    this->background.setSize(sf::Vector2f(550, 470));
    this->background.setPosition(1280 / 2 - this->background.getSize().x / 2, 720 / 2 - this->background.getSize().y / 2);
    this->background.setFillColor(sf::Color{36, 171, 72, 165});
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

void QuestionPopup::setInputAnswer(string inputAnswer)
{
    this->inputAnswer.setString(inputAnswer);
    this->inputAnswer.setPosition(this->input.getPosition().x + (this->input.getSize().x - this->inputAnswer.getLocalBounds().width) / 2, this->input.getPosition().y + (this->input.getSize().y - this->inputAnswer.getLocalBounds().height) / 2);
}

string QuestionPopup::getInputAnswer()
{
    return this->inputAnswer.getString();
}

string QuestionPopup::getCorrectAnswer()
{
    return this->correctAnswer;
}

void QuestionPopup::addPhoto(string photoPath)
{
    this->hasPhoto = 1;
    this->photo.loadFromFile(photoPath);
    this->photoSprite.setTexture(this->photo);
    this->photoSprite.setPosition(this->background.getPosition().x + this->background.getSize().x / 2 - this->photoSprite.getGlobalBounds().width / 2, this->input.getPosition().y + this->input.getSize().y + 10);
}

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

void QuestionPopup::changeBackgroundSize(int width, int height)
{
    this->background.setSize(sf::Vector2f(width, height));
}