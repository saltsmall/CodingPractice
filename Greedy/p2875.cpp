/* 
https://www.acmicpc.net/problem/2875
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int ans = 0;
    int N, M, K;
    cin >> N >> M >> K;

    for(int man=0; man<=K; man++){
        //인턴보내는 학생 수 결정
        int men = M-man;
        int women = N-(K-man);

        //최대 만들 수 있는 팀 
        int team = min(women/2, men);
        if(team > ans) ans = team;
    }
    cout << ans;

    return 0;
}