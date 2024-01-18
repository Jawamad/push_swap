/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmuller <florianmuller@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:23 by flmuller          #+#    #+#             */
/*   Updated: 2024/01/18 14:10:41 by florianmull      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*init_node(t_pile *node, int value, t_pile *previous, t_pile *next)
{
	node->value = value;
	if (next)
		node->next = next;
	else
		node->next = malloc(sizeof(t_pile));
	if (previous)
	{
		node->previous = previous;
		previous = node;
	}
	return (node->next);
}

/*
	Function: init_pile
	-------------------
	Init an list of t_pile struct with provided numbers.
	return pointer on the first element of the list.
	return Null in case of Error.
 */
t_pile	**init_pile(int *numbers, unsigned int nbelem)
{
	int		i;
	t_pile	*node;
	t_pile	*previous;
	t_pile	*next;
	t_pile	*first;

	i = 0;
	node = malloc(sizeof(t_pile));
	if (!node)
		return(NULL);
	first = node;
	while (!node->next)
	{
		next = NULL;
		if (i >= nbelem)
			next = first;
		node = init_node(node, numbers[i++], previous, next);
	}
}

int	*control_pile(int nbelem, char **elems)
{
	char	**nblist;
	int		*intlist;
	int		i;
	int		j;

	nblist = check_pile(nbelem, elems);
	if (!nblist)
		return (NULL);
	intlist = charlist_to_intlist(nblist);
	if(!check_dupli(intlist, nbelem))
	{
		i = 0;
		while (i < nbelem)
			free(intlist[i++]);
	}
	return (intlist);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc > 1)
	{
		controlpile(argc - 1, &argv[1]);
	}
	else
	{
		write(1, "Error", 5);
	}
	write(1, '\n', 1);
	return(0);
}