#include <iostream>
#include <windows.h>
#include <string>
#include<ctime>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <direct.h>
#include <errno.h>

using namespace std;

PROCESS_INFORMATION pi[100];
STARTUPINFO si[100];
LPSTR cString[100];
int n = 0;
//vector<string> nameProcess;
void print(const string &s)
{
    cout << s;
}

void help() {
    // Display all commands
    cout << "For more information on a specific command, type HELP command-name\n";
    cout.width(20); cout << left << "kill -1" << "Kill or stop all running processes\n";
    cout.width(20); cout << left << "kill 'ID'" << "Kill or stop a running process\n";
    cout.width(20); cout << left << "date " << "Displays or sets the date\n";
    cout.width(20); cout << left << "calc" << "Open system calculator\n";
    cout.width(20); cout << left << "list" << "Displays list of commands\n";
    cout.width(20); cout << left << "help" << "Provides Help information for Windows commands\n";
    cout.width(20); cout << left << "cls" << "Clear tiny shell\n";
    cout.width(20); cout << left << "cd 'path'" << "Change current directory to this path\n";
    cout.width(20); cout << left << "cd .." << "Change parrent directory of current directory\n";
    cout.width(20); cout << left << "exit" << "Exit process\n\n";
}

void kill(string s) {
    int id = atoi(s.c_str());

    int a = 1;
    for(int i = 1; i <= n; ++i) {
        if(pi[i].dwProcessId == id) {
            TerminateProcess(pi[i].hProcess, 1);
            //CloseHandle(pi[i].hProcess);
            //CloseHandle(pi[i].hThread);
            printf("Process %s killed\n", cString[i]);
            for(int j = i; j <n; ++j) {
              
                pi[j] = pi[j+1];
                si[j] = si[j+1];
                cString[j] = cString[j+1];    
            }
            n--;
            a = 0;
            break;
        }
    }
    if(a) {
        printf("Can't find process with this id = %d\n", id);
    }
}

void kill_All() {
    for(int i = 1; i <= n; ++i) {
        TerminateProcess(pi[i].hProcess, 1);
        //CloseHandle(pi[i].hProcess);
        //CloseHandle(pi[i].hThread);
    }
    printf("All process killed ...\n");
    n = 0;
}

void openInBackOrFore(const string &s)
{
    void openProcessInForeGround(const string &s);
    void openProcessInBackGround(const string &s);
    cout << "Type 1 to open this process in background mode, otherwise open in foreground mode" << endl;
    string choice;
    getline(cin, choice);
    if (choice.compare("1") == 0)
    {
        openProcessInBackGround(s);
    }
    else
    {
        openProcessInForeGround(s);
    }
}

void openProcessInForeGround(const string &s)
{

    PROCESS_INFORMATION pi;
    STARTUPINFO si = {sizeof(STARTUPINFO)}; // lpStartupInfo    // lpProcessInformation
    // cpp string must be modified to use in c
    LPSTR cString = strdup(s.c_str());
    ZeroMemory(&si, sizeof(si)); // fill this block with zeros
    si.cb = sizeof(si);
    //CreateProcess(cString, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
    if (!CreateProcess(cString, // No module name (use command line)
                       NULL,       // Command line
                       NULL,       // Process handle not inheritable
                       NULL,       // Thread handle not inheritable
                       TRUE,       // Set handle inheritance to FALSE
                       CREATE_NEW_CONSOLE,
                       NULL,   // Use parent's environment block
                       NULL,   // Use parent's starting directory
                       &si, // Pointer to STARTUPINFO structure
                       &pi) // Pointer to PROCESS_INFORMATION structure
    )
    {
        printf("Changing of directory or opening file not successful!\n");
        return;
    }
    WaitForSingleObject(pi.hProcess, INFINITE); // INFINITE
    // hProcess: The handle is used to specify the process in all functions that perform operations on the process object.
    TerminateProcess(pi.hProcess, 1);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void openProcessInBackGround(const string &s)
{
    ++n;
    si[n] = {sizeof(STARTUPINFO)}; // lpStartupInfo
    pi[n];                         // lpProcessInformation
    // cpp string must be modified to use in c
    ZeroMemory(&si[n], sizeof(si[n])); // fill this block with zeros
    si[n].cb = sizeof(si[n]);
    cString[n] = strdup(s.c_str());
    //CreateProcess(cString,NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
    if (!CreateProcess(cString[n], // No module name (use command line)
                       NULL,       // Command line
                       NULL,       // Process handle not inheritable
                       NULL,       // Thread handle not inheritable
                       TRUE,       // Set handle inheritance to FALSE
                       CREATE_NEW_CONSOLE,
                       NULL,   // Use parent's environment block
                       NULL,   // Use parent's starting directory
                       &si[n], // Pointer to STARTUPINFO structure
                       &pi[n]) // Pointer to PROCESS_INFORMATION structure
    )
    {
        --n;
        printf("Changing of directory or opening file not successful!\n");
        return;
    }
    
    
    CloseHandle(pi[n].hThread);
    CloseHandle(pi[n].hProcess);
}


void time()
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

/*void time1(){
    HANDLE h1;   
    DWORD ThreadId;
    h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)time, NULL, 0, &ThreadId);
    cin.get();
    TerminateThread(h1, 0);
    CloseHandle(h1);

}*/

void dir()
{
   char* buffer;

   // Get the current working directory:
   if ( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      printf( "%s ", buffer );
      free(buffer);
   }
}

void listOfCurrent()
{
    char* buffer;

   // Get the current working directory:
   if ( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      printf( "%s \n", buffer );
   }
   if(_chdir( buffer ) )
   {
      switch (errno)
      {
      case ENOENT:
         printf( "Unable to locate the directory: %s\n", buffer );
         break;
      case EINVAL:
         printf( "Invalid buffer.\n");
         break;
        default:
         printf( "Unknown error.\n");
      }
   }
   else
      system( "dir ");
}

void list1()
{ //Track running process
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| Numbers            IdProcess                hProcess                        Name               \n");
    for (int i = 1; i <= n; ++i)
    {
        printf("|   %d                  %d             %p         %s\n", i, pi[i].dwProcessId, pi[i].hProcess, cString[i]);
    }
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void cd(string s)
{
    LPSTR cString = strdup( s.c_str() );
    //pass your path in the function
    int ch=chdir(cString);
    /*if the change of directory was successful it will print successful otherwise it will print not successful*/
    if(ch < 0){
        openInBackOrFore(cString);
    }
    else
        printf("chdir change of directory successful!");
}