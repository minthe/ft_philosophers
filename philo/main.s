	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_myTurn                 ## -- Begin function myTurn
	.p2align	4, 0x90
_myTurn:                                ## @myTurn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movl	$2, (%rax)
	movl	$1, %edi
	callq	_sleep
	leaq	L_.str(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	jmp	LBB0_1
	.cfi_endproc
                                        ## -- End function
	.globl	_yourTurn               ## -- Begin function yourTurn
	.p2align	4, 0x90
_yourTurn:                              ## @yourTurn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movl	$1, (%rax)
	movl	$1, %edi
	callq	_sleep
	leaq	L_.str.1(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	jmp	LBB1_1
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_myTurn(%rip), %rdx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, -40(%rbp)
	leaq	-40(%rbp), %rsi
	leaq	-24(%rbp), %rdi
	movq	%rsi, -48(%rbp)         ## 8-byte Spill
	movq	%rcx, %rsi
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB2_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB2_9
LBB2_2:
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	_yourTurn(%rip), %rcx
	leaq	-40(%rbp), %rdx
	leaq	-32(%rbp), %rdi
	movq	%rdx, -56(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB2_4
## %bb.3:
	movl	$2, -4(%rbp)
	jmp	LBB2_9
LBB2_4:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB2_6
## %bb.5:
	movl	$3, -4(%rbp)
	jmp	LBB2_9
LBB2_6:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-32(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB2_8
## %bb.7:
	movl	$4, -4(%rbp)
	jmp	LBB2_9
LBB2_8:
	movl	$0, -4(%rbp)
LBB2_9:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"My Turn!\n"

L_.str.1:                               ## @.str.1
	.asciz	"Your Turn!\n"

.subsections_via_symbols
