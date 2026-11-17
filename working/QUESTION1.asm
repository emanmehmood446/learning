[org 0x0100]
jmp start
start:
mov ax, array1
push ax
mov ax, [lenofArray]
push ax
call statsofArray
jmp Exit
statsofArray:
push bp
mov bp, sp
push ax
push bx
push cx
push dx
push si
push di
mov si, [bp+6]       
mov di, [bp+4]       
push di              
push si              
call bubblesort
mov ax, [si]        
mov bx, di
dec bx
shl bx, 1            
mov bx, [si+bx]      
mov cx, di
shr cx, 1            
shl cx, 1           
mov ax, di
mov bl, 2
div bl               
cmp ah, 0
je EvenMedian
mov dx, [si+cx]
jmp MedianDone
EvenMedian:
mov dx, [si+cx-2]    
add dx, [si+cx]      
shr dx, 1           
MedianDone:
pop di
pop si
pop dx
pop cx
pop bx
pop ax
pop bp
ret 4
bubblesort:
push bp
mov bp, sp
push ax
push bx
push cx
push dx
push si
push di
mov si, [bp+4]      
mov cx, [bp+6]       
dec cx
jcxz Done
Outer:
mov di, cx
mov bx, si
Inner:
mov ax, [bx]
mov dx, [bx+2]
cmp ax, dx
jbe NoSwap
mov [bx], dx
mov [bx+2], ax
NoSwap:
add bx, 2
loop Inner
mov cx, di
dec cx
jcxz Done
jmp Outer
Done:
pop di
pop si
pop dx
pop cx
pop bx
pop ax
pop bp
ret 4
Exit:
mov ax, 0x4c00
int 0x21
array1: dw 6,7,3,9,100,5,1,50
lenofArray: dw 8