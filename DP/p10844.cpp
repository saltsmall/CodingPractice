/*  
https://www.acmicpc.net/problem/10844
*/

#include <iostream>
#include <vector>

using namespace std;

/*  
dp[N][i]
길이가 N일 때 i숫자로 끝났을 때
*/

int main(){
    vector<vector<long long> > dp(101,vector<long long>(10));

    int N;
    cin >> N;
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1; j<=9; j++){
            if(j == 9) dp[i][j] = dp[i-1][j-1]%1000000000;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    long long ans = 0;
    for(int i=0; i<=9; i++){
        ans += dp[N][i];
        ans %= 1000000000;
    }
    cout << ans;

    return 0;
}