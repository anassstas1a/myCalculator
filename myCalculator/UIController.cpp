#include "UIController.h"

UIController::UIController(Calculator& calculator, Window& window,
                           Buttons& buttons, DisplayText& displayText)
    : calculator_(calculator),
      window_(window),
      buttons_(buttons),
      displayText_(displayText) {}

void UIController::handleEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      processButtonClick(event);
    }
  }
}

void UIController::processButtonClick(const sf::Event& event) {
  for (int i = 0; i < buttons_.getNumberButtonsByHeight(); ++i) {
    for (int j = 0; j < buttons_.getNumberButtonsByWidth(); ++j) {
      if (buttons_[i][j].isClicked(
              sf::Vector2i(event.mouseButton.x, event.mouseButton.y),
              window_)) {
        handleButtonAction(buttons_[i][j].getLabel());
      }
    }
  }
}

void UIController::handleButtonAction(std::string buttonLabel) {
  if (buttonLabel == "=") {
    calculator_.calculate();
    calculator_.clearExpression();
    calculator_.addSymbol(calculator_.getAnswer());
  } else if (buttonLabel == "C") {
    calculator_ = Calculator();
  } else {
    calculator_.addSymbol(buttonLabel);
  }
}

void UIController::updateDisplay() {
  displayText_.setString(calculator_.getDisplayText());
}

void UIController::render() {
  window_.clear();
  displayText_.drawDisplayText(window_);
  buttons_.drawButtons(window_);
  window_.display();
}
