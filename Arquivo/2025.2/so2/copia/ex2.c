#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main ()
{

char bloco[1024];
int in, out; /* serão usados como descritores de arquivos */
int nread;
in = open("file.in", O_RDONLY);
out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
while ((nread = read(in, bloco, sizeof(bloco))) > 0)
	write (out, bloco, nread);
}