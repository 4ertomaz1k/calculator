#include "Button.h"
#include "CalculatorModel.h"
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

    //Create buttons
        Button button_0     (255, 63.3, 10, 15, 422.36, 226, 226, 218, 0, 0, 0, "0", font);
        Button button_equals(75, 63.3, 10, 285, 422.36, 84, 84, 82, 255, 255, 255, "=", font);

        Button button_1(75, 63.3, 10, 15, 346.42, 226, 226, 218, 0, 0, 0, "1", font);
        Button button_2(75, 63.3, 10, 15+((75+15)*1), 346.42, 226, 226, 218, 0, 0, 0, "2", font);
        Button button_3(75, 63.3, 10, 15+((75+15)*2), 346.42, 226, 226, 218, 0, 0, 0, "3", font);
        Button button_plus(75, 63.3, 10, 15+((75+15)*3), 346.42, 84, 84, 82, 255, 255, 255, "+", font);

        Button button_4(75, 63.3, 10, 15, 346.42-(75.94*1), 226, 226, 218, 0, 0, 0, "4", font);
        Button button_5(75, 63.3, 10, 15+((75+15)*1), 346.42-(75.94*1), 226, 226, 218, 0, 0, 0, "5", font);
        Button button_6(75, 63.3, 10, 15+((75+15)*2), 346.42-(75.94*1), 226, 226, 218, 0, 0, 0, "6", font);
        Button button_minus(75, 63.3, 10, 15+((75+15)*3), 346.42-(75.94*1), 84, 84, 82, 255, 255, 255, "-", font);
           
        Button button_7(75, 63.3, 10, 15, 346.42-(75.94*2), 226, 226, 218, 0, 0, 0, "7", font);
        Button button_8(75, 63.3, 10, 15+((75+15)*1), 346.42-(75.94*2), 226, 226, 218, 0, 0, 0, "8", font);
        Button button_9(75, 63.3, 10, 15+((75+15)*2), 346.42-(75.94*2), 226, 226, 218, 0, 0, 0, "9", font);
        Button button_multiply(75, 63.3, 10, 15+((75+15)*3), 346.42-(75.94*2), 84, 84, 82, 255, 255, 255, "*", font);

        Button button_clear_all(75, 63.3, 10, 15, 346.42-(75.94*3), 49, 48, 46, 255, 255, 255, "C", font);
        Button button_clear_last_symdol(75, 63.3, 10, 15+((75+15)*1), 346.42-(75.94*3), 49, 48, 46, 255, 255, 255, ">", font);
        Button button_point(75, 63.3, 10, 15+((75+15)*2), 346.42-(75.94*3), 84, 84, 82, 255, 255, 255, ".", font);
        Button button_division(75, 63.3, 10, 15+((75+15)*3), 346.42-(75.94*3), 84, 84, 82, 255, 255, 255, "/", font);

        //array for reading buttons from screens
            Button* buttons[] = 
            {
            &button_0, &button_1, &button_2, &button_3, 
            &button_4, &button_5, &button_6, &button_7, 
            &button_8, &button_9, &button_plus, &button_minus,
            &button_multiply, &button_division, &button_point,
            &button_equals, &button_clear_all, &button_clear_last_symdol
            };

        //for display button
            std::string displayText = "0";

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

            //if Mouse Button Pressed
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();//get info about clicked(where, what pressed) ; auto = sf::Event::MouseButtonPressed*; getIf - return pointer to ivent
                if (mouseEvent->button == sf::Mouse::Button::Left)//if mouse hit button
                {
                    sf::Vector2f mousePos(mouseEvent->position.x, mouseEvent->position.y);//get coordination of click
                    
                    // check all buttons
                    for (Button* btn : buttons)
                    {
                        if (btn->isClicked(mousePos))
                        {
                            std::string btnText = btn->getText();
                            
                            // click processing
                            if (btnText == "C")
                            {
                                displayText = "0";
                            }
                            else if (btnText == ">")
                            {
                                if (displayText.length() > 1)
                                {
                                    displayText.pop_back();
                                }
                                else
                                {
                                    displayText = "0";
                                }
                            }
                            else if (btnText == "=")
                            {
                                displayText = std::to_string(result(displayText));
                            }
                            else
                            {
                                // add symbol
                                if (displayText == "0")
                                {
                                    displayText = btnText;
                                }
                                else
                                {
                                    displayText += btnText;
                                }
                            }
                            
                            break; // find button -> next iteration
                        }
                    }
                }
            }
        }

            // 2. Drawing
                window.clear(sf::Color(175,175,175));//clear the screen by the black color     144, 142, 129
                
                button_0.draw(window);
                button_equals.draw(window);

                button_1.draw(window);
                button_2.draw(window);
                button_3.draw(window);
                button_plus.draw(window);

                button_4.draw(window);
                button_5.draw(window);
                button_6.draw(window);
                button_minus.draw(window);

                button_7.draw(window);
                button_8.draw(window);
                button_9.draw(window);
                button_multiply.draw(window);

                button_clear_all.draw(window);
                button_clear_last_symdol.draw(window);
                button_point.draw(window);
                button_division.draw(window);

                Button current_display(345, 100, 10, 15, 10, 120, 120, 120, 255, 255, 255, displayText, font);
                current_display.draw(window);

            // 3. Visualizing
                window.display();//show users what is drawn
        }

    return 0;
}
