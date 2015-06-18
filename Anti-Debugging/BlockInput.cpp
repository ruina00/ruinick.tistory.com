#include <stdio.h>
#include <windows.h>
#include <Winable.h>
 
int main()
{
	char str[100];
 
	BlockInput(TRUE);
	printf("Input String: ");
	scanf("%s", str);
	return 0;
}
