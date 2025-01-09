#include<stdio.h>
void printletter(char letter)
{         int i = 0;
          switch( letter )
	   {
		   case 'A':
			   printf("    *    \n");
			   printf("   * *   \n");
			   printf("  *   *  \n");
			   printf(" ******* \n");
			   printf("*       *\n");
			   break;
	           case 'E':
			   printf("*********\n");
			   printf("*        \n");
			   printf("*        \n");
			   printf("*******  \n");
			   printf("*        \n");
			   printf("*        \n");
			   printf("*********\n");
			   break;
	           case 'T':
	                  printf("***********\n");
	                  printf("     *     \n");
	                  printf("     *     \n");
	                  printf("     *     \n");
	                  printf("     *     \n");
	                  printf("     *     \n");
	                  printf("     *     \n");
	                  break;		                 
		                
		   case 'H':
	                  printf("*       *  \n");
	                  printf("*       *  \n");
	                  printf("*       *  \n");
	                  printf("*********  \n");
	                  printf("*       *  \n");
	                  printf("*       *  \n");
	                  printf("*       *  \n");
	                  break;	     
		                
		                } //function to print patten according to letter
}      
int main()
{
	char input[5] ;
        scanf("%4s",input); //storage letter in the array
        for(int i=0; i<5; i++)
       {
            printletter(input[i] ); //print the patten 
            printf("\n");
       }
  return 0;
	
}
