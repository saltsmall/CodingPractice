/*  
https://www.acmicpc.net/problem/1107
*/

#include <iostream>
#include <vector>
#include <cmath> //abs
#include <string>
#include <algorithm>

using namespace std;

vector<bool> broken(10,false);

bool isBroken(int num){
    string str = to_string(num);
    for(int i=0; i<str.length(); i++){
        if(broken[str[i]-'0']) return false;
        //고장난 번호는 입력할 수 없다.
    }
    return true;
}


int main(){
    int N, M;
    cin >> N >> M;
    
    //고장난 번호 저장
    int number;
    for(int i=0; i<M; i++) {
        cin >> number;
        broken[number] = true;
    }

    int ans = abs(N-100);
    for(int i = 0; i<=1000000; i++){
        if(isBroken(i)){
            //현재 숫자로부터 거리(+ or -) + 숫자 버튼 입력 
            int temp = abs(N-i) + to_string(i).length();
            ans = min(ans, temp);
        }
    }
    
    cout << ans;

    return 0;
}