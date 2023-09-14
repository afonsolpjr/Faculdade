; Pequeno programa para testar acesso a memoria com indices (offset value a partir de uma base)


SYS_EXIT EQU 1
SYS_WRITE EQU 4
STDOUT EQU 1
STDIN EQU 0
QTD equ 2



section	.text
global _start     ;must be declared for linker (ld)

_start:             ;tell linker entry point
	
   ;writing the name 'Zara Ali'
    mov	edx, len       ;message length
    mov	ecx, name   ;message to write
    mov	ebx,STDOUT       ;file descriptor (stdout)
    mov	eax,SYS_WRITE       ;system call number (sys_write)
    int	0x80        ;call kernel

    ;colocando 'ra' no final de 'Ali', QTD vezes
_repeat:

    mov edx, 2  ; tamanho da str em bytes
    mov ecx, name+2 ; acessando segundo elemento de name
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    
    inc word [counter] 
    cmp word [counter],QTD
    jne _repeat

    ; preparando sys_exit
    mov eax, SYS_EXIT
    int 0x80


section	.data
name db 'Zara Ali'
counter db 0
len equ $ - name