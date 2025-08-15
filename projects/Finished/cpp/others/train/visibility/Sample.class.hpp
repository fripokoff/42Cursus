# ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream>

class Sample {

public:

    int pubFoo;
    Sample( void);
    ~Sample( void );
    void    pop( void );

private:
    int _privFoo;
    void _privPop ( void ) const;

};

#endif