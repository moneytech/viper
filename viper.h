#ifndef __VIPER_H__
#define __VIPER_H__

#define SHORTHELP "%s [OPTIONS] [FIELDSIZE]\n"
#define LONGHELP \
	"OPTIONS:\n" \
	"    -s(peed) N\n" \
	"    -l(ength) N\n" \
	"    -h(elp)\n" \
	"FIELDSIZE:\n" \
	"    WxH (width 'x' height)\n" \
	"    defaults to 30x20\n" \
	"\n" \
	"Keybindings:\n" \
	"    hjkl: move left/down/up/right\n" \
	"    p:    pause / unpause\n" \
	"    r:    start a new game\n" \
	"    q:    quit\n"

struct snake {
	int r; /* row */
	int c; /* column */
	struct snake* next; /* points to tail */
};
struct item {
	int r; /* row */
	int c; /* column */
	int t; /* type */
	int v; /* value */
	int s; /* spawn time (for bonus) */
	struct item* prev;
	struct item* next;
};
enum direction {
	NONE,
	NORTH,
	EAST,
	SOUTH,
	WEST,
};
enum item_type {
	NO_ITEM,
	FOOD,
	BONUS,
};
enum food_value {
	FOOD_PEAR,
	FOOD_WMELON,
	FOOD_BANANA,
	FOOD_KIWI,

	FOOD_APPLER,
	FOOD_CHERRY,

	FOOD_AVOCADO,
	NUM_FOODS,
};
enum bonus_value {
	BONUS_SNIP,
	BONUS_GROW,
	BONUS_SLOW,
	BONUS_FAST,
	BONUS_WRAP,
	BONUS_STOP,
	NUM_BONI,
};
enum game_state {
	GAME_INIT,
	GAME_START,
	GAME_OVER,
	GAME_WON,
	GAME_EXIT,
};

int viper(void);
void snake_advance (void);
void spawn_item (int type, int value, struct item* p_item);
void consume_item (struct item* i);
void show_playfield (void);
void draw_sprites (int erase_r, int erase_c);
void pause_game (void);
int end_screen(char* message);
void snake_append (struct snake** s, int row, int col);
void remove_bonus (struct item*  i);
void init_snake();
void quit (void);
int getctrlseq (void);
void append_movement (int d);
void move_ph (int line, int col);
void clamp_fieldsize (void);
void timer_setup (int enable);
void signal_setup (void);
void signal_handler (int signum);
void screen_setup (int enable);
void raw_mode(int enable);
enum event {
	/* for getctrlseq() */
	CTRSEQ_NULL    =  0,
	CTRSEQ_EOF     = -1,
	CTRSEQ_INVALID = -2,
	CTRSEQ_MOUSE   = -3,
	CTRSEQ_CURSOR_LEFT  = -7,
	CTRSEQ_CURSOR_DOWN  = -8,
	CTRSEQ_CURSOR_UP    = -9,
	CTRSEQ_CURSOR_RIGHT = -10,
};

#endif
