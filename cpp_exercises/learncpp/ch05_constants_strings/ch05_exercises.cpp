#include <cstdint> // for std::uint8_t
#include <iostream>

int main()
{
    std::cout << "How old are you?\n";

    std::uint16_t age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas: ";

    if (age >= 16)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << '\n';

    return 0;
}