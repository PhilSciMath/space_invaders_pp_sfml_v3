#include "Button.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


Button::Button(sf::Vector2f position, float width, float height, int red,
               int green, int blue, std::string text) :
    font("fonts/pixeldroidMenuRegular.otf"),
    button_txt(font)
{
    button.setPosition(position);
    button.setFillColor(sf::Color(red, green, blue));
    button.setSize({width, height});

    text = "" + text;

    float text_padding_x = width / 10.f;
    float text_padding_y = height / 10.f;
    button_txt.setCharacterSize(height * .7f);
    button_txt.setString(text);
    button_txt.setPosition({position.x + text_padding_x,
        position.y + text_padding_y});

    collider = sf::FloatRect({position}, {width, height});
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(button_txt);
}
