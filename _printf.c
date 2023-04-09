#include "printf.h"

/**
 * _printf - Implement custom printf function
 *
 * @format: formatted output to stdout
 * @...: represent remaining arguments
 * Return: number of the value printed to the stdout
 */
int _printf(char * restrict format, ...)
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



int main(int ac, char **av)
{

    int ret_val1 = printf("NULL STRING %p\n", NULL);
    int ret_val2 = printf("NULL STRING %p\n", NULL);
    printf("%d %d\n", ret_val1, ret_val2);

    printf("%s", (char*)NULL);
    _printf("%s", (char*)NULL);

    char *hey = "Hello world!";
    printf("\n%p\n", hey);
    _printf("%p\n", hey);


    int x = printf("%s\n", hey);
    int y = _printf("%s\n", hey);
    _printf("%d %d\n", x, y);

    return (0);
}
