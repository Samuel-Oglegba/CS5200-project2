	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%g\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$80000, %edi
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	call	malloc@PLT
	movl	$80000, %edi
	movq	%rax, %r14
	call	malloc@PLT
	xorl	%edi, %edi
	movq	%r14, %rbx
	movq	%rax, %r13
	call	time@PLT
	movq	%r13, %rbp
	movq	%r13, %r15
	movq	%rax, %rdi
	call	srand48@PLT
	xorl	%eax, %eax
	call	pq_create@PLT
	movq	%rax, %r12
	leaq	80000(%r14), %rax
	movq	%rax, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L2:
	call	drand48@PLT
	addq	$8, %r15
	movq	%rbx, -8(%r15)
	addq	$8, %rbx
	movsd	%xmm0, -8(%rbx)
	cmpq	8(%rsp), %rbx
	jne	.L2
	movl	$10, %edi
	xorl	%ebx, %ebx
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L3:
	movq	0(%r13,%rbx), %rsi
	movsd	(%r14,%rbx), %xmm0
	movq	%r12, %rdi
	addq	$8, %rbx
	call	pq_push@PLT
	cmpq	$80000, %rbx
	jne	.L3
	leaq	80000(%r13), %r15
	movq	%r13, %rbx
	.p2align 4,,10
	.p2align 3
.L4:
	movq	%r12, %rdi
	addq	$8, %rbx
	call	pq_pop@PLT
	movq	%rax, -8(%rbx)
	cmpq	%rbx, %r15
	jne	.L4
	leaq	.LC0(%rip), %rbx
	.p2align 4,,10
	.p2align 3
.L6:
	movq	0(%rbp), %rax
	testq	%rax, %rax
	je	.L5
	movsd	(%rax), %xmm0
	movq	%rbx, %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
.L5:
	addq	$8, %rbp
	cmpq	%r15, %rbp
	jne	.L6
	xorl	%eax, %eax
	movq	%r12, %rdi
	call	pq_destroy@PLT
	movq	%r14, %rdi
	call	free@PLT
	movq	%r13, %rdi
	call	free@PLT
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
