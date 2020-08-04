global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx

copy:
	cmp	BYTE[rsi + rcx], 0
	je	return
	mov	dl, BYTE[rsi + rcx]
	mov	BYTE[rdi + rcx], dl
	inc rcx
	jmp copy

return:
	mov		BYTE[rdi + rcx], 0
	mov		rax, rdi
	ret
