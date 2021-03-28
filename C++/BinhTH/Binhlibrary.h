#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void print(const string& s){
    cout << s;
}

void openProcess(const string& s){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    LPSTR cString = strdup( s.c_str() );
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    CreateProcess(cString,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    WaitForSingleObject(pi.hProcess,10000);//INFINITE
    TerminateProcess(pi.hProcess, 0);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}