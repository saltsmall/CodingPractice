/*
https://www.acmicpc.net/problem/9095
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> dp(11);
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i=4; i<11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        cout << dp[num];
    }

    return 0;
}
