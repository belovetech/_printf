#include "printf.h"

/**
 * _putchar - print character to the stdout
 *
 * @c: character to print
 * Return: length of the character (1)
 */
int _putchar(int c)
{
    return (write(1, &c, 1));
}

/**
 * _printstr - print string or sequence of character to the stdout
 *
 * @str: string to print
 * Return: length of the string
 */
int _printstr(char *str)
{
    int len =  0;

    while (*str != '\0') {
        _putchar(*str);
        str++;
        len++;
    }
    return (len);
}

/**
 * _putintbase - convert number to different number base
 *
 * @buffer:  buffer to hold the converted base
 * @num: Number to convert to different base
 * @base: Desired base to convert number to
 * @c: Represent the character denoted the base (e.g x for hexadecimal)
 * Return: length of the output
 */
int _putintbase(char *buffer, unsigned int num, int base, char c)
{
    unsigned int quotient;
    int i = 1, j, temp;
    int len = 0;

    quotient = num;
    while (quotient != 0) {
        temp = quotient % base;
        if (temp < 10) temp += 48;
        else {
            if (c == 'x') temp += 87;
            else if (c == 'X') temp += 55;
        }

        buffer[i++] = temp;
        quotient = quotient / base;
    }

	for (j = i - 1; j > 0; j--)
        len += _putchar(buffer[j]);

    return (len);
}

/**
 * _putint - Print integer to the stdout
 *
 * @n: number to print
 * Return: Length of the integer
 */
int _putint(int n)
{
    int len = 0;

	if (n < 0) {
		len += _putchar(45);
		n = -n;
	}
	if (n > 9) len += _putint(n/10);
	len += _putchar((n%10) + '0');

    return (len);
}

/**
 * _putpointer - print address of the any variables
 *
 * @number: number
 * @base:base 16
 * Return: address of the varaiable
 */
char* _putpointer(unsigned long int number, int base)
{
    unsigned long int original_n = number;
    unsigned int len = 0;
    char* result = NULL;
    unsigned long int temp_n;

    original_n = original_n > 0 ? original_n : -(original_n);
    while (number){
        number = number / base;
        len++;
    }
    if (!(result = (char*)malloc(sizeof(char) * len + 1))){
        return NULL;
    }
    *(result + len) = '\0';
    len--;
    while (original_n > 0){
        temp_n = original_n % base;
        if (temp_n < 10)
            *(result + len) = temp_n + '0';
        else
            *(result + len) = ((temp_n)-10 + 97);
        original_n = original_n / base;
        len--;
    }
    return result;
}

