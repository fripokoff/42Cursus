#include "Sample.class.hpp"

int main( void )
{
    Sample instance;

    instance.pubFoo = 48;
    std::cout << " instance.pubFoo " <<  instance.pubFoo  << std::endl;
    instance._privFoo = 78;
    instance.pop();

    return 0;
}