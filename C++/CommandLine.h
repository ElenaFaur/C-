#pragma once
#include<iostream>
#include<string>
using std::string;

class CommandLine
{
    private:
        char szDriverName[32];
        char lpszPipename[256];
        string DriverName;
        string Pipename;
    public:
        bool oldway(char *lpCmdLine);
        bool newway(string const& CommandLine);
};