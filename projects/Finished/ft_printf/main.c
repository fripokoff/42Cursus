#include "./include/ft_printf.h"

int main (int ac, char **av)
{
    (void)ac;
    (void)av;
    ft_printf("%c", av[1]);
    return 0;
}