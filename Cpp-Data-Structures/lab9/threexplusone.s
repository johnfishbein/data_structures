
	global collatz

	section .text

collatz:
	push 	rdi
	cmp	rdi, 1
	je	base

	mov	rdx, rdi
	and	rdx, 1
	cmp	rdx, 0
	jne	odd
	shr	rdi, 1
	call	collatz
	jmp	end

odd:	
	mov	r10, rdi
	shl	rdi, 2 		;x*4
	sub	rdi, r10
	add	rdi, 1
	call 	collatz
end:	
	add 	rax, 1
	jmp	done
	
base:
	mov	rax, 0
	
done:
	pop	rdi
	ret
