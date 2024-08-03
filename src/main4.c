#ifdef _WIN32
    #include <curses.h>
#else 
    #include <ncurses.h>
#endif

int main()
{
    initscr();

    cbreak(); // cntl c exits out of program
    noecho(); // doesnt echo inputed characters

    // Check to see if term has colors
    if (!has_colors())
    {
        printw("Terminal doesnt support colors");
        getch();
        endwin();
        return 1;
    }
    // If has color, start color
    start_color();

    /*  Colors
        COLOR_BLACK     : 0
        COLOR_RED       : 1
        COLOR_GREEN     : 2
        COLOR_YELLOW    : 3
        COLOR_BLUE      : 4
        COLOR_MAGENTA   : 5
        COLOR_CYAN      : 6
        COLOR_WHITE     : 7
    */

    // Check if the terminal can change a default color    
    if (can_change_color())
    {
        printw("can change colors");

        // Change a default color to a different rbg value. 
        // init_color(COLOR_CYAN, r:0-999, g:0-999, b:0-999)
        init_color(COLOR_CYAN, 999, 600, 600);  // Make cyan pink
    }
    else
    {
        printw("cannot change colors");
    }
    
    
    // init a new color pair
    init_pair(1, COLOR_CYAN, COLOR_WHITE);

    

    /*  Attributes: 
        A_NORMAL        : Normal display 
        A_STANDOUT      : "Best highlighting mode of the terminal"
        A_UNDERLINE     : Underlining 
        A_REVERSE       : Reverses forground and background color
        A_BLINK         : Blinking
        A_DIM           : Half bright
        A_BOLD          : Extra bright or bold
        A_PROTECT       : Protected mode
        A_INVIS         : Invisible or blank mode
        A_ALTCHARSET    : Alternate character set
        A_CHARTEXT      : Bit-mask to extract a character
    
    */

    // Attributes 
    attron(A_BLINK | COLOR_PAIR(1));

    printw("This is some text");

    // Attributes off
    attroff(A_BLINK);

    getch();
    endwin();

    return 0;
}