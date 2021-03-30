/*  
https://www.acmicpc.net/problem/11722
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> map(MAX);
vector<int> dp(MAX);

int main(){
    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> map[i];
    }

    int ans = 0;
    for (int i=1; i<=N; i++){
        int num = 0;
        for (int j=0; j<i; j++){
            if (map[i] < map[j]){
                if (num < dp[j]){
                    num = dp[j];
                }
            }
        }
        dp[i] = num + 1;

        if(ans < dp[i]) ans = dp[i];
    }
    
    cout << ans << "\n";

}   