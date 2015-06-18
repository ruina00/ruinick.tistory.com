#include <windows.h>
#include <stdio.h>
 
BOOL anti_debug()
{
	char buffer[100];
	HKEY hKey;
	int i=0;
	DWORD len=sizeof(buffer);
    RegOpenKeyEx (HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\Disk\\Enum", 0L, KEY_READ , &hKey);
    RegQueryValueEx(hKey,"0",NULL,NULL,(LPBYTE)&buffer,&len);
    RegCloseKey(hKey);
	if (strstr(buffer, "VMware"))
    {
        return 1;
    }
    return 0;
 
}
 
int main(int argc, char **argv)
{
	if(anti_debug())
		printf("VM Detected\n");
	else
		printf("No VM...\n");
	return 0;
}
