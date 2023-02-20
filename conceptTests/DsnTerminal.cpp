#include <iostream>
#include <string>
#include <typeinfo>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int centerOutput(std::string input)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    // printf ("lines %d\n", w.ws_row);
    // printf ("columns %d\n", w.ws_col);
    char padding[]{};
    // get the length of the input provided
    int len = input.size() / 2;

    int left_padding = w.ws_col / 2 - len;
    std::string tape = "";
    for (int i = 0; i < left_padding; i++)
    {
        tape += " ";
    }
    std::cout << tape;
    std::cout << input;
    printf("\n");
    return 0;
}

void loadingBar()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int screen_width = w.ws_col-3;
    std::string progress_arrow = "[=>";
    for (int i = 0; i < screen_width; i++)
    {
        printf("\e[?25l");
        printf("\n\n\n\n\n\n\n\n\n");
        centerOutput("Loading");
        printf("\n\n\n\n");
        std::cout << progress_arrow;
        printf("\n");
        usleep(15000);
        system("clear");
        progress_arrow.pop_back();
        progress_arrow.pop_back();
        progress_arrow += "=>]";
        
    }
    printf("\e[?25h");
}

int main()
{
    // while (true)
    // {
    char response{};
    printf("\nWould like to establish a link to the NASA Deep Space Network?(y/n)\n");
    std::cin >> response;
    if (response == 'y')
    {
        loadingBar();
        return false;
    }
    // printf("Establishing a connection....\n");
    // }
    return 0;
}
