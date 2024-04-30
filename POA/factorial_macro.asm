fact macro f
    up:
    mul f
    dec f
    jnz up
endm

data segment
    num dw 05h
    result dw ?
ends

stack segment
    dw 128 dup(0)
ends

code segment
    start:
    mov ax,data
    mov ds,ax
    mov cx,num
    
    mov ax, 0001h
    fact num
    mov result,ax
code ends
end start
