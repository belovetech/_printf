#include "printf.h"

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

char* _putpointer(unsigned long int number, int base){
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