#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();
    noecho();
    
    printw("Hello World!");
    mvprintw(1, 0, "Hello World!");

    move(0, 1);
    getch();

    clrtoeol(); // wclrtoeol(): clears from cursor to end of line
    getch();

    mvprintw(2, 0, "Everything below this gets cleared");
    mvprintw(3, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    mvprintw(4, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    getch();
    move(2, 21);
    clrtobot(); // wclrtobot(): clear to bottom
    getch();

    printw("Looking at erase()");
    mvprintw(5, 5, "Im down here");
    mvprintw(10, 10, "Farther down");
    getch();
    erase();    // werase(): "soft clear"
    getch();

    
    mvprintw(0, 0, "Looking at erase()");
    mvprintw(5, 5, "Im down here");
    mvprintw(10, 10, "Farther down");
    getch();
    clear();    // wclear(): "hard clear"


    getch();
    endwin();

    return 0;
}