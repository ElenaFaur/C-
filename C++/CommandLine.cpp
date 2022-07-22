#include<sstream>
#include "CommandLine.h"
#include<cstring>// strchr
#include<cstdio>
#include<stdlib.h>
#include<string.h>
//#define _CRT_SECURE_NO_WARNINGS
using std::stringstream;

//simulating a more complicated header
#define FALSE false;
#define TRUE true;

bool CommandLine::oldway(char *lpCmdLine)
{
    char *ptr;

    ptr=strchr(lpCmdLine,' ');
    if(!ptr)
        return FALSE;
    *ptr=0;
    strncpy(szDriverName,lpCmdLine,32);
    *ptr=' ';
    while(*ptr && isspace(*ptr))
        ptr++;
    if(!*ptr)
        return FALSE;
    sprintf(lpszPipename,"\\\\.\\pipe\\%s",ptr);

    return TRUE;
}
bool CommandLine::newway(string const & CommandLine)
{
    stringstream ss(CommandLine);
    ss>>DriverName>>Pipename;

    if(DriverName==""|| Pipename=="")
        return false;
    Pipename=R"(\\.\pipe\)" + Pipename; //R=backslash
    return true;
}