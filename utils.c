#include "my_printf.h"

int _putchar(int c)
{
    return (write(1, &c, 1));
}

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

int _putintbase(char *hex, unsigned int num, int base, char c)
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
        
        hex[i++] = temp;
        quotient = quotient / base;
    }

	for (j = i -1; j > 0; j--)
        len += _putchar(hex[j]);
    
    return (len);
}

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