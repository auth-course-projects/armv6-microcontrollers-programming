	AREA isPalindromeAsm, CODE, READONLY
		ENTRY
		EXPORT __main
			
__main
	PUSH {r0, r1, r2, r3, r4}
	
	// r2 <-- &string[left]
	// r3 <-- string[left]
	// r0 <-- &string[right]
	// r4 <-- string[right]
	MOV r2, r0
	
strlen_loop
	LDRB r3, [r0], #1	// r3 <-- (*string)++
	CMP r3, #0
	BNE strlen_loop

strlen_loop_end
	SUB r0, r0, #2		// right <-- strlen(string) - 1
	
checkedges_loop
	LDRB r3, [r2]
	LDRB r4, [r0]
	CMP r3, r4
	BNE return_result_false
	
	ADD r2, r2, #1
	SUB r0, r0, #1
	CMP r2, r0
	BPL return_result_true
	
	B checkedges_loop
	
	
return_result_false
	MOV r0, #0
	B return_result
	
return_result_true
	MOV r0, #1
	B return_result
	
return_result
	STRB r0, [r1]
	POP {r0, r1, r2, r3, r4}
	BX lr
