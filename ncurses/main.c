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

    #define ESC_KEY 27
#define LEN_INPUT_BUFF 280
#define MAX_OUTPUT_LINES 5

char *create_char_buffer(char *i_buf) { 
    char *char_arr = malloc(LEN_INPUT_BUFF);
    if (char_arr == NULL) return NULL;
    return memcpy(char_arr, i_buf, LEN_INPUT_BUFF);
}

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
    char **output_buffer = malloc((MAX_OUTPUT_LINES) * sizeof(char));

    size_t cursor_p = 0;
    int ch;
    /*
        TODO: we need an output buffer to keep line number analogous to cursor
        pos and stores input buffer output in a char **(an array of strings) ex char[MAX_LINES][LEN_INPUT_BUFFER]
    */
    // 27 is char code for ESC key
    // ncurses gives you macro for backspace key
    int o_idx = 0;
    int c_out_start = 2;
    while((ch = wgetch(w_in)) != ESC_KEY){
        if(ch == '\n') {
            output_buffer[o_idx] = create_char_buffer(input_buffer);          
            memset(input_buffer, 0, LEN_INPUT_BUFF);
            mvwprintw(w_out, c_out_start++, 1, "%s", output_buffer[o_idx]);
            wrefresh(w_out);
            if (o_idx++ == MAX_OUTPUT_LINES - 1) {
                // reset output lines
                mvwprintw(w_out, c_out_start, 1, "%s", "max lines reached, resetting on next entry...");
                wrefresh(w_out);
                o_idx = 0;
                c_out_start = 2;
                while (o_idx < MAX_OUTPUT_LINES + 1) {
                    if (output_buffer[o_idx] != NULL) memset(output_buffer[o_idx], 0, LEN_INPUT_BUFF);
                    wmove(w_out, c_out_start + o_idx, 1); wclrtoeol(w_out);
                    o_idx++;
                }
                output_buffer[0] = (char *) memcpy(output_buffer[0], input_buffer, LEN_INPUT_BUFF);
                mvwprintw(w_out, c_out_start, 1, "%s", output_buffer[0]);
                wrefresh(w_out);
                o_idx = 0;
                c_out_start++;
            }
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
    // getch(); // this will block until a key is pressed
    delwin(w_out);
    delwin(w_in);
    endwin();
    return 0;
}
