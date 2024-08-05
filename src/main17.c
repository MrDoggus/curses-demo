#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();
    noecho();
    refresh();

    // idlok(WINDOW*,  bool); 
    // idcok(WINDOW*,  bool); 

    // clearok(WINDOW*,  bool); // next tiem we run refresh, we want to make sure everything is refreshed (clear and redraw)
    // immedok(WINDOW*,  bool); // Tells drawing functions that you can refresh immediatly. Makes it so you dont have to refresh window
    // leaveok(WINDOW*,  bool); // Can redraw window, dont need to redraw cursor
    // scrollok(WINDOW*,  bool); // Scrolling effect. If text is to large to display in window, it will shift the text up (removing the first line in the process)

    WINDOW* win = newwin(5, 8, 10, 10);
    box(win, 0, 0);

    // leaveok(win, true);
    // wmove(win, 1, 2);
    // wgetch(win);

    // immedok(win,  true); 
    // waddch(win, 'a');

    // scrollok(win,  true); 
    // int counter = 0;
    // while (true)
    // {
    //     chtype ch = (counter % 10) + '0';
    //     waddch(win, ch);
    //     wrefresh(win);
    //     counter++;
    // }

    clearok(win, true); 
    int c;
    while ((c = wgetch(win)) > 0) {
        clear();
        wrefresh(win);
        refresh();

        waddch(win, c);
        box(win, 0, 0);
        wrefresh(win);
        refresh();
    }
    

    getch();
    endwin();

    return 0;
}