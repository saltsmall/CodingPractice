/* 
https://www.acmicpc.net/problem/1697
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int ans = 1000000000;
vector<bool> visited(MAX);

int BFS(){
    queue<pair<int, int>> q;

    q.push(make_pair(N,0));
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == K) return cnt;

        if(visited[cur]) continue;
        visited[cur] = true;

        if(cur+1 < MAX){
            q.push(make_pair(cur+1, cnt+1));
        }
        if(cur-1 >= 0){
            q.push(make_pair(cur-1, cnt+1));
        }
        if(cur*2 < MAX){
            q.push(make_pair(cur*2, cnt+1));
        }
    }
    return -1;
}


int main(){
    cin >> N >> K;
    
    cout << BFS() << "\n";

    return 0;
}