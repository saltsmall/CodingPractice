/*
https://www.acmicpc.net/problem/9466
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vec(100001);
vector<int> visited(100001, false);
vector<bool> team(100001, false);
int N, cnt;

void DFS(int cur){
    //더이상 진행하지 않아도 될 때
    if(visited[cur] == -1 || team[cur]) return ; 
    
    if(visited[cur] == 0) visited[cur]++;
    else if(visited[cur] == 1){
        //team에 속함
        team[cur] = true;
        cnt ++;
    }
    //한바퀴를 더 돈다.
    DFS(vec[cur]);
    visited[cur] = -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        cnt = 0;
        cin >> N;
        for(int n=1; n<=N; n++){
            cin >> vec[n];
            visited[n] = false;
            team[n] = false;
        }

        for(int n=1; n<=N; n++){
            if(!visited[n]) DFS(n);
        }
        int ans = N-cnt;
        cout << ans << "\n";
    }

    return 0;
}
