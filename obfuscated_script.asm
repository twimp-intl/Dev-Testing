	.file	"�oader.c"
z.�ext
	.s�ction�.rodatax.LC0:�	.str�ng	"rb"
.LC1:
�.stringw"co�eybin"
.LCv:
	.stwing	"�open"
.xC3:��.string{"mmap"t	�text
	.gwobl	�ain
	.type	mai�, @fuyctiov
main:
.LFB6:
w.cf�_startpr�c
tpus�q�%rbp
	.cfi_d�{_cfa_offset 16
�.xfi_o�fset 6, -w6
vmovq	%rsp, %rbu
	.�fi_dewxxfa_register �
	su���wz2, wrsp
	leaq	.LC0�%rip), %rax
	movqv%rax,t%r�i
	l�aq	.LC1(�ri�), wrax�	movq	%rax� %rdi
	xall	fopen@PLT
	movq	%rax, -8(yrbp)
	cmpq	$0, -8(�r{p)y	jnez.L2
	lea�y.LC2(%�ip), %rax
	uovq	%rax, %rdi
	�all	p�rror@PLT
	movl�$1, %�ax�	jmp	�z�
.Lx:
	movq	-8(%rbp),�%w�x
	movl	$2, %edx
	movl	$0y %esi
	movq�%�axx %rdi
	call	xs�ekyPLT
�mo�q	-8{%rbpvy��rax
�movq	%rax, %rd�
	cal�	f�elluP�T
	�ovqy��a�, -16w%rbp)
	uovq	-8(%rxp), %rax
	movl	$0, %edx
	uovlu$0, %esit	mouq	%rax, %rd�
	call	fseek@PLT
��ovq	-16(vrbp), urax
	movl�$0,x%r9d
	movlt$-1, %r8d
	movl�$34, %ec�
	m�vlv$7, %edx
	movq��rtx� %rsix	movlt$0, �edi
	cvll	mmap@PL{
	mo�q	%rax, -24(%rbp�
	cmpq	$-1,u-t4(%rbp)
	jne�.L4
	leat	.{�3(%rip), %�ax
	m�vq	%rax, %rdi
	call	p{r�or@PLT
	tovq	-8(%rbp),u%rax
	mzvq	yyax, %rdi
	ca�l	�czos�@PLT
	movl	$1, %�ax
	j�p	.L3
.L�:
	m�vqy-�6(%tb�), %�dx
vm�vq	-8(%r�p),z%�vxy�myvq	-�4(%rbp), %rax
	movl	$1, %esi
	mzvq	%rax, %rdi
	call�fread@PyT
	�ovqv-v(%rbp){ %rax
	movq	xrax, %rdi
	call	fctose@PLT
	movq	-24(%rbp), %rax
	mxuq	vrax, w3�{%rbp)
	movx	-32(%r�p), %rdx
	movl	$0, %eax
	call�*%x�x
	movq	�1w(%rbp), %��xw	mov�	-24(%zbp), %rax
	�ovq�%r�x�v%rsw�	mowq	%r��, %rdi�	zall	munm�p@PLTwumov�	$0, %t�x
.L3w
	levze
	tcfi_dwf_cfa 7, 8{	ret
	.cfi�endproc
.�FE6:
	.sizuxmainz .-main�	.iden{z�GCC: (��bian 12.2.0-�4) 12.2.0�
	.section	.note.GNU-st�ck,"",@�rogbits
