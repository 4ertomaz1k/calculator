#ifndef BUTTON_H//the first activation, BUTTON.H is not defined, the code inside the block is not executed
#define BUTTON_H//we define the BUTTON_H label, the processor knows that this file has already been processed.

#include "SFML/Graphics.hpp"
#include "RoundedRectangleShape.hpp"

#include <string>

class Button {
private:
    //main components of the button
    RoundedRectangleShape shape;
    RoundedRectangleShape shadowShape;
    sf::Text label;

public:
    // take arguments for customization the button
    Button(float width, float height, float radius, float x, float y, int r, int g, int b, int r_t, int g_t, int b_t, const std::string& text, const sf::Font& font);
    
    // draw the button
    void draw(sf::RenderWindow& window) const;
    //check if mouse clicked
    bool isClicked(const sf::Vector2f& mousePos) const;
    //get text on the display
    std::string getText() const;
};

#endif //Closes the conditional compilation block.