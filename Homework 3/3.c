#include<stdio.h>
#include<stdbool.h>


bool Safe(int A[8][8], int row, int col)
{
	for(int i=0; i<row; i++) 
	{
		if(A[i][col] == 1)// check if other row have queen in the col
		{
			return false;
		}
	}

	for(int i=row, j=col; i>=0 && j>=0; i--,j--)
	{
		if(A[i][j] == 1)// check if have queen on the left diagonal
		{
			return false;
		}
	}

	for(int i=row, j=col; i>=0 && j<8; i--,j++)
	{
		if(A[i][j] == 1)// check if have queen on the right diagonal
		{
			return false;
		}
	}
	
	return true;
}

void printsolution( int A[8][8] )
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}//print schemes




void allput(int A[8][8], int row)
{
	if(row>= 8)
	{          
	        printsolution(A);
	        printf("\n");
		//find a scheme print it
	}

	
	    for (int col=0 ; col<8; col++)//put queen at the first col
	    
	    {
		if( Safe(A, row, col))
		{
			A[row][col] = 1;
			allput(A, row+1);//recursion to put all queen
			A[row][col] = 0; //if the next row can't put queen , back and reposition the queen
		}
	    }
        
	

}





int main()
{
     int row = 0;
     int A[8][8] ={0};
     allput(A, row) ;
    
     return 0;
}


