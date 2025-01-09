#include<stdio.h>
int main()
{
	int A[2][3]= {{1,2,3},{4,5,6}};
	for(int i=0; i<2;i++)
	{
	    
	    for(int j=0; j<2; j++)
	    {
	         int diff = A[i][j+1] - A[i][j];
	         printf("%d",diff); //count the difference between A[i][j] and the next element 
	    }
		
	}
	return 0;
}

