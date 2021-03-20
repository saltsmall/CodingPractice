/*  
https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

vector<int> ans;
vector<vector<int> > map(25,vector<int>(25));
vector<vector<bool> > visited(25, vector<bool>(25, false));

int BFS(int y, int x){
    queue<pair<int,int> > q;

    int result = 0;

    q.push(make_pair(x,y));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();
        if(visited[y][x]) continue;
        visited[y][x] = true;
        result ++; //단지 추가

        //네방향으로 검색
        for(int i=0; i<4; i++){
            //범위를 벗어났을 경우
            if(y+dy[i]<0 || y+dy[i]>=N || x+dx[i]<0 || x+dx[i]>=N) continue;
            //집이 있는 곳일 경우
            if(map[y+dy[i]][x+dx[i]] == 1) q.push(make_pair(x+dx[i], y+dy[i]));
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //입력
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c; cin >> c;
            map[i][j] = c-'0'; 
        }
    }
    //BFS 실행
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 1 && !visited[i][j]) {
                int result = BFS(i,j);
                ans.push_back(result);
            }
        }
    }


    //출력
    
    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());
    for(int num: ans){
        cout << num << "\n";
    }

    return 0;
}