#include<stdio.h>
#include<string.h>
void Hang(char A[][7], int n ,int m)
{ 
  for(int x=0 ; x<n ; x++)
  {
        for(int i=0; i<m-1; i++)
        {
                for(int j= i+1; j<m; j++ )
                {
                        if (A[x][i]>A[x][j]) 
                        {
                       
                        char temp = A[x][i];
                        A[x][i] = A[x][j];
                        A[x][j] = temp;     //use bubble sort arrange every element in row
                        }
                }
        }
  }
}
void Lie(char A[][7], int n ,int m)
{
   for(int x=0 ; x < n-1 ; x++)
   {
        int sum1= 0;
        int sum2= 0;
        for(int i= 0; i<m; i++)
        {
             
              sum1 +=A[x][i];
              sum2 +=A[x+1][i]; 
        }
              if (sum1 > sum2)  //sum ascii at adjacent two row and compare them
              { 
                 for(int i=0; i<m; i++)
                 {
                     char temp;
                     temp = A[x][i];
                     A[x][i] = A[x+1][i];
                     A[x+1][i] = temp; //use bubble sort arrange every row
                 }
               }
        
   }
}


int main()
{
         int n=3;
         int m=6;
         char A[3][7]={
                       {'S','D','U','Y','E','S','\0'},
                       {'C','H','I','N','A','!','\0'},
                       {'A','F','T','E','R','X','\0'}
                       };
         Hang(A, n ,m-1); //don't sort the last "\0"
         Lie(A, n ,m-1);
         for(int i=0 ;i<3 ; i++)
         {
             printf("%s\n",A[i]);
         }
             
return 0;
}        
