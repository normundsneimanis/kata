#include <iostream>

int main() {
    {
        int x;    // define an integer variable named x (preferred)
        int y, z; // define two integer variables, named y and z
        int width; // define an integer variable named width
        width = 5; // assignment of value 5 into variable width

        int width2 { 5 };    // define variable width and initialize with initial value 5
        int height = { 6 }; // copy-list-initialization of initial value 6 into variable height (rarely used)

        int a;         // default-initialization (no initializer)

        // Traditional initialization forms:
        int b = 5;     // copy-initialization (initial value after equals sign)
        int c ( 6 );   // direct-initialization (initial value in parenthesis)

        // Modern initialization forms (preferred):
        int d { 7 };   // direct-list-initialization (initial value in braces)
        int e {};      // value-initialization (empty braces)

        // int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion
        int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
        int w3 (4.5);   // compiles: w3 direct-initialized to value 4
        int width3 {}; // value-initialization / zero-initialization to value 0
    }

    // Multi-initialization
    {
        int a = 5, b = 6;          // copy-initialization
        int c ( 7 ), d ( 8 );      // direct-initialization
        int e { 9 }, f { 10 };     // direct-list-initialization
        int i {}, j {};            // value-initialization
    }

    {
        // int a, b = 5;     // wrong: a is not initialized to 5!
        int a = 5, b = 5; // correct: a and b are initialized to 5
    }

    {
        [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
        [[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
        [[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused

        std::cout << pi << '\n';
        std::cout << phi << '\n';
    }
}