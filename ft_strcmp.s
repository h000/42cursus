global _ft_strcmp

_ft_strcmp:
	xor rcx, rcx
	cmp	rdi, rsi
	je equal

compare:
	mov	dl, BYTE[rdi + rcx]
	cmp	BYTE[rsi + rcx], dl
	jne	return
	cmp	dl, 0
	je	equal
	inc	rcx
	jmp	compare

equal:
	xor	rax, rax
	ret

return:
	sub dl, BYTE[rsi + rcx]
	movsx	rax, dl
	ret
