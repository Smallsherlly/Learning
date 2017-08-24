#include<stdio.h>
#define y (date1->iYear)
#define m (date1->iMon)
#define d (date1->iDay)
struct date
{
	int iYear;
	int iMon;
	int iDay;
};

int dayplus(struct date *date1,int n)
{
	while(n--)
	switch(m)
	{
		case 1:
		{
			if(d<31)
			{
				//printf("%d",d);

				d=d+1;
			//	printf("%d",d);
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 2:
		{
			if(y%4==0&&y%100!=0||y%400==0)
			{
				if(d<29)
				{
					d=d+1;
				}else{
					m++;
					d = 1;
				}
			}else{
				if(d<28)
				{
					d=d+1;
				}else{
					m++;
					d = 1;
				}
			}
			break;
		}
		case 3:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 4:
		{
			if(d<30)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 5:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 6:
		{
			if(d<30)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 7:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 8:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 9:
		{
			if(d<30)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 10:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 11:
		{
			if(d<30)
			{
				d=d+1;
			}else{
				m++;
				d = 1;
			}
			break;
		}
		case 12:
		{
			if(d<31)
			{
				d=d+1;
			}else{
				y++;
				m = 1;
				d = 1;
			}
			break;
		}
	}
	
}
int main()
{
	struct date date1;
	int n = 0;
	printf("请输入一个初始日期。（格式参考‘2017 6 16’）\n");
	scanf("%d %d %d",&date1.iYear,&date1.iMon,&date1.iDay);
	printf("请输入经过的天数：\n");
	scanf("%d",&n);
	dayplus(&date1,n);
	printf("%d天后的日期为%d %d %d\n",n,date1.iYear,date1.iMon,date1.iDay);
	
	return 0;	
}

