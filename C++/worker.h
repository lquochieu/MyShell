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
#include "BinhTH/Binhlibrary.h"
#include "CurrentDir.h"

using namespace std;
void runable(string command) {
    if (command.compare("help") == 0){
            cout << "list:";
        }
        else if (command.compare("exit") == 0){
            printf("Bye my friend, see you later!");
            this_thread::sleep_for(chrono::milliseconds(800));
            exit(0);
        }
        else if (command.compare("calc") == 0){
            print("\"Hello\"");
            openProcess("c:/windows/system32/calc.exe");
        }
        else if (command.compare("dir") == 0){
            addCurrentDir();
        }
        else {
            printf("Illegal command!");
        }

}