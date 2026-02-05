#pragma once

# include <stdint.h>
# include <string>

typedef struct s_data {
	std::string	        weapon;
	std::string	        nickname;
	int	                life;
}	Data;

class Serializer {
     private:
        Serializer();
        Serializer(Serializer const &other);
        ~Serializer();
        Serializer &operator=(Serializer const &other);

    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};
