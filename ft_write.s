global _ft_write
extern ___error

_ft_write:					; ft_write (rdi, rsi, rdx)
	push rbp
	call ___error
	pop rbp
	mov	rbx, rax			; save address of error number in rbx
	mov rax, 0x2000004		; sys_write syscall number, 1 in Linux
    syscall					; call rax (write)
	jc	error				; if syscall error -> carry flag = 1
	ret

error:
	mov [rbx], rax			; set error number
	mov rax, -1				; set return to -1
	ret						; return