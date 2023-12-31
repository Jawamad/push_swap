/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:23 by flmuller          #+#    #+#             */
/*   Updated: 2023/11/30 13:27:42 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *node)
{
	t_pile	*prevtemp;
	int 	value;

	prevtemp = node->previous;
	value = prevtemp->value;
	prevtemp->value = node->value;
	node->value = value;
}

void	push(t_pile **ntpush, t_pile **pushpile)
{
	t_pile	*temppushn;
	t_pile	*temppushp;
	t_pile	*tempnodepush;

	if (*ntpush)
	{
		temppushn = (*ntpush)->next;
		temppushp = (*ntpush)->previous;
		temppushp->next = temppushn;
		temppushn->previous = temppushp;
		tempnodepush = *ntpush;
		*ntpush = temppushp;
		if (*pushpile)
		{
			temppushn =	(*pushpile)->next;
			tempnodepush->next = temppushn;
			tempnodepush->previous = *pushpile;
		}
		else
		{
			tempnodepush->next = tempnodepush;
			tempnodepush->previous = tempnodepush;
		}
		*pushpile = tempnodepush;
	}
}

void	rotate(t_pile **node, int nbrot)
{
	int	i;

	i = 0;
	while (i != nbrot)
	{
		*node = (*node)->previous;
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

t_pile	*init_node(int value, t_pile *previous, t_pile *next)
{
	t_pile	*node;

	node = malloc(sizeof(t_pile));
	if (!node)
		return(NULL);
	node->value = value;
	if (next)
		node->next = next;
	if (previous)
		node->previous = previous;
	return (node);
}


/*
	Function: init_pile
	-------------------
	Init an list of t_pile struct with provided numbers.
	return pointer on the first element of the list.
	return Null in case of Error.
 */
t_pile	**init_pile(char **numbers, unsigned int nbelem)
{
	int	i;
	t_pile	*node;
	t_pile	*previous;
	t_pile	*next;
	t_pile	*first;

	i = 0;
	node = malloc(sizeof(t_pile));
	if (!node)
		return(NULL);
	first = node;
	while (!node->previous)
	{
		if (!node->value)
		{
			node->value = ft_atoi(numbers[i]);
			i++;
		}
		if (i < nbelem)
		{
		next = malloc(sizeof(t_pile));
		if (!next)
			return(NULL);
		}
		else
			next = first;
		node->next = next;
		if (previous)
			node->previous = previous;
		previous = node;
		node = next;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc > 1)
	{
		
	}
	else
	{
		write(1, "Error", 5);
	}
	write(1, '\n', 1);
	return(0);
}