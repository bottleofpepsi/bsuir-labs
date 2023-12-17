.model small
.code
PUBLIC C inlineAsm
proc inlineAsm
			finit									

			mov ecx, N
			lea ebx, array					

			fldz										

		Calculate_loop:
			fld [ebx]							
			fcom
			fstsw ax
			sahf
			ja Greater

		Less:										
			fmul [ebx]
			fstp [ebx]
			jmp End
		
		Greater:									
			fmul [ebx]
			fmul [ebx]
			fstp [ebx]

		End:										
			add ebx, 4								
			loop Calculate_loop

			fwait
inlineAsm endp        
end