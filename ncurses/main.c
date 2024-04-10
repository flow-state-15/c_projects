#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void ui_init(void) {
    initscr();
    noecho();
    curs_set(0);
    set_escdelay(0);
}

#define LEN_INPUT_BUFF 280

int main(void) {
    ui_init();
    // get current terminal dimensions
    int height = getmaxy(stdscr);
    int width = getmaxx(stdscr);

    WINDOW *w_out = newwin(height - 5, width - 2, 1, 1); //takes 4 ints of col/row: height, width, startx, starty 
    if (w_out == NULL) {
        fprintf(stderr, "new window failure\n");
        exit(EXIT_FAILURE);
    }
    box(w_out, 0, 0);

    mvwprintw(w_out, 1, 1, "hello screen!\n");

    WINDOW *w_in = newwin(3, width - 2, height - 3, 1);
    box(w_in, 0, 0);
    mvwprintw(w_in, 1, 1, " > ");

    refresh();
    wrefresh(w_out);
    wrefresh(w_in);
    // printw prints to standard screen by default
    // printw("hello screen!\n");

    char input_buffer[LEN_INPUT_BUFF] = {0};
    size_t cursor_p = 0;
    int ch;
    /*
        TODO: we need an output buffer to keep line number analogous to cursor
        pos and stores input buffer output in a char **(an array of strings) ex char[MAX_LINES][LEN_INPUT_BUFFER]
    */
    // 27 is char code for ESC key
    // ncurses gives you macro for backspace key
    #define ESC_KEY 27
    while((ch = wgetch(w_in)) != ESC_KEY){
        if(ch == '\n') {
            mvwprintw(w_out, 1, 1, "%s", input_buffer);
            wmove(w_in, 1, 3);
            memset(input_buffer, 0, LEN_INPUT_BUFF);
            wclrtoeol(w_in);
            cursor_p = 0;
            wrefresh(w_in);
            wrefresh(w_out);
        } else if (cursor_p < LEN_INPUT_BUFF){
            input_buffer[cursor_p++] = (char) ch;
            mvwprintw(w_in, 1, 4, "%s", input_buffer);
            wrefresh(w_in);
        }
    }
    getch(); // this will block until a key is pressed
    delwin(w_out);
    delwin(w_in);
    endwin();
    return 0;
}
