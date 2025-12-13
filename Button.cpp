#include "Button.h"
#include <iostream>
#include <filesystem>

// take arguments for customization the button
Button::Button(float width, float height, float radius, float x, float y, int r, int g, int b, int r_t, int g_t, int b_t, const std::string& text, const sf::Font& font): label(font)
{
    //rectangle properties
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(sf::Color(r, g, b));
        shape.setCornersRadius(radius); 
        shape.setCornerPointCount(20);

    //text properties
        label.setString(text);
        label.setCharacterSize(45);       
        label.setFillColor(sf::Color(r_t, g_t, b_t));
        
    // shadow properties
        shadowShape.setSize(sf::Vector2f(width, height));
        shadowShape.setPosition(sf::Vector2f(x, y + 5));
        shadowShape.setFillColor(sf::Color(r*0.65, g*0.65, b*0.65));
        shadowShape.setCornersRadius(radius); 
        shadowShape.setCornerPointCount(20);


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
    window.draw(shadowShape);
    window.draw(shape);
    window.draw(label);
}