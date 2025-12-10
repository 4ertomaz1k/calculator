#ifndef BUTTON_H//the first activation, BUTTON.H is not defined, the code inside the block is not executed
#define BUTTON_H//we define the BUTTON_H label, the processor knows that this file has already been processed.

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    //main components of the button
    sf::RectangleShape shape;
    sf::Text label;

public:
    // take arguments for customization the button
    Button(float width, float height, float x, float y, int r, int g, int b, const std::string& text, const sf::Font& font);
    
    // draw the button
    void draw(sf::RenderWindow& window) const;
};

#endif //Closes the conditional compilation block.