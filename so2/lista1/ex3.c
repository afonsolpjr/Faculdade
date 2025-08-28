#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

/* 
3. Usando stat() para informações de um arquivo
Faça um programa que:
Receba o nome de um arquivo.
Use stat() para mostrar:
Tamanho
Número de links
UID do dono
Permissões de acesso (rwx)
Última modificação (st_mtime formatada em data/hora) */


    //    struct stat {
    //        dev_t      st_dev;      /* ID of device containing file */
    //        ino_t      st_ino;      /* Inode number */
    //        mode_t     st_mode;     /* File type and mode */
    //        nlink_t    st_nlink;    /* Number of hard links */
    //        uid_t      st_uid;      /* User ID of owner */
    //        gid_t      st_gid;      /* Group ID of owner */
    //        dev_t      st_rdev;     /* Device ID (if special file) */
    //        off_t      st_size;     /* Total size, in bytes */
    //        blksize_t  st_blksize;  /* Block size for filesystem I/O */
    //        blkcnt_t   st_blocks;   /* Number of 512 B blocks allocated */

    //        /* Since POSIX.1-2008, this structure supports nanosecond
    //           precision for the following timestamp fields.
    //           For the details before POSIX.1-2008, see VERSIONS. */

    //        struct timespec  st_atim;  /* Time of last access */
    //        struct timespec  st_mtim;  /* Time of last modification */
    //        struct timespec  st_ctim;  /* Time of last status change */

    //    #define st_atime  st_atim.tv_sec  /* Backward compatibility */
    //    #define st_mtime  st_mtim.tv_sec
    //    #define st_ctime  st_ctim.tv_sec
    //    };

int main(int argc, char const *argv[])
{
	struct stat file_status;
	struct tm *time_struct;
	char *formatted_time;

	if( stat(argv[1],&file_status))
	{
		puts("Erro na abertura ou leitura do status do arquivo.");
		return 1;
	}

	/* se stat() para mostrar:
		Tamanho
		Número de links
		UID do dono
		Permissões de acesso (rwx)
		Última modificação (st_mtime formatada em data/hora) */
	
	time_struct = localtime( &file_status.st_ctime);

	//  struct tm {
    //        int         tm_sec;    /* Seconds          [0, 60] */
    //        int         tm_min;    /* Minutes          [0, 59] */
    //        int         tm_hour;   /* Hour             [0, 23] */
    //        int         tm_mday;   /* Day of the month [1, 31] */
    //        int         tm_mon;    /* Month            [0, 11]  (January = 0) */
    //        int         tm_year;   /* Year minus 1900 */
    //        int         tm_wday;   /* Day of the week  [0, 6]   (Sunday = 0) */
    //        int         tm_yday;   /* Day of the year  [0, 365] (Jan/01 = 0) */
    //        int         tm_isdst;  /* Daylight savings flag */

    //        long        tm_gmtoff; /* Seconds East of UTC */
    //        const char *tm_zone;   /* Timezone abbreviation */
    //    };
	asprintf(&formatted_time,"%d/%d/%d %d:%d",
		time_struct->tm_mday,time_struct->tm_mon,time_struct->tm_year + 1900,
		time_struct->tm_hour,time_struct->tm_min);
	
	printf("File: \"%s\"\n"
		"\tLinks: %ld\n"
		"\tOwner UID: %d\n"
		"\tAcess: %d\n"
		"\tLast modified: %s\n",
			argv[1], file_status.st_nlink, file_status.st_uid, file_status.st_mode, formatted_time);

	return 0;
}
