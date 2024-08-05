#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();

    WINDOW* testwin = newwin(10, 25, 0, 0);
    box(testwin, 0, 0);
    refresh();
    wrefresh(testwin);

    getch();

    delwin(testwin);    // Frees a window
    
    endwin();

    return 0;
}