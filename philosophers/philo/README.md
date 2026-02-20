# PHILOSOPHERS (42)

## Workflow

### Understanding the issue

**Understanding** : First of all we have N philosophers on a table with N forks. At the right and left of each philosopher there is a fork. The goal is to provide each philo from the death by eating. However there are no enough forks for everyone so if one takes two forks, both aside must wait to use forks. There are requirements like time_to_die, time_to_eat, time_to_sleep

N : The number of philosophers and forks.

time_to_die : The time for a philosopher to eat before dying.

time_to_eat : The time that eating takes.

time_to_sleep : the time that sleeping takes.


## Identify bordeline cases :



## Identify input/output :
```
Input : 
- Type : [unsigned int * 4]
- Description : Check above
- Validation : It must be positive integers

Output :
- Type : void
- Description : None
- Errors code : ERRARGS, ERRINIT 
```

## Break down into sub-problems
```
Main issue : Multi threading
├── Sub-problem 1 : Verifying the arguements
│       └── 
├── Sub-problem 2 : Initialize philosophers, forks and times (sleep, die, eat) 
│   ├── 
│   ├──  
│   └──  
├── Sub-problem 3 : Create threads for each philosophers
│   ├── 
│   ├── 
│   └──  
├── Sub-problem 4 : Start the battle
│   ├── 
└── END   
```

## Define the Data Structures 
```
typedef struct s_fork
{
    unsigned int index;
    pthread_mutex_t locker;
} t_fork;

typedef struct s_philosophers
{
    pthread_t tid;
    int index;
    int tto_eat;
    int tto_die;
    int tto_sleep;
    t_fork left_fork;
    t_fork right_fork;
} t_philo;

typedef struct s_args
{
    int nb_philos_forks;
    int tto_eat;
    int tto_die;
    int tto_sleep;
} t_args;

```

## Design algorithms (pseudo-code)
```







```

## External functs.

- malloc : allocating memory on the heap
- free : free up the memory that was allocated
- printf : displays a string with variables on terminal
- write : write on a fd
- memset : The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
- usleep : The  usleep() function suspends execution of the calling thread for (at least) usec microseconds.
- gettimeofday : can get the time of a timezone.
- pthread_create : create a thread and give it a task
- pthread_detach : detach a thread from the calling thread
- pthread_join : allows one thread to wait for the termination of another thread
- pthread_mutex_init
- pthread_mutex_destroy
- pthread_mutex_lock
- pthread_mutex_unlock

## Check to do
