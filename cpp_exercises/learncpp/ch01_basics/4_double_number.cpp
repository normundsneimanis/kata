#include <iostream>

// less-bad version
int main()
{
    std::cout << "Enter an integer: ";

    int num{ };
    std::cin >> num;

    std::cout << "Double that number is: " << num * 2 << '\n'; // then print the value of that variable here

    return 0;
}