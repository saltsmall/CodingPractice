/*  
https://www.acmicpc.net/problem/2178
*/

/*  
[BFS와 DFS]

<DFS> : 스택 -> 재귀사용
-조합(최단거리로 갈 수 있는 경로의 수)
-목적지에 도달할 수 있는지 여부
-n에 대해서 조건
-모드 노드 확인

<BFS> : 큐 ->재귀사용못함. while문 사용
-최단거리(최단경로),
-가중치 같고 최소비용 또는 최소횟수
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> map(N+1, vector<int>(M+1));
    vector<vector<bool>> visited(N+1, vector<bool>(M+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            char c;
            cin >> c;
            map[i][j] = c -'0';
        }
    }
    

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));

    int ans = 0;
    bool isFind = false;
    while(!q.empty()){
        int size = q.size();
        for(int s=0; s<size; s++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(visited[y][x]) continue;
            visited[y][x] = true;

            if(y==N && x==M){
                isFind = true;
                break;
            }
            for(int i=0; i<4; i++){
                if(y+dy[i]<1 || y+dy[i]>N) continue;
                if(x+dx[i]<1 || x+dx[i]>M) continue;
                if(map[y+dy[i]][x+dx[i]] == 1){
                    q.push(make_pair(y+dy[i], x+dx[i]));
                }
            }
        }
        ans ++;
        if(isFind){
            break;
        }        
    }
    cout << ans << "\n";

    return 0;
}