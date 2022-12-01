#ifndef _MY_PRINTF_H_
#define _MY_PRINTF_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putint(int n);
int _putchar(int c);
int _printstr(char *str);
int _putintbase(char *hex, unsigned int num, int base, char c);
int checkflag(va_list *ap, char flag);
int my_printf(char * restrict format, ...);

#endif /*_MY_PRINTF_H_*/