format PE
entry start

include 'win32axp.inc'

section '.data' data readable writeable
	fp dd 0
	sum dd 0
	formatstring db "%d", 13, 10, 0

section '.text' code readable executable
	start:
		cinvoke fopen, "input1", "r"
		mov [fp], eax
	reset:
		cinvoke getc, [fp]
		cmp eax, -1
		je fin
		cmp eax, 40
		je incr
	decr:
		dec [sum]
		jmp reset
	incr:
		inc [sum]
		jmp reset
	fin:
		cinvoke printf, formatstring, [sum]
		invoke ExitProcess, 0

section '.idata' import data readable

        library msvcrt, 'msvcrt.dll',\
                kernel32, 'kernel32.dll'

	import msvcrt, printf, 'printf',\
		getc, 'getc',\
		fopen, 'fopen'

	import kernel32, ExitProcess, 'ExitProcess'
