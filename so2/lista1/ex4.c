#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

/* 
4. Comparação entre stat() e lstat()
Crie um link simbólico para um arquivo (ln -s arquivo.txt
link.txt).
Escreva um programa que:
Use stat("link.txt") e mostre o tamanho do arquivo real.
Use lstat("link.txt") e mostre o tamanho do link (nÃ£o do alvo).
Explique a diferença.
*/

int main(int argc, char const *argv[])
{	
	struct stat file_status;

	const char* file_name = "symlsdfgsdgink";
	symlink(argv[0],file_name);

	if( stat(argv[0],&file_status) )
	{
		puts("Erro na manipulação do arquivo pelo stat().");
		return 1;
	}
	
	printf("Tamanho do arquivo \"%s\":\n"
		"\t%ld Bytes\n", argv[0],file_status.st_size);
	

	if( lstat(file_name,&file_status) )
	{
		puts("Erro na manipulação do arquivo pelo stat().");
		return 1;
	}
	
	printf("Tamanho do link \"%s\":\n"
		"\t%ld Bytes\n",file_name,file_status.st_size);
	
		/* Vemos que o tamanho do link é exatamente o tamanho da cadeia de caracteres que define o pathname do arquivo original. */
	return 0;
}
