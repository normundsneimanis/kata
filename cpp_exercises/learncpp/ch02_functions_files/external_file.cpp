#include <iostream>
#include "external_file.h"

int getValueFromUser() // this function returns an integer value
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}