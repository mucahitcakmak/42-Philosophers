#include "philo.h"

void	write_status(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->pi->dead_mutex);
	printf("[%lums] %d %s\n", get_ms(p->pi), p->index + 1, str);
	pthread_mutex_unlock(&p->pi->dead_mutex);
}

void    *philo_life_cycle(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&p->pi->forks[p->index]);
		write_status(p, "has taken fork");
		pthread_mutex_lock(&p->pi->forks[(p->index + 1) % p->pi->size_of_philo]);
		write_status(p, "has taken fork");
		write_status(p, "is eating");
		p->pi->eat_counter++;
		p->last_eat_time = get_ms(p->pi);
		ms_sleep(p, p->pi->eat_time);
		write_status(p, "is sleeping");
		pthread_mutex_unlock(&p->pi->forks[p->index]);
		pthread_mutex_unlock(&p->pi->forks[(p->index + 1) % p->pi->size_of_philo]);
		ms_sleep(p, p->pi->sleep_time);
		write_status(p, "is thinking");
	}
    return (NULL);
}
