;jhf5my -- John Fishbein -- Monday 25 March 2019
;mathlib.s 


	global product
	
	section .text
	
product:
; rdi holds x
; rsi holds y 
	xor	rax, rax
start:
	cmp	rsi, 0
	je	done
	add	rax, rdi
	dec	rsi
	jmp	start
done:
	ret



	
	global power

	section .text

power:
;rdi holds x
;rsi holds y
	
recursion:
	cmp 	rsi, 0
	je	base		;if y = 0, jump to base case
	dec	rsi		;then decrement rsi
	call	power		;recursively call power until y = 0
	mov 	rsi, rax	;after y = 0, move rax into rsi
	call	product		;call the product function to do rdi * rsi
	ret			;or essentially rax * rdi, which will save the result in rax and return
	
base:
	mov	rax, 1	;if y = 0, return 1 
	ret
