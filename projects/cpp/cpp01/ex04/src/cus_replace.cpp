/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cus_replace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:23:14 by kpires            #+#    #+#             */
/*   Updated: 2025/08/11 20:18:53 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string cus_replace(const std::string str, const std::string &to_replace, const std::string &replace_by){

    //checks
    if(to_replace.empty())
        return str;
    if(to_replace == replace_by)
        return str;

    std::ostringstream result;
    size_t pos = 0;
    size_t found;

    //std::string::npos constant representing "not found".
    //main loop for replace all occurences
    while((found = str.find(to_replace, pos)) != std::string::npos)
    {
        result << str.substr(pos, found - pos) << replace_by;
        pos = found + to_replace.length();
    }
    result << str.substr(pos);
    return result.str();
}