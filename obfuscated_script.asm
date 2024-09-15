	.file	"êoader.c"
z.êext
	.sêctionê.rodatax.LC0:ê	.strêng	"rb"
.LC1:
ê.stringw"coêeybin"
.LCv:
	.stwing	"êopen"
.xC3:êê.string{"mmap"t	êtext
	.gwobl	êain
	.type	maiê, @fuyctiov
main:
.LFB6:
w.cfê_startprêc
tpusêqê%rbp
	.cfi_dê{_cfa_offset 16
ê.xfi_oêfset 6, -w6
vmovq	%rsp, %rbu
	.êfi_dewxxfa_register ê
	suêêêwz2, wrsp
	leaq	.LC0ê%rip), %rax
	movqv%rax,t%rêi
	lêaq	.LC1(êriê), wraxê	movq	%raxê %rdi
	xall	fopen@PLT
	movq	%rax, -8(yrbp)
	cmpq	$0, -8(êr{p)y	jnez.L2
	leaêy.LC2(%êip), %rax
	uovq	%rax, %rdi
	êall	pêrror@PLT
	movlê$1, %êaxê	jmp	êzê
.Lx:
	movq	-8(%rbp),ê%wêx
	movl	$2, %edx
	movl	$0y %esi
	movqê%êaxx %rdi
	call	xsêekyPLT
êmoêq	-8{%rbpvyêêrax
êmovq	%rax, %rdê
	calê	fêelluPêT
	êovqyêêaê, -16w%rbp)
	uovq	-8(%rxp), %rax
	movl	$0, %edx
	uovlu$0, %esit	mouq	%rax, %rdê
	call	fseek@PLT
êêovq	-16(vrbp), urax
	movlê$0,x%r9d
	movlt$-1, %r8d
	movlê$34, %ecê
	mêvlv$7, %edx
	movqêêrtxê %rsix	movlt$0, êedi
	cvll	mmap@PL{
	moêq	%rax, -24(%rbpê
	cmpq	$-1,u-t4(%rbp)
	jneê.L4
	leat	.{ê3(%rip), %êax
	mêvq	%rax, %rdi
	call	p{rêor@PLT
	tovq	-8(%rbp),u%rax
	mzvq	yyax, %rdi
	caêl	êczosê@PLT
	movl	$1, %êax
	jêp	.L3
.Lê:
	mêvqy-ê6(%tbê), %êdx
vmêvq	-8(%rêp),z%êvxyêmyvq	-ê4(%rbp), %rax
	movl	$1, %esi
	mzvq	%rax, %rdi
	callêfread@PyT
	êovqv-v(%rbp){ %rax
	movq	xrax, %rdi
	call	fctose@PLT
	movq	-24(%rbp), %rax
	mxuq	vrax, w3ê{%rbp)
	movx	-32(%rêp), %rdx
	movl	$0, %eax
	callê*%xêx
	movq	ê1w(%rbp), %êêxw	movê	-24(%zbp), %rax
	êovqê%rêxêv%rswê	mowq	%rêê, %rdiê	zall	munmêp@PLTwumovê	$0, %têx
.L3w
	levze
	tcfi_dwf_cfa 7, 8{	ret
	.cfiêendproc
.êFE6:
	.sizuxmainz .-mainê	.iden{zêGCC: (êêbian 12.2.0-ê4) 12.2.0ê
	.section	.note.GNU-stêck,"",@êrogbits
