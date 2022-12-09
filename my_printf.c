#include "printf.h"

int checkflag(va_list *ap, char flag)
{
    char *str, c, buf[100];
    int len = 0;
    int d;
    unsigned int num;
    
    if (flag == 's') {
        str = va_arg(*ap, char*);
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
    else if (flag == 'x') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 16, 'x');
    }
    else if (flag == 'X') {
        num = va_arg(*ap, int);
        len += _putintbase(buf, num, 16, 'X');
    }
    else if (flag == '%') {
       len += _putchar('%');
    }
    
    va_end(*ap);

    return (len);
}

int my_printf(char * restrict format, ...)
{
    int len = 0;
    va_list ap;
    int flag = 0;
    
    va_start(ap, format);
    while (*format != '\0')
    {
        if (flag) {
            len += checkflag(&ap, *format);
            flag  = 0;
        }
        else if (*format == '%') flag = 1;
        else len += _putchar(*format);
        format++;
    } 
    va_end(ap);
    return len;
}
