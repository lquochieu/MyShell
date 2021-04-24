#include <iostream>
#include <windows.h>
#include <string>
#include<ctime>
using namespace std;

void print(const string& s){
    cout << s;
}

void openProcess(const string& s){
    STARTUPINFO si = {sizeof (STARTUPINFO)};;
    PROCESS_INFORMATION pi;
    LPSTR cString = strdup( s.c_str() );
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    CreateProcess(cString,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    WaitForSingleObject(pi.hProcess,INFINITE);//INFINITE
    TerminateProcess(pi.hProcess, 0);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
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