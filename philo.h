#ifndef PHILO_H
#define PHILO_H

// Yeni Fonksiyonlar
# include <pthread.h>
# include <sys/time.h>

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

enum e_philo_state {
	NONE,
	EAT,
	THINK,
	SLEEP
};

typedef struct s_philo {
	pthread_t			thread;
	enum e_philo_state	state;
	int					*left_hand;
	int					*right_hand;
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
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_philo_info;

int	ft_atoi(char *str);
int	get_ms(unsigned long start_usec);
void    philo_life_cycle(t_philo_info   *pi);

#endif