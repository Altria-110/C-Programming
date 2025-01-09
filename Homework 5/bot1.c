#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void board(char B[3][3])
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%c",B[i][j]);
		
		       if (j< 3)
		       {
		          printf ("|");
		       }
		}
		printf("\n");
	}
}

int win(char B[3][3] ,char player)
{
	for(int i=0; i<3 ;i++)
	{
	        if(B[i][1] == player && B[i][2]==player && B[i][0]==player)

		return 1;
	}

	 for(int j=0; j<3 ;j++)
        {
                if(B[1][j] == player && B[2][j]==player && B[0][j]==player)

                return 1;
        }
        
	 if (B[0][0] == player && B[1][1]==player &&B[2][2]==player)

	 return 1;

	 if (B[0][2] ==player && B[1][1] ==player &&B[2][0] ==player)

	 return 1;
}

int Ping (char B[3][3])
{
	for(int i=0; i<3;i ++)
	{
		for(int j=0; j<3; j++)
		{
			if (B[i][j] == ' ');
			
			return 0;
		}
	}
	return 1;
}


typedef struct
{
    int row;
    int col;
} Move;

Move aiMove(char B[3][3], char player) 
{
   
   int moves[9][2] = {
                     {0, 0}, {0, 2}, {2, 0}, {2, 2}, 
                                  {1, 1},                         
                     {0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (int i = 0; i < 8; i++) 
    {
        int r = moves[i][0];
        int c = moves[i][1];
        if (B[r][c] == ' ') 
        {
            B[r][c] = player;
            return (Move){r, c};
        }
    }
   
    srand(time(NULL)); 
    Move randomMove;
    do 
    {
        randomMove.row = rand() % 3;
        randomMove.col = rand() % 3;
    }
     while (B[randomMove.row][randomMove.col] != ' ');
     B[randomMove.row][randomMove.col] = player;
    return randomMove;
}



int main ()
{
	char B[3][3]={ {' ', ' ', ' '},
		       {' ', ' ', ' '},
		       {' ', ' ', ' '}};
	int currentplayer = 0;
	char plays[2] = {'X','O'};
	int gamewin =0;
	int gameping =0;

	while (!gamewin ==1 && !gameping ==1)
	{
	      board(B);
              int row ,col;
              if (currentplayer == 0)
              {

                 printf("Player %d:",currentplayer + 1);
	         scanf("%d %d", &row, &col);
                 while (row < 0 || row >= 3 || col < 0 || col >= 3 || B[row][col] != ' ')
	         {
                     printf(" Try again.\n");
                     
	         }
	         B[row][col] = plays[currentplayer];

	         if(win(B ,plays[currentplayer])  == 1)
	         { 
		     printf("palyer %d win\n", currentplayer +1);
                     gamewin = 1;
                 }
               }
               else
               {
                  printf("computermove\n");
	          aiMove(B ,plays[currentplayer]);
	          printf("It's your time\n"); 
	          if(win(B ,plays[currentplayer])  == 1)
	         { 
		     printf("palyercomputer win\n");
                     gamewin = 1;
                 } 
	          else if(Ping(B) == 1)
		  {
		     printf("It's a draw\n");
		     gameping =1;
                 }
	        
		     
	      }
	      currentplayer = (currentplayer +1) %2;
	         
	}

	return 0;
}	
                   



