//it is used to call the function1,2 and print their reture
#include<stdio.h>
#include"module.h"
int main ()
{
	int x;
	int y;
	x = function1();
	y = function2();

	printf("function1:%d\n", x);
        printf("function2:%d\n", y);
        printf("%d\n",global);
 
return 0;
}

