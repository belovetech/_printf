#include "printf.h"

/**
 * checkflag - check flag format
 *
 * @ap: pointer to the arguement list
 * @flag: format flag
 * Return: length of the value print to stdout
 */
int checkflag(va_list *ap, char flag)
{
    char *str, c, buf[100];
    int len = 0;
    int d;
    unsigned int num;
    intptr_t num2;
    char* res_convert = NULL;

    if (flag == 's' || flag == 'S') {
        str = va_arg(*ap, char*);
        if(str == NULL) str = "(null)";
        if (str) len += _printstr(str);
    }
    else if (flag == 'c') {
        c = (char) va_arg(*ap, int);
        len += _putchar(c);
    }
    else if (flag == 'd') {
        d = va_arg(*ap, int);
        len += _putint(d);
    }
    else if (flag == 'o') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 8, 'o');
    }
    else if (flag == 'u') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 10, 'o');
    }
    else if (flag == 'x' || flag == 'X') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 16, 'X');
    }
    else if (flag == 'x') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 16, 'x');
    }
    else if (flag == '%') {
       len += _putchar('%');
    }
    else if (flag == 'p') {
        num2 = va_arg(*ap, intptr_t);
        res_convert = _putpointer(num2, 16);
        write(1, "0x", 2);
        len += _printstr(res_convert);
        len += 2;
    }

    va_end(*ap);

    return (len);
}
