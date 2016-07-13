.text
.global machine_switch

machine_switch:
	# address of the new tcb is arg1
	# address of the current tcb is arg2
	# need to store all required registered for old tcb
	# restore all required registred from the new tcb
	# then when you return, you should get to the new thread 

	#backup registers
	movq %r15, 0(%rsp)
	movq %r14, -8(%rsp)
	movq %r13, -16(%rsp)
	movq %r12, -24(%rsp)
	movq %rbp, -32(%rsp)
	movq %rbx, -40(%rsp)
	movq %rax, -48(%rsp)
	
	movq %rsp, 0(%rsi) #update sp on old tcb
	movq 0(%rdi), %rsp #switch to new stack 

	#restore registers from new stack
	movq 0(%rsp), %r15
	movq -8(%rsp), %r14
	movq -16(%rsp), %r13
	movq -24(%rsp), %r12
	movq -32(%rsp), %rbp
	movq -40(%rsp), %rbx
	movq -48(%rsp), %rax
	
	movq %rsp, 0(%rdi) #update new sp in new tcb

	ret

