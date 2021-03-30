/*  
https://www.acmicpc.net/problem/11054
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1001

vector<int> dp_up(MAX);
vector<int> dp_down(MAX);
vector<int> map(MAX);

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    int ans = 0;
    //i가 중심일 때 바이토닉 수열 구하기
    for(int i=1; i<=N; i++){
        int down = 0;
        for(int j=0; j<i; j++){
            if(map[i] > map[j]){
                if(down < dp_down[j]){
                    down = dp_down[j];
                }   
            }
        }
        dp_down[i] = down +1;
    }

    for(int i=N; i>0; i--){
        int up = 0;
        for(int j=N; j>i; j--){
            if(map[i] > map[j]){
                if(up < dp_up[j]){
                    up = dp_up[j];
                }   
            }
        }
        dp_up[i] = up + 1;
    }

    for(int i=1; i<=N; i++){
        ans = max(ans, dp_down[i]+dp_up[i]-1);
    }

    cout << ans << "\n";

    return 0;
}