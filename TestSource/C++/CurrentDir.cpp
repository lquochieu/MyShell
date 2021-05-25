#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <tlhelp32.h> 
#include <vector>
#include <tchar.h>
#include <debugapi.h>
#include <processthreadsapi.h>

using namespace std;
string Dir() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
int main()  {
	cout << Dir();
}