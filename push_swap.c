/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:23 by flmuller          #+#    #+#             */
/*   Updated: 2023/11/22 17:24:41 by flmuller         ###   ########.fr       */
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
