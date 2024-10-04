#include "Buttons.h"

Buttons::Buttons(sf::Font& font) : font(font) {
  buttons.resize(numberButtonsByHeight,
                 std::vector<Button>(numberButtonsByWidth));
  buttonLabels.resize(numberButtonsByHeight,
                      std::vector<sf::Text>(numberButtonsByWidth));
  createCalculatorButtons();
}

void Buttons::createCalculatorButtons() {
  for (int i = 0; i < numberButtonsByHeight; ++i) {
    std::vector<Button> row;
    for (int j = 0; j < numberButtonsByWidth; ++j) {
      if (buttonText[i][j] == "=") {
        buttonColor = buttonEqualColor;
      } else if (isdigit(buttonText[i][j][0]) || buttonText[i][j] == ".") {
        buttonColor = buttonDigitOrDotColor;
      } else {
        buttonColor = buttonOperatorColor;
      }

      float positionX = leftMargin + j * (buttonWidth_ + spacing);
      float positionY = topMargin + i * (buttonHeight_ + spacing);

      buttons[i][j].createButton(buttonWidth_, buttonHeight_, positionX,
                                 positionY, buttonColor, buttonText[i][j], font,
                                 labelSize_, labelColor);
    }
  }
}

void Buttons::drawButtons(Window& window) {
  for (int i = 0; i < numberButtonsByHeight; ++i) {
    for (int j = 0; j < numberButtonsByWidth; ++j) {
      buttons[i][j].draw(window);
    }
  }
}

std::vector<Button>& Buttons::operator[](std::size_t index) {
  return buttons[index];
}

const std::vector<Button>& Buttons::operator[](std::size_t index) const {
  return buttons[index];
}

int Buttons::getNumberButtonsByHeight() { return numberButtonsByHeight; }
int Buttons::getNumberButtonsByWidth() { return numberButtonsByWidth; }
