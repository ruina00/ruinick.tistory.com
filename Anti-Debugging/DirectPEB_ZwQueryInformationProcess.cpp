#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include <Winternl.h>
 
typedef DWORD (WINAPI *PFZWQUERYINFORMATIONPROCESS) (
	HANDLE		ProcessHandle,
	DWORD		ProcessInformationClass,	// Origianl : _PROCESS_INFORMATION_CLASS
	PVOID		ProcessInformation,
	ULONG		ProcessInformationLength,
	PULONG		ReturnLength
);
 
int main(int argc, char **argv)
{
	PROCESS_BASIC_INFORMATION pPib;
 
	PFZWQUERYINFORMATIONPROCESS pfZwQueryInformationProcess;
	HMODULE h_ntdll = GetModuleHandle("ntdll.dll");
	pfZwQueryInformationProcess = (PFZWQUERYINFORMATIONPROCESS)GetProcAddress(h_ntdll, "ZwQueryInformationProcess");
	pfZwQueryInformationProcess(GetCurrentProcess(), ProcessBasicInformation, &pPib, sizeof(PROCESS_BASIC_INFORMATION), 0);	// 0x0 : ProcessBasicInformation
	printf("PEB Address Is : %p\n", pPib.PebBaseAddress);
	return 0;
}
