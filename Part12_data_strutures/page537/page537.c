#include <stdio.h>
#include <stdlib.h>

#define NDCNT 3

int main(){
   struct node{
   char ch;   
   struct node *p;
   };

   struct node *pN = NULL,*tmp = NULL;
   pN = calloc(NDCNT,sizeof(struct node));
   pN->ch = 'a';
   tmp = pN;
   pN++;
   tmp->p = pN;

   pN->ch = 'b';
   tmp = pN;
   pN++;
   tmp->p = pN;

   pN->ch = 'c';
   pN->p = NULL;
  
   return 0;
}

/* 
aikidance@aikidance:~/C_Deytel$ cd Part12_data_strutures/page537
aikidance@aikidance:~/C_Deytel/Part12_data_strutures/page537$ cmake --build . --config Debug -- VERBOSE=1
aikidance@aikidance:~/C_Deytel/Part12_data_strutures/page537$ gdb ./page537
gef➤b main
gef➤run
---

aikidance@aikidance:~/C_Deytel/Part12_data_strutures/page537$ gdb ./page537
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
[ Legend: Modified register | Code | Heap | Stack | String ]
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── registers ────
$rax   : 0x0000555555555149  →  <main+0000> endbr64 
$rbx   : 0x00007fffffffd2d8  →  0x00007fffffffd5e7  →  "/home/aikidance/C_Deytel/Part12_data_strutures/pag[...]"
$rcx   : 0x0000555555557dc0  →  0x0000555555555100  →  <__do_global_dtors_aux+0000> endbr64 
$rdx   : 0x00007fffffffd2e8  →  0x00007fffffffd626  →  "SHELL=/bin/bash"
$rsp   : 0x00007fffffffd1a0  →  0x00007fffffffd290  →  0x0000555555555060  →  <_start+0000> endbr64 
$rbp   : 0x00007fffffffd1b0  →  0x00007fffffffd250  →  0x00007fffffffd2b0  →  0x0000000000000000
$rsi   : 0x00007fffffffd2d8  →  0x00007fffffffd5e7  →  "/home/aikidance/C_Deytel/Part12_data_strutures/pag[...]"
$rdi   : 0x1               
$rip   : 0x0000555555555155  →  <main+000c> mov QWORD PTR [rbp-0x10], 0x0
$r8    : 0x0               
$r9    : 0x00007ffff7fca380  →  <_dl_fini+0000> endbr64 
$r10   : 0x00007fffffffced0  →  0x0000000000800000
$r11   : 0x203             
$r12   : 0x1               
$r13   : 0x0               
$r14   : 0x0000555555557dc0  →  0x0000555555555100  →  <__do_global_dtors_aux+0000> endbr64 
$r15   : 0x00007ffff7ffd000  →  0x00007ffff7ffe2e0  →  0x0000555555554000  →   jg 0x555555554047
$eflags: [zero carry PARITY adjust sign trap INTERRUPT direction overflow resume virtualx86 identification]
$cs: 0x33 $ss: 0x2b $ds: 0x00 $es: 0x00 $fs: 0x00 $gs: 0x00 
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── stack ────
0x00007fffffffd1a0│+0x0000: 0x00007fffffffd290  →  0x0000555555555060  →  <_start+0000> endbr64          ← $rsp
0x00007fffffffd1a8│+0x0008: 0x00007fffffffd2d8  →  0x00007fffffffd5e7  →  "/home/aikidance/C_Deytel/Part12_data_strutures/pag[...]"
0x00007fffffffd1b0│+0x0010: 0x00007fffffffd250  →  0x00007fffffffd2b0  →  0x0000000000000000     ← $rbp
0x00007fffffffd1b8│+0x0018: 0x00007ffff7c2a1ca  →  <__libc_start_call_main+007a> mov edi, eax
0x00007fffffffd1c0│+0x0020: 0x00007fffffffd200  →  0x0000555555557dc0  →  0x0000555555555100  →  <__do_global_dtors_aux+0000> endbr64 
0x00007fffffffd1c8│+0x0028: 0x00007fffffffd2d8  →  0x00007fffffffd5e7  →  "/home/aikidance/C_Deytel/Part12_data_strutures/pag[...]"
0x00007fffffffd1d0│+0x0030: 0x0000000155554040
0x00007fffffffd1d8│+0x0038: 0x0000555555555149  →  <main+0000> endbr64 
────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── code:x86:64 ────
   0x55555555514d <main+0004>      push   rbp
   0x55555555514e <main+0005>      mov    rbp, rsp
   0x555555555151 <main+0008>      sub    rsp, 0x10
●→ 0x555555555155 <main+000c>      mov    QWORD PTR [rbp-0x10], 0x0
   0x55555555515d <main+0014>      mov    QWORD PTR [rbp-0x8], 0x0
   0x555555555165 <main+001c>      mov    esi, 0x10
   0x55555555516a <main+0021>      mov    edi, 0x3
   0x55555555516f <main+0026>      call   0x555555555050 <calloc@plt>
   0x555555555174 <main+002b>      mov    QWORD PTR [rbp-0x10], rax
────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── source:/home/aikidance[...]page537.c+12 ────
      7     struct node{
      8     char ch;
      9     struct node *p;
     10     };
     11  
 →   12     struct node *pN = NULL,*tmp = NULL;
     13     pN = calloc(NDCNT,sizeof(struct node));
     14     pN->ch = 'a';
     15     tmp = pN;
     16     pN++;
     17     tmp->p = pN;
────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── threads ────
[#0] Id 1, Name: "page537", stopped 0x555555555155 in main (), reason: BREAKPOINT
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── trace ────
[#0] 0x555555555155 → main()
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
gef➤  

*/