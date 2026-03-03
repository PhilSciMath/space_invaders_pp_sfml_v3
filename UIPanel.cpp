#include "UIPanel.hpp"


UIPanel::UIPanel(sf::Vector2i resolution, int x, int y, float width,
    float height, int alpha, int red, int green, int blue) :
    font("fonts/pixeldroidMenuRegular.otf"),
    text(font)
{
    // UI panel color
    ui_panel.setFillColor(sf::Color(red, green, blue, alpha));

    // Size in pixels of UI panel
    ui_panel.setSize({width, height});

    // Size in pixels of the view
    view.setSize({width, height});

    // Center the view around the panel
    view.setCenter({width / 2.0f, height / 2.0f});

    // Position of the view in the window relative to the resolution
    sf::Vector2f res = static_cast<sf::Vector2f>(resolution);
    view.setViewport(sf::FloatRect({1.f / (res.x / x), 1.f / (res.y / y)},
        {1.f / (res.x / width), 1.f / (res.y / height)}));
}

std::vector<std::shared_ptr<Button>> UIPanel::get_buttons() {
    return buttons;
}

void UIPanel::add_button(float x, float y, int width, int height,
    int red, int green, int blue, std::string label) {

    buttons.push_back(std::make_shared<Button>(sf::Vector2f({x, y}),
        width, height, red, green, blue, label));
}

void UIPanel::draw(sf::RenderWindow& window) {

    window.setView(view);

    if (!hidden) {
        window.draw(ui_panel);
        for (auto it = buttons.begin(); it != buttons.end(); it++) {
            (*it)->draw(window);
        }
    }
}

void UIPanel::show() {
    hidden = false;
}

void UIPanel::hide() {
    hidden = true;
}
