#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int count, count2, count3;
    count = ft_printf("Hello, world! %c %s %d\n", 48, "Test1", 42);
    count2 = printf("Hello, world! %c %s %d\n", 48, "Test2", 42);
    count3 = ft_printf("Characters printed: %q no comprendo");
    printf("Characters printed: %d\n", count2);
    ft_printf("Characters printed: %d\n", count);
    ft_printf("Characters printed: %d\n", count3);
    return 0;
}