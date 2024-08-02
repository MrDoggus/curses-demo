#include <stdlib.h>

#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();

    cbreak(); // cntl c exits out of program
    // raw(); // takes all input as raw characters without performing extra functionality
    noecho(); // doesnt echo inputed characters

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
    // wborder(win, left, right, top left, top right, bott left, bott right);
    wborder(win, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
    // box(win, 0x2550, 0x2551); //box(window, left/right char, top/bottom char)

    // Move cursor and print to specific window
    mvwprintw(win, 1, 1, "This is my box");

    // Refresh a specific window
    wrefresh(win);

    getch();
    getch();

    endwin();

    return 0;
}