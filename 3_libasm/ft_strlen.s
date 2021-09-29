global _ft_strlen

_ft_strlen:					; ft_strlen (rdi)
	xor rax, rax			; mov rax, 0
	jmp compare             ; jump to compare

increment:
	inc rax

compare:
	cmp BYTE[rax + rdi], 0	; char is 1byte
	jne increment           ; jump to increment, if [rax + rdi] is not 0

return:
 	ret
