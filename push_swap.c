/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmuller <florianmuller@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:23 by flmuller          #+#    #+#             */
/*   Updated: 2024/02/02 14:45:00 by florianmull      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Function: init_node
	-------------------
	Init a node of t_pile struct with provided value.
	parameter next is optional.
	If next parameter is not provided init a new node 
	that will be considered to be the "next" of the current node.
	Return the  adress of the next node.
	Return Null in case of Error.
 */
t_pile	*init_node(t_pile *node, int value, t_pile *next)
{
	t_pile	*temp;

	node->value = value;
	if (next)
		node->next = next;
	else
	{
		node->next = malloc(sizeof(t_pile));
		if (node->next == NULL)
			return (NULL);
	}
	temp = node->next;
	temp->previous = node;
	return (node->next);
}

/*
	Function: init_pile
	-------------------
	Init a list of t_pile struct with provided numbers.
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
	while (node->next != first)
	{
		next = NULL;
		if (i >= nbelem)
			next = first;
		node = init_node(node, numbers[i++], next);
	}
	first->previous = node;
	node = node->next;
	return (&node);
}

/*
	Function: control_pile 
	-------------------
	check the validity of parameters pass to the function
	return a list of numbers.
	return Null in case of Error.
 */
int	*control_pile(int nbelem, char **elems)
{
	char	**nblist;
	int		*intlist;

	nblist = check_pile(nbelem, elems);
	if (!nblist)
		return (NULL);
	intlist = charlist_to_intlist(nblist);
	if(!check_dupli(intlist, nbelem))
		free(intlist);
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