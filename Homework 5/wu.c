#include<stdio.h>
void board(char B[15][15])
{
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			printf("%c",B[i][j]);
		
		       if (j< 15)
		       {
		          printf ("|");
		       }
		}
		printf("\n");
	}
}

int win(char B[15][15] ,char player ,int row, int col )
{
       	int x = row;
	int count =1;

        while (x > 0 && B[x-1][col] == player)
       	{
                count++;
                x--;
        }
        while (x < 14 && B[x+1][col] == player)
       	{
                count++;
                x++;
        }
        if (count >= 5)
	return 1;

        int y = col;
	count = 1;

	while(y > 0 && B[row][y-1] == player)
	{
		count++;
		y--;
	}
	while (y < 14 && B[row][y+1] == player)
	{
		count++;
		y++;
	}

        count = 1;
	x = row;
	y = col;
        while (x>0 && y>0 && B[x-1][y-1] == player)
	{
		count++;
		x--;
		y--;
	}
	while (x<14 && y<14 && B[x+1][y+1] == player)
	{
		count++;
		x++;
		y++;
	}
        while(x<14 && y>0 && B[x-1][y+1] == player)
	{
		count++;
		x++;
		y--;
	}
	while(x>0 && y<14 && B[x+1][y-1] == player)
	{
		count++;
	        x--;
		y++;
	}

}

int Ping (char B[15][15])
{
	for(int i=0; i<15;i ++)
	{
		for(int j=0; j<15; j++)
		{
			if (B[i][j] == ' ');
			
			return 0;
		}
	}
	return 1;
}

int main ()
{
	char B[15][15]={ {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
	                 {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
			 {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '},
                         {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '}};

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
               if (row < 0 || row >= 15 || col < 0 || col >= 15 || B[row][col] != ' ')
	       {
                     printf(" Try again.\n");
                     continue;
	       }
	       B[row][col] = plays[currentplayer];

	       if(win(B ,plays[currentplayer],row ,col)  == 1)
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
                   

