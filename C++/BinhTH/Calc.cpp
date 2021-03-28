#include <windows.h>

#include <stdio.h>
int main(){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    CreateProcess("D:/Projects/CPP Projects/Shell/.vscode/dir.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    WaitForSingleObject(pi.hProcess,10000);//INFINITE
    TerminateProcess(pi.hProcess, 0);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    system("pause");    
    return 0;
}