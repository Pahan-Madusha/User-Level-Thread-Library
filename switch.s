.text
.global machine_switch

machine_switch:
	# address of the new tcb is arg1
	# address of the current tcb is arg2
	# need to store all required registered for old tcb
	# restore all required registred from the new tcb
	# then when you return, you should get to the new thread 

	#backup registers
	push %rax
	push %rbx
	push %rbp
	push %r12
	push %r13
	push %r14
	push %r15
	
	movq %rsp, 0(%rsi) #update sp on old tcb
	movq 0(%rdi), %rsp #switch to new stack 

	#restore registers from new stack
	pop %r15
	pop %r14
	pop %r13
	pop %r12
	pop %rbp
	pop %rbx
	pop %rax
	
	movq %rsp, 0(%rdi) #update new sp in new tcb

	ret

