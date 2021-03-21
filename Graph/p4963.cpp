/*  
https://www.acmicpc.net/problem/4963
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//지도의 너비, 높이
int w, h;
int ans;

//이동
vector<int> dx = {-1, 1, 0, 0, -1, 1, -1, 1};
vector<int> dy = {0, 0, -1, 1, -1, 1, 1, -1};

vector<vector<int> > map(50, vector<int>(50)); 
vector<vector<bool> > visited(50, vector<bool>(50, false));

void BFS(int y, int x){
    ans ++;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();
        if(visited[y][x]) continue;
        visited[y][x] = true;

        for(int i=0; i<8; i++){
            if(x+dx[i] < 0 || x+dx[i] >= w || y+dy[i] < 0 || y+dy[i] >= h) continue;
            if(map[y+dy[i]][x+dx[i]] == 1) q.push(make_pair(x+dx[i], y+dy[i]));
        }
    }
}

int main(){
    while(!cin.eof()){
        //입력
        cin >> w >> h;
        if(w == 0 && h == 0) break; //입력중단
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){ 
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }
        
        //섬 개수 찾기
        ans = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j] && map[i][j] == 1) BFS(i, j);
            }
        }

        cout << ans << "\n";
    }
}