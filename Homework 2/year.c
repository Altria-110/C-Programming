#include<stdio.h>
int runyear(int y)
{
	return(y%4 == 0 && ! y%100 == 0 || y%400 == 0);
		}

int days(int y, int m, int d)
{
	int day=0;
	

	for(int i= 2024; y<i; y++)
	{
	      day+= runyear(y) ? 366:365;
	}
	int mday[]={31, 28 ,31, 30 ,31 ,30 ,31, 31 ,30, 31 ,30, 31};
	if (runyear(y))
	{
	       	mday[1]= 29;
	}

	for(int i=0; i < m-1;i++)
	{
		day+=mday[i];
	}
        day+=d;
	
	return day;
}
int main()
{	int y;
        int m;
        int d;
	scanf("%d %d %d",&y, &m, &d);
	
        int day = days(y,  m,  d);
        int weekday =( day)%7;
        char* week[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
	printf("%s\n",week[weekday]);

	return 0;
	}
 	
