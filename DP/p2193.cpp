/*  
https://www.acmicpc.net/problem/2193
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<long long> > dp(91, vector<long long>(2));
    int N;
    cin >> N;

    dp[1][1] = 1;
    
    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    long long ans = dp[N][0] + dp[N][1];
    cout << ans;

    return 0;
}