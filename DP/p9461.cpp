/*  
https://www.acmicpc.net/problem/9461
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101

int main(){
    vector<long long> dp(MAX);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for(int i=4; i<MAX; i++){
        dp[i] = dp[i-3] + dp[i-2];
    }

    int T,N;
    cin >> T;
    for(int i=0; i<T;i++){
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}