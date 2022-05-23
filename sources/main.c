/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:51:20 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/23 15:56:55 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo_tab;

	if (argc < 5 || argc > 6 || !parsing(argc, argv))
	{
		write(2, "Error: bad arguments\n", 21);
		return (1);
	}
	if (!init(&philo_tab, argc, argv) || !launch_threads(&philo_tab))
	{
		write(2, "UNEXPECTED FAIL\n", 16);
		clean_philos(&philo_tab);
		return (2);
	}
	clean_philos(&philo_tab);
	return (0);
}
