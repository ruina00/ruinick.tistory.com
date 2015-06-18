#include <stdio.h>
#include <windows.h>
 
int anti_debug(){
	int rc=0;
	__try
    {
	__asm
        {
            mov    eax, 'VMXh'
            mov    ebx, 0; 
            mov    ecx, 0xA 
            mov    edx, 'VX' 
 
            in     eax, dx; 
            cmp    ebx, 'VMXh'
            jne       notVmware
            jmp    isVmware
            notVmware:
            mov rc, 0
            jmp done
            isVmware:
            mov    rc, eax 
            done:
 
        }
	}
	 __except(EXCEPTION_EXECUTE_HANDLER)
    {
        rc = 0;
    }
	return rc;
}
int main(int argc, char **argv)
{
	if(anti_debug())
		printf("VM Detected\n");
	else
		printf("No VM...\n");
	
	return 0;
}
