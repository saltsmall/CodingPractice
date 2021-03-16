/*  
https://www.acmicpc.net/problem/1476
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> max = {15, 28, 19};
    vector<int> cal(3);
    for(int i=0; i<3; i++){
        cin >> cal[i];    
    }

    int ans = 1;
    vector<int> cur = {1, 1, 1};
    while(1){
        if(cur == cal) break;

        //연도 증가
        for(int i=0; i<3; i++){
            if(cur[i] == max[i]) cur[i] = 1;
            else cur[i]++;
        }
        ans ++;
    }

    cout << ans;

    return 0;
}