/*  
https://www.acmicpc.net/problem/11726
*/
#include <vector>
#include <iostream>

using namespace std;

/* 
    dp[3] = dp[2] + d[1]
    dp[i] = dp[i-2] + dp[i-1]

 */
int main(){
    vector<int> dp(1000);
    dp[1] = 1; dp[2] = 2;
    int num;
    cin >> num;

    for(int i=3; i<=num; i++){
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }

    cout << dp[num];
}