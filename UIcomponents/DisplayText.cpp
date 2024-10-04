#include "DisplayText.h"

DisplayText::DisplayText(sf::Font& font) {
  displayText.setFont(font);
  displayText.setString("");
  displayText.setCharacterSize(displayTextSize);
  displayText.setFillColor(textFillColor);
  displayText.setPosition(displayTextPositionX, displayTextPositionY);
}

void DisplayText::setString(const sf::String& string) {
  displayText.setString(string);
}
void DisplayText::drawDisplayText(Window& window) {
  window.getWindow().draw(displayText);
}
std::string DisplayText::getString() { return displayText.getString(); }
