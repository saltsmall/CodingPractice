/*  
https://www.acmicpc.net/problem/1912
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

vector<int> map(MAX);
vector<long long> dp(MAX);

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    long long ans = map[1];
    dp[1] = map[1];
    for(int i=2; i<=N; i++){
        if(dp[i-1] > 0){
            dp[i] = map[i] + dp[i-1];
        }
        else{
            dp[i] = map[i];
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

    return 0;
}