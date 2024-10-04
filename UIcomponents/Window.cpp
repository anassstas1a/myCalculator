#include "Window.h"

Window::Window() {
  window.create(sf::VideoMode(windowWidth, windowHeight), "Calculator");
}

bool Window::isOpen() const { return window.isOpen(); }
bool Window::pollEvent(sf::Event& event) { return window.pollEvent(event); }
void Window::clear() { window.clear(windowFillColor); }
void Window::close() { window.close(); }
void Window::display() { window.display(); }
sf::RenderWindow& Window::getWindow() { return window; }
