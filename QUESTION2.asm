[org 0x0100]
jmp start
rowOffset: dw 0
start:
 call clrscr
push word 134       ; first number
push word 189       ; second number
push word 156       ; third number
push word 3         ; total numbers
call printNumbers
add sp, 8           
mov ax, 0x4c00
int 0x21
printNumbers:
push bp
mov bp, sp
push ax
push bx
push cx
push dx
push si
mov cx, [bp+4]       
cmp cx, 0
 je PN_Done
mov si, cx
dec si
shl si, 1
add si, 6
PN_Loop:
push cx
 mov ax, [bp+si]     
push ax
call printnum        
add si, -2           
pop cx
loop PN_Loop
PN_Done:
pop si
pop dx
pop cx
 pop bx
pop ax
pop bp
 ret
printnum:
 push bp
 mov bp, sp
push es
push ax
 push bx
push cx
push dx
push di
mov ax, 0xb800
mov es, ax
mov ax, [bp+4]     
 mov bx, 10
mov cx, 0
PN_Digit:
mov dx, 0
div bx               
add dl, 0x30         
push dx             
 inc cx
cmp ax, 0
jne PN_Digit
mov di, [rowOffset]
PN_Print:
pop dx
 mov dh, 0x07         
 mov [es:di], dx
add di, 2
loop PN_Print
mov ax, [rowOffset]
 add ax, 160
mov [rowOffset], ax
pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2
clrscr:
 push ax
push cx
push di
push es
mov ax, 0xb800
mov es, ax
xor di, di
mov ax, 0x0720
 mov cx, 2000
CS_Loop:
mov [es:di], ax
add di, 2
    loop CS_Loop
mov word [rowOffset], 0
 pop es
pop di
 pop cx
pop ax
ret