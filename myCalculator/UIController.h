#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "Buttons.h"
#include "Calculator.h"
#include "DisplayText.h"
#include "Window.h"
class UIController {
 public:
  UIController(Calculator& calculator, Window& window, Buttons& buttons,
               DisplayText& displayText);
  void handleEvents();
  void updateDisplay();
  void render();

 private:
  Calculator calculator_;
  Window& window_;
  Buttons buttons_;
  DisplayText displayText_;
  void processButtonClick(const sf::Event& event);
  void handleButtonAction(std::string buttonLabel);
};
