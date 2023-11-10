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

    prompt1 db "Insira 1 DIGITO:"
    len1 EQU $ - prompt1
    digitos db 0,0

section .text

global _start

_start:
    MOV eax, SYS_WRITE   ; exibindo msg
    MOV ebx, STDOUT
    MOV ecx, prompt1
    MOV edx, len1
    INT 0x80

    MOV eax, SYS_READ ; lendo (precisa colocar um byte a mais!! pro pointer do buffer nao ficar noq vc digitou)
    MOV ebx, STDIN
    MOV ecx, digitos
    MOV edx, 2
    INT 0x80

    MOV eax, SYS_WRITE   ; exibindo msg
    MOV ebx, STDOUT
    MOV ecx, prompt1
    MOV edx, len1
    INT 0x80

    MOV eax, SYS_READ ; lendo 
    MOV ebx, STDIN
    MOV ecx, digitos+1
    MOV edx, 2
    INT 0x80

    ; MOV eax, SYS_WRITE   ; exibindo ultimo digito
    ; MOV ebx, STDOUT
    ; MOV ecx, digitos+1
    ; MOV edx, 1
    ; INT 0x80

    ;Somando

    MOV al, [digitos]
    MOV bl, [digitos+1]
    SUB al, 48
    SUB bl, 48

    ADD al,bl
    ADD al, 48

    MOV [digitos+1], al
    MOV ecx, digitos+1            ; LEMBRE-SE, AQUI VAI O ENDEREÇO DO CHAR!!!! por isso nao está entre colchetes
    
    ; mostrando resultado

    MOV eax, SYS_WRITE   ; exibindo msg
    MOV ebx, STDOUT
    MOV edx, 1
    INT 0x80



    ; Finalizando

    MOV eax,1
    INT 0x80
