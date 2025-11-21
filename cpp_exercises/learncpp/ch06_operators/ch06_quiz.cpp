#include <iostream>

// Write the function getQuantityPhrase() here
std::string getQuantityPhrase(int num) {
    return std::to_string(num);
}

std::string_view getApplesPluralized(int num) {
    if (num == 0) {
        return "None";
    } else if (num == 1) {
        return "Single";
    }
    return "Some";
}

// Write the function getApplesPluralized() here

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}