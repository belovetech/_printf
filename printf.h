#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>


int _putchar(int c);
int _putint(int n);
int _printstr(char *str);
char* _putpointer(unsigned long int number, int base);
char* pointer_to_string(unsigned long int number, int base);
int _putintbase(char *hex, unsigned int num, int base, char c);
int _printf(char * restrict format, ...);
int checkflag(va_list *ap, char flag);

#endif /*_PRINTF_H_*/
