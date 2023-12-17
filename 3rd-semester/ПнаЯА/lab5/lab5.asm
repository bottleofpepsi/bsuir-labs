.model small
.stack 100h

.data
file_id dw 0
ptrh dw ?
ptrl dw ?
str_length dw 0
num dw 0 
flag db 0

msg1 db "Unable to open a file",0Dh,0Ah,'$'
msg2 db "Unable to close a file",0Dh,0Ah,'$'
msg3 db "Invalid input",0Dh,0Ah,'$'
success db "Deleted successfully!",0Dh,0Ah,'$' 

command_line db 126 dup(0)
file_name db 125 dup(0)
buffer db ?

.code
printStr MACRO str  
    push ax dx  
    
    mov dx,offset str
    mov ah,9
    int 21h
    
    pop dx ax    
ENDM

openFile PROC
    push cx dx
    
    mov ah,3Dh
    mov al,02h
    mov cl,0
    int 21h
    
    jnc file_opened    
    printStr msg1
    
    file_opened:
    pop dx cx
    ret
openFile ENDP
    
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

deleteStrings PROC
    push ax bx cx dx     
    
    mov bx,file_id
    mov ah,42h
    mov al,0
    xor cx,cx
    xor dx,dx
    int 21h
    
    deleteStr_loop:
    mov cx,num 
    cmp cx,0
    je deleteStr_delete
    
    deleteStr_skip:
    call skipString
    cmp flag,1
    je deleteStr_end
    loop deleteStr_skip
    
    deleteStr_delete: 
    call getLength
    call deleteFromFile
    cmp flag,1
    je deleteStr_end 
    
    jmp deleteStr_loop
    
    deleteStr_end:
    pop dx cx bx ax
    ret
deleteStrings ENDP

skipString PROC
    push ax dx cx
    
    skipStr_loop:
    mov ah,3Fh
    mov cx,1
    mov dx,offset buffer
    int 21h
    
    cmp ax,0
    je skipStr_EOF
    cmp [buffer],0Ah
    je skipStr_end
    jmp skipStr_loop
    
    skipStr_EOF:
    mov flag,1
    
    skipStr_end:
    pop cx dx ax
    ret
skipString ENDP
               
getLength PROC
    push ax dx cx
    
    mov ah, 42h
    mov al, 01h
    xor cx, cx
    xor dx, dx
    int 21h
    push ax dx
    mov str_length,0
    
    length_loop:
    inc str_length
    mov ah,3Fh
    mov cx,1
    mov dx,offset buffer
    int 21h
    
    cmp ax,0
    je length_EOF      
    cmp [buffer],0Ah
    je length_end
    jmp length_loop
    
    length_EOF:
    mov flag,1
    
    length_end:
    mov ah,42h
    mov al,00h
    pop cx
    pop dx
    int 21h
    
    pop cx dx ax
    ret
getLength ENDP

deleteFromFile proc     
    push ax dx cx di

    mov di,str_length

    mov ah,42h
    mov al,01h
    xor cx,cx
    xor dx,dx
    int 21h

    mov ptrh,dx
    mov ptrl,ax

deleteFromFile_loop:
    mov ah,42h
    mov al,01h
    xor cx,cx
    xor dx,dx
    int 21h
    push ax
    push dx

    mov ah,42h
    mov al,01h
    xor cx,cx
    mov dx,di
    int 21h

    mov ah,3Fh
    mov cx,1
    mov dx,offset buffer
    int 21h

    cmp ax, 0
    je deleteFromFile_EOF   
    
    mov ah,42h
    mov al,00h
    pop cx
    pop dx
    int 21h

    mov ah,40h
    mov cx,1
    mov dx,offset buffer
    int 21h

    jmp deleteFromFile_loop

deleteFromFile_EOF:
    mov ah,42h
    mov al,00h
    pop cx
    pop dx
    int 21h
    
    mov ah,40h
    mov cx,0
    mov dx,offset buffer
    int 21h

deleteFromFile_end:
    mov ah,42h
    mov al,00h    
    mov cx,ptrh
    mov dx,ptrl
    int 21h

    pop di cx dx ax
    ret
deleteFromFile endp

readCommandLine PROC
    push cx si di
    
    xor cx,cx
    mov cl,ds:[0080h]
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

closeFile PROC
    push ax
    
    mov ah,3Eh
    int 21h
    
    jnc file_closed
    printStr msg2

    file_closed:
    pop ax
    ret
closeFile ENDP

start:
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
    
    mov dx,offset file_name
    call openFile
    jc _end

    mov file_id,ax
    
    mov num,bx
    dec num
    call deleteStrings

    mov bx,file_id
    call closeFile
    jc _end
    
    printStr success

    _end:
    jmp skip_output_msg

    invalid_parameter: 
    printStr msg3

    skip_output_msg:
    mov ax,4c00h
    int 21h
end start