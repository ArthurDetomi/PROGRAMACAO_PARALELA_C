/**		Rômulo Silva de Oliveira

		Programação Concorrente com Pthreads e Linguagem C

		s03-a14-mutexlinux.c
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_t t1;	// Identificador da thread t1
pthread_t t2;	// Identificador da thread t2 

pthread_mutex_t em = PTHREAD_MUTEX_INITIALIZER;


/** Faz 10 iterações pegando o mutex em cada uma */
void codigo_tarefa_1(void){
	for( int ns=0; ns < 10; ++ns) {
		sleep(1);
		printf("Tarefa 1: passaram %d iteracoes\n", ns+1);	// Chance de escalonamento
 		pthread_mutex_lock(&em);
		printf("Tarefa 1: estah com o Mutex\n");
		//sleep(1);	// Errado !!!
 		pthread_mutex_unlock(&em);
 	}
}


/** Faz 10 iterações pegando o mutex em cada uma */
void codigo_tarefa_2(void){
	for( int ns=0; ns < 10; ++ns) {
		sleep(1);
		printf("Tarefa 2: passaram %d iteracoes\n", ns+1);
 		pthread_mutex_lock(&em);
		printf("Tarefa 2: estah com o Mutex\n");
 		pthread_mutex_unlock(&em);
	}
}


/** Função principal, cria as threads */
int main(void){
	printf("Inicio\n");

	pthread_create(&t1, NULL, (void *) codigo_tarefa_1, NULL);
	pthread_create(&t2, NULL, (void *) codigo_tarefa_2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Fim\n");
	return(0);
}




