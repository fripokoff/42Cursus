# CPP

### Namespaces
- Regrouper des fonctions, des symboles qui ont un rapport semantique.
- `::` = operateur de resolution de porter

```cpp
#include <stdio.h>

namespace Foo {
    int good = 5;
}

int main(void)
{
    printf("test [%d]\n", Foo::good);
    return 0;
}
```

---

# Stdio iostream
- `std::cin >> buffer` pour rediriger une input
```cpp
#include <iostream>

int main (void)
{
    char buffer[500];

    std::cout << "Hello World!" << std::endl;
    std::cout << "Input a word: ";
    std::cin >> buffer;
    std::cout << "Word input = " << buffer << std::endl;
    return 0;
}
```

---

# Class & Instance
#### Ne jamais oublier le `;` peut causer de grosse erreurs
### Jargon
- Private
- Public
- Constructor
- Destructor
- Instance

### Declaration de class
`~` **etant le destructeur**
**Il non pas de type de retour -> void en realiter**

**Notion: Class, Instance, Definition, Declaration, Constructeur, Destructeur**

## class.hpp
```cpp
# ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    public:
        Sample( void );
        ~Sample( void );
};

#endif
```

## class.cpp
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample ( void ){
    
    std::cout << " Sample construit " << std::endl;
    return;
}

Sample::~Sample ( void ){
    std::cout << " Sample Deconstruit " << std::endl;
    return;
}
```

## main.cpp
```cpp
#include "Sample.class.hpp"

int main( void )
{
    Sample var_name;// var_name instance de Sample
    return 0;
}
```

### cmd : `c++ -Wall -Wextra -Werror -Wno-used Sample.class.cpp main.cpp && ./a.out`

---

## This
- **This est en realite le pointeur de notre Class**
```cpp
# ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    public:
        Sample( void );
        ~Sample( void );
        int foo = 42;
        void myfunction( void );
};

#endif
```
- **a l'interieur de la class.cpp je vais pouvoir appeler this->myfunction(); ou bien faire this->foo = 42;**

```cpp
Sample::Sample ( void ){
    
    std::cout << " Sample construit " << std::endl;
    std::cout << " foo is :" << this->foo << std::endl;
    this->foo = 42;
    std::cout << " foo is now :" << this->foo << std::endl;
    this->pop();
    return;
}
```
**Sortie :**
```bash
➜ c++ -Wall -Wextra -Werror -Wno-used Sample.class.cpp main.cpp && ./a.out
 Sample construit 
 foo is :60
 foo is now :42
 Pop called 
 Sample Deconstruit 
 ```

---

 ## Const
 - **Les const sont a utiliser fortement si tel est le besoin**
 - **Ajouter const dans la declaration de class a la find du genre void `hello(void) const;`**
 - **Une const doit etre constatement initialiser sans ca des bug de compilation apparaitront**
 ## Exemple de class
 ```cpp
 class Sample {

public:
    float const pi;
    int         qd;
    Sample( const float f );
    ~Sample( void );
    int foo = 60;

    void    pop( void );

};
```
```cpp
Sample::Sample ( const float  f) : pi(f){
    
    std::cout << " Sample construit " << std::endl;
    std::cout << f << std::endl;
    this->pop();
    return;
}
```
```cpp
int main( void )
{
    Sample instance (47.4f);

    return 0;
}
```
- **Donc en principe il faudrait dans la declaration de classe ajouter le `:` suivi de la const de la class public ainsi que le parametre pi(f) pour l'exemple.**

---

## Private,Public
- ***Les classes private sont accessible uniquement depuis l'interieur de la construction/deconstruction `instance._privFoo()` int Sample::_privFoo’ is private within this context ne sera pas appeler**

- **Tandis que les plublic peuvent etre appeler via le main `instance.publicFoo();`**