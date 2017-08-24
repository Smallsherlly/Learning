#include<stdio.h>
#include<stdlib.h>
#include<get_direction.h>
#include<time.h>
//这是个推箱子的小游戏
int map();
int move();
int iX = 5,iY = 3;
int judge();
int step = 0;
int lose();

int main()
{
	int arr[7][8] = 
	{{0,1,1,1,1,1,1,0},
	 {0,1,0,0,0,0,1,1},
	 {1,3,0,1,1,2,0,1},
	 {1,0,3,3,2,0,0,1},
	 {1,0,0,1,2,0,0,1},
	 {1,0,0,4,0,1,1,1},
	 {1,1,1,1,1,0,0,0}};
	int brr[7][8] = 
	{{0,1,1,1,1,1,1,0},
	 {0,1,0,0,0,0,1,1},
	 {1,3,0,1,1,2,0,1},
	 {1,0,3,3,2,0,0,1},
	 {1,0,0,1,2,0,0,1},
	 {1,0,0,4,0,1,1,1},
	 {1,1,1,1,1,0,0,0}};
	
	
	while(1)
	{
		system("clear");	
		map(arr);
		move(arr,brr);
		if(lose(arr) == 0)
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
		}
		if(judge(arr) == 0)
		{
			system("clear");
			map(arr);
			printf("\n\n\n\n恭喜你，获得胜利！你的总步数为%d。\n",step);
	
			break;
		}
	}
	
	return 0;	
}

int map(int x[7][8])
{
	printf("推箱子小游戏\n      作者：林书思\n");
	for(int i = 0;i < 7;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(x[i][j] == 0)
			{
				printf(" ");
			}else if(x[i][j] == 1){
				printf("#");
			}else if(x[i][j] == 2){
				printf("@");
			}else if(x[i][j] == 3){
				printf("O");
			}else if(x[i][j] == 4){
				printf("$");
			}
		//	printf("\n");
		}printf("\n");
		
		
	}
	printf("\33[%d;%dH",iX+3,iY+1);
	
}
int move(int x[7][8],int y[7][8])
{
	switch(get_direction())
	{
		case KEY_UP:
		{
			if(x[iX-1][iY] == 0)
			{
				x[iX][iY] = 0;
				x[iX-1][iY] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iX--;
				step++;
				break;
			}else if(x[iX-1][iY] == 1)
			{
				break;
			}else if(x[iX-1][iY] == 2)
			{
				if(x[iX-2][iY] == 0||x[iX-2][iY] == 3)
				{	
					x[iX][iY] = 0;
					x[iX-1][iY] = 4;
					x[iX-2][iY] = 2;
					if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
					x[iX][iY] = 3;
					iX--;
					step++;
				}
				
				break;
			}else if(x[iX-1][iY] == 3)
			{
				x[iX][iY] = 0;
				x[iX-1][iY] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iX--;
				step++;
				break;
			}
		}
		case KEY_DOWN:
		{
			if(x[iX+1][iY] == 0)
			{
				x[iX][iY] = 0;
				x[iX+1][iY] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iX++;
				step++;
				break;
			}else if(x[iX+1][iY] == 1)
			{
				break;
			}else if(x[iX+1][iY] == 2)
			{
				if(x[iX+2][iY] == 0||x[iX+2][iY] == 3)
				{	
					x[iX][iY] = 0;
					x[iX+1][iY] = 4;
					x[iX+2][iY] = 2;
					if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
					x[iX][iY] = 3;
					iX++;
					step++;
				}
				break;
			}else if(x[iX+1][iY] == 3)
			{
				x[iX][iY] = 0;
				x[iX+1][iY] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iX++;
				step++;
				break;
			}
		}
		case KEY_LEFT:
		{
			if(x[iX][iY-1] == 0)
			{
				x[iX][iY] = 0;
				x[iX][iY-1] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iY--;
				step++;
				break;
			}else if(x[iX][iY-1] == 1)
			{
				break;
			}else if(x[iX][iY-1] == 2)
			{
				if(x[iX][iY-2] == 0||x[iX][iY-2] == 3)
				{	
					x[iX][iY] = 0;
					x[iX][iY-1] = 4;
					x[iX][iY-2] = 2;
					if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
					x[iX][iY] = 3;
					iY--;
					step++;
				}
				break;
			}else if(x[iX][iY-1] == 3)
			{
				x[iX][iY] = 0;
				x[iX][iY-1] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iY--;
				step++;
				break;
			}
		}
		case KEY_RIGHT:
		{
			if(x[iX][iY+1] == 0)
			{
				x[iX][iY] = 0;
				x[iX][iY+1] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iY++;
				step++;
				break;
			}else if(x[iX][iY+1] == 1)
			{
				break;
			}else if(x[iX][iY+1] == 2)
			{
				if(x[iX][iY+2] == 0||x[iX][iY+2] == 3)
				{	
					x[iX][iY] = 0;
					x[iX][iY+1] = 4;
					x[iX][iY+2] = 2;
					if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
					x[iX][iY] = 3;
					iY++;
					step++;
				}
				break;
			}else if(x[iX][iY+1] == 3)
			{
				x[iX][iY] = 0;
				x[iX][iY+1] = 4;
				if(iX == 2&&iY == 1||iX == 3&&iY == 2||iX == 3&&iY == 3)
				x[iX][iY] = 3;
				iY++;
				step++;
				break;
			}
		}
			case 10:
			{
				for(int i =0;i<7;i++)
				{
					for(int j = 0;j<8;j++)
					{
						x[i][j] = y[i][j];			
					}
					step = 0;
				}
				iX = 5;
				iY = 3;
				break;

			}
		
	}

	
	
}

int judge(int x[7][8])
{
	if(x[2][1] == 2&&x[3][2] == 2&&x[3][3] == 2)
	{
		
		return 0 ;
	}

	return -1;

}
int lose(int x[7][8])
{
	if(x[1][2] == 2||x[5][4] == 2||x[1][5] == 2||x[3][6] == 2||x[5][1] == 2||x[5][2] == 2)
	{
		return 0;	
	}
	return -1;
}
