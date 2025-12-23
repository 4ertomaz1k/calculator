#include "CalculatorModel.hpp"
#include <iostream>
#include <string>

long double result(std::string display_)
{
    long double v1=0,v2=0;
    int l=0,r=0;
    std::string all_sign = "+-*/";
    char current_sign;

    for (;r < display_.length();r++)
    {
        // if find sign("+-*/") or r achieved the end of the line(expression)
        if ( all_sign.find(display_[r]) != std::string::npos || r == display_.length()-1) //std::string::npos - not found
        {
            if (display_[r] == '-' && r == 0)//for working if v1 is negative
            {
                continue;
            }

                if (!current_sign)
                { 
                    current_sign = display_[r]; 
                }
                // cout << std::stod(display_.substr(l,r)) << endl;
                if (!v1) 
                {
                    v1 = std::stod(display_.substr(l,r+1));//stod - string to double; substr(l,r+1) - line slice(from l to r+1 not inclusive)
                }

                else
                {
                    v2 = std::stod(display_.substr(l+1,r-l));//substr gets(start position(index), len symbols)
                }

                l=r;
            
        }

    }

    switch (current_sign)
    {
        case '+':
            return v1 + v2;
        case '-':
            return v1 - v2;
        case '*':
            return v1 * v2;
        case '/':
            if (v2 != 0)
            { 
                return v1 / v2;
            }
            throw std::runtime_error("Division by zero is not possible");
        default:
            return v1; 
    }

}


//точка вниз а стирашка на 1 вправо 
//вправо значения на дисплее
//чутка подправить дизайн, текст у экрана +  чтобы не вылезало за границы