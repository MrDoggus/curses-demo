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
        endwin();
        printf("color cant be used\n");
        return 1;
    }

    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    // set attribute type with reversed colors and color pair 2
    attr_t emphasis = A_REVERSE | COLOR_PAIR(2);

    // print 'a' with the above attribute
    attron(emphasis);
    mvaddch(5, 5, 'a');
    attroff(emphasis);

    // store attribute with a character using chtype
    chtype c = 'a' | A_REVERSE | COLOR_PAIR(2);
    mvaddch(7, 5, c);

    getch();
    endwin();

    return 0;
}