#include "Button.hpp"
#include "CalculatorModel.hpp"
#include "SFML/Graphics.hpp"
#include "font_data.hpp"

#include <iostream>
#include <string>
#include <algorithm>// Necessarily for std::count
#include <stdexcept>// Necessarily for std::invalid_argument
#include <cmath>//round

std::string displayText;
std::string*ptrdisplayText = &displayText;
std::string all_operator = "+-*/";
std::string temp;

//translates long double to sting + fix result of operations and output on displayText
void res(std::string* ptrdisplayText)
{
    try
    {
        if (all_operator.find((*ptrdisplayText).back()) != std::string::npos)//like 36*
        {
            (*ptrdisplayText).pop_back();//delete unsignificant operator
        }

        temp = std::to_string(std::round(result((*ptrdisplayText)) * 100000.0) / 100000.0);//get result
        temp = temp.substr(0, temp.length() - 1);//get 6 numbers after point -> delete last symbol, because we rounded by 5 signs;

        //delete insignificant zeros and maybe point
            while (temp[temp.length() - 1] == '0' && temp.length() > 1)
            {
                temp.pop_back();
                if (temp[temp.length() - 1] == '.')
                {
                    temp.pop_back();
                }
            }

        //change the display info
        (*ptrdisplayText) = temp;
        
    }

    catch (const std::runtime_error& e) 
    {
        *ptrdisplayText = e.what(); //if result activate throw -> output text of error in display from result function
    }

    catch (const std::invalid_argument& e) 
    {
        *ptrdisplayText = "Invalid Input";
    }

}



// Сommand to compile - g++ CalculatorView.cpp Button.cpp CalculatorModel.cpp -o "./SFML_static/Calculator.exe" -I"./SFML_static/include" -L"./SFML_static/lib" -lsfml-graphics -lsfml-window -lsfml-system -mwindows
// Сommand to launch - .\SFML_static\Calculator.exe
int main()
{

    // Creating a context settings object
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8; //8x anti-aliasing
        
    // Creating the main window by passing the settings
    sf::RenderWindow window
    (
        sf::VideoMode({375, 500}), 
        "Calculator", 
        sf::State::Windowed, // We use the default style.
        settings            // Passing the anti-aliasing settings
    );

    //Create font(load from Memory(font_data.hpp))
        sf::Font font;
        if (!font.openFromMemory(arimo_ttf, arimo_ttf_len)) {
            //error
        }

    //Create buttons
        Button button_0     (165, 63.3, 10, 15, 422.36, 226, 226, 218, 0, 0, 0, "0", font);
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

        Button button_clear_all(165, 63.3, 10, 15, 346.42-(75.94*3), 49, 48, 46, 255, 255, 255, "C", font);
        Button button_clear_last_symdol(75, 63.3, 10, 15+((75+15)*2), 346.42-(75.94*3), 49, 48, 46, 255, 255, 255, ">", font);
        Button button_point(75, 63.3, 10, 15+((75+15)*2), 422.36, 84, 84, 82, 255, 255, 255, ".", font);
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


    displayText = "0";
    std::string all_sign = "+-*/.";
    std::string all_operator = "+-*/";
    std::string temp;
    char temporary_sign;
    bool is_operator_between_variables = false;
    bool is_point_in_v1 = false;
    bool is_minus_in_v1 = false;
    int max_point_on_display = 1;
    int current_point_on_display = 0;
    int operatorCount = 0;


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

                                //check
                                    bool isError = (displayText == "Division by zero is not possible" || displayText == "Invalid Input" || displayText == "Result is not defined");
                                    bool is_max_length = (displayText.length() == 16);

                                //calculator lock when dividing by 0
                                if (isError) 
                                {
                                    if (btnText != "C" && btnText != ">") 
                                    {
                                        continue;
                                    }
                                }

                                // calculator lock when display length == 16
                                if (is_max_length) 
                                {
                                    if (btnText != "C" && btnText != ">")//&& btnText != "+" && btnText != "-" && btnText != "*" && btnText != "/" coming soon
                                    {
                                        continue;
                                    }
                                }
                                
                                //counting necessary variables

                                    //operatorCount = 0
                                        operatorCount = 0;
                                        for (char c : displayText)
                                        {
                                            if (all_operator.find(c) != std::string::npos)
                                            {
                                                operatorCount+=1;
                                            }
                                        }

                                    // bool is_minus_in_v1 = false;
                                        is_minus_in_v1 = false;
                                        if ((displayText + btnText)[0] == '-')
                                        {
                                            is_minus_in_v1 = true;
                                        }

                                    // bool is_operator_between_variables = false;      //if 2+ -> 2* == true
                                        is_operator_between_variables = false;
                                        if ( ( (displayText[0] != '-') && (operatorCount == 1) ) || ( (displayText[0] == '-') && (operatorCount == 2) ) )
                                        {
                                            is_operator_between_variables = true;
                                        }

                                    // int current_point_on_display = 0;
                                        current_point_on_display = 0;
                                        for (char p : displayText)
                                        {
                                            if (p == '.')
                                            {
                                                current_point_on_display+=1;
                                            }
                                        }

                                    // bool is_point_in_v1 = false;
                                        is_point_in_v1 = false;
                                            for (int operator_index = 0; operator_index < displayText.length();operator_index++)
                                            {
                                                if (((displayText[operator_index] == '+' || displayText[operator_index] == '-' || displayText[operator_index] == '*' || displayText[operator_index] == '/') || (operator_index == displayText.length() - 1)) && (operator_index != 0))
                                                    for (int point_index = 0; point_index < operator_index; point_index++)
                                                    {
                                                        if (displayText[point_index] == '.')
                                                        {
                                                            is_point_in_v1 = true;
                                                            break;
                                                        }
                                                    }
                                            }

                                    // int max_point_on_display = 1;
                                        max_point_on_display = 1;
                                        if (is_operator_between_variables)
                                        {
                                            max_point_on_display = 2;
                                        }   



                                // click processing

                                    //counting buttons
                                        if (btnText == "C")
                                        {
                                            displayText = "0";
                                        }

                                        else if (btnText == ">")
                                        {
                                            if (displayText.length() > 1)
                                            {
                                                displayText.pop_back();
                                                if (isError)
                                                {
                                                    displayText = "0";
                                                }
                                            }

                                            else
                                            {
                                                displayText = "0";
                                            }
                                        }

                                        else if (btnText == "=")
                                        {
                                            if (displayText != "0")
                                            {
                                                res(&displayText);
                                            }

                                            else {}
                                            
                                        }

                                    //add symbol
                                        else
                                        {   
                                            //zero processing
                                                if (displayText == "0")
                                                    {
                                                        if (all_sign.find(btnText[0]) != std::string::npos)
                                                        {
                                                            displayText += btnText;//0 -> 0+
                                                        }

                                                        else
                                                        {
                                                            displayText = btnText;
                                                        }
                                                    }
                                            
                                            //refinement of nuances

                                            //if last symbol in displayText is operator and current symbol in btnText also operator -> we do only the new operator
                                                else if (all_sign.find(displayText.back()) != std::string::npos && all_sign.find(btnText[0]) != std::string::npos)
                                                {
                                                    if (is_operator_between_variables == 1 && current_point_on_display == 1 && max_point_on_display == 2 && (btnText.find(".") != std::string::npos))
                                                    {}

                                                    else
                                                    {
                                                        displayText.back() = btnText[0];
                                                    }
                                                    
                                                }

                                            //do not allow two points to appear in one variable
                                                else if ((current_point_on_display == max_point_on_display) && (btnText.find(".") != std::string::npos) || (!is_point_in_v1 && is_operator_between_variables && max_point_on_display == 2 && current_point_on_display == 1 && btnText.find(".") != std::string::npos))
                                                {}

                                            //if we get 2 operator on display -> counting result before second operator and add second operator after result
                                                else if (is_operator_between_variables && all_operator.find(btnText[0]) != std::string::npos)
                                                {
                                                    temporary_sign = btnText[0];
                                                    res(&displayText);
                                                    displayText += temporary_sign;
                                                }


                                            //processing 0-9 and + - * / .
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
                window.clear(sf::Color(175,175,175));//clear the screen by the rgb color
                
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