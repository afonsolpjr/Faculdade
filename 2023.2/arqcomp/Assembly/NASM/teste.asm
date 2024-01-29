    ; Programa para somar dois números 
    ; 13/08/2023
; Valores para system_calls (colocar no A)

SYS_EXIT EQU 1   ; 
SYS_WRITE EQU 4
SYS_READ EQU 3

; Indicadores de leitura e escrita (colocar no B)
STDOUT EQU 1
STDIN EQU 0


section .data
    char DB 99

section .text

global _start

_start:
  
    
    MOV eax, SYS_WRITE   ; exibindo msg
    MOV ebx, STDOUT
    MOV ecx, char
    MOV edx, 1
    INT 0x80



    ; Finalizando

    MOV eax,1
    INT 0x80
