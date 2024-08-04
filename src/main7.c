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
    WINDOW* menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    // Allows you to use keys such as arrows/function keys
    keypad(menuwin, true);

    // Menu options
    char choices[3][5] = {
        "Walk",
        "Jog",
        "Run"
    };
    int choice;
    int highlight = 0;

    int doloop = 1;
    while (doloop)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                mvwprintw(menuwin, i+1, 1, "highlight = %d", highlight);
                continue;
            }

            if (i == highlight)
            {
                wattron(menuwin, A_REVERSE);
            }

            mvwprintw(menuwin, i+1, 1, "%s", choices[i]);
            wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight-1)%3;
            if (highlight < 0)
                highlight += 3;
            /* code */
            break;

        case KEY_DOWN:
            highlight = (highlight+1)%3;
            break;
        case 10:
            doloop = 0;
            break;
        default:
            break;
        }

        // refresh();
        // wrefresh(menuwin);
    }

    printw("Your choice was: %s", choices[highlight]);

    getch();
    endwin();

    return 0;
}