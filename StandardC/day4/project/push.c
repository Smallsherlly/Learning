#include<stdio.h>
#include<get_direction.h>
#include<stdlib.h>
//#include<time.h>
extern int iX,iY,step;
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
			}else if(x[i][j] == 2||x[i][j] == 5){
				printf("@");
			}else if(x[i][j] == 3){
				printf("O");
			}else if(x[i][j] == 4||x[i][j] == 7){
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
				
				x[iX-1][iY] = 4;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iX--;
				step++;
				
			}else if(x[iX-1][iY] == 1)
			{
				break;
			}else if(x[iX-1][iY] == 2)
			{
				if(x[iX-2][iY] == 0||x[iX-2][iY] == 3)
				{	
					x[iX-1][iY] = 4;
					if(x[iX-2][iY] == 3)
					{
						x[iX-2][iY] = 5;
					}else{
						x[iX-2][iY] = 2;
					}
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					iX--;
					step++;
				}
				
			}else if(x[iX-1][iY] == 3)
			{
				
				x[iX-1][iY] = 7;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iX--;
				step++;
				
			}else if(x[iX-1][iY] == 5)
			{
				if(x[iX-2][iY] == 0||x[iX-2][iY] == 3)
				{
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					x[iX-1][iY] = 7;
					if(x[iX-2][iY] == 3)
					{
						x[iX-2][iY] = 5;
					}else{
						x[iX-2][iY] = 2;
					}
					iX--;
					step++;
				}
				
			}
			break;
				
		}
		case KEY_DOWN:
		{
			if(x[iX+1][iY] == 0)
			{
				
				x[iX+1][iY] = 4;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iX++;
				step++;
				
			}else if(x[iX+1][iY] == 1)
			{
				break;
			}else if(x[iX+1][iY] == 2)
			{
				if(x[iX+2][iY] == 0||x[iX+2][iY] == 3)
				{	
					
					x[iX+1][iY] = 4;
					if(x[iX+2][iY] == 3)
					{
						x[iX+2][iY] = 5;
					}else{
						x[iX+2][iY] = 2;
					}
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					iX++;
					step++;
				}
				
			}else if(x[iX+1][iY] == 3)
			{
				
				x[iX+1][iY] = 7;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iX++;
				step++;
				
			
			}else if(x[iX+1][iY] == 5)
			{
				if(x[iX+2][iY] == 0||x[iX+2][iY] == 3)
				{
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					x[iX+1][iY] = 7;
					if(x[iX+2][iY] == 3)
					{
						x[iX+2][iY] = 5;
					}else{
						x[iX+2][iY] = 2;
					}
					iX++;
					step++;
				}
			}
			break;
		}
		case KEY_LEFT:
		{
			if(x[iX][iY-1] == 0)
			{
			
				x[iX][iY-1] = 4;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iY--;
				step++;
				
			}else if(x[iX][iY-1] == 1)
			{
				break;
			}else if(x[iX][iY-1] == 2)
			{
				if(x[iX][iY-2] == 0||x[iX][iY-2] == 3)
				{	
					
					x[iX][iY-1] = 4;
					if(x[iX][iY-2] == 3)
					{
						x[iX][iY-2] = 5;
					}else{
						x[iX][iY-2] = 2;
					}
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					iY--;
					step++;
				}
				
			}else if(x[iX][iY-1] == 3)
			{
			
				x[iX][iY-1] = 7;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iY--;
				step++;
				
			}else if(x[iX][iY-1] == 5)
			{
				if(x[iX][iY-2] == 0||x[iX][iY-2] == 3)
				{
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					x[iX][iY-1] = 7;
					if(x[iX][iY-2] == 3)
					{
						x[iX][iY-2] = 5;
					}else{
						x[iX][iY-2] = 2;
					}
					iY--;
					step++;
				}
			}
			break;
		}
		case KEY_RIGHT:
		{
			if(x[iX][iY+1] == 0)
			{
			
				x[iX][iY+1] = 4;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iY++;
				step++;
				
			}else if(x[iX][iY+1] == 1)
			{
				break;
			}else if(x[iX][iY+1] == 2)
			{
				if(x[iX][iY+2] == 0||x[iX][iY+2] == 3)
				{	
				
					x[iX][iY+1] = 4;
					if(x[iX][iY+2] == 3)
					{
						x[iX][iY+2] = 5;
					}else{
						x[iX][iY+2] = 2;
					}
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					iY++;
					step++;
				}
				
			}else if(x[iX][iY+1] == 3)
			{
				
				x[iX][iY+1] = 7;
				if(x[iX][iY] == 7)
				{
					x[iX][iY] = 3;
				}else{
					x[iX][iY] = 0;
				}
				iY++;
				step++;
				
			}else if(x[iX][iY+1] == 5)
			{
				if(x[iX][iY+2] == 0||x[iX][iY+2] == 3)
				{
					if(x[iX][iY] == 7)
					{
						x[iX][iY] = 3;
					}else{
						x[iX][iY] = 0;
					}
					x[iX][iY+2] = 7;
					if(x[iX][iY+2] == 3)
					{
						x[iX][iY+2] = 5;
					}else{
						x[iX][iY+2] = 2;
					}
					iY++;
					step++;
				}
				
			}
			break;
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
	int z = 0;
	for(int i = 0;i < 7;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			if(x[i][j] == 5)
			{
				z++;
			}
		}
	}
	if(z == 3)
	{
		
		return 0 ;
	}

	return -1;

}
/*int lose(int x[7][8])
{
	if(x[1][2] == 2||x[5][4] == 2||x[1][5] == 2||x[3][6] == 2||x[5][1] == 2||x[5][2] == 2)
	{
		return 0;	
	}
	return -1;
}*/
