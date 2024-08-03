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

    resize_term(0, 0);
    refresh();

    
    int conh, conw;

    // height and width of specified window
    // getbegyx(WINDOW*, int: height of window, int: width of window)
    getmaxyx(stdscr, conh, conw);

    // Create temp window
    WINDOW* win = newwin(10, 40, (conh-10)/2, (conw-40)/2);

    int x, y;
    int startx, starty;
    int height, width;

    // position of cursor that is in the window specified
    // getyx(WINDOW*, int: ypos, int: xpos); <-- macro. x and y SHOULD NOT be a pointer
    getyx(win, y, x);    // stdscr is the default window
    wprintw(win, "ypos: %d | xpos: %d\n", y, x);

    // top left corner of window specified
    // getbegyx(WINDOW*, int top left y, int top left x)
    getbegyx(win, starty, startx);
    wprintw(win, "window start y: %d | window start x: %d\n", starty, startx);

    // height and width of specified window
    // getbegyx(WINDOW*, int: height of window, int: width of window)
    getmaxyx(win, height, width);
    wprintw(win, "window height: %d | window width: %d\n", height, width);

    wrefresh(win);

    getch();
    endwin();

    return 0;
}