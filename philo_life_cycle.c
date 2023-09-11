#include "philo.h"

// philo_eat();
// philo_sleep();
// philo_think();

void    philo_eat(t_philo_info *pi)
{
    pthread_mutex_lock(&pi->forks[pi->index]);
    printf("[%lums] %d has taken a fork\n", get_ms(pi), pi->index);
    if (pi->size_of_philo - 1 == pi->index)
    {
        pthread_mutex_lock(&pi->forks[0]);
        printf("%d == %d", pi->size_of_philo - 1, pi->index);
    }
    else
        pthread_mutex_lock(&pi->forks[pi->index + 1]);
    printf("[%lums] %d has taken a fork\n", get_ms(pi), pi->index);
}

void    philo_sleep(t_philo_info *pi, int index)
{
    int i;

    i = -1;
    while (++i < pi->size_of_philo)
    {
        if ((i + 1) % 2 == (index + 1) % 2)
        {
            pthread_mutex_unlock(&pi->forks[i]);
            pthread_mutex_unlock(&pi->forks[i + 1]);
        	printf("[%lums] %d sleeping\n", get_ms(pi), i + 1);
        }
    }
}

void    philo_think(t_philo_info *pi, int index)
{
    int i;

    i = -1;
    while (++i < pi->size_of_philo)
    {
        if ((i + 1) % 2 == (index + 1) % 2)
        {
            printf("[%lums] %d thinking\n", get_ms(pi), i + 1);
        }
    }
}

void    *philo_life_cycle(void *pi)
{
    
    while (1)
    {   
        philo_eat(pi);
    }
    //usleep(pi->eat_time * 1000);
    // philo_sleep(pi, index);
    // usleep(pi->sleep_time * 1000);
    // philo_think(pi, index);
    // usleep(pi->think_time * 1000);
    return (NULL);
}





// void    philo_eat(t_philo_info *pi, int index)
// {
//     static int  last_philo = 0;
//     int i;

//     i = -1;
//     while (++i < pi->size_of_philo)
//     {
//         if ((i + 1) % 2 == (index + 1) % 2)
//         {
// 			pi->philos->left_hand = &pi->forks[i];
// 			pi->philos->left_hand = &pi->forks[i + 1];
//             pthread_mutex_lock(&pi->forks[i]);
//             if (pi->size_of_philo % 2 == 1 && i == pi->size_of_philo - 1)
//                 pthread_mutex_lock(&pi->forks[0]);
//             else
//                 pthread_mutex_lock(&pi->forks[i + 1]);
//             printf("[%lums] %d has taken a fork\n", get_ms(pi), i + 1);
//             printf("[%lums] %d has taken a fork\n", get_ms(pi), i + 1);
//             printf("[%lums] %d eating\n", get_ms(pi), i + 1);
//         }
//     }
// }


// void    philo_eat(t_philo_info *pi, int index)
// {
//     static int  last_philo = 0;
//     int i;

//     i = -1;
//     while (++i < pi->size_of_philo)
//     {
//         if ((i + 1) % 2 == (index + 1) % 2)
//         {
//             pthread_mutex_lock(&pi->forks[i]);
//             printf("[%dms] %d has taken a fork\n", get_ms(pi->start_ms), i);
//             // if (pi->size_of_philo % 2 == 1 && i == pi->size_of_philo - 1 && last_philo > 0)
//             // {
//             //     last_philo++;
//             //     pthread_mutex_lock(&pi->forks[0]);
//             //     if (last_philo == 2)
//             //     {
//             //         last_philo = 0;
//             //         printf("[%dms] %d has taken a fork\n", get_ms(pi->start_ms), i);
//             //     }
//             // }else
//             // {
//             //     pthread_mutex_lock(&pi->forks[i + 1]);
//             //     printf("[%dms] %d has taken a fork\n", get_ms(pi->start_ms), i);
//             // }
//         }
//     }
// }