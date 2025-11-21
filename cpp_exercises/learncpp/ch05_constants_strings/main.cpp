#include <iostream>
#include <bitset>
// #include <format> // C++20
// #include <print> // C++23

int main() {

/*
    integral	u or U	unsigned int
    integral	l or L	long
    integral	ul, uL, Ul, UL, lu, lU, Lu, LU	unsigned long
    integral	ll or LL	long long
    integral	ull, uLL, Ull, ULL, llu, llU, LLu, LLU	unsigned long long
    integral	z or Z	The signed version of std::size_t (C++23)
    integral	uz, uZ, Uz, UZ, zu, zU, Zu, ZU	std::size_t (C++23)
    floating point	f or F	float
    floating point	l or L	long double
    string	s	std::string
    string	sv	std::string_view
*/
    {
        std::cout << "decimal, hex, octal" << std::endl;
        int x { 12 }; // 12 is assumed to be a decimal number
        int x_octal{ 012 }; // 0 before the number means this is octal
        int x_hex{ 0xF }; // 0x before the number means this is hexadecimal
        int bin{};        // assume 16-bit ints
        bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
        bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
        bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
        bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable
        int bin2 { 0b1011'0010 };  // assign binary 1011 0010 to the variable 0x14
        long value { 2'132'673'462 }; // much easier to read than 2132673462
    }

    {
        int x { 12 };
        std::cout << x << '\n'; // decimal (by default)
        std::cout << std::hex << x << '\n'; // hexadecimal
        std::cout << x << '\n'; // now hexadecimal
        std::cout << std::oct << x << '\n'; // octal
        std::cout << std::dec << x << '\n'; // return to decimal
        std::cout << x << '\n'; // decimal
    }

    {
        // std::bitset<8> means we want to store 8 bits
        std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
        std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

        std::cout << bin1 << '\n' << bin2 << '\n';
        std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it
    }

    // {
    //     // Format
    //     std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    //     std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits
    //
    //     std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline
    // }
    return 0;
}