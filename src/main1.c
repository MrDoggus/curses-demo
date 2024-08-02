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

    int x, y;
    x = 10;
    y = 10;

    // moves the cursor to the specified location
    move(y, x);

    // Prints hello world!
    printw("Hello World!");

    // Refreshes screen to match whats in buffer
    refresh();

    // waits for user input
    int c = getch();

    // Clear the screen
    clear();

    // Move cursor and print recieved char
    mvprintw(0, 0, "%d", c);

    // wait till keypress again
    getch();

    // deallocs and ends ncurses
    endwin();

    return 0;
}