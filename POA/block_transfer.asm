; multi-segment executable file template
data segment
seg1 db 11h ,12h ,13h, 14h
ends
extra segment
seg2 db ?
ends
code segment
start:
; set segment registers:
mov ax, data
mov ds, ax
mov ax, extra
mov es, ax
; add your code here
lea si , seg1
lea di , seg2 
mov cx, 04h
x: mov ah,seg1[si]
mov es:[di],ah

inc si
inc di
dec cx 
jnz x
int 3

ends
end start ;
