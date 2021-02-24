/*  
https://www.acmicpc.net/problem/1924
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dayOfWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month, day;
    cin >> month >> day; 

    for(int i=1; i<month; i++){
        day += dayOfMonth[i];
    }
    cout << dayOfWeek[day%7];
    
    return 0;
}

/* 
경우를 따지기보다는 공통점을 찾아서 코드 단순화 하자
*/