.model tiny

.code 
org 100h

jmp start

Output_string proc
    mov ah,9
    int 21h
    ret
Output_string endp   

Input_string macro str
    lea dx,str
    mov ah,0Ah
    int 21h
endm

Exit proc                 
    mov dx,offset newl
    call Output_string
    mov dx,offset result
    call Output_string
    mov dx,offset string[2]
    call Output_string
    mov dx,offset newl
    call Output_string  
    
    mov ax,4C00h
    int 21h
    ret
Exit endp

Empty_exit proc
    mov ax,4C00h
    int 21h
    ret
Empty_exit endp

Delete proc 
    inc si
    mov dl,[si]
    dec si
    mov [si],dl
    inc si
    cmp [si],0Dh
    jne call Delete  
    mov si,bx
    cmp [si],' '
    jne call Check
    ret
Delete endp
       
Check proc
    cmp [si],0Dh
    jne call Delete
    ret
Check endp     
                
start:               
    mov dx,offset msg1
    call Output_string
    Input_string string      
    
    mov dx,offset newl
    call Output_string
    mov dx,offset msg3
    call Output_string
    Input_string word
    
    cmp string[1],0
    je isEmpty
    
    cmp word[1],0
    je isEmpty
    
isEmpty:
    mov ah,[string[1]]
    cmp ah,0
    je String_is_empty
    mov ah,[word[1]]
    cmp ah,0
    je Word_is_empty
    jne Find
    
String_is_empty:
    mov dx,offset newl
    call Output_string
    mov dx,offset msg6
    call Output_string
    call Empty_exit
    
Word_is_empty:
    mov dx,offset newl
    call Output_string
    mov dx,offset msg7
    call Output_string
    call Empty_exit
    
Find:
    mov si,offset string[1]
    mov di,offset word[2]
    jmp Find_symbol

Find_symbol:
    inc si
    cmp [si],0Dh
    je notFound
    mov dl,[si]
    cmp [si],' '
    je Find_symbol
    cmp dl,0Dh
    je call Exit
    cmp dl,[di]
    jne Skip_word
    mov bx,si
    jmp Find_word
loop Find_symbol
    
Skip_word:
    cmp [si],' '
    je Find_symbol
    cmp [si],0Dh
    je notFound
    inc si
loop Skip_word     
    
Find_word:
    inc si
    inc di
    cmp [di],0Dh
    je isEnd
    mov dl,[si]
    cmp dl,[di]
    je loop Find_word
    jmp Next_word 
    
isEnd:
    cmp [si],' '
    je Found
    cmp [si],0Dh
    je Found
    
Next_word:
    mov di,offset word[2]
    jmp Skip_word

notFound:
    mov dx,offset newl
    call Output_string
    mov dx,offset msg5
    call Output_string
    call Exit
        
Found:
    inc si
    mov dx,offset newl
    call Output_string
    jmp Delete_word
    
Delete_word:
    dec bx
    mov si,bx
    call Delete
    call Exit
       
string db 200,200 dup ('$')
word db 200,200 dup ('$')
    
msg1 db "Enter the string: $"
msg2 db "Entered string: $"
msg3 db "Enter the word to delete: $"
msg4 db "Entered word: $"
msg5 db "Word not found!$"
msg6 db "String is empty$"
msg7 db "Word is empty$"
result db "Result: $"
newl db 0Dh,0Ah,'$'
    
end start