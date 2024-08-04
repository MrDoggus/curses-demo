#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();
    noecho();
    cbreak();

    // Get size of screen
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Create a window for user input
    WINDOW* inputwin = newwin(3, xMax-12, yMax-5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    // Allows you to use keys such as arrows/function keys
    keypad(inputwin, true);

    // Get input from window
    int c = wgetch(inputwin);
    if (c == KEY_UP)
    {
        mvwprintw(inputwin, 1, 1, "You pressed key up!!!!!");
        wrefresh(inputwin);
    }

    getch();
    endwin();

    return 0;
}