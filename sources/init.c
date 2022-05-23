/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:59:10 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/22 10:18:21 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	init_philos(t_philo **philo_tab, t_data **data, int nb_forks)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	*philo_tab = malloc(sizeof(t_philo) * nb_forks);
	if (!*philo_tab)
		return (0);
	tmp = *philo_tab;
	while (i < nb_forks)
	{
		tmp[i].phi_id = i;
		tmp[i].fork1 = 0;
		tmp[i].fork2 = 0;
		tmp[i].last_eat_time = 0;
		tmp[i].nb_eat = 0;
		tmp[i].data = *data;
		i++;
	}
	return (1);
}

int	init(t_philo **philo_tab, int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (0);
	if (!init_philos(philo_tab, &data, data->nb_forks))
	{
		clean_data(&data);
		return (0);
	}
	return (1);
}
