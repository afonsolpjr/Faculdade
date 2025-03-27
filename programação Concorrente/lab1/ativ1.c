#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

/* Função a ser executada pela thread*/
void* cafe_com_leite(void* arg){
	long int id = (long int) arg;
	printf("Teste da thread nº %ld \n", id, (unsigned long)time(NULL));
	pthread_exit(NULL);
}



int main(int argc, char* argv[])
{
	/* Validando argumento de entradas (numero de threads) */
	if(argc < 2)
	{
		puts("Número de threads não informado.");
		return 1;
	}	
	int n_threads = atoi(argv[1]);

	printf("\n\t n_threads:%d \n",n_threads);

	/* Alocando espaço para TIDs */
	pthread_t *tid;
	tid = (pthread_t*) malloc(n_threads*sizeof(tid));
	if(tid == NULL)
	{
		puts("problema na alocação de memoria");
		return 1;
	}
	long int i;

	/* Executando threads */
	for(i = 0; i<n_threads;i++)
	{
		int ret = pthread_create(&tid[i],NULL,cafe_com_leite,(void*)i);
		if(ret)
		{
			printf("\n Erro [%d] na criação da thread nº %d",ret,i);
		}
	}

	/* Esperando fim da execução das threads*/
	for(i=0;i<n_threads;i++){
		pthread_join(tid[i],NULL);
	}

	printf("\t [~*~ Fim ~*~]");
	
	puts("\n");
	return 0;
}
