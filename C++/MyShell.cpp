#include <windows.h>
#include <bits/stdc++.h>
#include <string.h>
#include<vector>
#include <thread>
#include <chrono>
#include <tlhelp32.h> 
#include <tchar.h>
#include<debugapi.h>
#include <processthreadsapi.h>
#include "BinhTH/Binhlibrary.h"
#include "CurrentDir.h"
#include "messenger.h"
#include "concurentCommandBuilder.h"

using namespace std;

const string EXIT_COMMAND = "exit";
    string currentDirectory;
    void runable(string command) {
    if (command.compare("help") == 0){
            cout << "list:";
        }
        else if (command.compare("exit") == 0){
            GOODBYE;
            this_thread::sleep_for(chrono::milliseconds(800));
            exit(0);
        }
        else if (command.compare("calc") == 0){
            print("Hello\n");
            openProcess("c:/windows/system32/calc.exe");
        }
        else if (command.compare("dir") == 0){
            addCurrentDir();
        }
        else {
            printf("Illegal command!\n");
        }

}

void run(string command) {
    vector<string> jobs;
    jobs = createJobs(command);
    for(int i = 0; i < jobs.size(); ++i) {
        cout << trim(jobs[i]) << " " << trim(jobs[i]).length() << endl;
        runable(trim(jobs[i]));
    }
}
int main() {
    WELCOME();
    string command;
    while(true) {
        cout << "> ";
        getline(cin, command);
        trim(command);
        if(command == EXIT_COMMAND) {
            GOODBYE();
            break;
        }
        else {
            run(command);
        }
    }

}
