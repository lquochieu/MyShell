#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <tlhelp32.h> 
#include<vector>
#include <tchar.h>
#include<debugapi.h>
#include <processthreadsapi.h>
#include <string>
#include <thread>
#include <chrono>
#include "Bibrary.h"
#include<ctime>

using namespace std;

#define MAX_NAME_LEN 20


int main(){
    string command;
    void time1();
    void date();

    while(true){
        cout << endl;
        cout << ">> ";
        getline(cin, command);

        if (command.compare("help") == 0){
            cout << "list:";
        }

        else if (command.compare("exit") == 0){
            printf("Bye my friend, see you later!");
            this_thread::sleep_for(chrono::milliseconds(800));
            exit(0);
        }

        else if (command.compare("calc") == 0){
            openProcessInBackGround("C:\\windows\\system32\\calc.exe");
        }

        else if (command.compare("notepad") == 0){
            openInBackOrFore("C:\\Windows\\notepad.exe");
        }
        else if (command.compare("dir") == 0){
            dir();
        }

        else if (command.rfind("cd ") == 0){
            string temp = command.substr(3);
            if (temp.compare("..") == 0){
                chdir("..");
            }
            else if (temp.compare("-l") == 0){
                listOfCurrent();
            }
            else{
                cd(temp);
            }
        }

        else if (command.length() > 4 && command[0] == 'k' && command[1] == 'i' && command[2] == 'l' & command[3] == 'l')
        {
            if (command.length() == 7 && command[5] == '-' && command[6] == '1')
            {
                kill_All();
            }
            else
            {
                string s = "";
                for (int i = 4; i <= command.length(); ++i)
                {
                    s += command[i];
                }
                kill(s);
            }
        }

        else if (command.compare("list") == 0){
            list1();
        }

        else if (command.compare("time") == 0){
            HANDLE h1;   
            DWORD ThreadId;
            h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)time1, NULL, 0, &ThreadId);
            cin.get();
            TerminateThread(h1, 0);
            CloseHandle(h1);
        }

        else if (command.compare("date") == 0){
            HANDLE h1;   
            DWORD ThreadId;
            h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)date, NULL, 0, &ThreadId);
            cin.get();
            TerminateThread(h1, 0);
            CloseHandle(h1);
        }

        else if (command.compare("clear") == 0){
            system("cls");
        }

        else {
            printf("Illegal command!");
        }



    }

    cout << endl;
    system("pause");
}

void time1()
{
    int sec_prev=0; 
    while(1)
    {
        int seconds, minutes, hours;
        string str;

        //storing total seconds
        time_t total_seconds=time(0);

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds);

        seconds=ct->tm_sec;
        minutes=ct->tm_min;
        hours=ct->tm_hour;

        //converting it into 12 hour format
        /*if(hours>=12)
            str="PM";
        else
            str="AM";
        hours=hours>12?hours-12:hours;  */


        //printing the result
        if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
        {
            cout << '\r';
            cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str;
        }

        sec_prev=seconds;

    }
}

void date()
{
    int sec_prev=0; //save previous second
    while(1){
        int seconds, minutes, hours;
        int days, months, years;
        string str;

        //storing total seconds
        time_t total_seconds=time(0);

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds);

        seconds=ct->tm_sec;
        minutes=ct->tm_min;
        hours=ct->tm_hour;
        days = ct->tm_mday;
        months = ct->tm_mon + 1;
        years = ct ->tm_year + 1900;    //in struct ct, tm_year beginning at 1900

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
            cout<<'\t' <<(days<10?"0":"") << days <<"/" << (months<10?"0":"") << months << "/" << (years<10?"0":"") << years;
        }

        sec_prev=seconds;

    }
}