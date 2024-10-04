#include <SFML/Graphics.hpp>
#include <sstream>

#include "Buttons.h"
#include "Calculator.h"
#include "DisplayText.h"
#include "Separator.h"
#include "UIController.h"
#include "Window.h"
#include "test.h"

int main() {
  TestsRunner test;
  test.runTests();

  sf::Font font;
  if (!font.loadFromFile("../resources/ofont.ru_Times_New_Roman.ttf")) {
    return -1;
  }
  Calculator calculator;
  Window window;
  Buttons buttons(font);
  DisplayText displayText(font);

  UIController uiController(calculator, window, buttons, displayText);
  while (window.isOpen()) {
    uiController.handleEvents();
    uiController.updateDisplay();
    uiController.render();
  }
  return 0;
}

/*
const int windowWidth = 690;
const int windowHeight = 420;
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight),
                        "Calculator");

sf::Font font;
if (!font.loadFromFile("../resources/ofont.ru_Times_New_Roman.ttf")) {
  return -1;
}
const int displayTextSize = 50;
sf::Text displayText("", font, displayTextSize);
displayText.setPosition(20, 20);
displayText.setFillColor(sf::Color::Black);

const int buttonWidth = 100;
const int buttonHeight = 50;
const int spacing = 10;
const int leftMargin = 20;
const int topMargin = 100;
const int numberButtonsByHeight = 5;
const int numberButtonsByWidth = 6;
const int buttonLabelSize = 30;

std::vector<std::vector<sf::RectangleShape>> buttons(
    numberButtonsByHeight,
std::vector<sf::RectangleShape>(numberButtonsByWidth));

std::vector<std::vector<std::string>> buttonText = {
    {"p", "e", "!", "(", ")", "C"},
    {"sin", "ln", "7", "8", "9", "/"},
    {"cos", "log", "4", "5", "6", "*"},
    {"tan", "sqrt", "1", "2", "3", "-"},
    {"cot", "^", "0", ".", "=", "+"}};

std::vector<std::vector<sf::Text>> buttonLabels(
    numberButtonsByHeight, std::vector<sf::Text>(numberButtonsByWidth));

for (int i = 0; i < numberButtonsByHeight; ++i) {
  for (int j = 0; j < numberButtonsByWidth; ++j) {
    buttons[i][j].setSize(sf::Vector2f(buttonWidth, buttonHeight));
    if (buttonText[i][j] == "=") {
      buttons[i][j].setFillColor(sf::Color(255, 160, 160));
    } else if (isdigit(buttonText[i][j][0]) || buttonText[i][j] == ".") {
      buttons[i][j].setFillColor(sf::Color(233, 241, 254));
    } else {
      buttons[i][j].setFillColor(sf::Color(216, 231, 255));
    }

    buttons[i][j].setPosition(leftMargin + j * (buttonWidth + spacing),
                              topMargin + i * (buttonHeight + spacing));

    buttonLabels[i][j].setFont(font);
    buttonLabels[i][j].setString(buttonText[i][j]);
    buttonLabels[i][j].setCharacterSize(buttonLabelSize);
    buttonLabels[i][j].setFillColor(sf::Color::Black);

    sf::FloatRect textRect = buttonLabels[i][j].getLocalBounds();

    buttonLabels[i][j].setOrigin(
        std::floor(textRect.left + textRect.width / 2.0f),
        std::floor(textRect.top + textRect.height / 2.0f));

    buttonLabels[i][j].setPosition(
        buttons[i][j].getPosition().x + buttonWidth / 2.0f,
        buttons[i][j].getPosition().y + buttonHeight / 2.0f);
  }
}

while (window.isOpen()) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
      for (int i = 0; i < numberButtonsByHeight; ++i) {
        for (int j = 0; j < numberButtonsByWidth; ++j) {
          if (buttons[i][j].getGlobalBounds().contains(event.mouseButton.x,
                                                       event.mouseButton.y)) {
            std::string btn = buttonText[i][j];
            if (btn == "=") {
              calculator.calculate();
              calculator.clearExpression();
              calculator.addSymbol(calculator.getAnswer());
            } else if (btn == "C") {
              calculator = Calculator();
            } else {
              calculator.addSymbol(btn);
            }
          }
        }
      }
    }
  }

  displayText.setString(calculator.getDisplayText());

  window.clear(sf::Color::White);

  window.draw(displayText);

  for (int i = 0; i < numberButtonsByHeight; ++i) {
    for (int j = 0; j < numberButtonsByWidth; ++j) {
      window.draw(buttons[i][j]);
      window.draw(buttonLabels[i][j]);
    }
  }
  window.display();
}
return 0;
}
*/

/*#include <SFML/Graphics.hpp>
#include <sstream>

#include "Buttons.h"
#include "Calculator.h"
#include "DisplayText.h"
#include "Separator.h"
#include "Window.h"
#include "test.h"

int main() {
  TestsRunner test;
  test.runTests();

  Calculator calculator;

  sf::Font font;
  if (!font.loadFromFile("../resources/ofont.ru_Times_New_Roman.ttf")) {
    return -1;
  }

  Window window;
  DisplayText displayText(font);
  Buttons buttons(font);
  const int numberButtonsByHeight = buttons.getNumberButtonsByHeight();
  const int numberButtonsByWidth = buttons.getNumberButtonsByWidth();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i < numberButtonsByHeight; ++i) {
          for (int j = 0; j < numberButtonsByWidth; ++j) {
            if (buttons[i][j].isClicked(
                    sf::Vector2i(event.mouseButton.x, event.mouseButton.y),
                    window)) {
              std::string btn = buttons[i][j].getLabel();
              if (btn == "=") {
                calculator.calculate();
                calculator.clearExpression();
                calculator.addSymbol(calculator.getAnswer());
              } else if (btn == "C") {
                calculator = Calculator();
              } else {
                calculator.addSymbol(btn);
              }
            }
          }
        }
      }
    }
    window.clear();
    displayText.setString(calculator.getDisplayText());
    displayText.drawDisplayText(window);
    buttons.drawButtons(window);
    window.display();
  }
  return 0;
}*/
