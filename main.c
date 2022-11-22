#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

#define BINGO_RES_UNFINISHED	-1
#define BINGO_RES_FINISHED		0
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int get_number(void){
	int selNum=0;
	
	do{
		printf("select a number : ");
		scanf("%d", &selNum);
		fflush(stdin);
		
		if(selNum < 1 || selNum > N_SIZE*N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT){
			printf("%i is not on the board! select the other one.\n", selNum);
		}
	} while (selNum < 1 || selNum > N_SIZE*N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT);
	
	return selNum;
}


int check_gameEnd(void){
	int res = BINGO_RES_UNFINISHED;
	
	if (bingo_countCompletedLine() >= N_BINGO)
		res = BINGO_RES_FINISHED;
		
	return res;
}

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	
	//opening
	printf("======================================================\n");
	printf("******************************************************\n");
	printf("                      BINGO GAME                      \n");
	printf("******************************************************\n");
	printf("======================================================\n\n\n");
	
	
	//game
	/*
	//test
	bingo_init();
	bingo_printBoard();
	
	test
	bingo_inputNum(8);
	bingo_printBoard();
	bingo_inputNum(25);
	bingo_printBoard();
	bingo_inputNum(18);
	bingo_printBoard();
	
	
	
	int selNum;
	selNum = get_number();
	bingo_inputNum(selNum);
	bingo_printBoard();
	*/
	bingo_init();
	
	while(check_gameEnd() == BINGO_RES_UNFINISHED)
	{
		int selNum;
		
		bingo_printBoard();
		printf("No. of completed lines : %i\n", bingo_countCompletedLine());
		selNum = get_number();
		bingo_inputNum(selNum);
	}
		
	
	//initialize bingo board
	
	/*
	while (game is not end) //줄 수가 N_BINGO보다 작음 
	{
		//bingo board print
		
		//print no.of completed line
		
		//select a number
		
		//update the board status
	}
	*/
	
	bingo_printBoard();
	printf("No. of completed lines : %i\n", bingo_countCompletedLine());
	
	//ending
	printf("\n\n\n\n\n\n");
	printf("======================================================\n");
	printf("******************************************************\n");
	printf("********                                    **********\n");
	printf("********               BINGO!!!             **********\n");
	printf("********           CONGRATULATION!!!        **********\n");
	printf("********              YOU WIN!!!            **********\n");
	printf("********                                    **********\n");
	printf("******************************************************\n");
	printf("======================================================\n\n\n");
	
	return 0;
}
