/*  
https://www.acmicpc.net/problem/11055
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> dp(MAX, 0);
vector<int> map(MAX, 0);

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> map[i];
    }   
    
    int ans = 0;
    for(int i=1; i<=N; i++){
        int num = 0;
        int ind = 0;
        for(int j=0; j<i; j++){
            if(map[j]< map[i]){
                if(num < dp[j]){
                    num = dp[j];
                    ind = j;
                }
            }
        }
        dp[i] = dp[ind] + map[i];
        if(ans < dp[i]) ans = dp[i];
    }

    cout << ans << "\n";

    return 0;
    
}