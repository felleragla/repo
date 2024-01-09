/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** files
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "./hunter.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb < 10){
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return nb;
}

void function(const char *format, va_list list_of_arg, int *c)
{
    if (format[*c] == '%' &&
        (format[*c + 1] == 'd' || format[*c + 1] == 'i')) {
        my_put_nbr(va_arg(list_of_arg, int));
        *c = *c + 2;
    } else if (format[*c] == '%' && format[*c + 1] == 's') {
        my_putstr(va_arg(list_of_arg, char *));
        *c = *c + 2;
    }
    if (format[*c] == '%' && format[*c + 1] == 'c') {
        my_putchar((char)va_arg(list_of_arg, int));
        *c = *c + 2;
    } else if (format[*c] == '%' && format[*c + 1] == '%') {
        my_putchar('%');
        *c = *c + 2;
    }
    *c++;
}

int mini_printf(const char *format, ...)
{
    va_list list_of_arg;
    int c;

    va_start(list_of_arg, format);
    for (c = 0; format[c] != '\0'; c++) {
        function(format, list_of_arg, &c);
        my_putchar(format[c]);
    }
    va_end(list_of_arg);
    return c;
}
