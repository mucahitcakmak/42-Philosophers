#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct s_philo_info;

typedef struct s_philo {
	struct s_philo_info	*pi;
	pthread_t			thread;
	int					index;
	int					last_eat_time;
}	t_philo;

typedef struct s_philo_info {
	int				size_of_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_limit;
	int				eat_counter;
	unsigned long	start_ms;
	struct timeval	tv;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
}	t_philo_info;

int		check_arguman(char **argv);
void	ms_sleep(t_philo *p, int time);
void	destroy_mutex(t_philo_info *pi);
void	arguman_init(t_philo_info *pi, char **argv);
void	main_loop(t_philo_info *pi);
void	thread_create(t_philo_info *pi);
void    *philo_life_cycle(void *philo);
int	ft_atoi(char *str);
unsigned long	get_ms(t_philo_info *pi);
void    *philo_life_cycle(void *pi);
#endif