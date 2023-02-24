#include <iostream>
//cant 
class Ram
{
private:
    std::string ram[4000];

public:
    Ram()
    {
        if (initRam() != 0)
        {
            std::cout << "Ram initialization failed";
        }
        else
        {

            std::cout << "Ram initialization succeeded";
        }
    };
    int initRam()
    {
        for (int i = 0; i < sizeof(ram); i++)
        {
            ram[i] = "0b000000";
        }
        return 0;
    }
};
