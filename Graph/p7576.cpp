/*  
https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    vector<vector<int> > map(N,vector<int>(M));
    vector<vector<bool> > visited(N,vector<bool>(M));
    queue<pair<int,int> > q; 

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push(make_pair(i,j));
            }
        }
    }
    if(q.size() == 0){
        cout << 0 << "\n";
        return 0;
    }
    int ans = -1;
    while(!q.empty()){
        int size = q.size();

        bool next = false;
        for(int i=0; i<size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(visited[y][x]) continue;
            visited[y][x] = true;

            next = true;
            for(int i=0; i<4; i++){
                if(y+dy[i]<0 || y+dy[i]>=N) continue;
                if(x+dx[i]<0 || x+dx[i]>=M) continue;

                if(map[y+dy[i]][x+dx[i]] == 0)
                    q.push(make_pair(y+dy[i], x+dx[i]));
            }
        }
        if(next) ans++;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]&&map[i][j]!=-1){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << ans <<"\n";

    return 0;
}