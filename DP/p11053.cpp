/*  
https://www.acmicpc.net/problem/11053
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> dp(MAX);
vector<int> map(MAX);

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    int max = 0;
    for(int i=1; i<=N; i++){
        //자신보다 작은 수를 검색
        int num = 0;
        for(int j=0; j<i; j++){
            if(map[i]>map[j]){
                if(num < dp[j]){
                    num = dp[j];
                }
            }
        }
        dp[i] = num + 1;

        //max 값 찾기

        if(max < dp[i]) max = dp[i];
    }

    cout << max << "\n"; 

    return 0;
}