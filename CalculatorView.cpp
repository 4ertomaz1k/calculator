#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>

//g++ CalculatorView.cpp -o Calculator.exe -I"C:\SFML-3.0.2\include" -L"C:\SFML-3.0.2\lib" -lsfml-graphics -lsfml-window -lsfml-system
int main()
{
    // Create the main window
        sf::RenderWindow window(sf::VideoMode({800, 600}), "Black Screen SFML");

    
    //create font
        const sf::Font font("arimo.ttf");//load font


    //create text
        sf::Text text(font);
        text.setString("0");
        text.setCharacterSize(40);       
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(35.f, 130.f));


    //Сreate button(rectangle)
        sf::RectangleShape button;

        button.setSize(sf::Vector2f(80.f, 80.f));//set size: 80x80 pix - Vector2f - a two-dimensional vector with coordinates of the float type
        button.setPosition(sf::Vector2f(420.f, 120.f));//x, y - set position: indent 20px from the left edge and 120px from the top(below the display)
        button.setFillColor(sf::Color(60, 60, 60));//set color by rgb palette


    //Centering text on button
        sf::FloatRect textBounds = text.getLocalBounds(); //getLocalBounds() return a rectangle that covers the entire text.
        
        // Centering text relative to itself
        text.setOrigin(sf::Vector2f(
            textBounds.position.x + textBounds.size.x / 2.0f,//textBounds.position.x - X is the coordinate of the left edge of the text  | textBounds.position.y - Y is the coordinate of the top edge of the text
            textBounds.position.y + textBounds.size.y / 2.0f//textBounds.size.x - text width (in pixels) | textBounds.size.y - text height (in pixels)
        ));

        // Position text center at button center
        float buttonCenterX = button.getPosition().x + button.getSize().x / 2.0f;
        float buttonCenterY = button.getPosition().y + button.getSize().y / 2.0f;
        text.setPosition(sf::Vector2f(buttonCenterX, buttonCenterY));



    //Game loop - cycle need to every visual program for constant updating of the screen
        while (window.isOpen()) // general cycle: while not close
        {

            //1. Event processing - reading all event(clicks, input, closing)
                while (const std::optional event = window.pollEvent())//window.pollEvent - input processing, returns an event wrapped in std::optional(it means or you have event(users move) or not)
                {
                    //If an event exists, we check its type.
                    if (event->is<sf::Event::Closed>())//sf::Event::Closed - clicking on the cross. And if it is we do window.close
                    {
                        window.close();// Close the window and out of cycle
                    }
                }


            // 2. Drawing
                window.clear(sf::Color::Black);//clear the screen by the black color
                window.draw(button);
                window.draw(text);


            // 3. Visualizing
                window.display();//show users what is drawn
        }


    return 0;
}
