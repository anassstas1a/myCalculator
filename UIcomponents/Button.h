#pragma once
#include <SFML/Graphics.hpp>

#include "Window.h"

class Button {
 public:
  Button();
  void createButton(const int buttonWidth, const int buttonHeight,
                    float buttonPositionX, float buttonPositionY,
                    sf::Color buttonColor, std::string& stringLabel,
                    sf::Font& font, int labelSize, sf::Color labelColor);
  void draw(Window& window);
  bool isClicked(sf::Vector2i mousePos, Window& window);
  std::string getLabel() const;

 private:
  sf::RectangleShape buttonShape_;
  sf::Text buttonLabel_;
  std::string stringLabel_;
};
