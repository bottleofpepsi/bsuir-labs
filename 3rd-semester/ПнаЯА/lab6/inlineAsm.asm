.386
.model small, c
.code
PUBLIC C inlineAsm
inlineAsm proc uses ebx ecx

			push ebp
			mov ebp,esp

			finit									

			mov ecx, [ebp+4]
			lea ebx, [ebp+8]					

			fldz										

		Calculate_loop:
			fld dword ptr [ebx]							
			fcom
			fstsw ax
			sahf
			ja Greater

		Less:										
			fmul
			fstp dword ptr [ebx]
			jmp loop_End
	
		Greater:									
			fmul
			fmul
			fstp dword ptr [ebx]

		loop_End:										
			add ebx, 4								
			loop Calculate_loop

			fwait 
			pop ebp
			ret
inlineAsm endp
end