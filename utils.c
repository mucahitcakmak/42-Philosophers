#include "philo.h"

unsigned long	get_ms(t_philo_info *pi)
{
	gettimeofday(&pi->tv, NULL);
	return ((pi->tv.tv_usec / 1000 + pi->tv.tv_sec * 1000) - pi->start_ms);
}

void	destroy_mutex(t_philo_info *pi)
{
	int	i;

	i = -1;
	while (++i < pi->size_of_philo)
		pthread_mutex_destroy(&pi->forks[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
