
../Phantom/core/core_system_polymorph_cpu_syscalls_jit.mod:     file format elf64-x86-64


Disassembly of section .init:

0000000000002000 <_init>:
    2000:	48 83 ec 08          	sub    $0x8,%rsp
    2004:	48 8b 05 c5 3f 00 00 	mov    0x3fc5(%rip),%rax        # 5fd0 <__gmon_start__@Base>
    200b:	48 85 c0             	test   %rax,%rax
    200e:	74 02                	je     2012 <_init+0x12>
    2010:	ff d0                	call   *%rax
    2012:	48 83 c4 08          	add    $0x8,%rsp
    2016:	c3                   	ret

Disassembly of section .plt:

0000000000002020 <putchar@plt-0x10>:
    2020:	ff 35 ca 3f 00 00    	push   0x3fca(%rip)        # 5ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    2026:	ff 25 cc 3f 00 00    	jmp    *0x3fcc(%rip)        # 5ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    202c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000002030 <putchar@plt>:
    2030:	ff 25 ca 3f 00 00    	jmp    *0x3fca(%rip)        # 6000 <putchar@GLIBC_2.2.5>
    2036:	68 00 00 00 00       	push   $0x0
    203b:	e9 e0 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002040 <puts@plt>:
    2040:	ff 25 c2 3f 00 00    	jmp    *0x3fc2(%rip)        # 6008 <puts@GLIBC_2.2.5>
    2046:	68 01 00 00 00       	push   $0x1
    204b:	e9 d0 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002050 <printf@plt>:
    2050:	ff 25 ba 3f 00 00    	jmp    *0x3fba(%rip)        # 6010 <printf@GLIBC_2.2.5>
    2056:	68 02 00 00 00       	push   $0x2
    205b:	e9 c0 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002060 <srand@plt>:
    2060:	ff 25 b2 3f 00 00    	jmp    *0x3fb2(%rip)        # 6018 <srand@GLIBC_2.2.5>
    2066:	68 03 00 00 00       	push   $0x3
    206b:	e9 b0 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002070 <time@plt>:
    2070:	ff 25 aa 3f 00 00    	jmp    *0x3faa(%rip)        # 6020 <time@GLIBC_2.2.5>
    2076:	68 04 00 00 00       	push   $0x4
    207b:	e9 a0 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002080 <sleep@plt>:
    2080:	ff 25 a2 3f 00 00    	jmp    *0x3fa2(%rip)        # 6028 <sleep@GLIBC_2.2.5>
    2086:	68 05 00 00 00       	push   $0x5
    208b:	e9 90 ff ff ff       	jmp    2020 <_init+0x20>

0000000000002090 <rand@plt>:
    2090:	ff 25 9a 3f 00 00    	jmp    *0x3f9a(%rip)        # 6030 <rand@GLIBC_2.2.5>
    2096:	68 06 00 00 00       	push   $0x6
    209b:	e9 80 ff ff ff       	jmp    2020 <_init+0x20>

Disassembly of section .plt.got:

00000000000020a0 <__cxa_finalize@plt>:
    20a0:	ff 25 3a 3f 00 00    	jmp    *0x3f3a(%rip)        # 5fe0 <__cxa_finalize@GLIBC_2.2.5>
    20a6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000020b0 <_start>:
    20b0:	31 ed                	xor    %ebp,%ebp
    20b2:	49 89 d1             	mov    %rdx,%r9
    20b5:	5e                   	pop    %rsi
    20b6:	48 89 e2             	mov    %rsp,%rdx
    20b9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    20bd:	50                   	push   %rax
    20be:	54                   	push   %rsp
    20bf:	45 31 c0             	xor    %r8d,%r8d
    20c2:	31 c9                	xor    %ecx,%ecx
    20c4:	48 8d 3d 3b 0d 00 00 	lea    0xd3b(%rip),%rdi        # 2e06 <main>
    20cb:	ff 15 ef 3e 00 00    	call   *0x3eef(%rip)        # 5fc0 <__libc_start_main@GLIBC_2.34>
    20d1:	f4                   	hlt
    20d2:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    20d9:	00 00 00 
    20dc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000020e0 <deregister_tm_clones>:
    20e0:	48 8d 3d 09 44 00 00 	lea    0x4409(%rip),%rdi        # 64f0 <__TMC_END__>
    20e7:	48 8d 05 02 44 00 00 	lea    0x4402(%rip),%rax        # 64f0 <__TMC_END__>
    20ee:	48 39 f8             	cmp    %rdi,%rax
    20f1:	74 15                	je     2108 <deregister_tm_clones+0x28>
    20f3:	48 8b 05 ce 3e 00 00 	mov    0x3ece(%rip),%rax        # 5fc8 <_ITM_deregisterTMCloneTable@Base>
    20fa:	48 85 c0             	test   %rax,%rax
    20fd:	74 09                	je     2108 <deregister_tm_clones+0x28>
    20ff:	ff e0                	jmp    *%rax
    2101:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    2108:	c3                   	ret
    2109:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000002110 <register_tm_clones>:
    2110:	48 8d 3d d9 43 00 00 	lea    0x43d9(%rip),%rdi        # 64f0 <__TMC_END__>
    2117:	48 8d 35 d2 43 00 00 	lea    0x43d2(%rip),%rsi        # 64f0 <__TMC_END__>
    211e:	48 29 fe             	sub    %rdi,%rsi
    2121:	48 89 f0             	mov    %rsi,%rax
    2124:	48 c1 ee 3f          	shr    $0x3f,%rsi
    2128:	48 c1 f8 03          	sar    $0x3,%rax
    212c:	48 01 c6             	add    %rax,%rsi
    212f:	48 d1 fe             	sar    %rsi
    2132:	74 14                	je     2148 <register_tm_clones+0x38>
    2134:	48 8b 05 9d 3e 00 00 	mov    0x3e9d(%rip),%rax        # 5fd8 <_ITM_registerTMCloneTable@Base>
    213b:	48 85 c0             	test   %rax,%rax
    213e:	74 08                	je     2148 <register_tm_clones+0x38>
    2140:	ff e0                	jmp    *%rax
    2142:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    2148:	c3                   	ret
    2149:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000002150 <__do_global_dtors_aux>:
    2150:	f3 0f 1e fa          	endbr64
    2154:	80 3d 95 43 00 00 00 	cmpb   $0x0,0x4395(%rip)        # 64f0 <__TMC_END__>
    215b:	75 2b                	jne    2188 <__do_global_dtors_aux+0x38>
    215d:	55                   	push   %rbp
    215e:	48 83 3d 7a 3e 00 00 	cmpq   $0x0,0x3e7a(%rip)        # 5fe0 <__cxa_finalize@GLIBC_2.2.5>
    2165:	00 
    2166:	48 89 e5             	mov    %rsp,%rbp
    2169:	74 0c                	je     2177 <__do_global_dtors_aux+0x27>
    216b:	48 8b 3d d6 3e 00 00 	mov    0x3ed6(%rip),%rdi        # 6048 <__dso_handle>
    2172:	e8 29 ff ff ff       	call   20a0 <__cxa_finalize@plt>
    2177:	e8 64 ff ff ff       	call   20e0 <deregister_tm_clones>
    217c:	c6 05 6d 43 00 00 01 	movb   $0x1,0x436d(%rip)        # 64f0 <__TMC_END__>
    2183:	5d                   	pop    %rbp
    2184:	c3                   	ret
    2185:	0f 1f 00             	nopl   (%rax)
    2188:	c3                   	ret
    2189:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000002190 <frame_dummy>:
    2190:	f3 0f 1e fa          	endbr64
    2194:	e9 77 ff ff ff       	jmp    2110 <register_tm_clones>

0000000000002199 <core_cpu_nop_random_nop>:
    2199:	55                   	push   %rbp
    219a:	48 89 e5             	mov    %rsp,%rbp
    219d:	48 83 ec 10          	sub    $0x10,%rsp
    21a1:	e8 ea fe ff ff       	call   2090 <rand@plt>
    21a6:	89 c2                	mov    %eax,%edx
    21a8:	48 63 c2             	movslq %edx,%rax
    21ab:	48 69 c0 67 66 66 66 	imul   $0x66666667,%rax,%rax
    21b2:	48 c1 e8 20          	shr    $0x20,%rax
    21b6:	d1 f8                	sar    %eax
    21b8:	89 d1                	mov    %edx,%ecx
    21ba:	c1 f9 1f             	sar    $0x1f,%ecx
    21bd:	29 c8                	sub    %ecx,%eax
    21bf:	89 45 fc             	mov    %eax,-0x4(%rbp)
    21c2:	8b 4d fc             	mov    -0x4(%rbp),%ecx
    21c5:	89 c8                	mov    %ecx,%eax
    21c7:	c1 e0 02             	shl    $0x2,%eax
    21ca:	01 c8                	add    %ecx,%eax
    21cc:	29 c2                	sub    %eax,%edx
    21ce:	89 55 fc             	mov    %edx,-0x4(%rbp)
    21d1:	8b 45 fc             	mov    -0x4(%rbp),%eax
    21d4:	89 c6                	mov    %eax,%esi
    21d6:	48 8d 05 2b 0e 00 00 	lea    0xe2b(%rip),%rax        # 3008 <_IO_stdin_used+0x8>
    21dd:	48 89 c7             	mov    %rax,%rdi
    21e0:	b8 00 00 00 00       	mov    $0x0,%eax
    21e5:	e8 66 fe ff ff       	call   2050 <printf@plt>
    21ea:	e8 a1 fe ff ff       	call   2090 <rand@plt>
    21ef:	48 63 d0             	movslq %eax,%rdx
    21f2:	48 69 d2 1f 85 eb 51 	imul   $0x51eb851f,%rdx,%rdx
    21f9:	48 c1 ea 20          	shr    $0x20,%rdx
    21fd:	c1 fa 05             	sar    $0x5,%edx
    2200:	89 c1                	mov    %eax,%ecx
    2202:	c1 f9 1f             	sar    $0x1f,%ecx
    2205:	29 ca                	sub    %ecx,%edx
    2207:	89 55 f4             	mov    %edx,-0xc(%rbp)
    220a:	8b 55 f4             	mov    -0xc(%rbp),%edx
    220d:	6b d2 64             	imul   $0x64,%edx,%edx
    2210:	29 d0                	sub    %edx,%eax
    2212:	89 45 f4             	mov    %eax,-0xc(%rbp)
    2215:	83 7d fc 02          	cmpl   $0x2,-0x4(%rbp)
    2219:	7e 38                	jle    2253 <core_cpu_nop_random_nop+0xba>
    221b:	83 7d f4 25          	cmpl   $0x25,-0xc(%rbp)
    221f:	7e 32                	jle    2253 <core_cpu_nop_random_nop+0xba>
    2221:	e8 6a fe ff ff       	call   2090 <rand@plt>
    2226:	89 c2                	mov    %eax,%edx
    2228:	89 d0                	mov    %edx,%eax
    222a:	c1 f8 1f             	sar    $0x1f,%eax
    222d:	c1 e8 1e             	shr    $0x1e,%eax
    2230:	01 c2                	add    %eax,%edx
    2232:	83 e2 03             	and    $0x3,%edx
    2235:	29 c2                	sub    %eax,%edx
    2237:	89 55 fc             	mov    %edx,-0x4(%rbp)
    223a:	8b 45 fc             	mov    -0x4(%rbp),%eax
    223d:	89 c6                	mov    %eax,%esi
    223f:	48 8d 05 e2 0d 00 00 	lea    0xde2(%rip),%rax        # 3028 <_IO_stdin_used+0x28>
    2246:	48 89 c7             	mov    %rax,%rdi
    2249:	b8 00 00 00 00       	mov    $0x0,%eax
    224e:	e8 fd fd ff ff       	call   2050 <printf@plt>
    2253:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
    2257:	75 11                	jne    226a <core_cpu_nop_random_nop+0xd1>
    2259:	48 8d 05 eb 0d 00 00 	lea    0xdeb(%rip),%rax        # 304b <_IO_stdin_used+0x4b>
    2260:	48 89 c7             	mov    %rax,%rdi
    2263:	e8 d8 fd ff ff       	call   2040 <puts@plt>
    2268:	eb 3c                	jmp    22a6 <core_cpu_nop_random_nop+0x10d>
    226a:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
    2271:	eb 21                	jmp    2294 <core_cpu_nop_random_nop+0xfb>
    2273:	90                   	nop
    2274:	8b 45 f8             	mov    -0x8(%rbp),%eax
    2277:	83 c0 01             	add    $0x1,%eax
    227a:	89 c6                	mov    %eax,%esi
    227c:	48 8d 05 cd 0d 00 00 	lea    0xdcd(%rip),%rax        # 3050 <_IO_stdin_used+0x50>
    2283:	48 89 c7             	mov    %rax,%rdi
    2286:	b8 00 00 00 00       	mov    $0x0,%eax
    228b:	e8 c0 fd ff ff       	call   2050 <printf@plt>
    2290:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
    2294:	8b 45 f8             	mov    -0x8(%rbp),%eax
    2297:	3b 45 fc             	cmp    -0x4(%rbp),%eax
    229a:	7c d7                	jl     2273 <core_cpu_nop_random_nop+0xda>
    229c:	bf 0a 00 00 00       	mov    $0xa,%edi
    22a1:	e8 8a fd ff ff       	call   2030 <putchar@plt>
    22a6:	c9                   	leave
    22a7:	c3                   	ret

00000000000022a8 <core_cpu_nop_add_zero_ah>:
    22a8:	55                   	push   %rbp
    22a9:	48 89 e5             	mov    %rsp,%rbp
    22ac:	80 c4 00             	add    $0x0,%ah
    22af:	48 8d 05 9e 0d 00 00 	lea    0xd9e(%rip),%rax        # 3054 <_IO_stdin_used+0x54>
    22b6:	48 89 c7             	mov    %rax,%rdi
    22b9:	e8 82 fd ff ff       	call   2040 <puts@plt>
    22be:	90                   	nop
    22bf:	5d                   	pop    %rbp
    22c0:	c3                   	ret

00000000000022c1 <core_cpu_nop_add_zero_al>:
    22c1:	55                   	push   %rbp
    22c2:	48 89 e5             	mov    %rsp,%rbp
    22c5:	04 00                	add    $0x0,%al
    22c7:	48 8d 05 8f 0d 00 00 	lea    0xd8f(%rip),%rax        # 305d <_IO_stdin_used+0x5d>
    22ce:	48 89 c7             	mov    %rax,%rdi
    22d1:	e8 6a fd ff ff       	call   2040 <puts@plt>
    22d6:	90                   	nop
    22d7:	5d                   	pop    %rbp
    22d8:	c3                   	ret

00000000000022d9 <core_cpu_nop_add_zero_ax>:
    22d9:	55                   	push   %rbp
    22da:	48 89 e5             	mov    %rsp,%rbp
    22dd:	66 83 c0 00          	add    $0x0,%ax
    22e1:	48 8d 05 7e 0d 00 00 	lea    0xd7e(%rip),%rax        # 3066 <_IO_stdin_used+0x66>
    22e8:	48 89 c7             	mov    %rax,%rdi
    22eb:	e8 50 fd ff ff       	call   2040 <puts@plt>
    22f0:	90                   	nop
    22f1:	5d                   	pop    %rbp
    22f2:	c3                   	ret

00000000000022f3 <core_cpu_nop_add_zero_bh>:
    22f3:	55                   	push   %rbp
    22f4:	48 89 e5             	mov    %rsp,%rbp
    22f7:	80 c7 00             	add    $0x0,%bh
    22fa:	48 8d 05 6e 0d 00 00 	lea    0xd6e(%rip),%rax        # 306f <_IO_stdin_used+0x6f>
    2301:	48 89 c7             	mov    %rax,%rdi
    2304:	e8 37 fd ff ff       	call   2040 <puts@plt>
    2309:	90                   	nop
    230a:	5d                   	pop    %rbp
    230b:	c3                   	ret

000000000000230c <core_cpu_nop_add_zero_bl>:
    230c:	55                   	push   %rbp
    230d:	48 89 e5             	mov    %rsp,%rbp
    2310:	80 c3 00             	add    $0x0,%bl
    2313:	48 8d 05 5e 0d 00 00 	lea    0xd5e(%rip),%rax        # 3078 <_IO_stdin_used+0x78>
    231a:	48 89 c7             	mov    %rax,%rdi
    231d:	e8 1e fd ff ff       	call   2040 <puts@plt>
    2322:	90                   	nop
    2323:	5d                   	pop    %rbp
    2324:	c3                   	ret

0000000000002325 <core_cpu_nop_add_zero_bp>:
    2325:	55                   	push   %rbp
    2326:	48 89 e5             	mov    %rsp,%rbp
    2329:	66 83 c5 00          	add    $0x0,%bp
    232d:	48 8d 05 4d 0d 00 00 	lea    0xd4d(%rip),%rax        # 3081 <_IO_stdin_used+0x81>
    2334:	48 89 c7             	mov    %rax,%rdi
    2337:	e8 04 fd ff ff       	call   2040 <puts@plt>
    233c:	90                   	nop
    233d:	5d                   	pop    %rbp
    233e:	c3                   	ret

000000000000233f <core_cpu_nop_add_zero_bpl>:
    233f:	55                   	push   %rbp
    2340:	48 89 e5             	mov    %rsp,%rbp
    2343:	40 80 c5 00          	add    $0x0,%bpl
    2347:	48 8d 05 3c 0d 00 00 	lea    0xd3c(%rip),%rax        # 308a <_IO_stdin_used+0x8a>
    234e:	48 89 c7             	mov    %rax,%rdi
    2351:	e8 ea fc ff ff       	call   2040 <puts@plt>
    2356:	90                   	nop
    2357:	5d                   	pop    %rbp
    2358:	c3                   	ret

0000000000002359 <core_cpu_nop_add_zero_bx>:
    2359:	55                   	push   %rbp
    235a:	48 89 e5             	mov    %rsp,%rbp
    235d:	66 83 c3 00          	add    $0x0,%bx
    2361:	48 8d 05 2c 0d 00 00 	lea    0xd2c(%rip),%rax        # 3094 <_IO_stdin_used+0x94>
    2368:	48 89 c7             	mov    %rax,%rdi
    236b:	e8 d0 fc ff ff       	call   2040 <puts@plt>
    2370:	90                   	nop
    2371:	5d                   	pop    %rbp
    2372:	c3                   	ret

0000000000002373 <core_cpu_nop_add_zero_ch>:
    2373:	55                   	push   %rbp
    2374:	48 89 e5             	mov    %rsp,%rbp
    2377:	80 c5 00             	add    $0x0,%ch
    237a:	48 8d 05 1c 0d 00 00 	lea    0xd1c(%rip),%rax        # 309d <_IO_stdin_used+0x9d>
    2381:	48 89 c7             	mov    %rax,%rdi
    2384:	e8 b7 fc ff ff       	call   2040 <puts@plt>
    2389:	90                   	nop
    238a:	5d                   	pop    %rbp
    238b:	c3                   	ret

000000000000238c <core_cpu_nop_add_zero_cl>:
    238c:	55                   	push   %rbp
    238d:	48 89 e5             	mov    %rsp,%rbp
    2390:	80 c1 00             	add    $0x0,%cl
    2393:	48 8d 05 0c 0d 00 00 	lea    0xd0c(%rip),%rax        # 30a6 <_IO_stdin_used+0xa6>
    239a:	48 89 c7             	mov    %rax,%rdi
    239d:	e8 9e fc ff ff       	call   2040 <puts@plt>
    23a2:	90                   	nop
    23a3:	5d                   	pop    %rbp
    23a4:	c3                   	ret

00000000000023a5 <core_cpu_nop_add_zero_cx>:
    23a5:	55                   	push   %rbp
    23a6:	48 89 e5             	mov    %rsp,%rbp
    23a9:	66 83 c1 00          	add    $0x0,%cx
    23ad:	48 8d 05 fb 0c 00 00 	lea    0xcfb(%rip),%rax        # 30af <_IO_stdin_used+0xaf>
    23b4:	48 89 c7             	mov    %rax,%rdi
    23b7:	e8 84 fc ff ff       	call   2040 <puts@plt>
    23bc:	90                   	nop
    23bd:	5d                   	pop    %rbp
    23be:	c3                   	ret

00000000000023bf <core_cpu_nop_add_zero_dh>:
    23bf:	55                   	push   %rbp
    23c0:	48 89 e5             	mov    %rsp,%rbp
    23c3:	80 c6 00             	add    $0x0,%dh
    23c6:	48 8d 05 eb 0c 00 00 	lea    0xceb(%rip),%rax        # 30b8 <_IO_stdin_used+0xb8>
    23cd:	48 89 c7             	mov    %rax,%rdi
    23d0:	e8 6b fc ff ff       	call   2040 <puts@plt>
    23d5:	90                   	nop
    23d6:	5d                   	pop    %rbp
    23d7:	c3                   	ret

00000000000023d8 <core_cpu_nop_add_zero_di>:
    23d8:	55                   	push   %rbp
    23d9:	48 89 e5             	mov    %rsp,%rbp
    23dc:	66 83 c7 00          	add    $0x0,%di
    23e0:	48 8d 05 da 0c 00 00 	lea    0xcda(%rip),%rax        # 30c1 <_IO_stdin_used+0xc1>
    23e7:	48 89 c7             	mov    %rax,%rdi
    23ea:	e8 51 fc ff ff       	call   2040 <puts@plt>
    23ef:	90                   	nop
    23f0:	5d                   	pop    %rbp
    23f1:	c3                   	ret

00000000000023f2 <core_cpu_nop_add_zero_dil>:
    23f2:	55                   	push   %rbp
    23f3:	48 89 e5             	mov    %rsp,%rbp
    23f6:	40 80 c7 00          	add    $0x0,%dil
    23fa:	48 8d 05 c9 0c 00 00 	lea    0xcc9(%rip),%rax        # 30ca <_IO_stdin_used+0xca>
    2401:	48 89 c7             	mov    %rax,%rdi
    2404:	e8 37 fc ff ff       	call   2040 <puts@plt>
    2409:	90                   	nop
    240a:	5d                   	pop    %rbp
    240b:	c3                   	ret

000000000000240c <core_cpu_nop_add_zero_dl>:
    240c:	55                   	push   %rbp
    240d:	48 89 e5             	mov    %rsp,%rbp
    2410:	80 c2 00             	add    $0x0,%dl
    2413:	48 8d 05 ba 0c 00 00 	lea    0xcba(%rip),%rax        # 30d4 <_IO_stdin_used+0xd4>
    241a:	48 89 c7             	mov    %rax,%rdi
    241d:	e8 1e fc ff ff       	call   2040 <puts@plt>
    2422:	90                   	nop
    2423:	5d                   	pop    %rbp
    2424:	c3                   	ret

0000000000002425 <core_cpu_nop_add_zero_dx>:
    2425:	55                   	push   %rbp
    2426:	48 89 e5             	mov    %rsp,%rbp
    2429:	66 83 c2 00          	add    $0x0,%dx
    242d:	48 8d 05 a9 0c 00 00 	lea    0xca9(%rip),%rax        # 30dd <_IO_stdin_used+0xdd>
    2434:	48 89 c7             	mov    %rax,%rdi
    2437:	e8 04 fc ff ff       	call   2040 <puts@plt>
    243c:	90                   	nop
    243d:	5d                   	pop    %rbp
    243e:	c3                   	ret

000000000000243f <core_cpu_nop_add_zero_eax>:
    243f:	55                   	push   %rbp
    2440:	48 89 e5             	mov    %rsp,%rbp
    2443:	83 c0 00             	add    $0x0,%eax
    2446:	48 8d 05 99 0c 00 00 	lea    0xc99(%rip),%rax        # 30e6 <_IO_stdin_used+0xe6>
    244d:	48 89 c7             	mov    %rax,%rdi
    2450:	e8 eb fb ff ff       	call   2040 <puts@plt>
    2455:	90                   	nop
    2456:	5d                   	pop    %rbp
    2457:	c3                   	ret

0000000000002458 <core_cpu_nop_add_zero_ebp>:
    2458:	55                   	push   %rbp
    2459:	48 89 e5             	mov    %rsp,%rbp
    245c:	83 c5 00             	add    $0x0,%ebp
    245f:	48 8d 05 8a 0c 00 00 	lea    0xc8a(%rip),%rax        # 30f0 <_IO_stdin_used+0xf0>
    2466:	48 89 c7             	mov    %rax,%rdi
    2469:	e8 d2 fb ff ff       	call   2040 <puts@plt>
    246e:	90                   	nop
    246f:	5d                   	pop    %rbp
    2470:	c3                   	ret

0000000000002471 <core_cpu_nop_add_zero_ebx>:
    2471:	55                   	push   %rbp
    2472:	48 89 e5             	mov    %rsp,%rbp
    2475:	83 c3 00             	add    $0x0,%ebx
    2478:	48 8d 05 7b 0c 00 00 	lea    0xc7b(%rip),%rax        # 30fa <_IO_stdin_used+0xfa>
    247f:	48 89 c7             	mov    %rax,%rdi
    2482:	e8 b9 fb ff ff       	call   2040 <puts@plt>
    2487:	90                   	nop
    2488:	5d                   	pop    %rbp
    2489:	c3                   	ret

000000000000248a <core_cpu_nop_add_zero_ecx>:
    248a:	55                   	push   %rbp
    248b:	48 89 e5             	mov    %rsp,%rbp
    248e:	83 c1 00             	add    $0x0,%ecx
    2491:	48 8d 05 6c 0c 00 00 	lea    0xc6c(%rip),%rax        # 3104 <_IO_stdin_used+0x104>
    2498:	48 89 c7             	mov    %rax,%rdi
    249b:	e8 a0 fb ff ff       	call   2040 <puts@plt>
    24a0:	90                   	nop
    24a1:	5d                   	pop    %rbp
    24a2:	c3                   	ret

00000000000024a3 <core_cpu_nop_add_zero_edi>:
    24a3:	55                   	push   %rbp
    24a4:	48 89 e5             	mov    %rsp,%rbp
    24a7:	83 c7 00             	add    $0x0,%edi
    24aa:	48 8d 05 5d 0c 00 00 	lea    0xc5d(%rip),%rax        # 310e <_IO_stdin_used+0x10e>
    24b1:	48 89 c7             	mov    %rax,%rdi
    24b4:	e8 87 fb ff ff       	call   2040 <puts@plt>
    24b9:	90                   	nop
    24ba:	5d                   	pop    %rbp
    24bb:	c3                   	ret

00000000000024bc <core_cpu_nop_add_zero_edx>:
    24bc:	55                   	push   %rbp
    24bd:	48 89 e5             	mov    %rsp,%rbp
    24c0:	83 c2 00             	add    $0x0,%edx
    24c3:	48 8d 05 4e 0c 00 00 	lea    0xc4e(%rip),%rax        # 3118 <_IO_stdin_used+0x118>
    24ca:	48 89 c7             	mov    %rax,%rdi
    24cd:	e8 6e fb ff ff       	call   2040 <puts@plt>
    24d2:	90                   	nop
    24d3:	5d                   	pop    %rbp
    24d4:	c3                   	ret

00000000000024d5 <core_cpu_nop_add_zero_esi>:
    24d5:	55                   	push   %rbp
    24d6:	48 89 e5             	mov    %rsp,%rbp
    24d9:	83 c6 00             	add    $0x0,%esi
    24dc:	48 8d 05 3f 0c 00 00 	lea    0xc3f(%rip),%rax        # 3122 <_IO_stdin_used+0x122>
    24e3:	48 89 c7             	mov    %rax,%rdi
    24e6:	e8 55 fb ff ff       	call   2040 <puts@plt>
    24eb:	90                   	nop
    24ec:	5d                   	pop    %rbp
    24ed:	c3                   	ret

00000000000024ee <core_cpu_nop_add_zero_esp>:
    24ee:	55                   	push   %rbp
    24ef:	48 89 e5             	mov    %rsp,%rbp
    24f2:	83 c4 00             	add    $0x0,%esp
    24f5:	48 8d 05 30 0c 00 00 	lea    0xc30(%rip),%rax        # 312c <_IO_stdin_used+0x12c>
    24fc:	48 89 c7             	mov    %rax,%rdi
    24ff:	e8 3c fb ff ff       	call   2040 <puts@plt>
    2504:	90                   	nop
    2505:	5d                   	pop    %rbp
    2506:	c3                   	ret

0000000000002507 <core_cpu_nop_add_zero_r10b>:
    2507:	55                   	push   %rbp
    2508:	48 89 e5             	mov    %rsp,%rbp
    250b:	41 80 c2 00          	add    $0x0,%r10b
    250f:	48 8d 05 20 0c 00 00 	lea    0xc20(%rip),%rax        # 3136 <_IO_stdin_used+0x136>
    2516:	48 89 c7             	mov    %rax,%rdi
    2519:	e8 22 fb ff ff       	call   2040 <puts@plt>
    251e:	90                   	nop
    251f:	5d                   	pop    %rbp
    2520:	c3                   	ret

0000000000002521 <core_cpu_nop_add_zero_r10d>:
    2521:	55                   	push   %rbp
    2522:	48 89 e5             	mov    %rsp,%rbp
    2525:	41 83 c2 00          	add    $0x0,%r10d
    2529:	48 8d 05 11 0c 00 00 	lea    0xc11(%rip),%rax        # 3141 <_IO_stdin_used+0x141>
    2530:	48 89 c7             	mov    %rax,%rdi
    2533:	e8 08 fb ff ff       	call   2040 <puts@plt>
    2538:	90                   	nop
    2539:	5d                   	pop    %rbp
    253a:	c3                   	ret

000000000000253b <core_cpu_nop_add_zero_r10w>:
    253b:	55                   	push   %rbp
    253c:	48 89 e5             	mov    %rsp,%rbp
    253f:	66 41 83 c2 00       	add    $0x0,%r10w
    2544:	48 8d 05 01 0c 00 00 	lea    0xc01(%rip),%rax        # 314c <_IO_stdin_used+0x14c>
    254b:	48 89 c7             	mov    %rax,%rdi
    254e:	e8 ed fa ff ff       	call   2040 <puts@plt>
    2553:	90                   	nop
    2554:	5d                   	pop    %rbp
    2555:	c3                   	ret

0000000000002556 <core_cpu_nop_add_zero_r11b>:
    2556:	55                   	push   %rbp
    2557:	48 89 e5             	mov    %rsp,%rbp
    255a:	41 80 c3 00          	add    $0x0,%r11b
    255e:	48 8d 05 d1 0b 00 00 	lea    0xbd1(%rip),%rax        # 3136 <_IO_stdin_used+0x136>
    2565:	48 89 c7             	mov    %rax,%rdi
    2568:	e8 d3 fa ff ff       	call   2040 <puts@plt>
    256d:	90                   	nop
    256e:	5d                   	pop    %rbp
    256f:	c3                   	ret

0000000000002570 <core_cpu_nop_add_zero_r11d>:
    2570:	55                   	push   %rbp
    2571:	48 89 e5             	mov    %rsp,%rbp
    2574:	41 83 c3 00          	add    $0x0,%r11d
    2578:	48 8d 05 d8 0b 00 00 	lea    0xbd8(%rip),%rax        # 3157 <_IO_stdin_used+0x157>
    257f:	48 89 c7             	mov    %rax,%rdi
    2582:	e8 b9 fa ff ff       	call   2040 <puts@plt>
    2587:	90                   	nop
    2588:	5d                   	pop    %rbp
    2589:	c3                   	ret

000000000000258a <core_cpu_nop_add_zero_r11w>:
    258a:	55                   	push   %rbp
    258b:	48 89 e5             	mov    %rsp,%rbp
    258e:	66 41 83 c3 00       	add    $0x0,%r11w
    2593:	48 8d 05 c8 0b 00 00 	lea    0xbc8(%rip),%rax        # 3162 <_IO_stdin_used+0x162>
    259a:	48 89 c7             	mov    %rax,%rdi
    259d:	e8 9e fa ff ff       	call   2040 <puts@plt>
    25a2:	90                   	nop
    25a3:	5d                   	pop    %rbp
    25a4:	c3                   	ret

00000000000025a5 <core_cpu_nop_add_zero_r12b>:
    25a5:	55                   	push   %rbp
    25a6:	48 89 e5             	mov    %rsp,%rbp
    25a9:	41 80 c4 00          	add    $0x0,%r12b
    25ad:	48 8d 05 b9 0b 00 00 	lea    0xbb9(%rip),%rax        # 316d <_IO_stdin_used+0x16d>
    25b4:	48 89 c7             	mov    %rax,%rdi
    25b7:	e8 84 fa ff ff       	call   2040 <puts@plt>
    25bc:	90                   	nop
    25bd:	5d                   	pop    %rbp
    25be:	c3                   	ret

00000000000025bf <core_cpu_nop_add_zero_r12d>:
    25bf:	55                   	push   %rbp
    25c0:	48 89 e5             	mov    %rsp,%rbp
    25c3:	41 83 c4 00          	add    $0x0,%r12d
    25c7:	48 8d 05 aa 0b 00 00 	lea    0xbaa(%rip),%rax        # 3178 <_IO_stdin_used+0x178>
    25ce:	48 89 c7             	mov    %rax,%rdi
    25d1:	e8 6a fa ff ff       	call   2040 <puts@plt>
    25d6:	90                   	nop
    25d7:	5d                   	pop    %rbp
    25d8:	c3                   	ret

00000000000025d9 <core_cpu_nop_add_zero_r12w>:
    25d9:	55                   	push   %rbp
    25da:	48 89 e5             	mov    %rsp,%rbp
    25dd:	66 41 83 c4 00       	add    $0x0,%r12w
    25e2:	48 8d 05 9a 0b 00 00 	lea    0xb9a(%rip),%rax        # 3183 <_IO_stdin_used+0x183>
    25e9:	48 89 c7             	mov    %rax,%rdi
    25ec:	e8 4f fa ff ff       	call   2040 <puts@plt>
    25f1:	90                   	nop
    25f2:	5d                   	pop    %rbp
    25f3:	c3                   	ret

00000000000025f4 <core_cpu_nop_add_zero_r13b>:
    25f4:	55                   	push   %rbp
    25f5:	48 89 e5             	mov    %rsp,%rbp
    25f8:	41 80 c5 00          	add    $0x0,%r13b
    25fc:	48 8d 05 8b 0b 00 00 	lea    0xb8b(%rip),%rax        # 318e <_IO_stdin_used+0x18e>
    2603:	48 89 c7             	mov    %rax,%rdi
    2606:	e8 35 fa ff ff       	call   2040 <puts@plt>
    260b:	90                   	nop
    260c:	5d                   	pop    %rbp
    260d:	c3                   	ret

000000000000260e <core_cpu_nop_add_zero_r13d>:
    260e:	55                   	push   %rbp
    260f:	48 89 e5             	mov    %rsp,%rbp
    2612:	41 83 c5 00          	add    $0x0,%r13d
    2616:	48 8d 05 7c 0b 00 00 	lea    0xb7c(%rip),%rax        # 3199 <_IO_stdin_used+0x199>
    261d:	48 89 c7             	mov    %rax,%rdi
    2620:	e8 1b fa ff ff       	call   2040 <puts@plt>
    2625:	90                   	nop
    2626:	5d                   	pop    %rbp
    2627:	c3                   	ret

0000000000002628 <core_cpu_nop_add_zero_r13w>:
    2628:	55                   	push   %rbp
    2629:	48 89 e5             	mov    %rsp,%rbp
    262c:	66 41 83 c5 00       	add    $0x0,%r13w
    2631:	48 8d 05 6c 0b 00 00 	lea    0xb6c(%rip),%rax        # 31a4 <_IO_stdin_used+0x1a4>
    2638:	48 89 c7             	mov    %rax,%rdi
    263b:	e8 00 fa ff ff       	call   2040 <puts@plt>
    2640:	90                   	nop
    2641:	5d                   	pop    %rbp
    2642:	c3                   	ret

0000000000002643 <core_cpu_nop_add_zero_r14b>:
    2643:	55                   	push   %rbp
    2644:	48 89 e5             	mov    %rsp,%rbp
    2647:	41 80 c6 00          	add    $0x0,%r14b
    264b:	48 8d 05 5d 0b 00 00 	lea    0xb5d(%rip),%rax        # 31af <_IO_stdin_used+0x1af>
    2652:	48 89 c7             	mov    %rax,%rdi
    2655:	e8 e6 f9 ff ff       	call   2040 <puts@plt>
    265a:	90                   	nop
    265b:	5d                   	pop    %rbp
    265c:	c3                   	ret

000000000000265d <core_cpu_nop_add_zero_r14d>:
    265d:	55                   	push   %rbp
    265e:	48 89 e5             	mov    %rsp,%rbp
    2661:	41 83 c6 00          	add    $0x0,%r14d
    2665:	48 8d 05 4e 0b 00 00 	lea    0xb4e(%rip),%rax        # 31ba <_IO_stdin_used+0x1ba>
    266c:	48 89 c7             	mov    %rax,%rdi
    266f:	e8 cc f9 ff ff       	call   2040 <puts@plt>
    2674:	90                   	nop
    2675:	5d                   	pop    %rbp
    2676:	c3                   	ret

0000000000002677 <core_cpu_nop_add_zero_r14w>:
    2677:	55                   	push   %rbp
    2678:	48 89 e5             	mov    %rsp,%rbp
    267b:	66 41 83 c6 00       	add    $0x0,%r14w
    2680:	48 8d 05 3e 0b 00 00 	lea    0xb3e(%rip),%rax        # 31c5 <_IO_stdin_used+0x1c5>
    2687:	48 89 c7             	mov    %rax,%rdi
    268a:	e8 b1 f9 ff ff       	call   2040 <puts@plt>
    268f:	90                   	nop
    2690:	5d                   	pop    %rbp
    2691:	c3                   	ret

0000000000002692 <core_cpu_nop_add_zero_r15b>:
    2692:	55                   	push   %rbp
    2693:	48 89 e5             	mov    %rsp,%rbp
    2696:	41 80 c7 00          	add    $0x0,%r15b
    269a:	48 8d 05 2f 0b 00 00 	lea    0xb2f(%rip),%rax        # 31d0 <_IO_stdin_used+0x1d0>
    26a1:	48 89 c7             	mov    %rax,%rdi
    26a4:	e8 97 f9 ff ff       	call   2040 <puts@plt>
    26a9:	90                   	nop
    26aa:	5d                   	pop    %rbp
    26ab:	c3                   	ret

00000000000026ac <core_cpu_nop_add_zero_r15d>:
    26ac:	55                   	push   %rbp
    26ad:	48 89 e5             	mov    %rsp,%rbp
    26b0:	41 83 c7 00          	add    $0x0,%r15d
    26b4:	48 8d 05 20 0b 00 00 	lea    0xb20(%rip),%rax        # 31db <_IO_stdin_used+0x1db>
    26bb:	48 89 c7             	mov    %rax,%rdi
    26be:	e8 7d f9 ff ff       	call   2040 <puts@plt>
    26c3:	90                   	nop
    26c4:	5d                   	pop    %rbp
    26c5:	c3                   	ret

00000000000026c6 <core_cpu_nop_add_zero_r15w>:
    26c6:	55                   	push   %rbp
    26c7:	48 89 e5             	mov    %rsp,%rbp
    26ca:	66 41 83 c7 00       	add    $0x0,%r15w
    26cf:	48 8d 05 10 0b 00 00 	lea    0xb10(%rip),%rax        # 31e6 <_IO_stdin_used+0x1e6>
    26d6:	48 89 c7             	mov    %rax,%rdi
    26d9:	e8 62 f9 ff ff       	call   2040 <puts@plt>
    26de:	90                   	nop
    26df:	5d                   	pop    %rbp
    26e0:	c3                   	ret

00000000000026e1 <core_cpu_nop_add_zero_r8b>:
    26e1:	55                   	push   %rbp
    26e2:	48 89 e5             	mov    %rsp,%rbp
    26e5:	41 80 c0 00          	add    $0x0,%r8b
    26e9:	48 8d 05 01 0b 00 00 	lea    0xb01(%rip),%rax        # 31f1 <_IO_stdin_used+0x1f1>
    26f0:	48 89 c7             	mov    %rax,%rdi
    26f3:	e8 48 f9 ff ff       	call   2040 <puts@plt>
    26f8:	90                   	nop
    26f9:	5d                   	pop    %rbp
    26fa:	c3                   	ret

00000000000026fb <core_cpu_nop_add_zero_r8d>:
    26fb:	55                   	push   %rbp
    26fc:	48 89 e5             	mov    %rsp,%rbp
    26ff:	41 83 c0 00          	add    $0x0,%r8d
    2703:	48 8d 05 f1 0a 00 00 	lea    0xaf1(%rip),%rax        # 31fb <_IO_stdin_used+0x1fb>
    270a:	48 89 c7             	mov    %rax,%rdi
    270d:	e8 2e f9 ff ff       	call   2040 <puts@plt>
    2712:	90                   	nop
    2713:	5d                   	pop    %rbp
    2714:	c3                   	ret

0000000000002715 <core_cpu_nop_add_zero_r8w>:
    2715:	55                   	push   %rbp
    2716:	48 89 e5             	mov    %rsp,%rbp
    2719:	66 41 83 c0 00       	add    $0x0,%r8w
    271e:	48 8d 05 e0 0a 00 00 	lea    0xae0(%rip),%rax        # 3205 <_IO_stdin_used+0x205>
    2725:	48 89 c7             	mov    %rax,%rdi
    2728:	e8 13 f9 ff ff       	call   2040 <puts@plt>
    272d:	90                   	nop
    272e:	5d                   	pop    %rbp
    272f:	c3                   	ret

0000000000002730 <core_cpu_nop_add_zero_r9b>:
    2730:	55                   	push   %rbp
    2731:	48 89 e5             	mov    %rsp,%rbp
    2734:	41 80 c1 00          	add    $0x0,%r9b
    2738:	48 8d 05 d0 0a 00 00 	lea    0xad0(%rip),%rax        # 320f <_IO_stdin_used+0x20f>
    273f:	48 89 c7             	mov    %rax,%rdi
    2742:	e8 f9 f8 ff ff       	call   2040 <puts@plt>
    2747:	90                   	nop
    2748:	5d                   	pop    %rbp
    2749:	c3                   	ret

000000000000274a <core_cpu_nop_add_zero_r9d>:
    274a:	55                   	push   %rbp
    274b:	48 89 e5             	mov    %rsp,%rbp
    274e:	41 83 c1 00          	add    $0x0,%r9d
    2752:	48 8d 05 c0 0a 00 00 	lea    0xac0(%rip),%rax        # 3219 <_IO_stdin_used+0x219>
    2759:	48 89 c7             	mov    %rax,%rdi
    275c:	e8 df f8 ff ff       	call   2040 <puts@plt>
    2761:	90                   	nop
    2762:	5d                   	pop    %rbp
    2763:	c3                   	ret

0000000000002764 <core_cpu_nop_add_zero_r9w>:
    2764:	55                   	push   %rbp
    2765:	48 89 e5             	mov    %rsp,%rbp
    2768:	66 41 83 c1 00       	add    $0x0,%r9w
    276d:	48 8d 05 af 0a 00 00 	lea    0xaaf(%rip),%rax        # 3223 <_IO_stdin_used+0x223>
    2774:	48 89 c7             	mov    %rax,%rdi
    2777:	e8 c4 f8 ff ff       	call   2040 <puts@plt>
    277c:	90                   	nop
    277d:	5d                   	pop    %rbp
    277e:	c3                   	ret

000000000000277f <core_cpu_nop_add_zero_si>:
    277f:	55                   	push   %rbp
    2780:	48 89 e5             	mov    %rsp,%rbp
    2783:	66 83 c6 00          	add    $0x0,%si
    2787:	48 8d 05 9f 0a 00 00 	lea    0xa9f(%rip),%rax        # 322d <_IO_stdin_used+0x22d>
    278e:	48 89 c7             	mov    %rax,%rdi
    2791:	e8 aa f8 ff ff       	call   2040 <puts@plt>
    2796:	90                   	nop
    2797:	5d                   	pop    %rbp
    2798:	c3                   	ret

0000000000002799 <core_cpu_nop_add_zero_sil>:
    2799:	55                   	push   %rbp
    279a:	48 89 e5             	mov    %rsp,%rbp
    279d:	40 80 c6 00          	add    $0x0,%sil
    27a1:	48 8d 05 8e 0a 00 00 	lea    0xa8e(%rip),%rax        # 3236 <_IO_stdin_used+0x236>
    27a8:	48 89 c7             	mov    %rax,%rdi
    27ab:	e8 90 f8 ff ff       	call   2040 <puts@plt>
    27b0:	90                   	nop
    27b1:	5d                   	pop    %rbp
    27b2:	c3                   	ret

00000000000027b3 <core_cpu_nop_add_zero_sp>:
    27b3:	55                   	push   %rbp
    27b4:	48 89 e5             	mov    %rsp,%rbp
    27b7:	66 83 c4 00          	add    $0x0,%sp
    27bb:	48 8d 05 7e 0a 00 00 	lea    0xa7e(%rip),%rax        # 3240 <_IO_stdin_used+0x240>
    27c2:	48 89 c7             	mov    %rax,%rdi
    27c5:	e8 76 f8 ff ff       	call   2040 <puts@plt>
    27ca:	90                   	nop
    27cb:	5d                   	pop    %rbp
    27cc:	c3                   	ret

00000000000027cd <core_cpu_nop_add_zero_spl>:
    27cd:	55                   	push   %rbp
    27ce:	48 89 e5             	mov    %rsp,%rbp
    27d1:	40 80 c4 00          	add    $0x0,%spl
    27d5:	48 8d 05 6d 0a 00 00 	lea    0xa6d(%rip),%rax        # 3249 <_IO_stdin_used+0x249>
    27dc:	48 89 c7             	mov    %rax,%rdi
    27df:	e8 5c f8 ff ff       	call   2040 <puts@plt>
    27e4:	90                   	nop
    27e5:	5d                   	pop    %rbp
    27e6:	c3                   	ret

00000000000027e7 <core_cpu_nop_add_zero>:
    27e7:	55                   	push   %rbp
    27e8:	48 89 e5             	mov    %rsp,%rbp
    27eb:	48 81 ec b0 01 00 00 	sub    $0x1b0,%rsp
    27f2:	48 8d 85 50 fe ff ff 	lea    -0x1b0(%rbp),%rax
    27f9:	48 8d 15 60 38 00 00 	lea    0x3860(%rip),%rdx        # 6060 <__dso_handle+0x18>
    2800:	b9 34 00 00 00       	mov    $0x34,%ecx
    2805:	48 89 c7             	mov    %rax,%rdi
    2808:	48 89 d6             	mov    %rdx,%rsi
    280b:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
    280e:	e8 7d f8 ff ff       	call   2090 <rand@plt>
    2813:	48 63 c8             	movslq %eax,%rcx
    2816:	48 ba c5 4e ec c4 4e 	movabs $0x4ec4ec4ec4ec4ec5,%rdx
    281d:	ec c4 4e 
    2820:	48 89 c8             	mov    %rcx,%rax
    2823:	48 f7 e2             	mul    %rdx
    2826:	48 c1 ea 04          	shr    $0x4,%rdx
    282a:	48 89 d0             	mov    %rdx,%rax
    282d:	48 01 c0             	add    %rax,%rax
    2830:	48 01 d0             	add    %rdx,%rax
    2833:	48 c1 e0 02          	shl    $0x2,%rax
    2837:	48 01 d0             	add    %rdx,%rax
    283a:	48 c1 e0 02          	shl    $0x2,%rax
    283e:	48 29 c1             	sub    %rax,%rcx
    2841:	48 89 ca             	mov    %rcx,%rdx
    2844:	89 55 fc             	mov    %edx,-0x4(%rbp)
    2847:	8b 45 fc             	mov    -0x4(%rbp),%eax
    284a:	48 98                	cltq
    284c:	48 8b 84 c5 50 fe ff 	mov    -0x1b0(%rbp,%rax,8),%rax
    2853:	ff 
    2854:	ff d0                	call   *%rax
    2856:	90                   	nop
    2857:	c9                   	leave
    2858:	c3                   	ret

0000000000002859 <core_cpu_nop_sub_zero_ah>:
    2859:	55                   	push   %rbp
    285a:	48 89 e5             	mov    %rsp,%rbp
    285d:	80 ec 00             	sub    $0x0,%ah
    2860:	90                   	nop
    2861:	5d                   	pop    %rbp
    2862:	c3                   	ret

0000000000002863 <core_cpu_nop_sub_zero_al>:
    2863:	55                   	push   %rbp
    2864:	48 89 e5             	mov    %rsp,%rbp
    2867:	2c 00                	sub    $0x0,%al
    2869:	90                   	nop
    286a:	5d                   	pop    %rbp
    286b:	c3                   	ret

000000000000286c <core_cpu_nop_sub_zero_ax>:
    286c:	55                   	push   %rbp
    286d:	48 89 e5             	mov    %rsp,%rbp
    2870:	66 83 e8 00          	sub    $0x0,%ax
    2874:	90                   	nop
    2875:	5d                   	pop    %rbp
    2876:	c3                   	ret

0000000000002877 <core_cpu_nop_sub_zero_bh>:
    2877:	55                   	push   %rbp
    2878:	48 89 e5             	mov    %rsp,%rbp
    287b:	80 ef 00             	sub    $0x0,%bh
    287e:	90                   	nop
    287f:	5d                   	pop    %rbp
    2880:	c3                   	ret

0000000000002881 <core_cpu_nop_sub_zero_bl>:
    2881:	55                   	push   %rbp
    2882:	48 89 e5             	mov    %rsp,%rbp
    2885:	80 eb 00             	sub    $0x0,%bl
    2888:	90                   	nop
    2889:	5d                   	pop    %rbp
    288a:	c3                   	ret

000000000000288b <core_cpu_nop_sub_zero_bp>:
    288b:	55                   	push   %rbp
    288c:	48 89 e5             	mov    %rsp,%rbp
    288f:	66 83 ed 00          	sub    $0x0,%bp
    2893:	90                   	nop
    2894:	5d                   	pop    %rbp
    2895:	c3                   	ret

0000000000002896 <core_cpu_nop_sub_zero_bpl>:
    2896:	55                   	push   %rbp
    2897:	48 89 e5             	mov    %rsp,%rbp
    289a:	40 80 ed 00          	sub    $0x0,%bpl
    289e:	90                   	nop
    289f:	5d                   	pop    %rbp
    28a0:	c3                   	ret

00000000000028a1 <core_cpu_nop_sub_zero_bx>:
    28a1:	55                   	push   %rbp
    28a2:	48 89 e5             	mov    %rsp,%rbp
    28a5:	66 83 eb 00          	sub    $0x0,%bx
    28a9:	90                   	nop
    28aa:	5d                   	pop    %rbp
    28ab:	c3                   	ret

00000000000028ac <core_cpu_nop_sub_zero_ch>:
    28ac:	55                   	push   %rbp
    28ad:	48 89 e5             	mov    %rsp,%rbp
    28b0:	80 ed 00             	sub    $0x0,%ch
    28b3:	90                   	nop
    28b4:	5d                   	pop    %rbp
    28b5:	c3                   	ret

00000000000028b6 <core_cpu_nop_sub_zero_cl>:
    28b6:	55                   	push   %rbp
    28b7:	48 89 e5             	mov    %rsp,%rbp
    28ba:	80 e9 00             	sub    $0x0,%cl
    28bd:	90                   	nop
    28be:	5d                   	pop    %rbp
    28bf:	c3                   	ret

00000000000028c0 <core_cpu_nop_sub_zero_cx>:
    28c0:	55                   	push   %rbp
    28c1:	48 89 e5             	mov    %rsp,%rbp
    28c4:	66 83 e9 00          	sub    $0x0,%cx
    28c8:	90                   	nop
    28c9:	5d                   	pop    %rbp
    28ca:	c3                   	ret

00000000000028cb <core_cpu_nop_sub_zero_dh>:
    28cb:	55                   	push   %rbp
    28cc:	48 89 e5             	mov    %rsp,%rbp
    28cf:	80 ee 00             	sub    $0x0,%dh
    28d2:	90                   	nop
    28d3:	5d                   	pop    %rbp
    28d4:	c3                   	ret

00000000000028d5 <core_cpu_nop_sub_zero_di>:
    28d5:	55                   	push   %rbp
    28d6:	48 89 e5             	mov    %rsp,%rbp
    28d9:	66 83 ef 00          	sub    $0x0,%di
    28dd:	90                   	nop
    28de:	5d                   	pop    %rbp
    28df:	c3                   	ret

00000000000028e0 <core_cpu_nop_sub_zero_dil>:
    28e0:	55                   	push   %rbp
    28e1:	48 89 e5             	mov    %rsp,%rbp
    28e4:	40 80 ef 00          	sub    $0x0,%dil
    28e8:	90                   	nop
    28e9:	5d                   	pop    %rbp
    28ea:	c3                   	ret

00000000000028eb <core_cpu_nop_sub_zero_dl>:
    28eb:	55                   	push   %rbp
    28ec:	48 89 e5             	mov    %rsp,%rbp
    28ef:	80 ea 00             	sub    $0x0,%dl
    28f2:	90                   	nop
    28f3:	5d                   	pop    %rbp
    28f4:	c3                   	ret

00000000000028f5 <core_cpu_nop_sub_zero_dx>:
    28f5:	55                   	push   %rbp
    28f6:	48 89 e5             	mov    %rsp,%rbp
    28f9:	66 83 ea 00          	sub    $0x0,%dx
    28fd:	90                   	nop
    28fe:	5d                   	pop    %rbp
    28ff:	c3                   	ret

0000000000002900 <core_cpu_nop_sub_zero_eax>:
    2900:	55                   	push   %rbp
    2901:	48 89 e5             	mov    %rsp,%rbp
    2904:	83 e8 00             	sub    $0x0,%eax
    2907:	90                   	nop
    2908:	5d                   	pop    %rbp
    2909:	c3                   	ret

000000000000290a <core_cpu_nop_sub_zero_ebp>:
    290a:	55                   	push   %rbp
    290b:	48 89 e5             	mov    %rsp,%rbp
    290e:	83 ed 00             	sub    $0x0,%ebp
    2911:	90                   	nop
    2912:	5d                   	pop    %rbp
    2913:	c3                   	ret

0000000000002914 <core_cpu_nop_sub_zero_ebx>:
    2914:	55                   	push   %rbp
    2915:	48 89 e5             	mov    %rsp,%rbp
    2918:	83 eb 00             	sub    $0x0,%ebx
    291b:	90                   	nop
    291c:	5d                   	pop    %rbp
    291d:	c3                   	ret

000000000000291e <core_cpu_nop_sub_zero_ecx>:
    291e:	55                   	push   %rbp
    291f:	48 89 e5             	mov    %rsp,%rbp
    2922:	83 e9 00             	sub    $0x0,%ecx
    2925:	90                   	nop
    2926:	5d                   	pop    %rbp
    2927:	c3                   	ret

0000000000002928 <core_cpu_nop_sub_zero_edi>:
    2928:	55                   	push   %rbp
    2929:	48 89 e5             	mov    %rsp,%rbp
    292c:	83 ef 00             	sub    $0x0,%edi
    292f:	90                   	nop
    2930:	5d                   	pop    %rbp
    2931:	c3                   	ret

0000000000002932 <core_cpu_nop_sub_zero_edx>:
    2932:	55                   	push   %rbp
    2933:	48 89 e5             	mov    %rsp,%rbp
    2936:	83 ea 00             	sub    $0x0,%edx
    2939:	90                   	nop
    293a:	5d                   	pop    %rbp
    293b:	c3                   	ret

000000000000293c <core_cpu_nop_sub_zero_esi>:
    293c:	55                   	push   %rbp
    293d:	48 89 e5             	mov    %rsp,%rbp
    2940:	83 ee 00             	sub    $0x0,%esi
    2943:	90                   	nop
    2944:	5d                   	pop    %rbp
    2945:	c3                   	ret

0000000000002946 <core_cpu_nop_sub_zero_esp>:
    2946:	55                   	push   %rbp
    2947:	48 89 e5             	mov    %rsp,%rbp
    294a:	83 ec 00             	sub    $0x0,%esp
    294d:	90                   	nop
    294e:	5d                   	pop    %rbp
    294f:	c3                   	ret

0000000000002950 <core_cpu_nop_sub_zero_r10b>:
    2950:	55                   	push   %rbp
    2951:	48 89 e5             	mov    %rsp,%rbp
    2954:	41 80 ea 00          	sub    $0x0,%r10b
    2958:	90                   	nop
    2959:	5d                   	pop    %rbp
    295a:	c3                   	ret

000000000000295b <core_cpu_nop_sub_zero_r10d>:
    295b:	55                   	push   %rbp
    295c:	48 89 e5             	mov    %rsp,%rbp
    295f:	41 83 ea 00          	sub    $0x0,%r10d
    2963:	90                   	nop
    2964:	5d                   	pop    %rbp
    2965:	c3                   	ret

0000000000002966 <core_cpu_nop_sub_zero_r10w>:
    2966:	55                   	push   %rbp
    2967:	48 89 e5             	mov    %rsp,%rbp
    296a:	66 41 83 ea 00       	sub    $0x0,%r10w
    296f:	90                   	nop
    2970:	5d                   	pop    %rbp
    2971:	c3                   	ret

0000000000002972 <core_cpu_nop_sub_zero_r11b>:
    2972:	55                   	push   %rbp
    2973:	48 89 e5             	mov    %rsp,%rbp
    2976:	41 80 eb 00          	sub    $0x0,%r11b
    297a:	90                   	nop
    297b:	5d                   	pop    %rbp
    297c:	c3                   	ret

000000000000297d <core_cpu_nop_sub_zero_r11d>:
    297d:	55                   	push   %rbp
    297e:	48 89 e5             	mov    %rsp,%rbp
    2981:	41 83 eb 00          	sub    $0x0,%r11d
    2985:	90                   	nop
    2986:	5d                   	pop    %rbp
    2987:	c3                   	ret

0000000000002988 <core_cpu_nop_sub_zero_r11w>:
    2988:	55                   	push   %rbp
    2989:	48 89 e5             	mov    %rsp,%rbp
    298c:	66 41 83 eb 00       	sub    $0x0,%r11w
    2991:	90                   	nop
    2992:	5d                   	pop    %rbp
    2993:	c3                   	ret

0000000000002994 <core_cpu_nop_sub_zero_r12b>:
    2994:	55                   	push   %rbp
    2995:	48 89 e5             	mov    %rsp,%rbp
    2998:	41 80 ec 00          	sub    $0x0,%r12b
    299c:	90                   	nop
    299d:	5d                   	pop    %rbp
    299e:	c3                   	ret

000000000000299f <core_cpu_nop_sub_zero_r12d>:
    299f:	55                   	push   %rbp
    29a0:	48 89 e5             	mov    %rsp,%rbp
    29a3:	41 83 ec 00          	sub    $0x0,%r12d
    29a7:	90                   	nop
    29a8:	5d                   	pop    %rbp
    29a9:	c3                   	ret

00000000000029aa <core_cpu_nop_sub_zero_r12w>:
    29aa:	55                   	push   %rbp
    29ab:	48 89 e5             	mov    %rsp,%rbp
    29ae:	66 41 83 ec 00       	sub    $0x0,%r12w
    29b3:	90                   	nop
    29b4:	5d                   	pop    %rbp
    29b5:	c3                   	ret

00000000000029b6 <core_cpu_nop_sub_zero_r13b>:
    29b6:	55                   	push   %rbp
    29b7:	48 89 e5             	mov    %rsp,%rbp
    29ba:	41 80 ed 00          	sub    $0x0,%r13b
    29be:	90                   	nop
    29bf:	5d                   	pop    %rbp
    29c0:	c3                   	ret

00000000000029c1 <core_cpu_nop_sub_zero_r13d>:
    29c1:	55                   	push   %rbp
    29c2:	48 89 e5             	mov    %rsp,%rbp
    29c5:	41 83 ed 00          	sub    $0x0,%r13d
    29c9:	90                   	nop
    29ca:	5d                   	pop    %rbp
    29cb:	c3                   	ret

00000000000029cc <core_cpu_nop_sub_zero_r13w>:
    29cc:	55                   	push   %rbp
    29cd:	48 89 e5             	mov    %rsp,%rbp
    29d0:	66 41 83 ed 00       	sub    $0x0,%r13w
    29d5:	90                   	nop
    29d6:	5d                   	pop    %rbp
    29d7:	c3                   	ret

00000000000029d8 <core_cpu_nop_sub_zero_r14b>:
    29d8:	55                   	push   %rbp
    29d9:	48 89 e5             	mov    %rsp,%rbp
    29dc:	41 80 ee 00          	sub    $0x0,%r14b
    29e0:	90                   	nop
    29e1:	5d                   	pop    %rbp
    29e2:	c3                   	ret

00000000000029e3 <core_cpu_nop_sub_zero_r14d>:
    29e3:	55                   	push   %rbp
    29e4:	48 89 e5             	mov    %rsp,%rbp
    29e7:	41 83 ee 00          	sub    $0x0,%r14d
    29eb:	90                   	nop
    29ec:	5d                   	pop    %rbp
    29ed:	c3                   	ret

00000000000029ee <core_cpu_nop_sub_zero_r14w>:
    29ee:	55                   	push   %rbp
    29ef:	48 89 e5             	mov    %rsp,%rbp
    29f2:	66 41 83 ee 00       	sub    $0x0,%r14w
    29f7:	90                   	nop
    29f8:	5d                   	pop    %rbp
    29f9:	c3                   	ret

00000000000029fa <core_cpu_nop_sub_zero_r15b>:
    29fa:	55                   	push   %rbp
    29fb:	48 89 e5             	mov    %rsp,%rbp
    29fe:	41 80 ef 00          	sub    $0x0,%r15b
    2a02:	90                   	nop
    2a03:	5d                   	pop    %rbp
    2a04:	c3                   	ret

0000000000002a05 <core_cpu_nop_sub_zero_r15d>:
    2a05:	55                   	push   %rbp
    2a06:	48 89 e5             	mov    %rsp,%rbp
    2a09:	41 83 ef 00          	sub    $0x0,%r15d
    2a0d:	90                   	nop
    2a0e:	5d                   	pop    %rbp
    2a0f:	c3                   	ret

0000000000002a10 <core_cpu_nop_sub_zero_r15w>:
    2a10:	55                   	push   %rbp
    2a11:	48 89 e5             	mov    %rsp,%rbp
    2a14:	66 41 83 ef 00       	sub    $0x0,%r15w
    2a19:	90                   	nop
    2a1a:	5d                   	pop    %rbp
    2a1b:	c3                   	ret

0000000000002a1c <core_cpu_nop_sub_zero_r8b>:
    2a1c:	55                   	push   %rbp
    2a1d:	48 89 e5             	mov    %rsp,%rbp
    2a20:	41 80 e8 00          	sub    $0x0,%r8b
    2a24:	90                   	nop
    2a25:	5d                   	pop    %rbp
    2a26:	c3                   	ret

0000000000002a27 <core_cpu_nop_sub_zero_r8d>:
    2a27:	55                   	push   %rbp
    2a28:	48 89 e5             	mov    %rsp,%rbp
    2a2b:	41 83 e8 00          	sub    $0x0,%r8d
    2a2f:	90                   	nop
    2a30:	5d                   	pop    %rbp
    2a31:	c3                   	ret

0000000000002a32 <core_cpu_nop_sub_zero_r8w>:
    2a32:	55                   	push   %rbp
    2a33:	48 89 e5             	mov    %rsp,%rbp
    2a36:	66 41 83 e8 00       	sub    $0x0,%r8w
    2a3b:	90                   	nop
    2a3c:	5d                   	pop    %rbp
    2a3d:	c3                   	ret

0000000000002a3e <core_cpu_nop_sub_zero_r9b>:
    2a3e:	55                   	push   %rbp
    2a3f:	48 89 e5             	mov    %rsp,%rbp
    2a42:	41 80 e9 00          	sub    $0x0,%r9b
    2a46:	90                   	nop
    2a47:	5d                   	pop    %rbp
    2a48:	c3                   	ret

0000000000002a49 <core_cpu_nop_sub_zero_r9d>:
    2a49:	55                   	push   %rbp
    2a4a:	48 89 e5             	mov    %rsp,%rbp
    2a4d:	41 83 e9 00          	sub    $0x0,%r9d
    2a51:	90                   	nop
    2a52:	5d                   	pop    %rbp
    2a53:	c3                   	ret

0000000000002a54 <core_cpu_nop_sub_zero_r9w>:
    2a54:	55                   	push   %rbp
    2a55:	48 89 e5             	mov    %rsp,%rbp
    2a58:	66 41 83 e9 00       	sub    $0x0,%r9w
    2a5d:	90                   	nop
    2a5e:	5d                   	pop    %rbp
    2a5f:	c3                   	ret

0000000000002a60 <core_cpu_nop_sub_zero_si>:
    2a60:	55                   	push   %rbp
    2a61:	48 89 e5             	mov    %rsp,%rbp
    2a64:	66 83 ee 00          	sub    $0x0,%si
    2a68:	90                   	nop
    2a69:	5d                   	pop    %rbp
    2a6a:	c3                   	ret

0000000000002a6b <core_cpu_nop_sub_zero_sil>:
    2a6b:	55                   	push   %rbp
    2a6c:	48 89 e5             	mov    %rsp,%rbp
    2a6f:	40 80 ee 00          	sub    $0x0,%sil
    2a73:	90                   	nop
    2a74:	5d                   	pop    %rbp
    2a75:	c3                   	ret

0000000000002a76 <core_cpu_nop_sub_zero_sp>:
    2a76:	55                   	push   %rbp
    2a77:	48 89 e5             	mov    %rsp,%rbp
    2a7a:	66 83 ec 00          	sub    $0x0,%sp
    2a7e:	90                   	nop
    2a7f:	5d                   	pop    %rbp
    2a80:	c3                   	ret

0000000000002a81 <core_cpu_nop_sub_zero_spl>:
    2a81:	55                   	push   %rbp
    2a82:	48 89 e5             	mov    %rsp,%rbp
    2a85:	40 80 ec 00          	sub    $0x0,%spl
    2a89:	90                   	nop
    2a8a:	5d                   	pop    %rbp
    2a8b:	c3                   	ret

0000000000002a8c <core_cpu_nop_sub_zero_xmm0>:
    2a8c:	55                   	push   %rbp
    2a8d:	48 89 e5             	mov    %rsp,%rbp
    2a90:	0f 5c c0             	subps  %xmm0,%xmm0
    2a93:	90                   	nop
    2a94:	5d                   	pop    %rbp
    2a95:	c3                   	ret

0000000000002a96 <core_cpu_nop_sub_zero_xmm1>:
    2a96:	55                   	push   %rbp
    2a97:	48 89 e5             	mov    %rsp,%rbp
    2a9a:	0f 5c c9             	subps  %xmm1,%xmm1
    2a9d:	90                   	nop
    2a9e:	5d                   	pop    %rbp
    2a9f:	c3                   	ret

0000000000002aa0 <core_cpu_nop_sub_zero_xmm10>:
    2aa0:	55                   	push   %rbp
    2aa1:	48 89 e5             	mov    %rsp,%rbp
    2aa4:	45 0f 5c d2          	subps  %xmm10,%xmm10
    2aa8:	90                   	nop
    2aa9:	5d                   	pop    %rbp
    2aaa:	c3                   	ret

0000000000002aab <core_cpu_nop_sub_zero_xmm11>:
    2aab:	55                   	push   %rbp
    2aac:	48 89 e5             	mov    %rsp,%rbp
    2aaf:	45 0f 5c db          	subps  %xmm11,%xmm11
    2ab3:	90                   	nop
    2ab4:	5d                   	pop    %rbp
    2ab5:	c3                   	ret

0000000000002ab6 <core_cpu_nop_sub_zero_xmm12>:
    2ab6:	55                   	push   %rbp
    2ab7:	48 89 e5             	mov    %rsp,%rbp
    2aba:	45 0f 5c e4          	subps  %xmm12,%xmm12
    2abe:	90                   	nop
    2abf:	5d                   	pop    %rbp
    2ac0:	c3                   	ret

0000000000002ac1 <core_cpu_nop_sub_zero_xmm13>:
    2ac1:	55                   	push   %rbp
    2ac2:	48 89 e5             	mov    %rsp,%rbp
    2ac5:	45 0f 5c ed          	subps  %xmm13,%xmm13
    2ac9:	90                   	nop
    2aca:	5d                   	pop    %rbp
    2acb:	c3                   	ret

0000000000002acc <core_cpu_nop_sub_zero_xmm14>:
    2acc:	55                   	push   %rbp
    2acd:	48 89 e5             	mov    %rsp,%rbp
    2ad0:	45 0f 5c f6          	subps  %xmm14,%xmm14
    2ad4:	90                   	nop
    2ad5:	5d                   	pop    %rbp
    2ad6:	c3                   	ret

0000000000002ad7 <core_cpu_nop_sub_zero_xmm15>:
    2ad7:	55                   	push   %rbp
    2ad8:	48 89 e5             	mov    %rsp,%rbp
    2adb:	45 0f 5c ff          	subps  %xmm15,%xmm15
    2adf:	90                   	nop
    2ae0:	5d                   	pop    %rbp
    2ae1:	c3                   	ret

0000000000002ae2 <core_cpu_nop_sub_zero_xmm2>:
    2ae2:	55                   	push   %rbp
    2ae3:	48 89 e5             	mov    %rsp,%rbp
    2ae6:	0f 5c d2             	subps  %xmm2,%xmm2
    2ae9:	90                   	nop
    2aea:	5d                   	pop    %rbp
    2aeb:	c3                   	ret

0000000000002aec <core_cpu_nop_sub_zero_xmm3>:
    2aec:	55                   	push   %rbp
    2aed:	48 89 e5             	mov    %rsp,%rbp
    2af0:	0f 5c db             	subps  %xmm3,%xmm3
    2af3:	90                   	nop
    2af4:	5d                   	pop    %rbp
    2af5:	c3                   	ret

0000000000002af6 <core_cpu_nop_sub_zero_xmm4>:
    2af6:	55                   	push   %rbp
    2af7:	48 89 e5             	mov    %rsp,%rbp
    2afa:	0f 5c e4             	subps  %xmm4,%xmm4
    2afd:	90                   	nop
    2afe:	5d                   	pop    %rbp
    2aff:	c3                   	ret

0000000000002b00 <core_cpu_nop_sub_zero_xmm5>:
    2b00:	55                   	push   %rbp
    2b01:	48 89 e5             	mov    %rsp,%rbp
    2b04:	0f 5c ed             	subps  %xmm5,%xmm5
    2b07:	90                   	nop
    2b08:	5d                   	pop    %rbp
    2b09:	c3                   	ret

0000000000002b0a <core_cpu_nop_sub_zero_xmm6>:
    2b0a:	55                   	push   %rbp
    2b0b:	48 89 e5             	mov    %rsp,%rbp
    2b0e:	0f 5c f6             	subps  %xmm6,%xmm6
    2b11:	90                   	nop
    2b12:	5d                   	pop    %rbp
    2b13:	c3                   	ret

0000000000002b14 <core_cpu_nop_sub_zero_xmm7>:
    2b14:	55                   	push   %rbp
    2b15:	48 89 e5             	mov    %rsp,%rbp
    2b18:	0f 5c ff             	subps  %xmm7,%xmm7
    2b1b:	90                   	nop
    2b1c:	5d                   	pop    %rbp
    2b1d:	c3                   	ret

0000000000002b1e <core_cpu_nop_sub_zero_xmm8>:
    2b1e:	55                   	push   %rbp
    2b1f:	48 89 e5             	mov    %rsp,%rbp
    2b22:	45 0f 5c c0          	subps  %xmm8,%xmm8
    2b26:	90                   	nop
    2b27:	5d                   	pop    %rbp
    2b28:	c3                   	ret

0000000000002b29 <core_cpu_nop_sub_zero_xmm9>:
    2b29:	55                   	push   %rbp
    2b2a:	48 89 e5             	mov    %rsp,%rbp
    2b2d:	45 0f 5c c9          	subps  %xmm9,%xmm9
    2b31:	90                   	nop
    2b32:	5d                   	pop    %rbp
    2b33:	c3                   	ret

0000000000002b34 <core_cpu_nop_sub_zero_zmm0>:
    2b34:	55                   	push   %rbp
    2b35:	48 89 e5             	mov    %rsp,%rbp
    2b38:	62 f1 7c 48 5c c0    	vsubps %zmm0,%zmm0,%zmm0
    2b3e:	90                   	nop
    2b3f:	5d                   	pop    %rbp
    2b40:	c3                   	ret

0000000000002b41 <core_cpu_nop_sub_zero_zmm1>:
    2b41:	55                   	push   %rbp
    2b42:	48 89 e5             	mov    %rsp,%rbp
    2b45:	62 f1 74 48 5c c9    	vsubps %zmm1,%zmm1,%zmm1
    2b4b:	90                   	nop
    2b4c:	5d                   	pop    %rbp
    2b4d:	c3                   	ret

0000000000002b4e <core_cpu_nop_sub_zero_zmm10>:
    2b4e:	55                   	push   %rbp
    2b4f:	48 89 e5             	mov    %rsp,%rbp
    2b52:	62 51 2c 48 5c d2    	vsubps %zmm10,%zmm10,%zmm10
    2b58:	90                   	nop
    2b59:	5d                   	pop    %rbp
    2b5a:	c3                   	ret

0000000000002b5b <core_cpu_nop_sub_zero_zmm11>:
    2b5b:	55                   	push   %rbp
    2b5c:	48 89 e5             	mov    %rsp,%rbp
    2b5f:	62 51 24 48 5c db    	vsubps %zmm11,%zmm11,%zmm11
    2b65:	90                   	nop
    2b66:	5d                   	pop    %rbp
    2b67:	c3                   	ret

0000000000002b68 <core_cpu_nop_sub_zero_zmm12>:
    2b68:	55                   	push   %rbp
    2b69:	48 89 e5             	mov    %rsp,%rbp
    2b6c:	62 51 1c 48 5c e4    	vsubps %zmm12,%zmm12,%zmm12
    2b72:	90                   	nop
    2b73:	5d                   	pop    %rbp
    2b74:	c3                   	ret

0000000000002b75 <core_cpu_nop_sub_zero_zmm13>:
    2b75:	55                   	push   %rbp
    2b76:	48 89 e5             	mov    %rsp,%rbp
    2b79:	62 51 14 48 5c ed    	vsubps %zmm13,%zmm13,%zmm13
    2b7f:	90                   	nop
    2b80:	5d                   	pop    %rbp
    2b81:	c3                   	ret

0000000000002b82 <core_cpu_nop_sub_zero_zmm14>:
    2b82:	55                   	push   %rbp
    2b83:	48 89 e5             	mov    %rsp,%rbp
    2b86:	62 51 0c 48 5c f6    	vsubps %zmm14,%zmm14,%zmm14
    2b8c:	90                   	nop
    2b8d:	5d                   	pop    %rbp
    2b8e:	c3                   	ret

0000000000002b8f <core_cpu_nop_sub_zero_zmm15>:
    2b8f:	55                   	push   %rbp
    2b90:	48 89 e5             	mov    %rsp,%rbp
    2b93:	62 51 04 48 5c ff    	vsubps %zmm15,%zmm15,%zmm15
    2b99:	90                   	nop
    2b9a:	5d                   	pop    %rbp
    2b9b:	c3                   	ret

0000000000002b9c <core_cpu_nop_sub_zero_zmm16>:
    2b9c:	55                   	push   %rbp
    2b9d:	48 89 e5             	mov    %rsp,%rbp
    2ba0:	62 a1 7c 40 5c c0    	vsubps %zmm16,%zmm16,%zmm16
    2ba6:	90                   	nop
    2ba7:	5d                   	pop    %rbp
    2ba8:	c3                   	ret

0000000000002ba9 <core_cpu_nop_sub_zero_zmm17>:
    2ba9:	55                   	push   %rbp
    2baa:	48 89 e5             	mov    %rsp,%rbp
    2bad:	62 a1 74 40 5c c9    	vsubps %zmm17,%zmm17,%zmm17
    2bb3:	90                   	nop
    2bb4:	5d                   	pop    %rbp
    2bb5:	c3                   	ret

0000000000002bb6 <core_cpu_nop_sub_zero_zmm18>:
    2bb6:	55                   	push   %rbp
    2bb7:	48 89 e5             	mov    %rsp,%rbp
    2bba:	62 a1 6c 40 5c d2    	vsubps %zmm18,%zmm18,%zmm18
    2bc0:	90                   	nop
    2bc1:	5d                   	pop    %rbp
    2bc2:	c3                   	ret

0000000000002bc3 <core_cpu_nop_sub_zero_zmm19>:
    2bc3:	55                   	push   %rbp
    2bc4:	48 89 e5             	mov    %rsp,%rbp
    2bc7:	62 a1 64 40 5c db    	vsubps %zmm19,%zmm19,%zmm19
    2bcd:	90                   	nop
    2bce:	5d                   	pop    %rbp
    2bcf:	c3                   	ret

0000000000002bd0 <core_cpu_nop_sub_zero_zmm2>:
    2bd0:	55                   	push   %rbp
    2bd1:	48 89 e5             	mov    %rsp,%rbp
    2bd4:	62 f1 6c 48 5c d2    	vsubps %zmm2,%zmm2,%zmm2
    2bda:	90                   	nop
    2bdb:	5d                   	pop    %rbp
    2bdc:	c3                   	ret

0000000000002bdd <core_cpu_nop_sub_zero_zmm20>:
    2bdd:	55                   	push   %rbp
    2bde:	48 89 e5             	mov    %rsp,%rbp
    2be1:	62 a1 5c 40 5c e4    	vsubps %zmm20,%zmm20,%zmm20
    2be7:	90                   	nop
    2be8:	5d                   	pop    %rbp
    2be9:	c3                   	ret

0000000000002bea <core_cpu_nop_sub_zero_zmm21>:
    2bea:	55                   	push   %rbp
    2beb:	48 89 e5             	mov    %rsp,%rbp
    2bee:	62 a1 54 40 5c ed    	vsubps %zmm21,%zmm21,%zmm21
    2bf4:	90                   	nop
    2bf5:	5d                   	pop    %rbp
    2bf6:	c3                   	ret

0000000000002bf7 <core_cpu_nop_sub_zero_zmm22>:
    2bf7:	55                   	push   %rbp
    2bf8:	48 89 e5             	mov    %rsp,%rbp
    2bfb:	62 a1 4c 40 5c f6    	vsubps %zmm22,%zmm22,%zmm22
    2c01:	90                   	nop
    2c02:	5d                   	pop    %rbp
    2c03:	c3                   	ret

0000000000002c04 <core_cpu_nop_sub_zero_zmm23>:
    2c04:	55                   	push   %rbp
    2c05:	48 89 e5             	mov    %rsp,%rbp
    2c08:	62 a1 44 40 5c ff    	vsubps %zmm23,%zmm23,%zmm23
    2c0e:	90                   	nop
    2c0f:	5d                   	pop    %rbp
    2c10:	c3                   	ret

0000000000002c11 <core_cpu_nop_sub_zero_zmm24>:
    2c11:	55                   	push   %rbp
    2c12:	48 89 e5             	mov    %rsp,%rbp
    2c15:	62 01 3c 40 5c c0    	vsubps %zmm24,%zmm24,%zmm24
    2c1b:	90                   	nop
    2c1c:	5d                   	pop    %rbp
    2c1d:	c3                   	ret

0000000000002c1e <core_cpu_nop_sub_zero_zmm25>:
    2c1e:	55                   	push   %rbp
    2c1f:	48 89 e5             	mov    %rsp,%rbp
    2c22:	62 01 34 40 5c c9    	vsubps %zmm25,%zmm25,%zmm25
    2c28:	90                   	nop
    2c29:	5d                   	pop    %rbp
    2c2a:	c3                   	ret

0000000000002c2b <core_cpu_nop_sub_zero_zmm26>:
    2c2b:	55                   	push   %rbp
    2c2c:	48 89 e5             	mov    %rsp,%rbp
    2c2f:	62 01 2c 40 5c d2    	vsubps %zmm26,%zmm26,%zmm26
    2c35:	90                   	nop
    2c36:	5d                   	pop    %rbp
    2c37:	c3                   	ret

0000000000002c38 <core_cpu_nop_sub_zero_zmm27>:
    2c38:	55                   	push   %rbp
    2c39:	48 89 e5             	mov    %rsp,%rbp
    2c3c:	62 01 24 40 5c db    	vsubps %zmm27,%zmm27,%zmm27
    2c42:	90                   	nop
    2c43:	5d                   	pop    %rbp
    2c44:	c3                   	ret

0000000000002c45 <core_cpu_nop_sub_zero_zmm28>:
    2c45:	55                   	push   %rbp
    2c46:	48 89 e5             	mov    %rsp,%rbp
    2c49:	62 01 1c 40 5c e4    	vsubps %zmm28,%zmm28,%zmm28
    2c4f:	90                   	nop
    2c50:	5d                   	pop    %rbp
    2c51:	c3                   	ret

0000000000002c52 <core_cpu_nop_sub_zero_zmm29>:
    2c52:	55                   	push   %rbp
    2c53:	48 89 e5             	mov    %rsp,%rbp
    2c56:	62 01 14 40 5c ed    	vsubps %zmm29,%zmm29,%zmm29
    2c5c:	90                   	nop
    2c5d:	5d                   	pop    %rbp
    2c5e:	c3                   	ret

0000000000002c5f <core_cpu_nop_sub_zero_zmm3>:
    2c5f:	55                   	push   %rbp
    2c60:	48 89 e5             	mov    %rsp,%rbp
    2c63:	62 f1 64 48 5c db    	vsubps %zmm3,%zmm3,%zmm3
    2c69:	90                   	nop
    2c6a:	5d                   	pop    %rbp
    2c6b:	c3                   	ret

0000000000002c6c <core_cpu_nop_sub_zero_zmm30>:
    2c6c:	55                   	push   %rbp
    2c6d:	48 89 e5             	mov    %rsp,%rbp
    2c70:	62 01 0c 40 5c f6    	vsubps %zmm30,%zmm30,%zmm30
    2c76:	90                   	nop
    2c77:	5d                   	pop    %rbp
    2c78:	c3                   	ret

0000000000002c79 <core_cpu_nop_sub_zero_zmm31>:
    2c79:	55                   	push   %rbp
    2c7a:	48 89 e5             	mov    %rsp,%rbp
    2c7d:	62 01 04 40 5c ff    	vsubps %zmm31,%zmm31,%zmm31
    2c83:	90                   	nop
    2c84:	5d                   	pop    %rbp
    2c85:	c3                   	ret

0000000000002c86 <core_cpu_nop_sub_zero_zmm4>:
    2c86:	55                   	push   %rbp
    2c87:	48 89 e5             	mov    %rsp,%rbp
    2c8a:	62 f1 5c 48 5c e4    	vsubps %zmm4,%zmm4,%zmm4
    2c90:	90                   	nop
    2c91:	5d                   	pop    %rbp
    2c92:	c3                   	ret

0000000000002c93 <core_cpu_nop_sub_zero_zmm5>:
    2c93:	55                   	push   %rbp
    2c94:	48 89 e5             	mov    %rsp,%rbp
    2c97:	62 f1 54 48 5c ed    	vsubps %zmm5,%zmm5,%zmm5
    2c9d:	90                   	nop
    2c9e:	5d                   	pop    %rbp
    2c9f:	c3                   	ret

0000000000002ca0 <core_cpu_nop_sub_zero_zmm6>:
    2ca0:	55                   	push   %rbp
    2ca1:	48 89 e5             	mov    %rsp,%rbp
    2ca4:	62 f1 4c 48 5c f6    	vsubps %zmm6,%zmm6,%zmm6
    2caa:	90                   	nop
    2cab:	5d                   	pop    %rbp
    2cac:	c3                   	ret

0000000000002cad <core_cpu_nop_sub_zero_zmm7>:
    2cad:	55                   	push   %rbp
    2cae:	48 89 e5             	mov    %rsp,%rbp
    2cb1:	62 f1 44 48 5c ff    	vsubps %zmm7,%zmm7,%zmm7
    2cb7:	90                   	nop
    2cb8:	5d                   	pop    %rbp
    2cb9:	c3                   	ret

0000000000002cba <core_cpu_nop_sub_zero_zmm8>:
    2cba:	55                   	push   %rbp
    2cbb:	48 89 e5             	mov    %rsp,%rbp
    2cbe:	62 51 3c 48 5c c0    	vsubps %zmm8,%zmm8,%zmm8
    2cc4:	90                   	nop
    2cc5:	5d                   	pop    %rbp
    2cc6:	c3                   	ret

0000000000002cc7 <core_cpu_nop_sub_zero_zmm9>:
    2cc7:	55                   	push   %rbp
    2cc8:	48 89 e5             	mov    %rsp,%rbp
    2ccb:	62 51 34 48 5c c9    	vsubps %zmm9,%zmm9,%zmm9
    2cd1:	90                   	nop
    2cd2:	5d                   	pop    %rbp
    2cd3:	c3                   	ret

0000000000002cd4 <core_cpu_nop_sub_zero>:
    2cd4:	55                   	push   %rbp
    2cd5:	48 89 e5             	mov    %rsp,%rbp
    2cd8:	48 81 ec 00 03 00 00 	sub    $0x300,%rsp
    2cdf:	48 8d 85 00 fd ff ff 	lea    -0x300(%rbp),%rax
    2ce6:	48 8d 15 13 35 00 00 	lea    0x3513(%rip),%rdx        # 6200 <__dso_handle+0x1b8>
    2ced:	b9 5e 00 00 00       	mov    $0x5e,%ecx
    2cf2:	48 89 c7             	mov    %rax,%rdi
    2cf5:	48 89 d6             	mov    %rdx,%rsi
    2cf8:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
    2cfb:	e8 90 f3 ff ff       	call   2090 <rand@plt>
    2d00:	48 63 c8             	movslq %eax,%rcx
    2d03:	48 89 c8             	mov    %rcx,%rax
    2d06:	48 d1 e8             	shr    %rax
    2d09:	48 ba 99 5c 41 4c ae 	movabs $0x572620ae4c415c99,%rdx
    2d10:	20 26 57 
    2d13:	48 f7 e2             	mul    %rdx
    2d16:	48 89 d0             	mov    %rdx,%rax
    2d19:	48 c1 e8 04          	shr    $0x4,%rax
    2d1d:	48 6b d0 5e          	imul   $0x5e,%rax,%rdx
    2d21:	48 89 c8             	mov    %rcx,%rax
    2d24:	48 29 d0             	sub    %rdx,%rax
    2d27:	89 45 fc             	mov    %eax,-0x4(%rbp)
    2d2a:	8b 45 fc             	mov    -0x4(%rbp),%eax
    2d2d:	48 98                	cltq
    2d2f:	48 8b 84 c5 00 fd ff 	mov    -0x300(%rbp,%rax,8),%rax
    2d36:	ff 
    2d37:	ff d0                	call   *%rax
    2d39:	90                   	nop
    2d3a:	c9                   	leave
    2d3b:	c3                   	ret

0000000000002d3c <core_cpu_nop>:
    2d3c:	55                   	push   %rbp
    2d3d:	48 89 e5             	mov    %rsp,%rbp
    2d40:	48 83 ec 20          	sub    $0x20,%rsp
    2d44:	48 8d 05 9c fa ff ff 	lea    -0x564(%rip),%rax        # 27e7 <core_cpu_nop_add_zero>
    2d4b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2d4f:	48 8d 05 7e ff ff ff 	lea    -0x82(%rip),%rax        # 2cd4 <core_cpu_nop_sub_zero>
    2d56:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2d5a:	48 8d 05 38 f4 ff ff 	lea    -0xbc8(%rip),%rax        # 2199 <core_cpu_nop_random_nop>
    2d61:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    2d65:	e8 26 f3 ff ff       	call   2090 <rand@plt>
    2d6a:	48 63 c8             	movslq %eax,%rcx
    2d6d:	48 ba ab aa aa aa aa 	movabs $0xaaaaaaaaaaaaaaab,%rdx
    2d74:	aa aa aa 
    2d77:	48 89 c8             	mov    %rcx,%rax
    2d7a:	48 f7 e2             	mul    %rdx
    2d7d:	48 d1 ea             	shr    %rdx
    2d80:	48 89 d0             	mov    %rdx,%rax
    2d83:	48 01 c0             	add    %rax,%rax
    2d86:	48 01 d0             	add    %rdx,%rax
    2d89:	48 29 c1             	sub    %rax,%rcx
    2d8c:	48 89 ca             	mov    %rcx,%rdx
    2d8f:	89 55 fc             	mov    %edx,-0x4(%rbp)
    2d92:	8b 45 fc             	mov    -0x4(%rbp),%eax
    2d95:	48 98                	cltq
    2d97:	48 8b 44 c5 e0       	mov    -0x20(%rbp,%rax,8),%rax
    2d9c:	ff d0                	call   *%rax
    2d9e:	90                   	nop
    2d9f:	c9                   	leave
    2da0:	c3                   	ret

0000000000002da1 <core_cpu_nop_safe>:
    2da1:	55                   	push   %rbp
    2da2:	48 89 e5             	mov    %rsp,%rbp
    2da5:	48 83 ec 20          	sub    $0x20,%rsp
    2da9:	48 8d 05 37 fa ff ff 	lea    -0x5c9(%rip),%rax        # 27e7 <core_cpu_nop_add_zero>
    2db0:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2db4:	48 8d 05 19 ff ff ff 	lea    -0xe7(%rip),%rax        # 2cd4 <core_cpu_nop_sub_zero>
    2dbb:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2dbf:	48 8d 05 d3 f3 ff ff 	lea    -0xc2d(%rip),%rax        # 2199 <core_cpu_nop_random_nop>
    2dc6:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    2dca:	e8 c1 f2 ff ff       	call   2090 <rand@plt>
    2dcf:	48 63 c8             	movslq %eax,%rcx
    2dd2:	48 ba ab aa aa aa aa 	movabs $0xaaaaaaaaaaaaaaab,%rdx
    2dd9:	aa aa aa 
    2ddc:	48 89 c8             	mov    %rcx,%rax
    2ddf:	48 f7 e2             	mul    %rdx
    2de2:	48 d1 ea             	shr    %rdx
    2de5:	48 89 d0             	mov    %rdx,%rax
    2de8:	48 01 c0             	add    %rax,%rax
    2deb:	48 01 d0             	add    %rdx,%rax
    2dee:	48 29 c1             	sub    %rax,%rcx
    2df1:	48 89 ca             	mov    %rcx,%rdx
    2df4:	89 55 fc             	mov    %edx,-0x4(%rbp)
    2df7:	8b 45 fc             	mov    -0x4(%rbp),%eax
    2dfa:	48 98                	cltq
    2dfc:	48 8b 44 c5 e0       	mov    -0x20(%rbp,%rax,8),%rax
    2e01:	ff d0                	call   *%rax
    2e03:	90                   	nop
    2e04:	c9                   	leave
    2e05:	c3                   	ret

0000000000002e06 <main>:
    2e06:	55                   	push   %rbp
    2e07:	48 89 e5             	mov    %rsp,%rbp
    2e0a:	48 83 ec 10          	sub    $0x10,%rsp
    2e0e:	bf 00 00 00 00       	mov    $0x0,%edi
    2e13:	e8 58 f2 ff ff       	call   2070 <time@plt>
    2e18:	89 c7                	mov    %eax,%edi
    2e1a:	e8 41 f2 ff ff       	call   2060 <srand@plt>
    2e1f:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    2e26:	eb 22                	jmp    2e4a <main+0x44>
    2e28:	b8 00 00 00 00       	mov    $0x0,%eax
    2e2d:	e8 b5 f9 ff ff       	call   27e7 <core_cpu_nop_add_zero>
    2e32:	b8 00 00 00 00       	mov    $0x0,%eax
    2e37:	e8 5d f3 ff ff       	call   2199 <core_cpu_nop_random_nop>
    2e3c:	bf 02 00 00 00       	mov    $0x2,%edi
    2e41:	e8 3a f2 ff ff       	call   2080 <sleep@plt>
    2e46:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    2e4a:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
    2e4e:	7e d8                	jle    2e28 <main+0x22>
    2e50:	90                   	nop
    2e51:	90                   	nop
    2e52:	c9                   	leave
    2e53:	c3                   	ret

Disassembly of section .fini:

0000000000002e54 <_fini>:
    2e54:	48 83 ec 08          	sub    $0x8,%rsp
    2e58:	48 83 c4 08          	add    $0x8,%rsp
    2e5c:	c3                   	ret
