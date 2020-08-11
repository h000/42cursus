#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// 뮤텍스 객체 선언
pthread_mutex_t mutex_lock;
int g_count = 0;  // 쓰레드 공유자원.
void *t_function(void *data)
{
    write(1, "1", 1);
    int i;
    char* thread_name = (char*)data;
    pthread_mutex_lock(&mutex_lock);
    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.
    while (g_count < 3)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원
        sleep(1);
    }
    pthread_mutex_unlock(&mutex_lock);
    return (NULL);
}
int main()
{
    pthread_t p_thread1, p_thread2;
    int status;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);


    // 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음
    pthread_mutex_init(&mutex_lock, NULL);
    // write(1, "1", 1);
    pthread_create(&p_thread1, &attr, t_function, (void *)"Thread1");
    // pthread_detach(p_thread1);
    pthread_create(&p_thread2, &attr, t_function, (void *)"Thread2");
    // pthread_detach(p_thread2);
    // write(1, "2", 1);
    sleep(100);
    // case 1
    // pthread_join(p_thread1, (void *)&status);
    // pthread_join(p_thread2, (void *)&status);
    // case 2
    // pthread_join(p_thread2, (void *)&status);
    // pthread_join(p_thread1, (void *)&status);
}