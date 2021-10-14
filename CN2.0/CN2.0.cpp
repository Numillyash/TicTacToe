#include "menu.h"

int main()
{
    start: printMenu();

    if (menuInp() == 0)
    {
        return 0;
    }
    else
    {
        if (game() == 0)
        {
            return 0;
        }
        else
        {
            clearScreen();
            goto start;
        }
    }
}