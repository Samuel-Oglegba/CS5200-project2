	.file	"pq-minheap.c"
	.text
	.p2align 4
	.globl	pq_create
	.type	pq_create, @function
pq_create:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movl	$16, %edi
	call	malloc@PLT
	movl	$80000, %edi
	movq	%rax, %r12
	call	malloc@PLT
	movq	%rax, (%r12)
	movabsq	$42949672960000, %rax
	movq	%rax, 8(%r12)
	movq	%r12, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	pq_create, .-pq_create
	.p2align 4
	.globl	create_new_data
	.type	create_new_data, @function
create_new_data:
.LFB40:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movl	$16, %edi
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movsd	%xmm0, 8(%rsp)
	call	malloc@PLT
	movsd	8(%rsp), %xmm0
	movq	%rbx, (%rax)
	movsd	%xmm0, 8(%rax)
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	create_new_data, .-create_new_data
	.p2align 4
	.globl	parent
	.type	parent, @function
parent:
.LFB41:
	.cfi_startproc
	endbr64
	subl	$1, %edi
	movl	%edi, %eax
	shrl	$31, %eax
	addl	%edi, %eax
	sarl	%eax
	ret
	.cfi_endproc
.LFE41:
	.size	parent, .-parent
	.p2align 4
	.globl	left_child
	.type	left_child, @function
left_child:
.LFB42:
	.cfi_startproc
	endbr64
	leal	1(%rdi,%rdi), %eax
	ret
	.cfi_endproc
.LFE42:
	.size	left_child, .-left_child
	.p2align 4
	.globl	right_child
	.type	right_child, @function
right_child:
.LFB43:
	.cfi_startproc
	endbr64
	leal	2(%rdi,%rdi), %eax
	ret
	.cfi_endproc
.LFE43:
	.size	right_child, .-right_child
	.p2align 4
	.globl	get_min
	.type	get_min, @function
get_min:
.LFB44:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movq	(%rax), %rax
	movsd	8(%rax), %xmm0
	ret
	.cfi_endproc
.LFE44:
	.size	get_min, .-get_min
	.p2align 4
	.globl	sortHeap
	.type	sortHeap, @function
sortHeap:
.LFB45:
	.cfi_startproc
	endbr64
	movl	8(%rdi), %r11d
	movq	%rdi, %rax
	cmpl	%r11d, %esi
	jge	.L27
	leal	(%rsi,%rsi), %ecx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	leal	1(%rcx), %edx
	addl	$2, %ecx
	cmpl	%r11d, %edx
	jge	.L12
	.p2align 4,,10
	.p2align 3
.L29:
	movq	(%rax), %r10
	movslq	%edx, %r8
	movslq	%esi, %rdi
	movq	(%r10,%r8,8), %r9
	movq	(%r10,%rdi,8), %rbx
	movsd	8(%rbx), %xmm0
	comisd	8(%r9), %xmm0
	jbe	.L12
	cmpl	%r11d, %ecx
	jl	.L18
	cmpl	%esi, %edx
	je	.L24
	leaq	(%r10,%r8,8), %rsi
	leaq	(%r10,%rdi,8), %rcx
	movq	(%rsi), %r8
	movq	(%rcx), %rdi
	movq	%rdi, (%rsi)
	movq	%r8, (%rcx)
.L19:
	movl	%edx, %esi
	leal	(%rsi,%rsi), %ecx
	leal	1(%rcx), %edx
	addl	$2, %ecx
	cmpl	%r11d, %edx
	jl	.L29
.L12:
	cmpl	%r11d, %ecx
	jge	.L24
	movq	(%rax), %r10
	movl	%esi, %edx
	movslq	%esi, %r8
.L18:
	movslq	%ecx, %rdi
	movq	(%r10,%r8,8), %r8
	movq	(%r10,%rdi,8), %rdi
	movsd	8(%r8), %xmm0
	ucomisd	8(%rdi), %xmm0
	cmova	%ecx, %edx
	cmpl	%esi, %edx
	je	.L24
	movslq	%edx, %rcx
	movslq	%esi, %rsi
	leaq	(%r10,%rcx,8), %r8
	leaq	(%r10,%rsi,8), %rcx
	movq	(%r8), %r9
	movq	(%rcx), %rsi
	movq	%rsi, (%r8)
	movq	%r9, (%rcx)
	cmpl	%r11d, %edx
	jl	.L19
.L24:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L27:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE45:
	.size	sortHeap, .-sortHeap
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Min Heap:"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Parent: %g, -> left: %g, -> right: %g \n"
	.text
	.p2align 4
	.globl	print_heap
	.type	print_heap, @function
print_heap:
.LFB46:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdi, %r12
	leaq	.LC1(%rip), %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	call	puts@PLT
	movl	8(%r12), %r15d
	testl	%r15d, %r15d
	jle	.L35
	leal	1(%r15,%r15), %r14d
	xorl	%ebp, %ebp
	movl	$1, %ebx
	xorl	%r13d, %r13d
	.p2align 4,,10
	.p2align 3
.L34:
	movq	(%r12), %rax
	pxor	%xmm1, %xmm1
	cmpl	%ebx, %r15d
	jle	.L32
	movq	8(%rax,%rbp,2), %rdx
	movsd	8(%rdx), %xmm1
.L32:
	leal	1(%rbx), %edx
	movq	%r13, %xmm2
	cmpl	%edx, %r15d
	jle	.L33
	movq	16(%rax,%rbp,2), %rdx
	movsd	8(%rdx), %xmm2
.L33:
	movq	(%rax,%rbp), %rax
	movl	$1, %edi
	addl	$2, %ebx
	addq	$8, %rbp
	leaq	.LC2(%rip), %rsi
	movsd	8(%rax), %xmm0
	movl	$3, %eax
	call	__printf_chk@PLT
	cmpl	%ebx, %r14d
	jne	.L34
.L35:
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$10, %edi
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
	jmp	putchar@PLT
	.cfi_endproc
.LFE46:
	.size	print_heap, .-print_heap
	.p2align 4
	.globl	pq_push
	.type	pq_push, @function
pq_push:
.LFB47:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movl	8(%rdi), %ebx
	movsd	%xmm0, 8(%rsp)
	cmpl	%ebx, 12(%rdi)
	jle	.L40
	leal	1(%rbx), %r13d
	movq	(%rdi), %rbp
	movq	%rsi, %r12
	movl	%r13d, 8(%rdi)
	movl	$16, %edi
	movslq	%r13d, %r13
	call	malloc@PLT
	movsd	8(%rsp), %xmm0
	movq	%r12, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	%rax, -8(%rbp,%r13,8)
	testl	%ebx, %ebx
	jg	.L42
	jmp	.L40
	.p2align 4,,10
	.p2align 3
.L44:
	movq	%rax, (%rsi)
	movq	%rdx, (%rcx)
	testl	%ebx, %ebx
	je	.L40
.L42:
	movslq	%ebx, %rax
	leal	-1(%rax), %ebx
	leaq	0(%rbp,%rax,8), %rcx
	sarl	%ebx
	movq	(%rcx), %rax
	movslq	%ebx, %rdx
	leaq	0(%rbp,%rdx,8), %rsi
	movq	(%rsi), %rdx
	movsd	8(%rdx), %xmm0
	comisd	8(%rax), %xmm0
	ja	.L44
.L40:
	addq	$24, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE47:
	.size	pq_push, .-pq_push
	.p2align 4
	.globl	pq_pop
	.type	pq_pop, @function
pq_pop:
.LFB48:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	testq	%rdi, %rdi
	je	.L59
	movl	8(%rdi), %edx
	testl	%edx, %edx
	jne	.L62
.L59:
	ret
	.p2align 4,,10
	.p2align 3
.L62:
	movq	(%rdi), %rcx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rcx), %rsi
	movq	(%rsi), %rbx
	movslq	%edx, %rsi
	subl	$1, %edx
	movq	-8(%rcx,%rsi,8), %rsi
	movq	%rsi, (%rcx)
	xorl	%esi, %esi
	movl	%edx, 8(%rdi)
	call	sortHeap
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE48:
	.size	pq_pop, .-pq_pop
	.p2align 4
	.globl	pq_destroy
	.type	pq_destroy, @function
pq_destroy:
.LFB49:
	.cfi_startproc
	endbr64
	jmp	free@PLT
	.cfi_endproc
.LFE49:
	.size	pq_destroy, .-pq_destroy
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
