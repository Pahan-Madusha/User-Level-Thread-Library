.text
.global switch_main

switch_main:
	# address of the new sp is arg1
	# address of the current tcb is arg2
	# need to store all required registered for old tcb
	# restore all required registred from the new tcb
	# then when you return, you should get to the new thread 

	//mov %rdi, %rsp
	push %rsi
	//mov %rsi, (%rsp)	

	ret 
