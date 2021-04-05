/*  
https://www.acmicpc.net/problem/2146
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100
#define INF 987654321

vector<vector<int> > map(MAX, vector<int>(MAX));
vector<vector<bool> > visited(MAX, vector<bool>(MAX)); 

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int N;

void displayIslandCnt(int y, int x, int cnt){
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));

    while(!q.empty()){
        int x_ = q.front().second;
        int y_ = q.front().first;
        q.pop();

        if(visited[y_][x_]) continue;
        visited[y_][x_] = true;
        map[y_][x_] = cnt;

        
        for(int i=0; i<4; i++){
            int next_y = y_ + dy[i];
            int next_x = x_ + dx[i];    
        
            if(next_y <0 || next_y >= N) continue;
            if(next_x <0 || next_x >= N) continue;
            if(map[next_y][next_x] == 1)
                q.push(make_pair(next_y, next_x));
        }
    }
}

int getBirdgeLength(int cnt){
    queue<pair<int, int> > q;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == cnt){
                q.push(make_pair(i,j));
            }
        }
    }

    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if(visited[y][x]) continue;
            visited[y][x] = true;

            for(int i=0; i<4; i++){
                int next_y = y + dy[i];
                int next_x = x + dx[i];
                
                if(next_y <0 || next_y >= N) continue;
                if(next_x <0 || next_x >= N) continue;
                //다른 섬이랑 만남
                if(map[next_y][next_x] != cnt && map[next_y][next_x] != 0) return ans; 
                else if(map[next_y][next_x] == 0) q.push(make_pair(next_y, next_x)); 
            }
        }
        ans++;
    }
    return INF;
}
int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    //섬 개수 표시
    int cnt = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && map[i][j] != 0){
                displayIslandCnt(i,j,cnt++);
            }
        }
    }

    int ans = INF;
    for(int i=1; i<cnt; i++){
        fill(visited.begin(), visited.end(), vector<bool>(N, false));
        ans = min(ans, getBirdgeLength(i));
    } 

    cout << ans << "\n";

    return 0;
}