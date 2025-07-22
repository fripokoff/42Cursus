
#include <stdio.h>

namespace Foo {
    int good = 5;
}

int main(void)
{
    printf("test [%d]\n", Foo::good);
    return 0;
}