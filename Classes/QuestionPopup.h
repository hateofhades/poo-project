#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

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
    QuestionPopup(string question, string correctAnswer, sf::Font font);
    void setInputAnswer(string inputAnswer);
    string getInputAnswer();
    string getCorrectAnswer();
    void addPhoto(string photoPath);
    void changeBackgroundSize(int width, int height);
};