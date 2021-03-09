/*  
https://www.acmicpc.net/problem/9095
*/

#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, T;
    vector<int> dp(11);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n;
        for(int i = 4; i<=n; i++){
            if(dp[i] == 0) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << "\n";
    }
    
    return 0;
}