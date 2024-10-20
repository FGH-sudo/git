	.file	"demo.c"
	.text
	.section	.rodata
.LC1:
	.string	"%d%c"
.LC0:
	.string	" \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	<img src="https://latex.codecogs.com/gif.latex?48,%20%rsp	movq	%fs:40,%20%rax	movq	%rax,%20-8(%rbp)	xorl	%eax,%20%eax	movl"/>1, -32(%rbp)
	movl	<img src="https://latex.codecogs.com/gif.latex?2,%20-28(%rbp)	movl"/>3, -24(%rbp)
	movl	<img src="https://latex.codecogs.com/gif.latex?4,%20-20(%rbp)	movl"/>5, -16(%rbp)
	movl	<img src="https://latex.codecogs.com/gif.latex?5,%20-36(%rbp)	movl"/>0, -40(%rbp)
	jmp	.L2
.L3:
	movl	-36(%rbp), %eax
	subl	<img src="https://latex.codecogs.com/gif.latex?1,%20%eax	cmpl	%eax,%20-40(%rbp)	sete	%al	movzbl	%al,%20%eax	cltq	leaq	.LC0(%rip),%20%rdx	movzbl	(%rax,%rdx),%20%eax	movsbl	%al,%20%edx	movl	-40(%rbp),%20%eax	cltq	movl	-32(%rbp,%rax,4),%20%eax	movl	%eax,%20%esi	leaq	.LC1(%rip),%20%rax	movq	%rax,%20%rdi	movl"/>0, %eax
	call	printf@PLT
	addl	<img src="https://latex.codecogs.com/gif.latex?1,%20-40(%rbp).L2:	movl	-40(%rbp),%20%eax	cmpl	-36(%rbp),%20%eax	jl	.L3	movl"/>0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
  
  
  
  