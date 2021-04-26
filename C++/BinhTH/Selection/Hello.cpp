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
            else{
                cd(temp);
            }
        }
        else if (command.compare("list") == 0){
            listOfCurrent();
        }
        else if (command.compare("time") == 0){
            time();
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