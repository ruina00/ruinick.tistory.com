#include <windows.h>
#include <stdio.h>
 
BOOL anti_debug()
{
	TCHAR pathname[512];
	TCHAR * filename;
	GetModuleFileName(0, pathname, 512);
	filename = wcsrchr(pathname, L'\\');
	if (wcsncmp(filename, L"\\%s%s.exe", 10) == 0) {
		return 1;
	} else {
		return 0;
	}
}
 
int main(int argc, char **argv)
{
	if(anti_debug())
		printf("Debugger Detected\n");
	else
		printf("No Debugger...\n");
	system("pause");
	return 0;
}
