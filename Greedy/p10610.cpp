/*  
https://www.acmicpc.net/problem/10610
*/
#include <iostream>
#include <string>
#include <algorithm>

/* 
[30의 배수 판정]
1.모든 수의 합은 3의배수
2.0은 하나이상 포함해야한다.

*/

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string N;
    cin >> N;
    
    //판정법
    int sum = 0;
    int count = 0;
    for(int i=0; i<N.length(); i++){
        if(N[i] == '0') count++;
        else sum += N[i];
    }
    if(sum%3!=0 || count ==0){
        cout << -1; 
    }
    else{
        sort(N.begin(), N.end(), greater<char>());
        cout << N << "\n";
        
    }
    return 0;
}
