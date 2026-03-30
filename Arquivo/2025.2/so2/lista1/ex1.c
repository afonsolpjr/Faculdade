#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* 1. Usando lseek() para medir o tamanho do arquivo
Escreva um programa que:
Abra um arquivo qualquer.
Use lseek(fd, 0, SEEK_END) para posicionar no final.
Exiba o tamanho do arquivo em bytes. */


int main(int argc, char const *argv[])
{
	long size;
	int fd;

	fd = open(argv[1],'r');
	size = lseek(fd,0,SEEK_END);

	printf("%ld\n",size);

	return 0;
}
