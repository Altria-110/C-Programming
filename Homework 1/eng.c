#include<stdio.h>
void printletter(char letter);
int main()
{
     char letter;
	   scanf("%c",&letter);
	   printletter(letter);
	   return 0;
}
void printletter(char letter)
{         
          switch(letter)
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
		                } 
}      
