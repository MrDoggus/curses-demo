#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();

    if (!has_colors())
    {
        return 1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    // int chgat(int: num of chars to change from curr pos, attr_t: atribute to set, short: color pair to set, const void *: not used, pass null)
    // chgat = wchgat(stdscr, n, attr, color, opts); mvchgat = mvwchgat(stdscr)
    // chgat doesnt move the cursor

    printw("Hello World");

    move(2, 0);
    chgat(5, A_STANDOUT, 0, NULL);

    move(4, 0);
    chgat(-1, A_STANDOUT, 0, NULL); // n = -1 -> Set attr to end of row

    move(6, 8);
    chgat(-1, A_STANDOUT, 0, NULL); // from curr column to end of row

    // highlight "World"
    mvchgat(0, 6, 5, A_STANDOUT, 1, NULL);


    getch();
    endwin();

    return 0;
}