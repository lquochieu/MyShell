#include<iostream>
#include<dirent.h>
using namespace std;

int main() {
    struct dirent *d;
    DIR *dr;
    dr = opendir(".");
	cout << "List of file in current directory:" << endl;
    if (dr != NULL){
        for(d = readdir(dr); d != NULL; d = readdir(dr)){
            cout << d->d_name << endl;
        }
        closedir(dr);
    } else {
    	cout << "Error Occurred!";
    }
    return 0;
}

