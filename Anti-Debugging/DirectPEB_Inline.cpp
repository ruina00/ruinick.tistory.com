#include <windows.h>
#include <stdio.h>
 
int main(int argc, char **argv)
{
	unsigned long *p;
 
	__asm
	{
		mov eax, fs:[0x30]
		mov p, eax
	}
	printf("PEB Address Is : %p\n", p);
	return 0;
}
