/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:54:18 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/26 17:13:56 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			if (i == 1 && ft_atoi(argv[i]) < 1)
				return (0);
		}
		else
		{
			if (ft_atoi(argv[i]) < 0
				|| (ft_atoi(argv[i]) == 0 && ft_strcmp(argv[i], "0") != 0))
				return (0);
		}
		i++;
	}
	return (1);
}
