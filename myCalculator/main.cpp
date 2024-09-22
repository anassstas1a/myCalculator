#include <SFML/Graphics.hpp>
#include <sstream>

#include "Calculator.h"
#include "Separator.h"
#include "test.h"
int main() {
  // std::string string;
  // getline(std::cin, string);
  // Calculator someExpression(string);
  // std::cout << someExpression.calculate() << '\n';
  TestsRunner test;
  test.runTests();

  Calculator calculator;

  sf::RenderWindow window(sf::VideoMode(690, 420), "Calculator");
  sf::Font font;
  if (!font.loadFromFile("../resources/ofont.ru_Times_New_Roman.ttf")) {
    return -1;
  }

  sf::RectangleShape displayRectangle(sf::Vector2f(650.f, 75.f));
  displayRectangle.setPosition(20, 20);
  displayRectangle.setOutlineColor(sf::Color(0, 0, 0));

  sf::Text displayText("", font, 50);
  displayText.setPosition(20, 20);
  displayText.setFillColor(sf::Color::Black);

  const int buttonWidth = 100;
  const int buttonHeight = 50;
  const int spacing = 10;
  const int leftMargin = 20;
  const int topMargin = 100;

  std::vector<std::vector<sf::RectangleShape>> buttons(
      5, std::vector<sf::RectangleShape>(6));
  std::string buttonText[5][6] = {{"p", "e", "!", "(", ")", "C"},
                                  {"sin", "ln", "7", "8", "9", "/"},
                                  {"cos", "log", "4", "5", "6", "*"},
                                  {"tan", "sqrt", "1", "2", "3", "-"},
                                  {"cot", "^", "0", ".", "=", "+"}};

  std::vector<std::vector<sf::Text>> buttonLabels(5, std::vector<sf::Text>(6));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      buttons[i][j].setSize(sf::Vector2f(buttonWidth, buttonHeight));
      if (buttonText[i][j] == "=") {
        buttons[i][j].setFillColor(sf::Color(255, 160, 160));
      } else if (buttonText[i][j] == "0" || buttonText[i][j] == "1" ||
                 buttonText[i][j] == "2" || buttonText[i][j] == "3" ||
                 buttonText[i][j] == "4" || buttonText[i][j] == "5" ||
                 buttonText[i][j] == "6" || buttonText[i][j] == "7" ||
                 buttonText[i][j] == "8" || buttonText[i][j] == "9" ||
                 buttonText[i][j] == ".") {
        buttons[i][j].setFillColor(sf::Color(233, 241, 254));
      } else {
        buttons[i][j].setFillColor(sf::Color(216, 231, 255));
      }

      buttons[i][j].setPosition(leftMargin + j * (buttonWidth + spacing),
                                topMargin + i * (buttonHeight + spacing));

      buttonLabels[i][j].setFont(font);
      buttonLabels[i][j].setString(buttonText[i][j]);
      buttonLabels[i][j].setCharacterSize(30);
      buttonLabels[i][j].setFillColor(sf::Color::Black);
      buttonLabels[i][j].setPosition(33 + j * 110, 116 + i * 60);

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
        for (int i = 0; i < 5; ++i) {
          for (int j = 0; j < 6; ++j) {
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

    window.draw(displayRectangle);
    window.draw(displayText);

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 6; ++j) {
        window.draw(buttons[i][j]);
        window.draw(buttonLabels[i][j]);
      }
    }

    window.display();
  }
  return 0;
}
