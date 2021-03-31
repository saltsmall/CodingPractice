/*  
https://www.acmicpc.net/problem/2579
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 301

vector<long long> map(MAX);
vector<long long> dp(MAX);

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    dp[1] = map[1];
    dp[2] = max(map[1], dp[1]+ dp[2]);
    for(int i=3; i<=N; i++){
        dp[i] = max(dp[i-2]+map[i], dp[i-3]+map[i-1]+map[i]);
    }
    cout << dp[N] << "\n";

    return 0;
}