#pragma once

# include <iostream>
# include <string>
# include <cerrno>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &other);

        public:
            static void convert(std::string const &str);
};
