#include <windows.h>
#include<bits/stdc++.h>
#include <string>
#include <iostream>
#include<vector>

using namespace std;

string rawCommands;
boolean validCommands;

string trim(string command) {
    int j = -1, k = command.length(), g = command.length();
    for(int i = 0; i < g; ++i) {
        if(command[i] == ' ') {
            j = i;
        }
        else {
            break;
        }
    }

    for(int i = g - 1; i > j; i--) {
        if(command[i] == ' ') {
            k = i;
        }
        else break;
    }
    for(int i = j + 1; i <= k; ++i) {
        command[i-j - 1] = command[i]; 
    }
    for(int i = k - j; i < g; ++i) command[i] = '\0';
    return command;
}
