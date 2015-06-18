#include <stdio.h>
#include <windows.h>
 
void self_debug()
{
	char result = FALSE;
	char szCmdLine[MAX_PATH];
	char szCurrPath[MAX_PATH];
	char pid_str[12];
 
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb= sizeof(si);
 
	GetModuleFileName(NULL, szCurrPath, sizeof(szCurrPath));
	itoa(GetCurrentProcessId(), pid_str, 10);
	sprintf(szCmdLine, "%s %s", szCurrPath, pid_str);
	printf("%s\n", szCmdLine);
	CreateProcessA(NULL, szCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	printf("Wait Child Process...\n");
	WaitForSingleObject(pi.hProcess, INFINITE);
	return;
}
 
void anti_debug(DWORD pid)
{
	BOOL success;
	HANDLE hProcess;
 
	MessageBox(NULL, "Checking..\n", "Self_Debugging", MB_OK);
 
	success = DebugActiveProcess(pid);
	if(!success)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		TerminateProcess(hProcess, -1);
	}
	DebugActiveProcessStop(pid);
}
 
int main(int argc, char **argv)
{
	if(argc < 2)
		self_debug();
	else
	{
		anti_debug(atoi(argv[1]));
		return 1;
	}
 
	printf("No Debugger...\n");
	return 0;
}
