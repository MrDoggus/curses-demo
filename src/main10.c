#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();
    noecho();

    // Input modes
    // cbreak();   // gets rid of line buffering, user input is immediatly available to program 
    
    // gets rid of line bufferingm, user input is immediatly available to program. 
    // waits (tenths of a second) before sending an error retval if no input was pressed.
    // halfdelay(1);    // Wait half a second before returning error

    //no buffering, no delay. If there isnt a char available, return immediatly
    // nodelay(stdscr, true);

    // negative input -> blocking. 0 -> no delay, greater than zero-> wait milliseconds
    wtimeout(stdscr, 1);

    int c;
    while ((c=getch()) != 'x')
    {
        printw("a %d\n", c);
        refresh();
    }

    endwin();

    return 0;
}