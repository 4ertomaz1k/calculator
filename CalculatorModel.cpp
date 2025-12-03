#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

// + - * /
long double result(std::string display_)
{
    long double v1=0,v2=0;
    int l=0,r=0;
    std::string all_sign = "+-*/";
    char current_sign;

    for (;r < display_.length();r++)
    {
        // if find sign("+-*/") or r achieved the end of the line(expression)
        if (all_sign.find(display_[r]) != std::string::npos || r == (display_.length()-1)) //std::string::npos - not found
        {
            if (!current_sign)
            { 
            current_sign = display_[r]; 
            }

            if (!v1) 
            {
                v1 = std::stod(display_.substr(l,r));//stod - string to double; substr(l,r) - line slice(from l to b not inclusive)
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
            return v1+v2;
        case '-':
            return v1-v2;
        case '*':
            return v1*v2;
        case '/':
            return v1/v2;
        default:
            cout << "Something went wrong" << endl;
            abort();
    }

};

int main()
{

    std::string display;
    cin >> display;

    cout << std::fixed;
    cout << std::setprecision(15);
    cout << result(display) <<endl;

    return 0;
}