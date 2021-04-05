/*  
https://www.acmicpc.net/problem/2225
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 201

int main(){
    int N,K;
    cin >> N >> K;

    vector<vector<long long> > dp(MAX, vector<long long>(MAX));
    for(int i=0; i<=N; i++){
        dp[1][i] = 1;
    }
    for(int i=1; i<=K; i++){
        for(int j=0; j<=N; j++){
            for(int l=0; l<=j; l++){
                dp[i][j] += dp[i-1][j-l];
                dp[i][j] %= 1000000000;
            }
        }
    }

    cout << dp[K][N] << "\n";



    return 0;
}