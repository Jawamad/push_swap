/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmuller <florianmuller@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:08:15 by flmuller          #+#    #+#             */
/*   Updated: 2024/01/29 14:05:09 by florianmull      ###   ########.fr       */
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
int		ft_atoi_ps(const char *nptr);
int		*control_pile(int nbelem, char **elems);
t_pile	*init_node(t_pile *node, int value, t_pile *next);
t_pile	**init_pile(int *numbers, unsigned int nbelem);
int		*charlist_to_intlist(char **nblist);
void 	remove_list(char **list);
char	**check_pile(int nbelem, char **elems);
int		check_valid_char(char *nblist);
int 	check_dupli(int *nblist, int listlen);

#endif