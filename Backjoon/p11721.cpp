/*  
https://www.acmicpc.net/problem/11721
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int length = str.length();
    for (int i = 0; i < length ; i+=10){
        cout << str.substr(i,10) << endl;
    }
    
    return 0;
}

/*  
substr(첫 시작, 개수)
*/