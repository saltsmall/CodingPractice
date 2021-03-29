/*  
https://www.acmicpc.net/problem/9465
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

vector<vector<long long> > dp (2, vector<long long>(MAX));
vector<vector<int> > map (2, vector<int>(MAX));
int N, T;

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        for(int n=0; n<2; n++){
            for(int m=1; m<=N; m++){
                cin >> map[n][m];
            }
        }

        dp[0][1] = map[0][1];
        dp[1][1] = map[1][1];
        for(int m=2; m<=N; m++){
            dp[0][m] = max(dp[1][m-1], dp[1][m-2]) + map[0][m];
            dp[1][m] = max(dp[0][m-1], dp[0][m-2]) + map[1][m];
        }

        cout << max(dp[0][N], dp[1][N]) << "\n";
    }

    return 0;
}