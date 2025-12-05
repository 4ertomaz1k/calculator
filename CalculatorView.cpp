#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // sf::VideoMode(width, height)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Black Screen SFML");
    //RenderWindow - create window
    //VideoMode - sets width and height window
    //Title of window - Black Screen SFML
    
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



        // 3. Visualizing

        window.display();//show users what is drawn
    }
    return 0;
}
