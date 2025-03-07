#include "ft_printf.h"

int main()
{
    int count;
    count = ft_printf("Hello, world! %c %s\n", 4, "Test");
    ft_printf("Characters printed: %d\n", count);
    return 0;
}