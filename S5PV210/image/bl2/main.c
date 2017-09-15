#include "stdio.h"
#include "ascii.h"

#define gpu_addr 0x20000000
extern unsigned char gImage_min[1843200];


int (*gpu_arr)[1024] = gpu_addr;
void draw_image(void)
{
	int j=0,i=0;
	for(j=0; j<600; j++)
	{
		for(i=0; i<1024; i++)
		{
			int num = 1024*j+i;
			gpu_arr[j][i] = gImage_min[num*3]<<16|gImage_min[num*3+1]<<8\
			|gImage_min[num*3+2];
//			gpu_arr[j][i] = 0xff0000;
		}
	}
}
/*
// 显示字母和汉字
void draw_char(unsigned short x,unsigned short y,int row,Color color)
{
	int i,j;
	for(j=0; j<16; j++)
	{
		for(i=0; i<16; i++)
		{
			if(str[row][j] & (1<<i%8))
			{
				set_pix(x+j/2+row*8,y+i,color);
			}
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

// 显示图片


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
			if(((x-focus_x)*(x-focus_x)+(y-focus_y)*(y-focus_y)) < r*r)
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
*/
void delay()
{
	int i = 0xfffff;
	while(i--);
}

void Main(void)
{
	draw_image();
	while(1);
}
