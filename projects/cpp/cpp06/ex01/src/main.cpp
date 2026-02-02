/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:52:24 by kpires            #+#    #+#             */
/*   Updated: 2026/02/02 16:50:13 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Serializer.hpp"

int main(){
    try {
        Data* data = new Data;

        data->weapon = "Sword";
        data->nickname = "Potatoes";
        data->life  = 6;

        std::cout << "Address of data:       " << data << std::endl;
        std::cout << "[Content of data]" << std::endl;
        std::cout << "Weapon:   " << data->weapon << std::endl;
        std::cout << "Nickname: " << data->nickname << std::endl;
        std::cout << "Life :    " << data->life  << std::endl;

        std::cout << std::endl << "Serialization of data:"  << std::endl;
        uintptr_t   raw = Serializer::serialize(data);
        std::cout << "Serialized value: " << raw << std::endl;

        std::cout << std::endl << "Deserialization of data:"  << std::endl;
        Data*       deserialized = Serializer::deserialize(raw);
        std::cout << "Address of deserialized:    " << deserialized << std::endl << std::endl;

        std::cout << "[Content data deserialized]" << std::endl;
        std::cout << "Weapon:   " << deserialized->weapon << std::endl;
        std::cout << "Nickname: " << deserialized->nickname << std::endl;
        std::cout << "Life :    " << deserialized->life  << std::endl;

        delete data;
        return 0;

    } catch (std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}