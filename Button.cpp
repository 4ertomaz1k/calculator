#include "Button.h"
#include <iostream>
#include <filesystem>

// take arguments for customization the button
Button::Button(float width, float height, float x, float y, int r, int g, int b, const std::string& text, const sf::Font& font): label(font)
{
    //rectangle properties
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(sf::Color(r, g, b));

    //text properties
        label.setString(text);
        label.setCharacterSize(30);       
        label.setFillColor(sf::Color::White);


    //Centering text on button
        sf::FloatRect textBounds =  label.getLocalBounds(); //getLocalBounds() return a rectangle that covers the entire text.
    
        // Centering text relative to itself
            label.setOrigin(sf::Vector2f(
                textBounds.position.x + textBounds.size.x / 2.0f,//textBounds.position.x - X is the coordinate of the left edge of the text  | textBounds.position.y - Y is the coordinate of the top edge of the text
                textBounds.position.y + textBounds.size.y / 2.0f//textBounds.size.x - text width (in pixels) | textBounds.size.y - text height (in pixels)
            ));

        // Position text center at button center
            float buttonCenterX = shape.getPosition().x + shape.getSize().x / 2.0f;
            float buttonCenterY = shape.getPosition().y + shape.getSize().y / 2.0f;
            label.setPosition(sf::Vector2f(buttonCenterX, buttonCenterY));
    
}

// draw the button
void Button::draw(sf::RenderWindow& window) const 
{
    window.draw(shape);
    window.draw(label);
}