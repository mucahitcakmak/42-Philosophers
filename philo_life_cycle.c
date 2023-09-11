#include "philo.h"

void	thread_create(t_philo_info *pi)
{
	long	i;

	i = -1;
	while (++i < pi->size_of_philo)
		pthread_mutex_init(&pi->forks[i], NULL);
	i = -1;
	while (++i < pi->size_of_philo)
	{
		pi->philos[i].pi = pi;
		pi->philos[i].last_eat_time = get_ms(pi);
		pi->philos[i].index = i;
		if (pthread_create(&pi->philos[i].thread, NULL, philo_life_cycle, &pi->philos[i]) != 0)
			printf("Error.\n");
		usleep(100);
	}
}

void    *philo_life_cycle(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&p->pi->forks[p->index]);
		printf("[%lums] %d has taken a fork\n", get_ms(p->pi), p->index + 1);
		pthread_mutex_lock(&p->pi->forks[(p->index + 1) % p->pi->size_of_philo]);
		printf("[%lums] %d has taken a fork\n", get_ms(p->pi), p->index + 1);
		printf("[%lums] %d is eating\n", get_ms(p->pi), p->index + 1);
		p->pi->eat_counter++;
		usleep(p->pi->eat_time * 1000);
		p->last_eat_time = get_ms(p->pi);
		printf("[%lums] %d is sleeping\n", get_ms(p->pi), p->index + 1);
		pthread_mutex_unlock(&p->pi->forks[p->index]);
		pthread_mutex_unlock(&p->pi->forks[(p->index + 1) % p->pi->size_of_philo]);
		usleep(p->pi->sleep_time * 1000);
		printf("[%lums] %d is thinking\n", get_ms(p->pi), p->index + 1);
		usleep(p->pi->think_time * 1000);
	}
    return (NULL);
}
