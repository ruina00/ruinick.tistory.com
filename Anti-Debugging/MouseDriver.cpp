#include <stdio.h>
#include <io.h>
 
int anti_debug()
{
    char strPath[] = { "C:\\Windows\\system32\\drivers\\vmmouse.sys" };
     
    if( !access( strPath, 0) )
		return 1;
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
