#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Button.hpp"


class UIPanel {

private:
    sf::RectangleShape ui_panel;
    bool hidden = false;
    std::vector<std::shared_ptr<Button>> buttons;

protected:
    float button_width = 0;
    float button_height = 0;
    float button_padding = 0;

    sf::Font font;
    sf::Text text;

    void add_button(float x, float y, int width, int height, int red,
                    int green, int blue, std::string label);

public:
    sf::View view;

    UIPanel(sf::Vector2i resolution, int x, int y, float width, float height,
            int alpha, int red, int green, int blue);

    std::vector<std::shared_ptr<Button>> get_buttons();
    virtual void draw(sf::RenderWindow& window);
    void show();
    void hide();
};
