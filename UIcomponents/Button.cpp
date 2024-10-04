#include "Button.h"

#include <SFML/Graphics.hpp>

Button::Button() {}

void Button::createButton(const int buttonWidth, const int buttonHeight,
                          float buttonPositionX, float buttonPositionY,
                          sf::Color buttonColor, std::string& stringLabel,
                          sf::Font& font, int labelSize, sf::Color labelColor) {
  buttonShape_.setSize(sf::Vector2f(buttonWidth, buttonHeight));
  buttonShape_.setPosition(buttonPositionX, buttonPositionY);
  buttonShape_.setFillColor(buttonColor);

  stringLabel_ = stringLabel;
  buttonLabel_.setString(stringLabel);
  buttonLabel_.setFont(font);
  buttonLabel_.setCharacterSize(labelSize);
  buttonLabel_.setFillColor(labelColor);

  sf::FloatRect textRect = buttonLabel_.getLocalBounds();
  buttonLabel_.setOrigin(std::floor(textRect.left + textRect.width / 2.0f),
                         std::floor(textRect.top + textRect.height / 2.0f));
  buttonLabel_.setPosition(buttonShape_.getPosition().x + buttonWidth / 2.0f,
                           buttonShape_.getPosition().y + buttonHeight / 2.0f);
}

void Button::draw(Window& window) {
  window.getWindow().draw(buttonShape_);
  window.getWindow().draw(buttonLabel_);
}

bool Button::isClicked(sf::Vector2i mousePos, Window& window) {
  sf::Vector2f worldPos = window.getWindow().mapPixelToCoords(mousePos);
  return buttonShape_.getGlobalBounds().contains(worldPos);

  // return
  // buttonShape_.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

std::string Button::getLabel() const { return stringLabel_; }
