/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:18:06 by mucakmak          #+#    #+#             */
/*   Updated: 2023/09/12 01:20:40 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **argv)
{
	t_philo_info	*pi;
	printf("-----------------\n");
	pi = malloc(sizeof(t_philo_info));

	if (ac != 5 && ac != 6)
		return (1);
	arguman_init(pi, argv);
	thread_create(pi);
	main_loop(pi);
	printf("\n-----------------\n");
    return (0);
}

void	arguman_init(t_philo_info *pi, char **argv)
{
	struct timeval tv;

	pi->tv = tv;
	gettimeofday(&pi->tv, NULL);
	pi->start_ms = (pi->tv.tv_usec / 1000 + pi->tv.tv_sec * 1000);
	pi->size_of_philo = ft_atoi(argv[1]);
	pi->die_time = ft_atoi(argv[2]);
	pi->eat_time = ft_atoi(argv[3]);
	pi->sleep_time = ft_atoi(argv[4]);
	pi->think_time = (ft_atoi(argv[2]) - ft_atoi(argv[4]));
	if (argv[5])
		pi->eat_limit = ft_atoi(argv[5]);
	else
		pi->eat_limit = -1;
	pi->eat_counter = 0;
	pi->philos = malloc(sizeof(t_philo) * pi->size_of_philo);
	pi->forks = malloc(sizeof(pthread_mutex_t) * pi->size_of_philo);
}

void	main_loop(t_philo_info *pi)
{
	int	i;

	i = 1;
	while (1)
	{
		if (pi->eat_limit != -1 && pi->eat_counter >= pi->eat_limit * pi->size_of_philo)
		{
			destroy_mutex(pi);
			return ;
		}
		// if (get_ms(pi) - pi->philos[i % pi->size_of_philo].last_eat_time >= pi->die_time)
		// {
		// 	destroy_mutex(pi);
		// 	printf("[%lums] %d died\n", get_ms(pi), (i % pi->size_of_philo) + 1);
		// 	return ;
		// }
		i++;
		usleep(100);
	}
}
