#include <iostream>

int main() {
    // {
    //     bool b{}; // default initialize to false
    //     std::cout << "Enter a boolean value: ";
    //     std::cin >> b;
    //     std::cout << "You entered: " << b << '\n';
    // }

    {
        bool b{};
        std::cout << "Enter a boolean value: ";

        // Allow the user to input 'true' or 'false' for boolean values
        // This is case-sensitive, so True or TRUE will not work
        std::cin >> std::boolalpha;
        std::cin >> b;

        // Let's also output bool values as `true` or `false`
        std::cout << std::boolalpha;
        std::cout << "You entered: " << b << '\n';
    }
}