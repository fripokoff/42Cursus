/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:14:46 by kpires            #+#    #+#             */
/*   Updated: 2026/02/02 15:02:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

static void printTypedMessage(int typeID, std::string msg){
    std::string types[4] = {"char", "int", "float", "double"};
    std::cout << types[typeID] << ": " << msg <<std::endl;
}

// check
static void printPseudo(std::string const &str){

    std::string arr[6] = {"-inf", "-inff", "+inf", "+inff", "nan", "nanf"};

    for(int i = 0; i < 6; i++)
    {
        if(str == arr[i])
        {
            for(int j = 0; j < 4; j++)
            {
                if(j < 2){
                    printTypedMessage(j, "impossible");
                }
                else if(j == 2 && i % 2 == 0){
                    printTypedMessage(j, arr[i + 1]);
                }
                else if(j == 3 &&  i % 2 != 0){
                    printTypedMessage(j, arr[i - 1]);
                }
                else{
                    printTypedMessage(j, arr[i]);
                }
            }
            return;
        }
    }
}

static bool isPseudo(std::string const &str){
    return (str == "-inf" || str == "+inf" || str == "nan" ||
            str == "-inff" || str == "+inff" || str == "nanf");
}

static void displayChar(double value){
    if (isnan(value) || isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void displayInt(double value){
    if (isnan(value) || isinf(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void displayFloat(double value){
    if (value > FLT_MAX || value < -FLT_MAX){
        std::cout << "float: impossible" << std::endl;
        return;
    }

    float f = static_cast<float>(value);

    std::cout << "float: " << f;

    if (!isnan(f) && !isinf(f) && f == static_cast<int>(f))
        std::cout << ".0";  // add .0 for integers

    std::cout << "f" << std::endl;
}

static void displayDouble(double value){
    std::cout << "double: " << value;
    if (!isnan(value) && !isinf(value) && value == static_cast<long long>(value))
        std::cout << ".0";
    std::cout << std::endl;
}

static void displayAll(double value){
    displayChar(value);
    displayInt(value);
    displayFloat(value);
    displayDouble(value);
}

static bool isValidFormat(std::string const &str){
    if (str.empty())
        return false;
    
    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (i >= str.length())  // sign alone
            return false;
    }
    
    if (str[i] == '.')  // starts with a dot
        return false;

    // block case like 00042
    if (str[i] == '0' && i + 1 < str.length() && str[i + 1] != '.' && str[i + 1] != 'f')
        return false;
    
    for (; i < str.length(); i++){

        if (isdigit(str[i])){
            hasDigit = true;
            continue ;
        }

        // a dot before
        if (str[i] == '.'){
            if (hasDot)
                return false;
            hasDot = true;
            if (i == str.length() - 1)  // dot at the end
                return false;
            if (i == str.length() - 2 && str[i + 1] == 'f')  // detect style 42.f
                return false;
            continue ;
        }

        if (str[i] == 'f' && i == str.length() - 1)  // f only at the end
            continue ;
        return false;
    }
    return hasDigit;
}

void ScalarConverter::convert(std::string const &str){

    // special cases
    if (isPseudo(str)){
        printPseudo(str);
        return;
    }

    // char literal like 'a'
    if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]) && str[0] != '+' && str[0] != '-' && str[0] != '.'){
        displayAll(static_cast<double>(str[0]));
        return;
    }

    // check format
    if (!isValidFormat(str)){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // convert string to double
    char* endptr;
    double value = strtod(str.c_str(), &endptr);

    displayAll(value);
}