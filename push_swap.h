/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:08:15 by flmuller          #+#    #+#             */
/*   Updated: 2023/11/30 13:13:21 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_pile
{
	int 				value;
	struct pile_list	*next;
	struct pile_list	*previous;
}	t_pile;

void	swap(t_pile *node);
void	push(t_pile **ntpush, t_pile **pushpile);
void	rotate(t_pile **node, int nbrot);

#endif