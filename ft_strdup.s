global _ft_strdup
extern _malloc						; malloc(rdi)
extern _ft_strlen					; ft_strlen(rdi)
extern _ft_strcpy					; ft_strcpy(rdi, rsi)
extern ___error

_ft_strdup:							; ft_strdup (rdi)
		call _ft_strlen
		inc rax						; to malloc(strlen + 1)

		push rdi
		mov rdi, rax
		call _malloc				; malloc(strlen + 1)
		cmp	rax, 0
		jc	error					; jump to error, if rax == 0

		pop rsi						; rsi <- strdup에서 받은 인자
		mov	rdi, rax				; rdi <- malloc 해놓은거
		call _ft_strcpy
		ret

error:
		call ___error
		mov [rbx], rax				; set error number
		mov rax, 0					; set return to 0
		ret							; return