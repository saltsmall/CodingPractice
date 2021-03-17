/*  
https://www.acmicpc.net/problem/11057
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<long long> > dp(1001, vector<long long>(10));

    int N;
    cin >> N;

    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            for(int k=j; k<=9;k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=9; i++){
        ans += dp[N][i];
        ans %= 10007;
    }

    cout << ans;



    return 0;
}