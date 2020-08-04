global _ft_strlen

_ft_strlen:
	xor rax, rax			; mov rax, 1
	jmp compare             ; jump to compare

increment:
	inc rax

compare:
	cmp BYTE[rax + rdi], 0	; char is 1byte
	jne increment           ; jump to increment, if [rax + rdi] is not 0

return:
 	ret
