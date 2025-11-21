#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> mybitset {};
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);  // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits<< '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    [[maybe_unused]] constexpr int  isHungry   { 0 };
    [[maybe_unused]] constexpr int  isSad      { 1 };
    [[maybe_unused]] constexpr int  isMad      { 2 };
    [[maybe_unused]] constexpr int  isHappy    { 3 };
    [[maybe_unused]] constexpr int  isLaughing { 4 };
    [[maybe_unused]] constexpr int  isAsleep   { 5 };
    [[maybe_unused]] constexpr int  isDead     { 6 };
    [[maybe_unused]] constexpr int  isCrying   { 7 };

    std::bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
    me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
    me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    std::bitset<8> bits1{ 0b0000'1101 };
    std::cout << bits1.size() << " bits are in the bitset\n";
    std::cout << bits1.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << bits1.all() << '\n';
    std::cout << "Some bits are true: " << bits1.any() << '\n';
    std::cout << "No bits are true: " << bits1.none() << '\n';

    std::cout << "Bitset, flipping ~:\n";
    std::bitset<4> b4{ 0b100 }; // b4 is 0100
    std::bitset<8> b8{ 0b100 }; // b8 is 0000 0100

    std::cout << "Initial values:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << "\n\n";

    b4 = ~b4; // flip b4 to 1011
    b8 = ~b8; // flip b8 to 1111 1011

    std::cout << "After bitwise NOT:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';

    std::cout << "Bitwise OR (|):\n";
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';

    std::cout << "Bitwise AND (&):\n";
    std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';

    std::cout << "Bitwise XOR (^)\n";

    std::cout << "Bitmasks\n";

    {
        constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
        constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
        constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
        constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
        constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
        constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
        constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
        constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7
    }

    {
        constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
        constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
        constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
        constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
        constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
        constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
        constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
        constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
    }

    {
        constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
        constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
        constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
        constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
        constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
        constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
        constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
        constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000
    }

    {
        [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
        [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
        [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
        [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
        [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
        [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
        [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
        [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

        std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

        std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
        std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    }

    {
        std::cout << "Setting a bit\n";
        [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
        [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
        [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
        [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
        [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
        [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
        [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
        [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

        std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

        std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

        flags |= mask1; // turn on bit 1

        std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    }

    {
        std::cout << "Re-Setting a bit\n";
        [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
        [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
        [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
        [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
        [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
        [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
        [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
        [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

        std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

        std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

        flags &= ~mask2; // turn off bit 2

        std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    }

    {
        std::cout << "Flipping a bit\n";

        [[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
        [[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
        [[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
        [[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
        [[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
        [[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
        [[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
        [[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

        std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

        std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
        flags ^= mask2; // flip bit 2
        std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
        flags ^= mask2; // flip bit 2
        std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    }

    {
        std::cout << "Masks with bitset\n";
        [[maybe_unused]] constexpr std::bitset<8> mask0{ 0b0000'0001 }; // represents bit 0
        [[maybe_unused]] constexpr std::bitset<8> mask1{ 0b0000'0010 }; // represents bit 1
        [[maybe_unused]] constexpr std::bitset<8> mask2{ 0b0000'0100 }; // represents bit 2
        [[maybe_unused]] constexpr std::bitset<8> mask3{ 0b0000'1000 }; // represents bit 3
        [[maybe_unused]] constexpr std::bitset<8> mask4{ 0b0001'0000 }; // represents bit 4
        [[maybe_unused]] constexpr std::bitset<8> mask5{ 0b0010'0000 }; // represents bit 5
        [[maybe_unused]] constexpr std::bitset<8> mask6{ 0b0100'0000 }; // represents bit 6
        [[maybe_unused]] constexpr std::bitset<8> mask7{ 0b1000'0000 }; // represents bit 7

        std::bitset<8> flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags
        std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
        std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

        flags ^= (mask1 | mask2); // flip bits 1 and 2
        std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
        std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

        flags |= (mask1 | mask2); // turn bits 1 and 2 on
        std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
        std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

        flags &= ~(mask1 | mask2); // turn bits 1 and 2 off
        std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
        std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
    }

    {
        std::cout << "Meaningful bitmasks\n";
        // Define a bunch of physical/emotional states
        [[maybe_unused]] constexpr std::uint8_t isHungry   { 1 << 0 }; // 0000 0001
        [[maybe_unused]] constexpr std::uint8_t isSad      { 1 << 1 }; // 0000 0010
        [[maybe_unused]] constexpr std::uint8_t isMad      { 1 << 2 }; // 0000 0100
        [[maybe_unused]] constexpr std::uint8_t isHappy    { 1 << 3 }; // 0000 1000
        [[maybe_unused]] constexpr std::uint8_t isLaughing { 1 << 4 }; // 0001 0000
        [[maybe_unused]] constexpr std::uint8_t isAsleep   { 1 << 5 }; // 0010 0000
        [[maybe_unused]] constexpr std::uint8_t isDead     { 1 << 6 }; // 0100 0000
        [[maybe_unused]] constexpr std::uint8_t isCrying   { 1 << 7 }; // 1000 0000

        std::uint8_t me{}; // all flags/options turned off to start
        me |= (isHappy | isLaughing); // I am happy and laughing
        me &= ~isLaughing; // I am no longer laughing

        // Query a few states
        // (we'll use static_cast<bool> to interpret the results as a boolean value)
        std::cout << std::boolalpha; // print true or false instead of 1 or 0
        std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
        std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
    }

    {
        std::cout << "Meaningful bitmasks with bitset\n";
        // Define a bunch of physical/emotional states
        [[maybe_unused]] constexpr std::bitset<8> isHungry   { 0b0000'0001 };
        [[maybe_unused]] constexpr std::bitset<8> isSad      { 0b0000'0010 };
        [[maybe_unused]] constexpr std::bitset<8> isMad      { 0b0000'0100 };
        [[maybe_unused]] constexpr std::bitset<8> isHappy    { 0b0000'1000 };
        [[maybe_unused]] constexpr std::bitset<8> isLaughing { 0b0001'0000 };
        [[maybe_unused]] constexpr std::bitset<8> isAsleep   { 0b0010'0000 };
        [[maybe_unused]] constexpr std::bitset<8> isDead     { 0b0100'0000 };
        [[maybe_unused]] constexpr std::bitset<8> isCrying   { 0b1000'0000 };


        std::bitset<8> me{}; // all flags/options turned off to start
        me |= (isHappy | isLaughing); // I am happy and laughing
        me &= ~isLaughing; // I am no longer laughing

        // Query a few states (we use the any() function to see if any bits remain set)
        std::cout << std::boolalpha; // print true or false instead of 1 or 0
        std::cout << "I am happy? " << (me & isHappy).any() << '\n';
        std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';
    }

    {
        // Bitmasks with multiple bits
        constexpr std::uint32_t redBits{ 0xFF000000 };
        constexpr std::uint32_t greenBits{ 0x00FF0000 };
        constexpr std::uint32_t blueBits{ 0x0000FF00 };
        constexpr std::uint32_t alphaBits{ 0x000000FF };

        std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
        std::uint32_t pixel{};
        std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

        // use Bitwise AND to isolate the pixels for our given color,
        // then right shift the value into the lower 8 bits
        const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
        const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
        const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
        const std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

        std::cout << "Your color contains:\n";
        std::cout << std::hex; // print the following values in hex

        // reminder: std::uint8_t will likely print as a char
        // we static_cast to int to ensure it prints as an integer
        std::cout << static_cast<int>(red)   << " red\n";
        std::cout << static_cast<int>(green) << " green\n";
        std::cout << static_cast<int>(blue)  << " blue\n";
        std::cout << static_cast<int>(alpha) << " alpha\n";
    }

    return 0;
}