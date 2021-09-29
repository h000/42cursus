global _ft_read
extern ___error

_ft_read:					; ft_read (rdi, rsi, rdx)
	push rbp
	call ___error
	pop rbp
	mov	rbx, rax			; save address of error number in rbx
	mov rax, 0x2000003		; sys_read syscall number, 0 in Linux
    syscall					; call rax (read)
	jc	error				; if syscall error -> carry flag = 1
	ret

error:
	mov [rbx], rax			; set error number
	mov rax, -1				; set return to -1
	ret						; return