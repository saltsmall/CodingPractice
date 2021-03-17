/*  
https://www.acmicpc.net/problem/11729
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

string message = "";
int count = 0;

//N번째 원반 start에서 to로 옮긴다 
void move(int N, int start, int to){
    message += to_string(start) + " " + to_string(to) + "\n";

    count ++;
}

void hanoi(int N, int start, int to, int via){
    if(N==1) move(1, start, to);
    else{
        hanoi(N-1, start, via, to);
        move(N, start, to);
        hanoi(N-1, via, to, start);
    }
}

int main(){
    int N;
    cin >> N;

    hanoi(N,1,3,2);

    cout << count << "\n";
    cout<< message;

    return 0;
}