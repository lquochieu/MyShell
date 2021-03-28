#include <windows.h>
#include<bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include "concurentCommandBuilder.h"

using namespace std;

vector<string> createJobs(string command) {
	vector<string> jobs;
	string s = "";
	int a = command.length();
	for(int i = 0; i < a; ++i) {
		if(command[i] != '>') {
			s = s + command[i];
		}
		else {
			jobs.push_back(s);
			s = "";
		}
	}
	jobs.push_back(s);
	for(int i = 0; i <= jobs.size(); ++i) {
		trim(jobs[i]);
	}
    return jobs;
}

int main() {
	vector<string> job;
	job = createJobs("hello > mina > san");
	for(int i = 0; i < job.size(); ++i) {
		cout << job[i] << endl;
	}
}

