#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

/* 
Abra um arquivo binário.
Use lseek() para percorrê-lo sem read() tradicional.
Conte quantos bytes nulos (\0) existem nele.
*/

int main(int argc, char const *argv[])
{	
	int fd, location;
	char c;

	if ( (fd = open(argv[0], O_RDONLY)) == -1)
	{
		puts("Erro na abertura do arquivo.\n");
		return 1;
	}
	
	int count = 0;
	while(read(fd,&c,1))
	{
		location = lseek(fd,0,SEEK_CUR);
		if( c == '\0' )
		{
			count++;
			printf("Byte nulo encontrado no offset [%d]\n",location);
		}
	}
	printf("\tTotal de bytes nulos: %d\n",count);
	return 0;
}
