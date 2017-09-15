#include "stdio.h"
#include "ascii.h"

#define gpu_addr 0x23e00000

// 不要求检查坐标点的合法性
/*
// 显示字母和汉字
void draw_char(unsigned short x,unsigned short y,char ch,Color color)
{
	int i,j;
	int count = 0;
	for(j=0; j<16; j++)
	{
		for(i=0; i<8; i++)
		{
			if(arr[j] & (1<<i))
			{
				set_pix(x+j,y+i,color);
			}
			count++;
		}
	}
}

void draw_str(unsigned short x,unsigned short y,char* str,Color color)
{
	while(*str)
	{
		draw_char(x,y,*str,color);
		y += 8;
		str++;
	}
}
*/
// 显示图片

// 定义颜色结构体
typedef struct Color
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}Color;

Color (*gpu_arr)[1024] = gpu_addr;
Color red = {0,0,255,0};
Color green = {0,255,0,0};
Color blue = {255,0,0,0};
Color white = {255,255,255,0};
Color black = {0,0,0,0};

// 定义显示像素函数
void set_pix(unsigned short x,unsigned short y,Color color)
{
	gpu_arr[x][y] = color;
}
/*
// 画直线和斜线
void draw_slash(unsigned short start_x,unsigned short start_y,\
				unsigned short end_x,unsigned short end_y,Color color)
{
	int x,y;
	for(x=start_x,y=start_y; x<end_x&&y<end_y; x++,y++)
	{
		set_pix(x,y,color);
	}
}

void draw_line(unsigned short start_x,unsigned short start_y,\
				unsigned short end_x,unsigned short end_y,Color color)
{
	int x,y;
	if(start_y == end_y)
	{
		y = start_y;
		for(x=start_x; x<end_x; x++)
		{
			set_pix(x,y,color);
		}
	}else if(start_x == end_x)
	{
		x = start_x;
		for(y=start_y; y<end_y; y++)
		{
			set_pix(x,y,color);
		}
	}
}

// 画矩形和圆形
void draw_rectangle(unsigned short start_x,unsigned short start_y,
					unsigned short end_x,unsigned short end_y,Color color)
{
	int x,y;
	for(x=start_x; x<end_x; x++)
	{
		for(y=start_y; y<end_y; y++)
		{
			set_pix(x,y,color);
		}
	}
}
void draw_circle(unsigned short focus_x,unsigned short focus_y,
				unsigned short r,Color color_f,Color color_m)
{
	int x,y;
	for(x=focus_x-r; x<focus_x+r; x++)
	{
		for(y=focus_y-r; y<focus_y+r; y++)
		{
			if(((x-focus_x)*(x-focus_x)+(y-focus_y)*(y-focus_x)) < r*r)
			{
				set_pix(x,y,color_f);
			}
			if(((x-focus_x)*(x-focus_x)+(y-focus_y)*(y-focus_y)) == r*r)
			{
				set_pix(x,y,color_f);
			}
		}
	}

}
*/
// 画背景
void draw_background(Color color)
{
	int x=0,y=0;
	for(x=0; x<600; x++)
	{
		for(y=0; y<1024; y++)
		{
			set_pix(x,y,color);
		}
	}
}

void delay()
{
	int i = 0xfffff;
	while(i--);
}

void Main(void)
{
	draw_background(white);
//	draw_slash(0,0,600,600,red);
//	draw_line(0,300,600,300,blue);
//	draw_rectangle(0,0,600,300,green);
//	draw_circle(300,500,50,blue,red);
	while(1);
}
