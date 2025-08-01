;; File stud_io.inc for both Linux and FreeBSD.
;;
;; Copyright (c) Andrey Vikt. Stolyarov, 2009, 2015, 2017, 2021
;;
;; I, the author, hereby grant everyone the right to use this file for any
;; purpose, in any manner, in it's original or modified form, provided that
;; modified versions are clearly marked as such AND the original author's
;; copyright notice is kept along with the other authors' copyright notices
;; as appropriate within the file.
;;
;; Only the file as such must retain the copyright notice.  Programs created
;; using this file (e.g. binaries) don't need to have any mentions of the fact
;; this file was used to create them.
;;
;; This file is provided as is, with absolutely NO WARRANTY, and this
;; statement must be taken literally: "NO" means "NO", period.  Please be
;; sure to search Internet for various types of warranty (e.g., implied,
;; hidden, etc) and take into account that you don't have them all.
;;

%define STUD_IO_LINUX
;%define STUD_IO_FREEBSD

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; system dependend part

%ifdef STUD_IO_LINUX

; generic 3-param syscall
%macro _syscall_3 4
	push edx
	push ecx
	push ebx ; it is senseless to save eax as it holds the return
	push %1
	push %2
	push %3
	push %4
	pop edx
	pop ecx
	pop ebx
	pop eax
	int 0x80
	pop ebx
	pop ecx
	pop edx
%endmacro

; syscall_exit is the only syscall we use that has 1 parameter
%macro _syscall_exit 1
	mov ebx, %1	; exit code
	mov eax, 1	; 1 = sys_exit
	int 0x80
%endmacro

%elifdef STUD_IO_FREEBSD

; generic 3-param syscall
%macro _syscall_3 4
	push	%4
	push	%3
	push	%2
	mov	eax, %1
	push	eax
	int	0x80
	add	esp, 16
%endmacro

%macro _syscall_exit 1
	push	%1	; exit code
	mov	eax, 1	; 1 = sys_exit
	push	eax
	int	0x80
	; no cleanup - this will never return anyway
%endmacro

%else
%error You must define either STUD_IO_LINUX or STUD_IO_FREEBSD
%endif

;; system dependent part ends here
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; %1: descriptor   %2: buffer addr   %3: buffer length
; output: eax: read bytes
%macro _syscall_read 3
	_syscall_3 3,%1,%2,%3
%endmacro

; %1: descriptor   %2: buffer addr   %3: buffer length
; output: eax: written bytes
%macro _syscall_write 3
	_syscall_3 4,%1,%2,%3
%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%macro 	PRINT 1
	pusha
	pushf
	jmp %%astr
%%str	db	%1
%%strln	equ	$-%%str
%%astr:	_syscall_write 1, %%str, %%strln
	popf
	popa
%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%macro	PUTCHAR 1
	pusha
	pushf
%ifstr %1
	mov	al, %1
%elifnum %1
	mov	al, %1
%elifidni %1,al
	nop
%elifidni %1,ah
	mov	al, ah
%elifidni %1,bl
	mov	al, bl
%elifidni %1,bh
	mov	al, bh
%elifidni %1,cl
	mov	al, cl
%elifidni %1,ch
	mov	al, ch
%elifidni %1,dl
	mov	al, dl
%elifidni %1,dh
	mov	al, dh
%else
	mov	al, %1  ; let's hope it is a memory location such as [var]
%endif
	sub	esp, 4  ; reserve memory for buffer
	mov	edi, esp
	mov	[edi], al
	_syscall_write 1, edi, 1
	add	esp, 4
	popf
	popa
%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%macro	GETCHAR 0
	pushf
	push	edi
	sub	esp, 4
	mov	edi, esp
	_syscall_read 0, edi, 1
	cmp	eax, 1
	jne	%%eof_reached
	xor	eax, eax
	mov	al, [edi]
	jmp	%%gcquit
%%eof_reached:
	xor	eax, eax
	not	eax 		; eax := -1
%%gcquit:
	add	esp, 4
	pop	edi
	popf
%endmacro

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%macro FINISH 0-1 0
	_syscall_exit %1
%endmacro