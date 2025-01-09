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

int  getdayinmonth(int y ,int m){
	int dayinmonth[] = {31, runyear(y) ? 29:28,31,30,31,30,31,31,30,31,30,31};
	return dayinmonth[m - 1];
	}
int main()
{	int y;
        int m;
        
	scanf("%d %d",&y,&m);
	
        int day = days(y,  m,  1);
        int weekday =( day)%7;
        char* week[]={"sun","mon","tue","wed","thu","fri","sat"};
	int dayinmonth = getdayinmonth(y,m);
	printf("%s %s %s %s %s %s %s \n",week[0],week[1],week[2],week[3],week[4],week[5],week[6]);
        for(int x = 0;x < weekday; x++)
			{
			printf("    ");
			}
			
	for(int i=1; i <=dayinmonth; i++){
		printf("%4d",i);
		   if((i + weekday - 1) % 7 ==6|| i == dayinmonth){  printf("\n");
		
		}
	}
	return 0;
	}
	
	
