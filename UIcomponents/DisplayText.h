#pragma once
#include <SFML/Graphics.hpp>

#include "Window.h"
class DisplayText {
 public:
  DisplayText(sf::Font& font);
  void setString(const sf::String& string);
  void drawDisplayText(Window& window);
  std::string getString();

 private:
  sf::Text displayText;
  const int displayTextSize = 50;
  const sf::Color textFillColor = sf::Color::Black;
  const float displayTextPositionX = 20;
  const float displayTextPositionY = 20;
};
