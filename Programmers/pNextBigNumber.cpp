/*  
https://school.programmers.co.kr/courses/10517/lessons/67198
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countBinary(int number){
    int result=0;
    while(number!=0){
        result += n%2;
        number/=2;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    int count = countBinary(n);
    int next = n+1;
    while(count!=countBinary(next)){
        next++;
    }
    cout << next;
}


