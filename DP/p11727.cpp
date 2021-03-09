/*  
https://www.acmicpc.net/problem/11727
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(1000);
    dp[1] = 1; dp[2] = 3;

    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]*2;
        dp[i] %= 10007;
    }    

    cout << dp[n];
}