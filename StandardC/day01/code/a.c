#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<get_keyboard.h>
#include<math.h>
#include<string.h>
#include<strings.h>
#define SIZE 4
#define FILENAME "./score_top.txt"
typedef struct ScoreTop
{
	char name[24];
	int score;
}ScoreTop;

void show(int board[SIZE][SIZE]);
void insertNewNumber(int board[SIZE][SIZE]);
int moveUp(int board[SIZE][SIZE]);
int moveDown(int board[SIZE][SIZE]);
int moveLeft(int board[SIZE][SIZE]);
int moveRight(int board[SIZE][SIZE]);
int gameOver(int board[SIZE][SIZE]);
int gameStart(int board[SIZE][SIZE]);
int saveScoreTopTen(int score);
void clearboard(int board[SIZE][SIZE]);
int main()
{
		srand(time(NULL));
		int board[SIZE][SIZE] = {};
		while(1)
		{
			int score = gameStart(board);
			int ret = saveScoreTopTen(score);

			if(ret != 0)
			{
				printf("保存得分排行榜TOP-TEN失败！\n");
			}
			char inputstr[4] = {};
			scanf("%*[^\n]%*c");
			printf("Once again,Yes or No? Enter Enter's key to start,but no or No to leave!\n");
			scanf("%s",inputstr);
			if(strcmp(inputstr,"no") == 0||strcmp(inputstr,"NO") == 0)
				//if(strcasecmp(inputstr,"no") == 0)
			{
				break;
			}
			clearboard(board);
		}
		return 0;
}
void clearboard(int board[SIZE][SIZE])
{
	//memset(board,0,sizeof(int)*SIZE*SIZE);
	bzero(board,sizeof(int)*SIZE*SIZE);
}
int saveScoreTopTen(int score)
{
	ScoreTop scorearr[10] = {};
	memset(&scorearr,0,sizeof(ScoreTop)*10);
	int num = 0;
	FILE *fp = fopen(FILENAME,"a+");
	if(fp == NULL)
	{
		printf("打开文件错误\n");
		return -1;
	}
	while(!feof(fp))
	{
		ScoreTop st = {};
		size_t ret = fread(&st,sizeof(st),1,fp);
		if(ret >= 0)
		{
			strcpy(scorearr[num].name,st.name);
			scorearr[num].score = st.score;
			num++;
		}
	}

	fclose(fp);
	int top = 0;
	for(top = 0;top < 10;top++)
	{
		if(scorearr[top].score < score)
		{
			break;
		}
	}
	
	if(top >= 10)
	{
		printf("很遗憾没有进入得分排行榜TOP-TEN！\n");
		return 0;
	}else{
			printf("恭喜你获得了得分排行榜TOP-TEN第%d名!\n",top+1);
	}
	char name[24] = {};
	printf("请输入你的姓名：\n");
	scanf("%s",name);
	for(int n = num-1;n > top;n--)
	{
		strcpy(scorearr[n].name,scorearr[n-1].name);
		scorearr[n].score = scorearr[n-1].score;
	}
	strcpy(scorearr[top].name,name);
scorearr[top].score = score;
	fp = fopen(FILENAME,"w");
	if(fp == NULL)
	{
		printf("打开文件错误！\n");
		return -1;
	}
	printf("\tTop TEN!\n");
	for(int n = 0;n < 10;n++)
	{
		if(scorearr[n].score != 0)
		{
			printf("第%d名 ：%s [%d]\n",n+1,scorearr[n].name,scorearr[n].score);
			size_t ret = fwrite(&scorearr[n],sizeof(scorearr[n]),1,fp);
		}
	}
	fclose(fp);
	return 0;
}
int gameStart(int board[SIZE][SIZE])
{
	insertNewNumber(board);
	insertNewNumber(board);
	while(1)
	{
		show(board);
		int isdo = 0;
		while(isdo == 0)
		{
			switch(get_keyboard())
			{
				case KEY_UP:
					isdo = moveUp(board);
					break;
				case KEY_DOWN:
					isdo = moveDown(board);
					break;
				case KEY_LEFT:
					isdo = moveLeft(board);
					break;
				case KEY_RIGHT:
					isdo = moveRight(board);
					break;
				}
		}
		show(board);
		insertNewNumber(board);
		show(board);
		int ret = gameOver(board);
		if(ret != 0)
		{
			printf("Game is Over! Your score is %d.\n",ret);
			return ret;
		}
	}
	return 0;
}

int gameOver(int board[SIZE][SIZE])
{
	int cboard[SIZE][SIZE] = {};
	int score = 0;
	for(int row = 0;row < SIZE;row++)
	{
		for(int col = 0;col < SIZE;col++)
		{
			cboard[row][col] = board[row][col];
			if(board[row][col] > score)
			{
				score = board[row][col];
			}
		}
	}
	if((moveUp(cboard) == 0)&&(moveDown(cboard) == 0)&&(moveLeft(cboard) == 0)&&(moveRight(cboard) == 0))
	{
		return score;
	}
	return 0;
}

int moveUp(int board[SIZE][SIZE])
{
	int isdo = 0;
	for(int col = 0;col < SIZE;col++)
	{
		for(int row = 0;row < SIZE-1;row++)
		{
			int flag = 0;
			if(board[row][col] != 0)
			{
				int k = row+1;
				while(k < SIZE)
				{
					if(board[k][col] != 0)
					{
						if(board[k][col] == board[row][col])
						{
							isdo = 1;
							flag = 1;
							board[row][col] *= 2;
							board[k][col] = 0;
						}
						break;
					}
					k++;
				}
				if(flag == 1)
				{
					break;
				}
			}
		}
	}
	for(int j = 0;j < SIZE;j++)
	{
		int yk = 0;
		for(int i = 0;i < SIZE;i++)
		{
			if(board[i][j] != 0)
			{
				if(yk != i)
				{
					board[yk][j] = board[i][j];
					board[i][j] = 0;
					isdo = 1;
				}
				yk++;
			}
		}
	}
	return isdo;
}

int moveDown(int board[SIZE][SIZE])
{
	int isdo  = 0;
	for(int col = 0;col < SIZE;col++)
	{
		for(int row = SIZE-1;row > 0;row--)
		{
			int flag = 0;
			if(board[row][col] != 0)
			{
				int k = row-1;
				while(k >= 0)
				{
					if(board[k][col] != 0)
					{	
						if(board[k][col] == board[row][col])
						{
							isdo = 1;
							flag = 1;
							board[row][col] *= 2;
							board[k][col] = 0;
						}
						break;
					}
					k--;
				}
				if(flag == 1)
				{
					break;
				}
			}
		}
	}
	for(int j = 0;j < SIZE;j++)
	{
		int yk = SIZE-1;
		for(int i = SIZE-1;i >= 0;i--)
		{
			if(board[i][j] != 0)
			{
				if(yk != i)
				{
					board[yk][j] = board[i][j];
					board[i][j] = 0;
					isdo = 1;
				}
				yk--;
			}
		}
	}
	return isdo;
}

int moveLeft(int board[SIZE][SIZE])
{
	int isdo = 0;
	for(int row = 0;row < SIZE;row++)
	{
		for(int col = 0;col < SIZE-1;col++)
		{
			int flag = 0;
			if(board[row][col] != 0)
			{
				int k = col+1;
				while(k < SIZE)
				{
					if(board[row][k] != 0)
					{
						if(board[row][k] == board[row][col])
						{
							board[row][col] *= 2;
							board[row][k] = 0;
							isdo = 1;
							flag = 1;
						}
						break;
					}
					k++;
				}
				if(flag == 1)
				{
					break;
				}
			}
		}
	}
	for(int i = 0;i < SIZE;i++)
	{
		int yk = 0;
		for(int j = 0;j < SIZE;j++)
		{
			if(board[i][j] != 0)
			{	
				if(yk != j)
				{
					board[i][yk] = board[i][j];
					board[i][j] = 0;
					isdo = 1;
				}
				yk++;
			}
		}
	}
	return isdo;
}

int moveRight(int board[SIZE][SIZE])
{
	int isdo = 0;
	for(int row = 0;row < SIZE;row++)
	{
		for(int col = SIZE-1;col > 0;col--)
		{
			int flag = 0;
			if(board[row][col] != 0)
			{
				int k = col-1;
				while(k >= 0)
				{
						if(board[row][k] != 0)
						{
							if(board[row][col] == board[row][k])
							{
								board[row][col] *= 2;
								board[row][k] = 0;
								isdo = 1;
								flag = 1;
							}
							break;
						}
						k--;
				}
				if(flag == 1)
				{
					break;
				}
			}	
		}
	}
	for(int i = 0;i < SIZE;i++)
	{
		int yk = SIZE-1;
		for(int j = SIZE-1;j >= 0;j--)
		{
			if(board[i][j] != 0)
			{
				if(yk != j)
				{
					board[i][yk] = board[i][j];
					board[i][j] = 0;
					isdo = 1;
				}
				yk--;
			}
		}
	}
	return isdo;
}

void insertNewNumber(int board[SIZE][SIZE])
{
	int number = (rand()%2+1)*2;
	int row = 0,col = 0;
	do
	{
		row = rand()%SIZE;
		if(board[row][0] != 0&&board[row][1] != 0&&board[row][2] != 0&&board[row][3] != 0)
		{
			continue;
		}
		while(1)
		{
			col = rand()%SIZE;
			if(board[row][col] == 0)
			{
				break;
			}
		}
	}while(board[row][col] != 0);
	board[row][col] = number;
}

void show(int board[SIZE][SIZE])
{
	system("clear");
	printf("+-------------------+\n");
	for(int row = 0;row < SIZE;row++)
	{
		printf("|");
		for(int col = 0;col < SIZE;col++)
		{
			int n = 30;
			if(board[row][col] != 0)
			{
				n += (int)(log(board[row][col])/log(2));
				printf("\033[%dm%4d\033[0m|",n,board[row][col]);
			}else{
					printf("    |");
			}
		}
		printf("\n");
		printf("+-------------------+\n");
	}
}


























