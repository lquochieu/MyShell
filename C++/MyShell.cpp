#include <windows.h>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <thread>
#include <chrono>
#include <tlhelp32.h>
#include <tchar.h>
#include <debugapi.h>
#include <processthreadsapi.h>
#include "BinhTH/Bibrary.h"
#include "CurrentDir.h"
#include "messenger.h"
#include "concurentCommandBuilder.h"

using namespace std;

const string EXIT_COMMAND = "exit";
string currentDirectory;

void runable(string command)
{
    if (command.compare("help") == 0)
    {
        help();
    }
    else if (command.compare("exit") == 0)
    {
        GOODBYE;
        printf("Sending signal to kill all child processes ...\n");
        kill_All();
        this_thread::sleep_for(chrono::milliseconds(800));
        exit(0);
    }
    else if (command.compare("calc") == 0)
    {
        print("Hello\n");
        openInBackOrFore("c:/windows/system32/calc.exe");
    }
    else if (command.compare("dir") == 0)
    {
        listOfCurrent();
    }
    else if (command.compare("date") == 0)
    {
        time1();
    }
    else if (command.compare("list") == 0)
    {

        list1();
    }
    else if (command.compare("clear") == 0)
    {
        system("cls");
    }
    else if (command.length() > 4 && command[0] == 'c' && command[1] == 'd' && command[2] == ' ')
    {
        string s = "";
        for (int i = 3; i <= command.length(); ++i)
        {
            s += command[i];
        }
        cd(s);
    }
    else if (command.length() > 4 && command[0] == 'k' && command[1] == 'i' && command[2] == 'l' & command[3] == 'l')
    {
        if (command.length() == 5 && command[5] == '1')
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
    else
    {
        printf("Illegal command!\n");
    }
}

void run(string command)
{
    vector<string> jobs;
    jobs = createJobs(command);
    for (int i = 0; i < jobs.size(); ++i)
    {
        runable(trim(jobs[i]));
    }
}
int main()
{
    WELCOME();
    string command;
    while (true)
    {
        
        cout << "> ";
        getline(cin, command);
        trim(command);
        if (command == EXIT_COMMAND)
        {
            GOODBYE();
            printf("Sending signal to kill all child processes ...\n");
            kill_All();
            break;
        }
        else
        {
            run(command);
        }
    }
}
