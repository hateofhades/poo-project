#include <time.h>
#include <random>
#include "Maze.h"

using namespace std;

Maze::Maze(string question, string correctAnswer, sf::Font font) : QuestionPopup{question, correctAnswer, font}
{
    this->playerX = 0;
    this->playerY = 1;

    this->player.setSize(sf::Vector2f(10, 10));
    this->player.setFillColor(sf::Color::Red);

    this->addPhoto("./Sources/Images/maze.png");
    this->player.setPosition(this->photoSprite.getPosition().x + this->playerX * 10, this->photoSprite.getPosition().y + this->playerY * 10);

    underscore = string(this->correctAnswer.size(), '_');
    this->pressEnter.setString("Answer: " + underscore);
    this->pressEnter.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->pressEnter.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->pressEnter.getLocalBounds().height - 10);
};
void Maze::ChangeColor(sf::Color color)
{
    this->background.setFillColor(color);
}
void Maze::draw(sf::RenderTarget &target, sf::RenderStates states) const
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

    target.draw(this->player);
};

void Maze::movePlayer(int playerX, int playerY)
{
    this->playerY = playerY;
    this->playerX = playerX;

    this->player.setPosition(this->photoSprite.getPosition().x + this->playerX * 10, this->photoSprite.getPosition().y + this->playerY * 10);

    if (this->maze[playerY][playerX] == 2)
    {
        this->maze[playerY][playerX] = 0;
        this->hints++;

        srand(time(NULL));
        while (this->hints)
        {
            int randomIndex = rand() % this->correctAnswer.size();
            if (this->underscore[randomIndex] == '_')
            {
                this->underscore[randomIndex] = this->correctAnswer[randomIndex];
                this->hints--;
            }
        }

        this->pressEnter.setString("Answer: " + underscore);
        this->pressEnter.setPosition(this->background.getPosition().x + (this->background.getSize().x - this->pressEnter.getLocalBounds().width) / 2, this->background.getPosition().y + this->background.getSize().y - this->pressEnter.getLocalBounds().height - 10);
    }
    else if (this->maze[playerY][playerX] == 3)
    {
        this->player.setSize(sf::Vector2f(0, 0));
        this->photoSprite.setScale(0, 0);
    }
};

void Maze::moveUp()
{
    if (this->playerY > 0 && this->maze[playerY - 1][playerX] != 1)
        this->movePlayer(playerX, playerY - 1);
};

void Maze::moveDown()
{
    if (this->playerY < 26 && this->maze[playerY + 1][playerX] != 1)
        this->movePlayer(playerX, playerY + 1);
};

void Maze::moveLeft()
{
    if (this->playerX > 0 && this->maze[playerY][playerX - 1] != 1)
        this->movePlayer(playerX - 1, playerY);
};

void Maze::moveRight()
{
    if (this->playerX < 26 && this->maze[playerY][playerX + 1] != 1)
        this->movePlayer(playerX + 1, playerY);
};