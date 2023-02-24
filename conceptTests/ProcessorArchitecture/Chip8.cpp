#include <iostream>
#include <cstddef>
#include <bitset>

class Ram
{
    using byte = std::byte;

private:
    byte ram[4096];

public:
    Ram()
    {
        if (initRam() != 0)
        {
            std::cout << "Ram initialization failed";
        }
        else
        {

            std::cout << "\nRam initialization succeeded \n";
        }
    };
    int initRam()
    {
        for (int i = 0; i < sizeof(ram); i++)
        {
            ram[i] = byte{0};
        }
        return 0;
    }

    byte getVal(int address)
    {
        return ram[address];
    }
};

class Display
{
    //initialize a display of the same dimensions

};

// allows me to actually print the binary number
std::ostream &
operator<<(std::ostream &os, std::byte b)
{
    return os << std::bitset<8>(std::to_integer<int>(b));
}
int main()
{
    using byte = std::byte;
    
    //initalize the components of the Chip
    Ram *ram = new Ram{};


    byte val = ram->getVal(0x000);
    std::cout << val;
}