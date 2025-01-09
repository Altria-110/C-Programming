#include<stdio.h>
void Selection(int A[],int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min = i;
		for(int j=i+1; j<n; j++)
		{
			if( A[j] < A[min] )
			   min = j; //select the min number behind A[i]
		}
        
               int temp = A[i];
	        A[i] = A[min];
                A[min] = temp; //exchange the min number with A[i]
         
	
        }
}

 
void Mao(int A[], int n)
{
        for(int i=0; i<n-1; i++)
        {
                for(int j= i+1; j<n; j++ )
                {
                        if (A[j]<A[i]) 
                        {
                           int temp = A[i];
                           A[i] = A[j];
                           A[j] = temp; //if the number behind A[i] smaller exchange it with A[i] until every number behind A[i] bigger than A[i]
                        }
                }
        }
}

                      
int main()
{       int n = 10;
        int A[]={29, 28 , 129 ,38, 39 ,10 ,92 ,21, 30 ,13};
     	Selection(A, n);

	for(int i=0; i<n ; i++)
	{
		printf("%d " ,A[i]);
	}
	printf("\n");
	
	Mao(A , n);
	for(int i=0 ; i<n ; i++)
	{
	        printf("%d ",A[i]);
	}        
	
return 0;
}
