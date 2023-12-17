.model small
.stack 100h

.data
num db 0 

msg1 db "Unable to load and execute program",0Dh,0Ah,'$'
msg2 db "Unable to allocate memory",0Dh,0Ah,'$'
msg3 db "Invalid input",0Dh,0Ah,'$' 
success db "Successfully runned "
times   db 3 dup(?)
        db " times!",0Dh,0Ah,'$'

command_line db 126 dup(0)
file_name db 125 dup(0)
EPB dw 0000 
    dw offset command_line 
    dw 005Ch,0,006Ch,0 


.code
printStr MACRO str  
    push ax dx  
    
    mov dx,offset str
    mov ah,9
    int 21h
    
    pop dx ax    
ENDM
    
isDelimiter PROC
    xor ah,ah
    
    cmp al,20h
    jne not_space
    mov ah,1 
    
    not_space:
    cmp al,9h
    jne not_tab
    mov ah,1
    
    not_tab:
    ret
isDelimiter ENDP

findWord PROC
    push bp
    mov bp,sp
    push ax cx si 
    
    mov si,[bp+4]
    
    handle_word:
    
    skip_delimiter:
    mov al,[si]
    call isDelimiter
    
    cmp ah,1
    je found_delimiter
    jmp stop_reading_string
    
    found_delimiter:  
    cmp cx,0
    jne string_end_not_reached
    jmp stop_reading_string  
    
    string_end_not_reached: 
    inc si
    dec cx
    
    jmp handle_word 
    
    stop_reading_string:
    mov bx,si
    sub bx,[bp+4]
    
    skip_character:
    mov al,[si]
    call isDelimiter
    
    cmp ah,1
    jne not_delimiter
    jmp word_read
    
    not_delimiter:
    cmp cx,0
    jne can_read_more
    jmp word_read 
    
    can_read_more: 
    cmp al,0Dh
    jne not_the_end
    jmp word_read
    
    not_the_end:
    inc si
    dec cx
    jmp skip_character
    
    word_read:
    mov di,si
    sub di,[bp+4]
    cmp bx,di
    je word_not_found
    dec dx
    
    word_not_found:
    cmp cx,0
    jne not_end_of_string
    jmp end_of_loop
    
    not_end_of_string:
    cmp dx,0
    jne not_this_word
    jmp end_of_loop
   
    not_this_word:
    cmp byte ptr [si],0Dh
    jne not_stop
    jmp end_of_loop
    
    not_stop:
    jmp handle_word
    
    end_of_loop:
    pop si cx ax bp
    ret
findWord ENDP

readCommandLine PROC
    push cx si di
    
    xor cx,cx
    mov cl,ds:[80h]
    mov bx,cx
   
    mov si,81h
    lea di,command_line
    
    rep movsb
    
    pop di si cx
    ret
readCommandLine ENDP

getFileNameFromCmd PROC
    push cx bx dx si di
    
    xor ax,ax
    mov dx,1
    mov cx,bx
    push offset command_line
    call findWord
    add sp,2
    
    cmp dx,0
    jne file_name_not_found
    
    mov cx,di
    sub cx,bx
    mov ax,cx
    
    mov di,offset file_name
    mov si,bx
    add si,offset command_line
    
    rep movsb
    
    file_name_not_found:
    pop di si dx bx cx
    ret
getFileNameFromCmd ENDP

isDigit PROC
    xor ch,ch
    
    cmp cl,30h
    jge greater_than_zero
    jmp not_a_number
    greater_than_zero:
    
    cmp cl,39h
    jle less_than_nine
    jmp not_a_number
    less_than_nine:
    
    mov ch,1
    not_a_number:
    
    ret
isDigit ENDP    

getNumberFromCmd PROC
    push bx cx dx si
    
    mov dx,2
    mov cx,bx
    push offset command_line
    call findWord
    add sp,2
    
    cmp dx,0
    jne invalid_input
    
    mov si,10
    xor ax,ax
    
    get_another_digit:  
    mov cl,command_line[bx]
    
    cmp bx,di
    jne not_end_of_number
    jmp end_of_number
    
    not_end_of_number:
    call isDigit
    cmp ch,1
    je digit_read
    jmp invalid_input
   
    digit_read: 
    mul si
    jno not_overflow
    jmp invalid_input
    
    not_overflow: 
    xor ch,ch
    sub cx,30h
    add ax,cx
    jno not_of
    jmp invalid_input
    
    not_of:   
    inc bx
    jmp get_another_digit
    
    end_of_number:
    jmp proc_end 
    
    invalid_input:
    xor ax,ax
    
    proc_end:
    pop si dx cx bx
    ret
getNumberFromCmd ENDP   

toString PROC
    push ax cx dx di
    
    to_string:
    mov dl,10
    lea di,times
    add di,2
       
    mov cx,3 
    
    to_string_loop:
    xor	ah,ah          
	div	dl            
                                 
	xchg al,ah        
	add	al,'0'
	
	mov [di],al
	dec di         
                 
	xchg al,ah
	                    
	loop to_string_loop
	
	pop di dx cx ax
	ret
toString ENDP

allocateMemory PROC
    push ax bx dx
    
    mov ax,es
    mov bx,zseg
    sub bx,ax    
    mov ah,4Ah
    int 21h
    
    jnc memory_allocated
    printStr msg2
    
    memory_allocated:  
    pop dx bx ax
    ret
allocateMemory ENDP    

loadProgram PROC
    push ax bx dx
      
    mov ax,ds
    mov word ptr EPB+4,ax 
    mov word ptr EPB+8,ax 
    mov word ptr EPB+0Ch,ax 
    
    mov dx,offset file_name
    mov bx,offset EPB   
    mov ah,4Bh
    mov al,0
    int 21h
    
    jnc loaded_successfully
    printStr msg1
    
    loaded_successfully:
    pop dx bx ax  
    ret
loadProgram ENDP

delay PROC
    push ax cx dx
    
    mov cx,3
    mov dx,22BCh
    mov ah,86h                              
    int 15h
    
    pop dx cx ax
    ret
delay ENDP

start:
    call allocateMemory
    mov ax,@data
    mov es,ax

    call readCommandLine
    mov ds,ax

    call getFileNameFromCmd
    cmp ax,0
    je invalid_parameter
 
    call getNumberFromCmd
    mov bx,ax
    cmp ax,0
    je invalid_parameter
    cmp ax,255
    jg invalid_parameter
    mov num,al
    call toString
    
    xor ch,ch
    mov cl,num
    mov al,0
    
    iteration:
    call delay 
    call loadProgram
    jc _end
                
    loop iteration
    
    printStr success
    
    _end:
    jmp skip_output_msg

    invalid_parameter: 
    printStr msg3

    skip_output_msg:
    mov ax,4c00h
    int 21h
    
zseg SEGMENT
zseg ENDS   
end start 