#pragma once
#include <SFML/Graphics.hpp>

class Window {
 public:
  Window();
  bool isOpen() const;
  bool pollEvent(sf::Event& event);
  void clear();
  void close();
  void display();
  sf::RenderWindow window;
  sf::RenderWindow& getWindow();

 private:
  const int windowWidth = 690;
  const int windowHeight = 420;
  const char windowTitle[11] = "Calculator";
  const sf::Color windowFillColor = sf::Color::White;
};
