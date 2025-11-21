#include <string>
#include <iostream>

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

void printString(std::string str)
{
    std::cout << str << '\n';
}

std::string_view getBoolName(bool b)
{
    if (b)
        return "true";  // return a std::string_view viewing "true"

    return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed at the end of the function

int main()
{
    {
        std::string name { "Alex" }; // initialize name with string literal "Alex"
        name = "John";               // change name to "John"
        std::cout << "My name is: " << name << '\n';

        std::cout << name << " has " << name.length() << " characters\n";

        std::cout << name << " has " << std::ssize(name) << " characters (ssize)\n";

        std::string empty{ };
        std::cout << '[' << empty << ']';
    }

    {
        std::cout << "Enter your full name: ";
        std::string name{};
        std::getline(std::cin >> std::ws, name); // read a full line of text into name

        std::cout << "Enter your favorite color: ";
        std::string color{};
        std::getline(std::cin >> std::ws, color); // read a full line of text into color

        std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
    }

    {
        // String literals
        using namespace std::string_literals; // easy access to the s suffix

        std::cout << "foo\n";   // no suffix is a C-style string literal
        std::cout << "goo\n"s;  // s suffix is a std::string literal
    }

    {
        std::string_view s{ "Hello, string view!" }; // now a std::string_view
        printSV(s);
    }

    {
        // String view initialization
        std::string_view s1 { "Hello, world!" }; // initialize with C-style string literal
        std::cout << s1 << '\n';

        std::string s{ "Hello, world!" };
        std::string_view s2 { s };  // initialize with std::string
        std::cout << s2 << '\n';

        std::string_view s3 { s2 }; // initialize with std::string_view
        std::cout << s3 << '\n';
    }

    {
        // Conversion
        std::string_view sv{ "Hello, world!" };

        // printString(sv);   // compile error: won't implicitly convert std::string_view to a std::string

        std::string s{ sv }; // okay: we can create std::string using std::string_view initializer
        printString(s);      // and call the function with the std::string

        printString(static_cast<std::string>(sv)); // okay: we can explicitly cast a std::string_view to a std::string
    }

    std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // ok

    {
        // Remove prefix, suffix
        std::string_view str{ "Peach" };
        std::cout << str << '\n';

        // Remove 1 character from the left side of the view
        str.remove_prefix(1);
        std::cout << str << '\n';

        // Remove 2 characters from the right side of the view
        str.remove_suffix(2);
        std::cout << str << '\n';

        str = "Peach"; // reset the view
        std::cout << str << '\n';
    }

    return 0;
}