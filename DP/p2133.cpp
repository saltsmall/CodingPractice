/*  
https://www.acmicpc.net/problem/2133
*/

#include <iostream>
#include <vector>

#define MAX 35

using namespace std;

vector<int> dp(MAX);

int main(){
    int N;
    cin >> N;

    dp[0] = 1, dp[1] = 0, dp[2] = 3;

    for(int i=3; i<=N; i++){
        dp[i] = dp[i-2] * dp[2];
        for(int j= i-4; j>=0; j = j-2){
            dp[i] += dp[j]*2;
        }
    }

    cout << dp[N] << "\n";

    return 0;
}