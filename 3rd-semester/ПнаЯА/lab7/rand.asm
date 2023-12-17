.model tiny

.data
msg db "Wise pseudorandom number generator says: $"
newl db 0Dh,0Ah,'$'
num db 3 dup (?),'$'

.code
start:
    mov ax,@data
    mov ds,ax

    rand_num:
    mov ah,2Ch           
	int 21h               
	
	mov al,dl                     
    mul dh                
	             
	to_string:
    mov dl,10
    lea di,num
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
	
	mov ah,9
	lea dx,msg
	int 21h
	lea dx,num
	int 21h
	lea dx,newl
	int 21h        

    mov ax, 4c00h 
    int 21h    

end start 
