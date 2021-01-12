disk_load:
    pusha
    push dx

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02

    mov ch, 0x00
    mov dh, 0x00

    int 0x13
    jc disk_error

    pop dx
    cmp al, dh
    jne sectors_error
    popa
    ret


disk_error:
    mov ah, 0x0e
    mov al, 'D'
    int 0x10
    mov al, 'E'
    int 0x10
    jmp disk_loop

sectors_error:
    mov ah, 0x0e
    mov al, 'S'
    int 0x10
    mov al, 'E'
    int 0x10

disk_loop:
    jmp $