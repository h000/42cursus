section	.text
   global _start     ;must be declared for linker (ld)
	
_start:
   mov	rax, 1		;sys_write
   mov	rdi, 1		;unsigned int fd
   mov	rsi, msg	;char *buf
   mov	rdx, 12		;size_t count
   syscall
	
   mov	rax, 60		;sys_exit
   mov	rdi, 0		;int error_code
   syscall

section	.data
msg db 'Hello, world!', 0x0a