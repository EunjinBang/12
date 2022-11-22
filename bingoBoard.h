#define N_SIZE 	5
#define BINGO_NUMSTATUS_ABSENT	-1
#define BINGO_NUMSTATUS_PRESENT	0
#define N_BINGO	2

void bingo_init(void);
void bingo_printBoard(void);
void bingo_inputNum(int sel);
int bingo_countCopmpletedLine(void);
int get_number(void);
