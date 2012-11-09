// krtvm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "disasm/disasm.h"

int _tmain(int argc, _TCHAR* argv[])
{
  int i,j,n;
  ulong l;
  char *pasm;
  t_disasm da;
  t_asmmodel am;
  char s[TEXTLEN],errtext[TEXTLEN];

  // Demonstration of Disassembler.
  printf("Disassembler:\n");

  // Quickly determine size of command.
  l=Disasm("\x81\x05\xE0\x5A\x47\x00\x01\x00\x00\x00\x11\x22\x33\x44\x55\x66",
    10,0x400000,&da,DISASM_SIZE);
  printf("Size of command = %i bytes\n",l);

  // ADD [475AE0],1 MASM mode, lowercase, don't show default segment
  ideal=0; lowercase=1; putdefseg=0;
  l=Disasm("\x81\x05\xE0\x5A\x47\x00\x01\x00\x00\x00",
    10,0x400000,&da,DISASM_CODE);
  printf("%3i  %-24s  %-24s   (MASM)\n",l,da.dump,da.result);

  // ADD [475AE0],1 IDEAL mode, uppercase, show default segment
  ideal=1; lowercase=0; putdefseg=1;
  l=Disasm("\x81\x05\xE0\x5A\x47\x00\x01\x00\x00\x00",
    10,0x400000,&da,DISASM_CODE);
  printf("%3i  %-24s  %-24s   (IDEAL)\n",l,da.dump,da.result);
  getchar();
  return 0;


}

