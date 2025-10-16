#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define N_THEARDS 5

pthread_t threads[N_THEARDS];

int ERROR_CODE = 400;
int SUCCESS_CODE = 201;

void *task_thread(char *nome) {
    for (int i = 0; i < 10; i++) {
        printf("%s: %d segundos\n", nome, i + 1);
        sleep(1);
    }
    
    if (nome[0] >= 'a' && nome[0] <= 'z') {
        return (void*) &ERROR_CODE;
    }

    return (void*) &SUCCESS_CODE;
}


int main(void) {
    char *nome = "Thread";
    char *nome2 = "thread";

    int *returned;
    
    printf("Inicio programa\n");

    for (int i = 0; i < N_THEARDS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i],NULL,(void *) task_thread, (void *) nome);
        } else {
            pthread_create(&threads[i],NULL,(void *) task_thread, (void *) nome2);
        }
    }

    for (int i = 0; i < N_THEARDS; i++) {
        pthread_join(threads[i], (void **)&returned);

        printf("Codigo retorno thread %d = %d\n", i + 1, *returned);
    }

    printf("Fim programa\n");

    return 0; 
}
