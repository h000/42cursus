# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>

int main()
{
    sem_unlink("/forks");
	sem_unlink("/pickup");
	sem_unlink("/print");
	sem_unlink("/someone_died");
}