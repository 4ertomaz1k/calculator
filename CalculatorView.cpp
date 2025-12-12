#include "Button.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>

//g++ CalculatorView.cpp Button.cpp -o Calculator.exe -I"C:\SFML-3.0.2\include" -L"C:\SFML-3.0.2\lib" -lsfml-graphics -lsfml-window -lsfml-system
int main()
{

    // Creating a context settings object
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; //8x anti-aliasing
        
    // Creating the main window by passing the settings
    sf::RenderWindow window(
        sf::VideoMode({375, 500}), 
        "Calculator", 
        sf::State::Windowed, // We use the default style.
        settings            // Passing the anti-aliasing settings
    );

    //Create font
        const sf::Font font("arimo.ttf");//load font

    //Сreate buttons(rectangle)
        Button button_0(255, 63.3, 10, 15, 407.36, 226, 226, 218, 0, 0, 0, "0", font);
        Button button_1(75, 63.3, 10, 15+255+15, 407.36, 226, 226, 218, 0, 0, 0, "1", font);

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
                button_0.draw(window);
                button_1.draw(window);

            // 3. Visualizing
                window.display();//show users what is drawn
        }

    return 0;
}
