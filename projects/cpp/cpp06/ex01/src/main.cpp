/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:52:24 by kpires            #+#    #+#             */
/*   Updated: 2026/01/21 13:49:31 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Serializer.hpp"

int main(){
    Data*   data = new Data;

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
    std::cout << "Address of data serialized: " << reinterpret_cast<void*>(raw)<< std::endl;

    std::cout << std::endl << "Deserialization of data:"  << std::endl;
    Data*       deserialized = Serializer::deserialize(raw);
    std::cout << "Address of deserialized:    " << deserialized << std::endl << std::endl;

    std::cout << "[Content data deserialized]" << std::endl;
    std::cout << "Weapon:   " << deserialized->weapon << std::endl;
    std::cout << "Nickname: " << deserialized->nickname << std::endl;
    std::cout << "Life :    " << deserialized->life  << std::endl;

    delete data;
    return 0;
}