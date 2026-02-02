/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:39:55 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 20:19:46 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>


void thread_routine(void *data)
{
    int *nb;
    int i;

    nb = (int *)data;
    i = 0;
    printf("Le nombre associe au thread : %d\n", *nb);
    while (i < 21000) 
    {
        (*nb)++;
        i++;
    }
}


int main(void)
{
    // pthread_t tid;
    // pthread_t tid2;
    // int data = 0;


    // pthread_create(&tid, NULL, thread_routine, &data);
    // printf("First thread : %ld\n", tid);
    // pthread_create(&tid2, NULL, thread_routine, &data);
    // printf("Second thread : %ld\n", tid2);

    // pthread_join(tid, NULL);
    // printf("Main is waiting for the thread %ld to end\n", tid);
    // pthread_join(tid2, NULL);
    // printf("Main is waiting for the thread %ld to end\n", tid2);
    // printf("The number may be equal to 42000œ: %d\n", data);
    // pthread_detach(tid);

    int timer = 0;
    while (timer < 60000) 
    {
        timer++;
    }
    return 0;
}