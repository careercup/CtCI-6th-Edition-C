#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * store column value in row array. hence, no need to have a 2 dimentional 8x8
 * array.
 * 0 means that row is not used. hence, size of array is 8+1=9.
 */
int board[9];

void print(int n)
{
 	int i, j;
	static int count = 1;

 	printf("-----------------------------------------------------------------\n");
 	printf("Solution %d:\n", count++);

 	for (i = 1; i <= n; i++)
  		printf("\t%d", i);
 	for (i = 1; i <= n; i++) {
  		printf("\n\n%d", i);
  		for (j = 1; j <= n; j++) {
   			if (board[i] == j)
    				printf("\tQ"); //queen at i,j position
   			else
    				printf("\t-"); //empty slot
  		}
 	}
 	printf("\n-----------------------------------------------------------------\n\n");
}

int place(int row, int column)
{
 	int i;

 	for (i = 1; i <= row - 1; i++) {
		if (board[i] == column)
   			return 0;
  		else if (abs(board[i] - column) == abs(i - row))
    			return 0;
 	}

 	return 1; //no conflicts
}

void queen(int row, int n)
{
 	int column;

 	for (column = 1; column <= n; column++) {
  		if (place(row, column)) {
   			board[row] = column; //no conflicts so place queen
   			if (row == n) /* placed 8 queens. */
    				print(n);
   			else /* try queen with next position */
    				queen(row + 1, n);
  		}
 	}
}

int main(void)
{
 	queen(1, 8);
 	return 0;
}

