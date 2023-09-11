#ifndef PHILO_H
#define PHILO_H

// Yeni Fonksiyonlar
# include <pthread.h>
# include <sys/time.h>

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo {
	pthread_t			thread;
	int					index;
	int					last_eat_time;
}	t_philo;

typedef struct s_philo_info {
	int				size_of_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				think_time;
	int				eat_limit;
	unsigned long	start_ms;
	struct timeval	tv;
	t_philo			*philos;
	int				index;
	pthread_mutex_t	*forks;
}	t_philo_info;

int	ft_atoi(char *str);
unsigned long	get_ms(t_philo_info *pi);
void    *philo_life_cycle(void *pi);
#endif