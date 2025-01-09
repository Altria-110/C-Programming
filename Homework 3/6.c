#include<stdio.h>
int two_dim_array_access(int *x, int i, int j, int m, int n, int C)
{
	int a = C*m + n; //count the address of the element

	return *(x + a); //return the address we need
}

int main()
{       
       int A[2][3] = {{1,2,3},{4,5,6}};
       printf("%d", two_dim_array_access( &A[0][0],0,1,1,2,3));
       printf("\n");
       printf("%d", two_dim_array_access( &A[0][0],0,0,1,2,3));
        
       return 0;
}


