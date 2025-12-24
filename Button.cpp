#include "Button.hpp"
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
        if (width > 300)
        {
            label.setCharacterSize(52);//for displayText
        }
        if (text.length() >= 11)
        {
            label.setCharacterSize(38);//for big numbers
        }
        if (text.find("not") != std::string::npos)//for division by 0 and 0/0
        {
            label.setCharacterSize(22);  
        }
        label.setFillColor(sf::Color(r_t, g_t, b_t));
        
    // shadow properties
     if (width != 345)
     {
        shadowShape.setSize(sf::Vector2f(width, height));
        shadowShape.setPosition(sf::Vector2f(x, y + 5));
        shadowShape.setFillColor(sf::Color(r*0.65, g*0.65, b*0.65));
        shadowShape.setCornersRadius(radius); 
        shadowShape.setCornerPointCount(20);
     }

    //Centering text on button
        sf::FloatRect textBounds = label.getLocalBounds(); //getLocalBounds() return a rectangle that covers the entire text.
    
        // Centering text relative to itself
            label.setOrigin//the center of the rectangle that describes the text.
            (sf::Vector2f
                (
                textBounds.position.x + textBounds.size.x / 2.0f,//textBounds.position.x - X is the coordinate of the left edge of the text  | textBounds.position.y - Y is the coordinate of the top edge of the text
                textBounds.position.y + textBounds.size.y / 2.0f//textBounds.size.x - text width (in pixels) | textBounds.size.y - text height (in pixels)
                )
            );

        //Calculating the center of the button
            float buttonCenterX = shape.getPosition().x + shape.getSize().x / 2.0f;
            float buttonCenterY = shape.getPosition().y + shape.getSize().y / 2.0f;

         //Positioning text center at button center
            label.setPosition(sf::Vector2f(buttonCenterX, buttonCenterY));
    
}

// draw the button
void Button::draw(sf::RenderWindow& window) const 
{
    window.draw(shadowShape);
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(const sf::Vector2f& mousePos) const
{
    //Create a rectangle for the button's borders
    sf::FloatRect bounds{shape.getPosition(), shape.getSize()};//Floatrect - 4s dimensional array gets 2 2s dimensional array(position and size)
    return bounds.contains(mousePos);//bounds(our button) is it in mouspose(in mouse pose) - true/false
}

std::string Button::getText() const
{
    return label.getString();//get text
}