#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>

//g++ CalculatorView.cpp -o Calculator.exe -I"C:\SFML-3.0.2\include" -L"C:\SFML-3.0.2\lib" -lsfml-graphics -lsfml-window -lsfml-system
int main()
{
    // sf::VideoMode(width, height)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Black Screen SFML");
    //RenderWindow - create window
    //VideoMode - sets width and height window
    //Title of window - Black Screen SFML
    
    //font
    sf::Font font;
    if (!font.openFromFile(std::filesystem::path("arimo.ttf")))
    { 
        std::cerr << "Error: Font not found or incorrect file name!" << std::endl;
        return -1; 
    }

    // create text
    sf::Text text(font);
    text.setString("0");
    text.setCharacterSize(40);       
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(35.f, 130.f));


    //Сreate button(rectangle)
    sf::RectangleShape button;
    //set size: 80x80 pix
    button.setSize(sf::Vector2f(80.f, 80.f));//Vector2f - a two-dimensional vector with coordinates of the float type
    // set position: indent 20px from the left edge and 120px from the top(below the display)
    button.setPosition(sf::Vector2f(20.f, 120.f));
    //set color by rgb palette
    button.setFillColor(sf::Color(60, 60, 60));





    //Game loop - cycle need to every visual program for constant updating of the screen
    while (window.isOpen()) // general cycle: while not close
    {
        // 1. event processing (closing the window, mouse clicks)

        //Reading all event(clicks, input, closing)
        while (const std::optional event = window.pollEvent())//window.pollEvent - input processing(mouse clicks, pressing the buttons, moving the mouse, clicking on the cross)
        {//pollEvent() - returns an event wrapped in std::optional(it means or you have event(users move) or not)
            
            //If an event exists, we check its type.
            if (event->is<sf::Event::Closed>())//sf::Event::Closed - clicking on the cross. And if it is we do window.close
            {
                window.close();// Close the window and out of cycle
            }
        }


        // 2. Drawing
        
        window.clear(sf::Color::Black);//clear the screen by the black color
        //draw some stuff...
        window.draw(button);
        window.draw(text);


        // 3. Visualizing

        window.display();//show users what is drawn
    }
    return 0;
}
