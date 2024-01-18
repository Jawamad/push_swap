/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramcontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmuller <florianmuller@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:43:46 by florianmull       #+#    #+#             */
/*   Updated: 2024/01/18 13:45:27 by florianmull      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*charlist_to_intlist(char **nblist)
{
	int	i;
	int	j;
	int	*intlist;

	i = 0;
	intlist = malloc(ft_strlen(nblist)* sizeof(int));
	if (intlist)
		return (NULL);
	while (nblist[i])
	{
		intlist[i] = ft_atoi_ps(nblist[i]);
		if (intlist[i++] == NULL)
		{
			j = 0;
			while (j < i - 1)
				free(intlist[j++]);
			remove_list(nblist);
			return (NULL);
		}
	}
	remove_list(nblist);
	return (intlist);
}

void remove_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

char	**check_pile(int nbelem, char **elems)
{
	char	**nblist;
	int		i;
	
	if (nbelem < 1)
		nblist = ft_split(elems[0], " ");
	else
		nblist = elems;
	i = 0;
	while (nblist[i])
	{
		if (!check_valid_char(nblist[i]))
		{
			while (nblist)
				free(nblist++);
			return (NULL);
		}
		i++;
	}
	return (nblist);
}

int	check_valid_char(char *nblist)
{
	int	symcheck;
	int	j;

	j = 0;
	while (nblist[j])
	{
		if (ft_isdigit(nblist[j]) || nblist[j] == '-' || nblist[j] == '+')
		{
			if (symcheck == 0)
				symcheck = 1;
			else
				if (nblist[j] == '-' || nblist[j] == '+')
					return (0);
		}
		else
			return (0);
		j++;
	}
	return (1);
}

int check_dupli(int *nblist, int listlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < listlen)
	{
		j = 0;
		while (j < listlen)
		{
			if (nblist[i] == nblist[j] && i != j)
				return (0);
		}
	}
	return (1);
}