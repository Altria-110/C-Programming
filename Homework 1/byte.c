#include<stdio.h>
int main ()
{
    char * c = " a ";
    short s = 10;
    int i = 1;
    double d = 1.11;
    float f =1.11f;
    long l =100;
    long long o = 10000;
    unsigned short u = 11;
    
    printf("The size of int is %ld bytes.\n", sizeof(int) );
    printf("The size of char is %ld bytes. \n", sizeof(char *) );
    printf("The size of short is %ld bytes.\n", sizeof(short) );
    printf("The size of long is %ld bytes.\n", sizeof(long) );
    printf("The size of float is %ld bytes.\n", sizeof(float) );
    printf("The size of double is %ld bytes.\n", sizeof(double) );
    printf("The size of long long is %ld byres.\n", sizeof(long long) );
    printf("The size of unsigned short %ld bytes.\n", sizeof(unsigned) );

    return 0;
} 
