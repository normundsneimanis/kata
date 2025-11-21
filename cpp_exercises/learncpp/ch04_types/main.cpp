#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT
#include <limits>

void print_double(double x) // print takes a double parameter
{
    std::cout << x << '\n';
}

void print_int(int x) // print now takes an int parameter
{
    std::cout << x << '\n';
}

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    {
        std::cout << "Unsigned overflow" << std::endl;;
        // assume 4 byte integers
        int x { 2147483647 }; // the maximum value of a 4-byte signed integer
        std::cout << x << '\n';

        x = x + 1; // integer overflow, undefined behavior
        std::cout << x << '\n';
    }

    // {
    //     std::cout << "Unsigned underflow" << std::endl;;
    //     unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    //     std::cout << "x was: " << x << '\n';
    //
    //     x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    //     std::cout << "x is now: " << x << '\n';
    //
    //     x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    //     std::cout << "x is now: " << x << '\n';
    // }

    // {
    //     // Underflow
    //     unsigned short x{ 0 }; // smallest 2-byte unsigned value possible
    //     std::cout << "x was: " << x << '\n';
    //
    //     x = -1; // -1 is out of our range, so we get modulo wrap-around
    //     std::cout << "x is now: " << x << '\n';
    //
    //     x = -2; // -2 is out of our range, so we get modulo wrap-around
    //     std::cout << "x is now: " << x << '\n';
    // }

    {
        signed int s { -1 };
        unsigned int u { 1 };

        if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
            std::cout << "-1 is less than 1\n";
        else
            std::cout << "1 is less than -1\n"; // this statement executes
    }

    {
        std::int8_t x { 65 };   // initialize 8-bit integral type with value 65
        std::cout << "uint8_t 64 is " << x << '\n'; // You're probably expecting this to print 65
    }

    {
        std::cout << "\nFast types" << std::endl;
        std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
        std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
        std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
        std::cout << '\n';
        std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
        std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
        std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";
    }

    {
        // Size of int
        int x { 5 };
        std::size_t s { sizeof(x) }; // sizeof returns a value of type std::size_t, so that should be the type of s
        std::cout << "Size of int: " << s << '\n';
    }

    {
        std::cout << "Max object size: " << sizeof(std::size_t) << '\n';
    }

    {
        // Float sizes
        std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
        std::cout << "IEEE 754 float: " << std::numeric_limits<float>::is_iec559 << '\n';
        std::cout << "IEEE 754 double: " << std::numeric_limits<double>::is_iec559 << '\n';
        std::cout << "IEEE 754 long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
    }

    {
        std::cout << "cout 6 precision by default" << std::endl;
        std::cout << 9.87654321f << '\n';
        std::cout << 987.654321f << '\n';
        std::cout << 987654.321f << '\n';
        std::cout << 9876543.21f << '\n';
        std::cout << 0.0000987654321f << '\n';

        std::cout << "Setting precision to 17" << std::endl;
        std::cout << std::setprecision(17); // show 17 digits of precision
        std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
        std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

        std::cout << "10 significant digits (123456789.0f)" << std::endl;
        float f { 123456789.0f }; // f has 10 significant digits
        std::cout << std::setprecision(9); // to show 9 digits in f
        std::cout << f << '\n';
    }

    {
        double d{0.1};
        std::cout << "double 0.1 with default precision: " <<  d << '\n'; // use default cout precision of 6
        std::cout << std::setprecision(17);
        std::cout << "double 0.1 with precision 17: " << d << '\n';
    }

    {
        std::cout << std::setprecision(17);

        double d1{ 1.0 };
        std::cout << "double 1.0 couted " << d1 << " to add" << '\n';

        double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
        std::cout << "Adding 10*0.1 results in: " << d2 << '\n';
    }

    {
        std::cout << "double special cases" << std::endl;
        double zero { 0.0 };

        double posinf { 5.0 / zero }; // positive infinity
        std::cout << posinf << '\n';

        double neginf { -5.0 / zero }; // negative infinity
        std::cout << neginf << '\n';

        double z1 { 0.0 / posinf }; // positive zero
        std::cout << z1 << '\n';

        double z2 { -0.0 / posinf }; // negative zero
        std::cout << z2 << '\n';

        double nan { zero / zero }; // not a number (mathematically invalid)
        std::cout << nan << '\n';
    }

    {
        std::cout << "booleans" << std::endl;
        std::cout << true << '\n';
        std::cout << false << '\n';

        std::cout << std::boolalpha; // print bools as true or false

        std::cout << true << '\n';
        std::cout << false << '\n';

        bool bFalse { 0 }; // okay: initialized to false
        bool bTrue  { 1 }; // okay: initialized to true
        // bool bNo    { 2 }; // error: narrowing conversions disallowed

        std::cout << bFalse << " " << bTrue << '\n';

        // Copy initialization
        std::cout << std::boolalpha; // print bools as true or false

        bool b1 = 4 ; // copy initialization allows implicit conversion from int to bool
        std::cout << b1 << '\n';

        bool b2 = 0 ; // copy initialization allows implicit conversion from int to bool
        std::cout << b2 << '\n';
    }

    print_double(5);
    print_int(static_cast<int>(5.5));

    {
        char ch{ 97 }; // 97 is ASCII code for 'a'
        // print value of variable ch as an int
        std::cout << ch << " has value " << static_cast<int>(ch) << '\n';
    }

    {
        std::cout << "Sign conversion using static cast" << std::endl;
        unsigned int u1 { 5 };
        // Convert value of u1 to a signed int
        int s1 { static_cast<int>(u1) };
        std::cout << s1 << '\n'; // prints 5

        int s2 { 5 };
        // Convert value of s2 to an unsigned int
        unsigned int u2 { static_cast<unsigned int>(s2) };
        std::cout << u2 << '\n'; // prints 5
    }

    {
        int s { -1 };
        std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

        unsigned int u { 4294967295 }; // largest 32-bit unsigned int
        std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20
    }

    {
        std::int8_t myInt{65};      // initialize myInt with value 65
        std::cout << myInt << '\n'; // you're probably expecting this to print 65
        std::cout << static_cast<int>(myInt) << '\n'; // will always print 65
    }

    return 0;
}