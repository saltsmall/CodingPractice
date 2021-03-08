/*  
https://www.acmicpc.net/problem/1463
*/
#include<vector>
#include<iostream>

using namespace std;

vector<int> dp(1000001); //저장

int solution(int num){
    if(num == 1) return 0;
    if(dp[num]>0) return dp[num];
    
    dp[num] = solution(num-1) +1;
    if(num %3 == 0){
        int temp = solution(num/3)+1;
        if(dp[num] > temp) dp[num] = temp;
    }
    if(num%2 == 0){
        int temp = solution(num/2)+1;
        if(dp[num] > temp) dp[num] = temp;
    }

    return dp[num];
}

int main(){
    int num;
    cin >> num;
    cout << solution(num) << "\n";

    return 0;
}