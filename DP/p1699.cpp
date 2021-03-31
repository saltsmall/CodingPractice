/*  
https://www.acmicpc.net/problem/1699
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 100001

vector<int> dp(MAX);

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=1; j*j <=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[N] << "\n";
    return 0;
}