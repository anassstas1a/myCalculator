#pragma once
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Window.h"
class Buttons {
 public:
  Buttons(sf::Font& font);
  void drawButtons(Window& window);
  std::vector<Button>& operator[](std::size_t index);
  const std::vector<Button>& operator[](std::size_t index) const;
  int getNumberButtonsByHeight();
  int getNumberButtonsByWidth();

 private:
  void createCalculatorButtons();

  std::vector<std::vector<Button>> buttons;
  std::vector<std::vector<sf::Text>> buttonLabels;

  const int buttonWidth_ = 100;
  const int buttonHeight_ = 50;
  sf::Color buttonColor;
  const sf::Color buttonEqualColor = sf::Color(255, 160, 160);
  const sf::Color buttonDigitOrDotColor = sf::Color(233, 241, 254);
  const sf::Color buttonOperatorColor = sf::Color(216, 231, 255);

  sf::Font font;
  const int labelSize_ = 30;
  const sf::Color labelColor = sf::Color::Black;

  const int spacing = 10;
  const int leftMargin = 20;
  const int topMargin = 100;
  const int numberButtonsByHeight = 5;
  const int numberButtonsByWidth = 6;

  std::vector<std::vector<std::string>> buttonText = {
      {"p", "e", "!", "(", ")", "C"},
      {"sin", "ln", "7", "8", "9", "/"},
      {"cos", "log", "4", "5", "6", "*"},
      {"tan", "sqrt", "1", "2", "3", "-"},
      {"cot", "^", "0", ".", "=", "+"}};
};
