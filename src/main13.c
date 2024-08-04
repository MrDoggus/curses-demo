#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();
    noecho();
    raw();

    char ch;
    while (ch = getch())
    {
        // CTRL+A -> 0x01, CTRL+B -> 0x02, ... , 
        // CTRL+G -> 0x07, CTRL+H -> 0x7F, CTRL+I -> 0x09, ...
        // CTRL+J -> nothing?, CTRL+K -> 0x0b, CTRL+L -> 0x0c, ...
        // CTRL+O -> 0x0f, CTRL+P -> 0x10, ..., CTRL+Z -> 0x1a
        // ctrl+[key] = (key & 0x1f)l 
        mvprintw(1, 0, "KEY NAME: %s - 0x%02x\n", keyname(ch), ch);
    }

    endwin();
    return 0;
}