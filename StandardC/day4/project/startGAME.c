#include"push.h"
#include<stdio.h>
#include<stdlib.h>
extern int step;
void startGAME()
{
int arr[7][8] = 
	{{0,1,1,1,1,1,1,0},
	 {0,1,0,0,0,0,1,1},
	 {1,3,0,1,1,2,0,1},
	 {1,0,3,3,2,0,0,1},
	 {1,0,0,1,2,0,0,1},
	 {1,0,0,4,0,1,1,1},
	 {1,1,1,1,1,0,0,0}};
	int brr[7][8] = {};
	for(int i = 0;i < 7;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			brr[i][j] = arr[i][j];	
			
		}
		
	}
	
	while(1)
	{
		system("clear");	
		map(arr);
		move(arr,brr);
		/*if(lose(arr) == 0)
		{
			system("clear");
			map(arr);
			printf("\n\n\n\n很遗憾，本次挑战失败！\n");
	
			while(get_direction()!=10){}

				for(int i =0;i<7;i++)
				{
					for(int j = 0;j<8;j++)
					{
						arr[i][j] = brr[i][j];			
					}
					step = 0;
				}

				iX = 5;
				iY = 3;
		}*/
		if(judge(arr) == 0)
		{
			system("clear");
			map(arr);
			printf("\n\n\n\n恭喜你，获得胜利！你的总步数为%d。\n",step);
	
			break;
		}
	}
}	
