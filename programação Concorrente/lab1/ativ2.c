#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>



typedef struct
{
    int id,n_threads;
} t_args;

/* Função a ser executada pela thread*/
void* print_hello(void* arg){
	t_args *args;
    args = (t_args*) arg;


	printf("Teste da thread nº %d/%d \n",(int) args->id,args->n_threads);
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

	/* Executando threads */
	long int i;
	for(i = 0; i<n_threads;i++)
	{
        /* Alocar estruturas de argumentos das threads */
        t_args *args;
        args = (t_args*) malloc(sizeof(t_args));
        args->id = i;
        args->n_threads = n_threads;

		int ret = pthread_create(&tid[i],NULL,print_hello,(void*)args);
        if(ret)
            printf("Erro [%d] na criação da thread %ld",ret,i);
	}

	/* Esperando fim da execução das threads*/
	for(int i=0;i<n_threads;i++){
		int ret = pthread_join(tid[i],NULL);
		if(ret){
			printf("Erro %d na finalização da thread %d",ret,i);
			return 1;
		}
		
	}

	printf("\t [~*~ Fim ~*~]");
	
	puts("\n");
	return 0;
}


