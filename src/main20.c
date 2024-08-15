#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

#define PINK 8

int main()
{
    initscr();

    if (!has_colors())
    {
        printw("Your terminal doesnt support colors.");
        getch();
        return 0;
    }

    start_color();

    init_color(COLORS-1, 976, 375, 554);

    init_pair(COLOR_PAIRS-1, COLORS-1, COLOR_BLACK);

    attron(COLOR_PAIR(COLOR_PAIRS-1));

    // Print existing color ids
    printw("%-13s: %d\n%-13s: %d\n\n",
        "COLORS", COLORS,
        "COLOR_PAIRS", COLOR_PAIRS
    );

    printw("%-13s: %d\n%-13s: %d\n%-13s: %d\n%-13s: %d\n%-13s: %d\n%-13s: %d\n%-13s: %d\n%-13s: %d\n\n",
        "COLOR_BLACK", COLOR_BLACK,
        "COLOR_RED", COLOR_RED,
        "COLOR_GREEN", COLOR_GREEN,
        "COLOR_YELLOW", COLOR_YELLOW,
        "COLOR_BLUE", COLOR_BLUE,
        "COLOR_MAGENTA", COLOR_MAGENTA,
        "COLOR_CYAN", COLOR_CYAN,
        "COLOR_WHITE", COLOR_WHITE
    );

    attroff(COLOR_PAIR(COLOR_PAIRS-1));

    getch();
    endwin();

    return 0;
}