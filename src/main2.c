#include <stdlib.h>

#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();

    int height, width;
    int starty, startx;
    height = 10;
    width = 20;
    startx = 10;
    starty = 10;

    // Create a new window
    WINDOW* win = newwin(height, width, starty, startx);
    
    // Refresh the whole screen so it knows window was created
    // Without this, box will not show an effect
    refresh();

    // Create a simple box
    box(win, 0, 0);

    // Move cursor and print to specific window
    mvwprintw(win, 1, 1, "This is my box");

    // Refresh a specific window
    wrefresh(win);

    int c = getch();

    endwin();

    return 0;
}