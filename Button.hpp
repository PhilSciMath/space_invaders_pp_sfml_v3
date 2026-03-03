#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


class Button {

private:

    sf::RectangleShape button;
    sf::Text button_txt;
    sf::Font font;

public:

    std::string text;
    sf::FloatRect collider;

    Button(sf::Vector2f position, float width, float height, int red,
           int green, int blue, std::string text);

    void draw(sf::RenderWindow& window);
};
