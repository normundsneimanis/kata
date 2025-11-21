#include <iostream>

int main() {
    // ask user to enter two doubles
    // double num1, num2;
    // std::cout << "Enter two numbers: ";
    // std::cin >> num1 >> num2;
    // std::cout << "Enter operation (+, -, *, /): ";
    // char operation;
    // std::cin >> operation;
    // switch (operation) {
    //     case '+':
    //         std::cout << "The sum is " << num1 + num2 << std::endl;
    //         break;
    //     case '-':
    //         std::cout << "The difference is " << num1 - num2 << std::endl;
    //         break;
    //     case '*':
    //         std::cout << "The product is " << num1 * num2 << std::endl;
    //         break;
    //     case '/':
    //         std::cout << "The quotient is " << num1 / num2 << std::endl;
    //         break;
    //     default:
    //         std::cout << "Invalid operation" << std::endl;
    //         break;
    // }

    const double gravity = 9.81;
    double fallen = 0.0;
    int height_of_tower;
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height_of_tower;
    int x_seconds = 0;
    double height = height_of_tower;
    while (height > 0) {
        fallen = gravity * (x_seconds * x_seconds) / 2;
        x_seconds += 1;
        height -= fallen;
        std::cout << "After " << x_seconds << " seconds fallen " << height << " m\n";
    }

    return 0;
}
