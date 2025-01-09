#include<stdio.h>
void matrix_multi(double A[3][4], double B[4][5], double C[3][5])
{
	for (int i=0; i<3; i++)
	{
		for(int j=0; j<5; j++)
		{
		        for(int n=0; n<4; n++) // cycle the row of A and the col of B
			{
			
			    C[i][j]+=A[i][n]*B[n][j]; //count C by formula of matrix multiplication
			
			}
		}
	}
}

int main()
{
	double A[3][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	double B[4][5]= {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{6,7,8,9,10}};
        double C[3][5]= {0};
        matrix_multi(A ,B,C);
	for(int i=0 ;i<3; i++)
	{
	        printf("\n");
	        
		for(int j=0; j<5; j++)
		{
	               printf("%f ", C[i][j]);
		}
	}
	
	printf("\n");
	return 0;
}

