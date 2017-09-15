#include "stdio.h"
#include "ascii.h"

#define gpu_addr 			0x23e00000

// 定义颜色结构体
typedef struct Color
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}Color;
// 不要求检查坐标点的合法性
unsigned char arr[16] = 
{0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00};
unsigned char str[4][16] = 
{
{0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0xBF,0x7F,0x08,0x04,0x0C,0x0E,0x1C,0x0E},
{0x2A,0x15,0x0A,0x15,0x89,0x24,0x48,0x44,0x28,0x04,0x08,0x04,0x08,0x04,0x08,0x04},/*"林",0*/
{0x40,0x04,0x40,0x08,0x40,0x10,0xFC,0x07,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04},
{0xFF,0x3F,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x14,0x40,0x08,0x40,0x00},/*"书",1*/
{0x00,0x00,0xFC,0x1F,0x84,0x10,0x84,0x10,0xFC,0x1F,0x84,0x10,0x84,0x10,0xFC,0x1F},
{0x04,0x10,0x80,0x00,0x10,0x11,0x12,0x21,0x12,0x48,0x12,0x48,0xE1,0x0F,0x00,0x00}
};

//void draw_chi(unsigned short){}
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

void delay()
{
	int i = 0xfffff;
	while(i--);
}

void Main(void)
{
	draw_background(white);
	draw_slash(0,0,600,600,red);
	draw_line(0,300,600,300,blue);
	draw_rectangle(0,0,600,300,green);
	draw_circle(300,500,50,blue,red);
	draw_char(300,400,0,red);
	draw_char(300,400,1,red);
	draw_char(300,400,2,red);
	draw_char(300,400,3,red);
	draw_char(300,400,4,red);
	draw_char(300,400,5,red);
	while(1);
}
