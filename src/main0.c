#include <stdlib.h>

#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif


int main()
{
    // itits screen. sets up memory and clears screen
    initscr();

    // Prints hello world!
    printw("Hello World!");

    // Refreshes screen to match whats in buffer
    refresh();

    // waits for user input
    int c = getch();

    // Print recieved char
    printw("%d", c);

    // wait till keypress again
    getch();

    // deallocs and ends ncurses
    endwin();

    return 0;
}