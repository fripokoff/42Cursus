/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:44:35 by kpires            #+#    #+#             */
/*   Updated: 2026/02/04 12:03:07 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename SourceType, typename ReturnType>
void	iter(SourceType* table, int tableSize, ReturnType (*f)(SourceType & it)) {
	for (int i = 0; i < tableSize; i++)
		f(table[i]);
}

// template <typename SourceType, typename ReturnType>
// void	iter(SourceType* table, int tableSize, ReturnType (*f)(SourceType const & it)) {
// 	for (int i = 0; i < tableSize; i++)
// 		f(table[i]);
// }

#endif