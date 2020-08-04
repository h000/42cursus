global _ft_strcmp

_ft_strcmp:							; ft_strcmp (rdi, rsi)
	xor rcx, rcx					; mov rcx, 0
	cmp	rdi, rsi
	je equal						; if rdi == rsi, jump to equal

compare:
	mov	dl, BYTE[rdi + rcx]
	cmp	BYTE[rsi + rcx], dl
	jne	return						; if s1[rcx] != s2[rcx], jump to return
	cmp	dl, 0
	je	equal						; if s1[rcx] == s2[rcx] == 0, jump to equal
	inc	rcx
	jmp	compare

equal:
	xor	rax, rax
	ret

return:
	sub	dl, BYTE[rsi + rcx]
	movsx	rax, dl					; return value is s1[rcx] - s2[rcx]
	ret
