/*  
https://www.acmicpc.net/problem/1707
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > map (20001);
vector<int> visited (20001, 0);

void BFS(int start){
    queue<int> q;
    q.push(start);

    //색 -1 or 1  /없음 = 0
    int color = -1;
    while(!q.empty()){
        int q_size = q.size();

        //같은 깊이인 정점들은 같은 색으로 칠한다.
        for(int i=0; i<q_size;i++){
            int num = q.front(); q.pop();
            
            if(visited[num] != 0) continue;
            visited[num] = color;

            for(int j=0; j<map[num].size(); j++){
                q.push(map[num][j]);
            }
        }
        color *= -1;
    }
}

bool isBipartiteGraph(int V){
    for(int i=1; i<=V; i++){
        for(int j=0; j<map[i].size(); j++){
            int next = map[i][j];
            if(visited[i] == visited[next]){
                return false;
            }
        }
    }
    return true;
}


int main(){
    //테스트 케이스
    int K;
    cin>>K;

    for(int i=0; i<K; i++){
        bool ans;
        int V, E;
        cin >> V >> E;

        //map 생성
        for(int i = 1; i<=E; i++){
            int x, y;
            cin >> x >> y;
            map[x].push_back(y);
            map[y].push_back(x);
        }

        //BFS 탐색
        for(int i=1; i<=V; i++){
            if(visited[i]==0){
                BFS(i);
            }
        }

        //이분 그래프 확인
        if(isBipartiteGraph(V)){
            cout << "YES\n";
        }
        else cout << "NO\n";

        //visited 초기화
        for(int i =1; i<=V; i++){
            visited[i] = 0;
            map[i].clear();
        }
    }

    return 0;
}