#include<stdio.h>
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

              printf("Player %d:",currentplayer + 1);
	      scanf("%d %d", &row, &col);
               if (row < 0 || row >= 3 || col < 0 || col >= 3 || B[row][col] != ' ')
	       {
                     printf(" Try again.\n");
                     continue;
	       }
	       B[row][col] = plays[currentplayer];

	       if(win(B ,plays[currentplayer])  == 1)
	       {
		     printf("palyer %d win", currentplayer +1);
                     gamewin = 1;
               }
	       else if(Ping(B) == 1)
		{
		     printf("It's a draw");
		     gameping =1;
               }
	       else 
	       {
		     currentplayer = (currentplayer +1) %2;
	       }
	}

	return 0;
}	
                   
                   



			

