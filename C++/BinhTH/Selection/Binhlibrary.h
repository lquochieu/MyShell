#include <iostream>
#include <windows.h>
#include <string>
#include<ctime>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
using namespace std;

void print(const string& s){
    cout << s;
}

void openInBackOrFore(const string& s){
    void openProcessInForeGround(const string& s);
    void openProcessInBackGround(const string& s);
    cout << "Type 1 to open this process in background mode, otherwise open in foreground mode" << endl;
    string choice;
    getline(cin, choice);
    if (choice.compare("1") == 0){
        openProcessInBackGround(s);
    }
    else{
        openProcessInForeGround(s);
    }
}

void openProcessInForeGround(const string& s){
    STARTUPINFO si = {sizeof (STARTUPINFO)};    // lpStartupInfo
    PROCESS_INFORMATION pi;     // lpProcessInformation
    // cpp string must be modified to use in c
    LPSTR cString = strdup( s.c_str() );
    ZeroMemory(&si, sizeof(si));    // fill this block with zeros
    si.cb = sizeof(si);
    CreateProcess(cString,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    WaitForSingleObject(pi.hProcess,INFINITE);// INFINITE
    // hProcess: The handle is used to specify the process in all functions that perform operations on the process object.
    TerminateProcess(pi.hProcess, 0);   
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void openProcessInBackGround(const string& s){
    STARTUPINFO si = {sizeof (STARTUPINFO)};    // lpStartupInfo
    PROCESS_INFORMATION pi;     // lpProcessInformation
    // cpp string must be modified to use in c
    ZeroMemory(&si, sizeof(si));    // fill this block with zeros
    si.cb = sizeof(si);
    LPSTR cString = strdup( s.c_str() );
    CreateProcess(cString,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}

int time()
{
  int sec_prev=0;
  while(1)
  {
    int seconds, minutes, hours;
    string str;

    //storing total seconds
    time_t total_seconds=time(0);

    //getting values of seconds, minutes and hours
    struct tm* ct=localtime(&total_seconds);

    seconds=ct->tm_sec;
    minutes=ct->tm_min;
    hours=ct->tm_hour;

    //converting it into 12 hour format
    if(hours>=12)
        str="PM";
    else
        str="AM";
    hours=hours>12?hours-12:hours;  


    //printing the result
    if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
    {
        cout << '\r';
        cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str;
    }

    sec_prev=seconds;

    }
}

void dir() {
    char s[PATH_MAX];
    // printing current working directory
    printf("%s\n", getcwd(s, 100));
}
