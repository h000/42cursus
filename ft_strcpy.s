global _ft_strcpy

_ft_strcpy:							; ft_strcpy (rdi, rsi)
	xor rcx, rcx					; mov rcx, 0

copy:
	cmp	BYTE[rsi + rcx], 0
	je	return						; if [rsi + rcx] == 0, jump to return
	mov	dl, BYTE[rsi + rcx]			; d∂st[rcx] = src[rcx]
	mov	BYTE[rdi + rcx], dl
	inc rcx							; ++rcx
	jmp copy

return:
	mov		BYTE[rdi + rcx], 0		; 끝에 NULL
	mov		rax, rdi
	ret
