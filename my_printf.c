#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>



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

char* pointer_to_string(unsigned long int number, int base){
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
        res_convert = pointer_to_string(num2, 16);
        write(1, "0x", 2);
        len += _printstr(res_convert);
        len += 2;
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


/*
int main() 
{                      
                                                                                                                   
    int ret_val = my_printf("NULL STRING %s!\n", (char *)NULL); 
    int ret_val2 = printf("NULL STRING %s!\n", (char *)NULL);    

    printf("%d %d\n", ret_val, ret_val2);


    // printf("%s", (char*)NULL);
    // my_printf("%s", (char*)NULL);

                                                                                                                                                            
    return ret_val;                                                                                                                                           
}*/