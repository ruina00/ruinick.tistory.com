#include <windows.h>
#include <stdio.h>
 
BOOL anti_debug()
{
	HKEY hKey;
	int i=0;
 
    if( RegOpenKeyEx (HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Enum\\IDE\\DiskVMware_Virtual_IDE_Hard_Drive___________00000001", 0L, KEY_READ , &hKey) )
        return 0;
    return 1;
 
}
 
int main(int argc, char **argv)
{
	if(anti_debug())
		printf("VM Detected\n");
	else
		printf("No VM...\n");
	return 0;
}
