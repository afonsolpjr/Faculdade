#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* 2. Ler parte de um arquivo com lseek()
Escreva um programa que:
Receba o nome de um arquivo
Leia apenas os 100 primeiros bytes usando read().
Depois, use lseek() para pular para o byte 200 e leia mais 50
bytes.
Exiba o conteúdo lido. */


int main(int argc, char const *argv[])
{
	int fd;
	char buf[256];
	fd = open(argv[1],'r');
	
	read(fd,buf,100);
	lseek(fd,100,SEEK_CUR);
	read(fd,&buf[100],50);	
	printf("%s",buf);

	return 0;
}
