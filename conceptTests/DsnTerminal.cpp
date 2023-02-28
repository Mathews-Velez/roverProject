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
    // get the length of the input provided
    int len = input.size() / 2;

    int screen_width = w.ws_col;
    int screen_height = w.ws_row;

    // adds the proper amount of padding for input to be centered
    int left_padding = w.ws_col / 2 - len;
    std::string tape = "";
    for (int i = 0; i < left_padding; i++)
    {
        tape += " ";
    }
    tape += input;

    // adds enough newlines before the strings needs to be added to center it vertically
    int top_padding = screen_height / 2 - 1;
    std::string roof = "";
    for (int i = 0; i < top_padding; i++)
    {
        roof += "\n";
    }
    roof += tape;
    system("clear");
    std::cout << roof;
    printf("\n");
    return 0;
}

void loadingBar()
{
    printf("\e[?25l");
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int screen_width = w.ws_col;
    std::string progress_arrow = "[=>";
    std::string progress_bar = "[=";

    // generate the empty progress bar
    for (int i = 0; i < screen_width - 3; i++)
    {
        progress_bar += " ";
    }
    progress_bar += "]";

    for (int i = 1; i < screen_width - 3; i++){
        centerOutput("Loading");
        printf("\n\n\n\n");
        progress_bar[i] = '=';
        progress_bar[i+1] = '>';
        std::cout << progress_bar;
        printf("\n");
        usleep(15000);
        system("clear");
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
    return 0;
}
