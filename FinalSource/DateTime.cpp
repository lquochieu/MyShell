#include <iostream>
#include <ctime>

using namespace std;
void time()
{
    int sec_prev = 0;
    while (1)
    {
        int seconds, minutes, hours;
        string str;

        time_t total_seconds = time(0);                          // storing total seconds
        struct tm *ct = localtime(&total_seconds);              // getting values of seconds, minutes and hours

        seconds = ct->tm_sec;
        minutes = ct->tm_min;
        hours = ct->tm_hour;

        //printing the result
        
        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0))
        {
        	system("cls");
            cout<<"       ,--.-----.--."<<endl;
      		cout<<"       |--|-----|--|"<<endl;
       		cout<<"       |--|     |--|"<<endl;
       		cout<<"       |  |-----|  |"<<endl;
     		cout<<"     __|--|     |--|__"<<endl;
    		cout<<"    /  |  |-----|  |  \\"<<endl;
   			cout<<"   /   \\__|-----|__/   \\"<<endl;
  			cout<<"  /   ______---______   \\/\\"<<endl;
 			cout<<" /   /               \\   \\/"<<endl;
			cout<<"{   /      ROLEX      \\   }"<<endl;
			cout<<"|  {                   }  |-,"<<endl;
			
			cout << (hours < 10 ? "|  |    0" : "|  |    ") << hours << (minutes < 10 ? " : 0" : " : ") << minutes
			<< (seconds < 10 ? " : 0" : " : ") << seconds << "   |  | |"  << endl;
			
			cout<<"|  {                   }  |-'"<<endl;
			cout<<"{   \\                 /   }"<<endl;
 			cout<<" \\   `------___------'   /\\"<< endl;
			cout<<"  \\     __|-----|__     /\\/"<< endl;
   			cout<<"   \\   /  |-----|  \\   /"<<endl;
    		cout<<"    \\  |--|     |--|  /"<<endl;
     		cout<<"     --|  |-----|  |--"<<endl;
       		cout<<"       |--|     |--|"<<endl;
       		cout<<"       |--|-----|--|"<<endl;
       		cout<<"       `--'-----`--'"<<endl;
        }
        sec_prev = seconds;
    }
}
int main(void){
	time();
}
