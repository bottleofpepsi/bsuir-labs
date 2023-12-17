.model small
.stack 100h

.data
  
    size equ 10
    size_array equ 5
    array dw size_array dup(?) 
    current_element dw ? 
    sign dw ?
    string db size dup('$')
    
    ten dw 10
    minus dw -1
    min dw ?
    max dw ?
    difference dw ?
    result dw ?
    msg1 db "Enter the array: $"
    msg2 db "Entered array: $"
    msg3 db "Difference of maximum and minimum value: $"
    msg4 db "Result: $"
    msg5 db "Min: $"
    msg6 db "Max: $" 
    msg7 db "Overflow!",0Dh,0Ah,'$'
    msg8 db "Error: Divided by zero!",0Dh,0Ah,'$'
    error db "Incorrect input!",0Dh,0Ah,'$'
    newl db 0Dh,0Ah,'$'
    min_num equ 32768
    max_num equ 32767
    
.code
   
Input_string macro str
    lea dx,str
    mov offset str,size-3
    mov ah,0Ah
    int 21h
    mov ax,0
    call Check_num
endm 

Output_string proc
    mov ah,9
    int 21h
    ret
Output_string endp 

Overflow_output proc
    mov dx,offset newl
    call Output_string
    mov dx,offset msg7
    call Output_string
    mov dx,offset newl
    call Output_string
    
    call Exit
    ret
Overflow_output endp

Output proc
Outp: 
    inc di
    mov dx,0
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    div ten 
    jo call Overflow_output
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    add dx,'0'
    push dx
    cmp ax,0
    jne Outp
    
    cmp sign,-1
    jne Output_num
    Output_sumb '-'
Output_num:
    pop ax
    Output_sumb ax
    dec di
    cmp di,0
jne loop Output_num
    ret
Output endp

Output_sumb macro symb                                                                                                      
    mov dx,symb
    mov ah,06h
    int 21h
endm

Negative_sign proc
    mov sign,-1
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mul minus
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov di,0
    call Output
    
    ret
Negative_sign endp

Positive_sign proc
    mov sign,1
    
    mov di,0
    call Output
    
    ret
Positive_sign endp

Check_num proc
    mov si,offset string
    add si,2
    cmp [si],'-' 
    je Negative_num
    mov bx,0
    mov sign,1
    call Convert_num
    ret
Negative_num:
    mov sign,-1
    inc si
    mov bx,0
    call Convert_num 
    ret
Check_num endp

Convert_num proc
    cmp [si],'0'
    jb call Num_error
    cmp [si],'9'
    ja call Num_error
    mov ax,ten
    mul bx
    mov bx,ax
    mov ax,0
    mov al,[si]
    sub ax,'0'
    add bx,ax
    inc si
    cmp [si],0Dh
    jne call Convert_num
    mov ax,bx
    
    cmp sign,-1
    je min_point
    jne max_point
    
max_point:    
    cmp ax,max_num
    ja call Num_error
    jmp point
    
min_point:
    cmp ax,min_num
    ja call Num_error
    
point:    
    mul sign
    mov current_element,ax
    ret
Convert_num endp

Num_error proc
    lea dx,newl
    call Output_string
    lea dx,error
    call Output_string
    Input_string string
    ret
Num_error endp   

Exit proc
    mov ax,4C00h
    int 21h
    ret
Exit endp

start:
    mov ax,@data
    mov ds,ax

    mov cx,size_array 
    mov di,offset array
    push es
    push di
    mov dx,offset msg1
    call Output_string
    mov dx,offset newl
    call Output_string
       
Input_array:
    Input_string string
    
    mov dx,offset newl
    call Output_string 
    mov ax,current_element
    stosw    
loop Input_array 

    mov cx,size_array
    mov di,0
    
    mov dx,offset msg2
    call Output_string
    
    pop si
    mov bx,ds
    mov es,bx
    pop ds
    
    cld
    
Output_array:
    mov ax,0
    lodsw
    
    cmp ax,0
    js negative
    call Positive_sign
    jmp continue 
    
negative:
    call Negative_sign
continue:
    Output_sumb ' ' 
    
loop Output_array
    
    mov di,size_array
    mov si,offset array
    mov ax,0
    lodsw
    dec di
    mov min,ax
    jmp Find_min
    
Change_min:
    mov min,ax
    
Find_min:
    cmp di,0
    jbe Find_continue
    
    mov ax,0
    lodsw
    dec di
    cmp min,ax
    jg Change_min
    cmp di,0
    jge Find_min
    
Find_continue:
    
    mov di,size_array
    mov si,offset array
    mov ax,0
    lodsw
    dec di
    mov max,ax
    jmp Find_max
    
Change_max:
    mov max,ax 
    
Find_max:
    cmp di,0
    jbe Find_end
    
    mov ax,0
    lodsw
    dec di
    cmp max,ax
    jl Change_max
    cmp di,0
    jge Find_max
    
Find_end:
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov dx,offset newl
    call Output_string
    mov dx,offset msg5
    call Output_string 
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov ax,min
    
    mov cx,1
    cmp ax,0
    js negative2
    call Positive_sign
    jmp continue2
negative2:
    call Negative_sign
    
continue2:

    
    push ds
    mov bx,es
    pop es
    mov ds,bx
      
    mov dx,offset newl
    call Output_string
    mov dx,offset msg6
    call Output_string
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
      
    mov ax,max
    
    mov cx,1
    cmp ax,0
    
    js negative3
    call Positive_sign
    jmp continue3
negative3:
    call Negative_sign
    
continue3:
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov dx,offset newl
    call Output_string
    mov dx,offset msg3
    call Output_string
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov ax,max
    sub ax,min
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    jo call Overflow_output
    push ds
    mov bx,es
    pop es
    mov ds,bx
    mov difference,ax
    
    mov ax,difference
    
    mov cx,1
    cmp ax,0
    js negative4
    call Positive_sign
    jmp continue4
negative4:
    call Negative_sign
    
continue4:
    
    mov sign,1
    cmp max,0
    js change_sign
    jmp cont
    
change_sign:
    mov ax,max
    mov sign,-1
    mul sign
    mov max,ax 
    
cont: 
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov dx,offset newl
    call Output_string
    mov dx,offset msg4
    call Output_string
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    cmp max,0
    je divby0
    
    cmp sign,-1
    jne cont2: 
    Output_sumb '-'
    
cont2:
    
    mov ax,difference
    mov dx,0 
    
    div max
    jo call Overflow_output
    
    mov result,ax
    
    mov cx,1
    cmp ax,0
    js negative5
    call Positive_sign
    jmp continue5
negative5:
    call Negative_sign
    
continue5:
    Output_sumb '.'
    mov ax,max
    
    mul result
    mov dx,ax
    mov ax,difference
    sub ax,dx
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mul ten
    jo call Overflow_output
    mul ten
    jo call Overflow_output
    
    push ds
    mov bx,es
    pop es
    mov ds,bx
    
    mov dx,0
    div max
    jo call Overflow_output
    
    mov cx,1
    cmp ax,0
    call Positive_sign
    
    call Exit
        
divby0:

    push ds
    mov bx,es
    pop es
    mov ds,bx

    mov dx,offset newl
    call Output_string
    mov dx,offset msg8
    call Output_string 
 
    call Exit
       
end start