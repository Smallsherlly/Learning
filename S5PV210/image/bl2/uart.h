#ifndef _UART_H__
#define _UART_H__

// uart初始化
void uart_init(unsigned int baud);
//输出一个字符
void putc(const char ch);
//输出一个字符串
void puts(const char* str);
//输入一个字符
char getc(void);
//输入一个字符串
char* gets(char* str);


#endif // _UART_H__
