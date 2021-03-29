/*  
https://www.acmicpc.net/problem/2156
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX 10001

vector<long long> dp (MAX);
vector<int> map(MAX);

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> map[i];
    }

    dp[1] = map[1];
    dp[2] = dp[1] + map[2];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-2] + map[i], dp[i-3] + map[i-1] + map[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}

