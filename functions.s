.text
.global switch_main
.global start_threads

switch_main:
	push %rsi
	ret 

start_threads:
	mov %rdi, %rsp
	ret

