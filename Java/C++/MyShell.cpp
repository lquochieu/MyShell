#include <bits/stdc++.h>
#include <string.h>
#include<vector>
#include "CurrentDir.h"
#include "messenger.h"
#include "concurentCommandBuilder.h"

using namespace std;

vector<string> jobs;
const string EXIT_COMMAND = "exit";
    string currentDirectory;
void run(string command) {
    jobs = createJobs(command);
    cout << jobs[0];
}
int main() {
    WELCOME();
    string command;
    currentDirectory = currentDir();
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
