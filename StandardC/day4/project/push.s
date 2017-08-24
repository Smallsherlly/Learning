	.file	"push.c"
	.section	.rodata
.LC0:
	.string	"tcgetattr"
.LC1:
	.string	"tcsetattr"
	.text
	.type	get_direction, @function
get_direction:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$168, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -136(%ebp)
	leal	-132(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	tcgetattr
	movl	%eax, -136(%ebp)
	cmpl	$0, -136(%ebp)
	jns	.L2
	movl	$.LC0, (%esp)
	call	perror
	movl	$-1, %eax
	jmp	.L3
.L2:
	movl	-132(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-128(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-124(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-120(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-116(%ebp), %eax
	movl	%eax, -56(%ebp)
	movl	-112(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-108(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-104(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-100(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-96(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-92(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	-88(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-60(%ebp), %eax
	andl	$-11, %eax
	movl	%eax, -60(%ebp)
	leal	-72(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	tcsetattr
	movl	%eax, -136(%ebp)
	cmpl	$0, -136(%ebp)
	jns	.L4
	movl	$.LC1, (%esp)
	call	perror
	movl	$-2, %eax
	jmp	.L3
.L4:
	movl	$0, -140(%ebp)
.L5:
	call	getchar
	addl	%eax, -140(%ebp)
	movl	stdin, %eax
	movl	8(%eax), %edx
	movl	stdin, %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	.L5
	leal	-132(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	tcsetattr
	movl	%eax, -136(%ebp)
	cmpl	$0, -136(%ebp)
	jns	.L6
	movl	$.LC1, (%esp)
	call	perror
	movl	$-3, %eax
	jmp	.L3
.L6:
	movl	-140(%ebp), %eax
.L3:
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	get_direction, .-get_direction
	.section	.rodata
	.align 4
.LC2:
	.string	"\346\216\250\347\256\261\345\255\220\345\260\217\346\270\270\346\210\217\n      \344\275\234\350\200\205\357\274\232\346\236\227\344\271\246\346\200\235"
.LC3:
	.string	"\033[%d;%dH"
	.text
	.globl	map
	.type	map, @function
map:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, -16(%ebp)
	jmp	.L9
.L19:
	movl	$0, -12(%ebp)
	jmp	.L10
.L18:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	jne	.L11
	movl	$32, (%esp)
	call	putchar
	jmp	.L12
.L11:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$1, %eax
	jne	.L13
	movl	$35, (%esp)
	call	putchar
	jmp	.L12
.L13:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$2, %eax
	je	.L14
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L15
.L14:
	movl	$64, (%esp)
	call	putchar
	jmp	.L12
.L15:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L16
	movl	$79, (%esp)
	call	putchar
	jmp	.L12
.L16:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$4, %eax
	je	.L17
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L12
.L17:
	movl	$36, (%esp)
	call	putchar
.L12:
	addl	$1, -12(%ebp)
.L10:
	cmpl	$7, -12(%ebp)
	jle	.L18
	movl	$10, (%esp)
	call	putchar
	addl	$1, -16(%ebp)
.L9:
	cmpl	$6, -16(%ebp)
	jle	.L19
	movl	iY, %eax
	leal	1(%eax), %ecx
	movl	iX, %eax
	leal	3(%eax), %edx
	movl	$.LC3, %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	map, .-map
	.globl	move
	.type	move, @function
move:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	get_direction
	cmpl	$184, %eax
	je	.L24
	cmpl	$184, %eax
	jg	.L27
	cmpl	$10, %eax
	je	.L22
	cmpl	$183, %eax
	je	.L23
	jmp	.L108
.L27:
	cmpl	$185, %eax
	je	.L25
	cmpl	$186, %eax
	je	.L26
	jmp	.L108
.L23:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	jne	.L28
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L29
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L30
.L29:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L30:
	movl	iX, %eax
	subl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L110
.L28:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$1, %eax
	je	.L109
.L32:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$2, %eax
	jne	.L33
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L34
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L110
.L34:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L35
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L36
.L35:
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$2, (%eax,%edx,4)
.L36:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L37
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L38
.L37:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L38:
	movl	iX, %eax
	subl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L110
.L33:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L39
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L40
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L41
.L40:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L41:
	movl	iX, %eax
	subl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L110
.L39:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L110
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L42
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L110
.L42:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L43
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L44
.L43:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L44:
	movl	iX, %eax
	subl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L45
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L46
.L45:
	movl	iX, %eax
	subl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$2, (%eax,%edx,4)
.L46:
	movl	iX, %eax
	subl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L110
.L24:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	jne	.L47
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L48
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L49
.L48:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L49:
	movl	iX, %eax
	addl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L112
.L47:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$1, %eax
	je	.L111
.L51:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$2, %eax
	jne	.L52
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L53
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L112
.L53:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L54
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L55
.L54:
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$2, (%eax,%edx,4)
.L55:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L56
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L57
.L56:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L57:
	movl	iX, %eax
	addl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L112
.L52:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L58
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L59
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L60
.L59:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L60:
	movl	iX, %eax
	addl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L112
.L58:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L112
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L61
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L112
.L61:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L62
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L63
.L62:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L63:
	movl	iX, %eax
	addl	$1, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L64
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L65
.L64:
	movl	iX, %eax
	addl	$2, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$2, (%eax,%edx,4)
.L65:
	movl	iX, %eax
	addl	$1, %eax
	movl	%eax, iX
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L112
.L26:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	jne	.L66
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L67
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L68
.L67:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L68:
	movl	iY, %eax
	subl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L114
.L66:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$1, %eax
	je	.L113
.L70:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$2, %eax
	jne	.L71
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L72
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L114
.L72:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L73
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L74
.L73:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	$2, (%eax,%edx,4)
.L74:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L75
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L76
.L75:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L76:
	movl	iY, %eax
	subl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L114
.L71:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L77
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L78
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L79
.L78:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L79:
	movl	iY, %eax
	subl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L114
.L77:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L114
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L80
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L114
.L80:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L81
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L82
.L81:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L82:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$1, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L83
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L84
.L83:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	subl	$2, %edx
	movl	$2, (%eax,%edx,4)
.L84:
	movl	iY, %eax
	subl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L114
.L25:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	jne	.L85
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L86
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L87
.L86:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L87:
	movl	iY, %eax
	addl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L116
.L85:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$1, %eax
	je	.L115
.L89:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$2, %eax
	jne	.L90
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L91
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L116
.L91:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	$4, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L92
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L93
.L92:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	$2, (%eax,%edx,4)
.L93:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L94
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L95
.L94:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L95:
	movl	iY, %eax
	addl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L116
.L90:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L96
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L97
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L98
.L97:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L98:
	movl	iY, %eax
	addl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L116
.L96:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$1, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L116
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	.L99
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L116
.L99:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$7, %eax
	jne	.L100
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$3, (%eax,%edx,4)
	jmp	.L101
.L100:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	movl	$0, (%eax,%edx,4)
.L101:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	$7, (%eax,%edx,4)
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$3, %eax
	jne	.L102
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	$5, (%eax,%edx,4)
	jmp	.L103
.L102:
	movl	iX, %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	iY, %edx
	addl	$2, %edx
	movl	$2, (%eax,%edx,4)
.L103:
	movl	iY, %eax
	addl	$1, %eax
	movl	%eax, iY
	movl	step, %eax
	addl	$1, %eax
	movl	%eax, step
	jmp	.L116
.L22:
	movl	$0, -16(%ebp)
	jmp	.L104
.L107:
	movl	$0, -12(%ebp)
	jmp	.L105
.L106:
	movl	-16(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-16(%ebp), %edx
	sall	$5, %edx
	addl	12(%ebp), %edx
	movl	-12(%ebp), %ecx
	movl	(%edx,%ecx,4), %ecx
	movl	-12(%ebp), %edx
	movl	%ecx, (%eax,%edx,4)
	addl	$1, -12(%ebp)
.L105:
	cmpl	$7, -12(%ebp)
	jle	.L106
	movl	$0, step
	addl	$1, -16(%ebp)
.L104:
	cmpl	$6, -16(%ebp)
	jle	.L107
	movl	$5, iX
	movl	$3, iY
	nop
	jmp	.L108
.L109:
	nop
	jmp	.L108
.L110:
	nop
	jmp	.L108
.L111:
	nop
	jmp	.L108
.L112:
	nop
	jmp	.L108
.L113:
	nop
	jmp	.L108
.L114:
	nop
	jmp	.L108
.L115:
	nop
	jmp	.L108
.L116:
	nop
.L108:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	move, .-move
	.globl	judge
	.type	judge, @function
judge:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -12(%ebp)
	movl	$0, -8(%ebp)
	jmp	.L118
.L122:
	movl	$0, -4(%ebp)
	jmp	.L119
.L121:
	movl	-8(%ebp), %eax
	sall	$5, %eax
	addl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	$5, %eax
	jne	.L120
	addl	$1, -12(%ebp)
.L120:
	addl	$1, -4(%ebp)
.L119:
	cmpl	$7, -4(%ebp)
	jle	.L121
	addl	$1, -8(%ebp)
.L118:
	cmpl	$6, -8(%ebp)
	jle	.L122
	cmpl	$3, -12(%ebp)
	jne	.L123
	movl	$0, %eax
	jmp	.L124
.L123:
	movl	$-1, %eax
.L124:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	judge, .-judge
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
