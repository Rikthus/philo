/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:06:10 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/23 12:08:59 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	fill_static_data(t_data **data, int argc, char **argv)
{
	t_data	*tmp_d;

	tmp_d = *data;
	tmp_d->t_die = ft_atoi(argv[2]);
	tmp_d->t_eat = ft_atoi(argv[3]);
	tmp_d->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		tmp_d->max_eat = ft_atoi(argv[5]);
	else
		tmp_d->max_eat = 0;
	tmp_d->nb_forks = ft_atoi(argv[1]);
	tmp_d->full_eat = 0;
	tmp_d->death = 0;
	tmp_d->end_diner = 0;
	//init starting_time after staring thread
}

static	int	init_forks(t_data **data)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = *data;
	tmp->forks = malloc(sizeof(int) * tmp->nb_forks);
	if (!tmp->forks)
		return (0);
	while (i < tmp->nb_forks)
	{
		tmp->forks[i] = 1;
		i++;
	}
	return (1);
}

static	int	init_mutex(t_data **data)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = *data;
	tmp->mtx = malloc(sizeof(*tmp->mtx) * tmp->nb_forks);
	if (!tmp->mtx)
		return (0);
	while (i < tmp->nb_forks)
	{
		pthread_mutex_init(&tmp->mtx[i], NULL);
		i++;
	}
	pthread_mutex_init(&tmp->mutex_chat, NULL);
	pthread_mutex_init(&tmp->mutex_end_diner, NULL);
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (0);
	fill_static_data(&data, argc, argv);
	if (!init_forks(&data))
	{
		free(data);
		return (NULL);
	}
	if (!init_mutex(&data))
	{
		clean_data(&data);
		return (NULL);
	}
	return (data);
}
