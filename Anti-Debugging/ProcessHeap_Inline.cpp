#include <windows.h>
#include <stdio.h>
 
BOOL anti_debug()
{
	BOOL result = FALSE;
	void *pHeap;
	DWORD Flags, ForceFlags;
 
	__asm
	{
		mov eax, fs:[0x30]				// PEB Address
		mov eax, dword ptr [eax+0x18]	// HEAP Address
		mov ecx, dword ptr [eax+0xc]	// HEAP.Flags
		mov Flags, ecx
		mov edx, dword ptr [eax+0x10]	// HEAP.ForceFlags
		mov ForceFlags, edx
	}
	
	result = (Flags & 0xFFFFFF00) || (ForceFlags & 0xFFFFFF00);
	return result;
}
 
int main(int argc, char **argv)
{
	if(anti_debug())
		printf("Debugger Detected\n");
	else
		printf("No Debugger...\n");
	return 0;
}
